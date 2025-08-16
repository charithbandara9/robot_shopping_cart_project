#ifndef DEFINATIONS___VARIABLE_H
#define DEFINATIONS___VARIABLE_H

// ---------------- Pins ----------------
// Motor driver (BTS7960) - LEFT
const uint8_t PIN_LF_PWM = 6;   // RPWM (forward)
const uint8_t PIN_LB_PWM = 4;   // LPWM (backward)
const uint8_t PIN_LF_EN  = 49;  // enable
const uint8_t PIN_LB_EN  = 47;  // enable

// Motor driver (BTS7960) - RIGHT
const uint8_t PIN_RF_PWM = 9;   // RPWM (forward)
const uint8_t PIN_RB_PWM = 7;   // LPWM (backward)
const uint8_t PIN_RF_EN  = 53;  // enable
const uint8_t PIN_RB_EN  = 51;  // enable

// Encoders (A channels)
const uint8_t PIN_ENC_L_A = 2;  // INT0
const uint8_t PIN_ENC_R_A = 3;  // INT1

// IR Sensor array (left→right)
const uint8_t SENSOR_PINS[8] = {A7, A6, A5, A4, A3, A2, A1, A0};

// Buttons (use INPUT_PULLUP)
const uint8_t PIN_BTN_START = 23;  // Start/calibrate
const uint8_t PIN_BTN_ESP   = 25;  // ESP reset (optional)

// Buzzer
const uint8_t PIN_BUZZER = 13;

// Optional SoftwareSerial to ESP-01
const uint8_t PIN_SW_RX = 10; // Mega listens on D10 (connected to ESP-01 TXD)
const uint8_t PIN_SW_TX = 11; // Mega transmits on D11 (to ESP-01 RXD via divider)

// ---------------- Control Params ----------------
const int   BASE_SPEED      = 120;   // 0..255 base PWM (tune for your chassis)
const int   MAX_PWM         = 255;
const float KP              = 18.0;  // PID gains for line error → steering
const float KD              = 6.0;
const float KI              = 0.0;

const bool  ENABLE_AUTO_START = true; // set true to start following after calibration

// Sensor calibration
extern int   sensorMin[8];
extern int   sensorMax[8];
extern int   sensorVal[8];

// Encoder counters
extern volatile long encL;
extern volatile long encR;

// Gyro state
extern float gyroZ_dps;   // instantaneous deg/s
extern float yaw_deg;     // integrated heading (rough)

// Shared
void beep(int ms);
void setMotor(int left, int right);
void setMotorRaw(int lF, int lB, int rF, int rB);
void stopMotors();

#endif
