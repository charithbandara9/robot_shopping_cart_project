#include <Arduino.h>
#include <Wire.h>
#include "definations___variable.h"

int   sensorMin[8];
int   sensorMax[8];
int   sensorVal[8];

volatile long encL = 0;
volatile long encR = 0;

void isrEncL(){ encL++; }
void isrEncR(){ encR++; }

void beep(int ms){
  digitalWrite(PIN_BUZZER, HIGH);
  delay(ms);
  digitalWrite(PIN_BUZZER, LOW);
}

void setupPins(){
  // Motor pins
  pinMode(PIN_LF_PWM, OUTPUT);
  pinMode(PIN_LB_PWM, OUTPUT);
  pinMode(PIN_RF_PWM, OUTPUT);
  pinMode(PIN_RB_PWM, OUTPUT);
  pinMode(PIN_LF_EN, OUTPUT);
  pinMode(PIN_LB_EN, OUTPUT);
  pinMode(PIN_RF_EN, OUTPUT);
  pinMode(PIN_RB_EN, OUTPUT);

  // Enable both bridges
  digitalWrite(PIN_LF_EN, HIGH);
  digitalWrite(PIN_LB_EN, HIGH);
  digitalWrite(PIN_RF_EN, HIGH);
  digitalWrite(PIN_RB_EN, HIGH);

  // Buttons
  pinMode(PIN_BTN_START, INPUT_PULLUP);
  pinMode(PIN_BTN_ESP,   INPUT_PULLUP);

  // Buzzer
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);

  // Sensors
  for(int i=0;i<8;i++){
    pinMode(SENSOR_PINS[i], INPUT);
    sensorMin[i] = 1023;
    sensorMax[i] = 0;
  }

  // Encoders
  pinMode(PIN_ENC_L_A, INPUT_PULLUP);
  pinMode(PIN_ENC_R_A, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_L_A), isrEncL, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_R_A), isrEncR, RISING);
}

void calibrateSensors(){
  // Simple calibration: sweep readings to capture min/max while robot is moved by hand
  unsigned long t0 = millis();
  while(millis() - t0 < 2000){ // 2 seconds
    for(int i=0;i<8;i++){
      int v = analogRead(SENSOR_PINS[i]);
      if(v < sensorMin[i]) sensorMin[i] = v;
      if(v > sensorMax[i]) sensorMax[i] = v;
    }
  }
}

// Map raw analog to 0..1000 per channel
int readLineSensors(int* out){
  long weighted = 0;
  long sum = 0;
  for(int i=0;i<8;i++){
    int v = analogRead(SENSOR_PINS[i]);
    // clamp min/max
    v = constrain(v, sensorMin[i], sensorMax[i]);
    // normalize so black ~ 1000, white ~ 0 (invert if your sensors output opposite)
    int norm = map(v, sensorMin[i], sensorMax[i], 0, 1000);
    out[i] = norm;
    weighted += (long)norm * (i * 1000); // position 0..7000
    sum += norm;
  }
  if(sum == 0) return -1; // line lost
  return (int)(weighted / sum); // 0..7000
}
