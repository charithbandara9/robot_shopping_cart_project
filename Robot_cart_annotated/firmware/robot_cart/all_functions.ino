#include <Arduino.h>
#include "definations___variable.h"

void setMotorRaw(int lF, int lB, int rF, int rB){
  lF = constrain(lF, 0, MAX_PWM);
  lB = constrain(lB, 0, MAX_PWM);
  rF = constrain(rF, 0, MAX_PWM);
  rB = constrain(rB, 0, MAX_PWM);
  analogWrite(PIN_LF_PWM, lF);
  analogWrite(PIN_LB_PWM, lB);
  analogWrite(PIN_RF_PWM, rF);
  analogWrite(PIN_RB_PWM, rB);
}

void setMotor(int left, int right){
  left  = constrain(left,  -MAX_PWM, MAX_PWM);
  right = constrain(right, -MAX_PWM, MAX_PWM);

  int lF = left  >= 0 ? left  : 0;
  int lB = left  <  0 ? -left : 0;
  int rF = right >= 0 ? right : 0;
  int rB = right <  0 ? -right: 0;

  setMotorRaw(lF, lB, rF, rB);
}

void stopMotors(){
  setMotorRaw(0,0,0,0);
}
