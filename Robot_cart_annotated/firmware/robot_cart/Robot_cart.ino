/*
  Robot Cart - Corrected Firmware (Arduino Mega 2560)
  - Dual BTS7960B motor drivers
  - 8x analog line sensor array
  - L3G4200D gyro over I2C
  - Encoder A channels on D2/D3
  - Optional ESP-01 via SoftwareSerial(D10,D11)
*/
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "definations___variable.h"

// Forward decl
void setupPins();
void calibrateSensors();
int  computeLineError();
bool gyroBegin();
void gyroUpdate(float dt);

SoftwareSerial espSerial(PIN_SW_RX, PIN_SW_TX); // Mega RX,TX

// PID
float integral = 0;
int   lastError = 0;

// State
bool started = false;
unsigned long lastMs = 0;

void setup(){
  Serial.begin(115200);
  espSerial.begin(9600); // match your ESP-01 firmware baud

  setupPins();
  Wire.begin();

  Serial.println("== Robot Cart ==");
  beep(120); delay(80); beep(120);

  Serial.println("Gyro init...");
  gyroBegin();

  Serial.println("Hold START button to calibrate sensors...");
  if(digitalRead(PIN_BTN_START) == LOW){
    beep(200);
    calibrateSensors();
    beep(400);
    Serial.println("Calibration done.");
  } else {
    Serial.println("Skipped calibration (press Start during boot to calibrate).");
  }

  if(ENABLE_AUTO_START){
    started = true;
    Serial.println("AUTO_START enabled → following line.");
  } else {
    Serial.println("Waiting for command or Start button...");
  }

  lastMs = millis();
}

void loop(){
  // Toggle start on button
  if(digitalRead(PIN_BTN_START) == LOW){
    started = !started;
    beep(150);
    delay(250);
  }

  // Optional: simple text protocol from ESP-01
  if(espSerial.available()){
    String cmd = espSerial.readStringUntil('\n');
    cmd.trim();
    if(cmd == "START"){ started = true;  beep(100); }
    if(cmd == "STOP"){  started = false; stopMotors(); beep(200); }
  }

  unsigned long now = millis();
  float dt = (now - lastMs) / 1000.0f;
  lastMs = now;

  gyroUpdate(dt);

  if(!started){
    stopMotors();
    return;
  }

  // Line following PID
  int err = computeLineError();             // -3500..+3500
  integral += err;
  float deriv = (err - lastError);
  lastError = err;

  float steer = KP*err + KD*deriv + KI*integral;
  steer /= 100.0f; // scale error

  int left  = BASE_SPEED - (int)steer;
  int right = BASE_SPEED + (int)steer;

  setMotor(left, right);
}
