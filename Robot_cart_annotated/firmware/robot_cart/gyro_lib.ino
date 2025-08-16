#include <Arduino.h>
#include <Wire.h>
#include "definations___variable.h"

// L3G4200D registers
#define L3G_ADDR 0x69 // try 0x68 if your board uses SA0 low
#define CTRL_REG1 0x20
#define CTRL_REG4 0x23
#define OUT_Z_L   0x2C

float gyroZ_dps = 0.0f;
float yaw_deg    = 0.0f;

static void i2cWrite(uint8_t reg, uint8_t val){
  Wire.beginTransmission(L3G_ADDR);
  Wire.write(reg);
  Wire.write(val);
  Wire.endTransmission();
}

static int16_t i2cRead16(uint8_t reg){
  Wire.beginTransmission(L3G_ADDR);
  Wire.write(reg | 0x80); // auto-increment
  Wire.endTransmission(false);
  Wire.requestFrom(L3G_ADDR, 2);
  while(Wire.available() < 2);
  uint8_t lo = Wire.read();
  uint8_t hi = Wire.read();
  return (int16_t)(hi << 8 | lo);
}

bool gyroBegin(){
  // Wire.begin() is called in main; this only configures the device
  // 800 Hz ODR, enable XYZ
  i2cWrite(CTRL_REG1, 0b00111111);
  // 2000 dps scale
  i2cWrite(CTRL_REG4, 0b00110000);
  delay(100);
  return true;
}

// call often; dt in seconds
void gyroUpdate(float dt){
  int16_t rawZ = i2cRead16(OUT_Z_L);
  // 2000 dps FS sensitivity ~ 70 mdps/digit
  gyroZ_dps = rawZ * 0.07f;
  yaw_deg += gyroZ_dps * dt;
}
