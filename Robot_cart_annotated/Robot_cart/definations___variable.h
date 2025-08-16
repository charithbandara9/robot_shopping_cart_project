/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments aim to clarify purpose without changing behavior.
 * Note: Some files contain "..." which indicates missing/omitted code in the provided project.
 * This annotation keeps your code compile-ready on Arduino Mega 2560.
 */

// Code line performing logic or calling a function; see the next line for details
#ifndef _VAR_H
// Define a constant or macro that the compiler replaces everywhere in the code
#define _VAR_H
// Define a constant or macro that the compiler replaces everywhere in the code
#define beep 13  //buzzer pin
// Existing comment from your code (kept): button definations
//button definations
// Define a constant or macro that the compiler replaces everywhere in the code
#define button1 23
// Define a constant or macro that the compiler replaces everywhere in the code
#define button2 25
// Existing comment from your code (kept): #define button3 34
// #define button3 34
// (blank line to keep code readable)

// Existing comment from your code (kept): qtr Threshold & weight
//qtr Threshold & weight
// Define a constant or macro that the compiler replaces everywhere in the code
#define juncDetectThreshold 11
// Define a constant or macro that the compiler replaces everywhere in the code
#define weightedValMax 30
// (blank line to keep code readable)

// Existing comment from your code (kept): BTS7960B motor drive pinmode
//BTS7960B motor drive pinmode
// Define a constant or macro that the compiler replaces everywhere in the code
#define LFPWM 6
// Define a constant or macro that the compiler replaces everywhere in the code
#define LBPWM 4
// Define a constant or macro that the compiler replaces everywhere in the code
#define LF_EN 49
// Define a constant or macro that the compiler replaces everywhere in the code
#define LB_EN 47
// Define a constant or macro that the compiler replaces everywhere in the code
#define RFPWM 9
// Define a constant or macro that the compiler replaces everywhere in the code
#define RBPWM 7
// Define a constant or macro that the compiler replaces everywhere in the code
#define RF_EN 53
// Define a constant or macro that the compiler replaces everywhere in the code
#define RB_EN 51
// Existing comment from your code (kept): ////////////////////////////////////////////////////////////////variables///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////variables///////////////////////////////////////////////////////////
// (blank line to keep code readable)

// Define a constant or macro that the compiler replaces everywhere in the code
#define SensorCount 8
// A single instruction; see the code line below for the exact action
const uint8_t sensorPins[SensorCount] = { A7, A6, A5, A4, A3, A2, A1, A0 };
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int rawValues[SensorCount];
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int minimum[SensorCount];
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int maximum[SensorCount];
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int digiSensorVals[SensorCount];  // 0 for black, 1 for white
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int blackWhiteThreshold = 900;    // Adjust this based on your sensor readings
// (blank line to keep code readable)

// (blank line to keep code readable)

// Existing comment from your code (kept): encorder
//encorder
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int enError = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
volatile unsigned int RMEnCount = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
volatile unsigned int LMEnCount = 0;
// (blank line to keep code readable)

// Existing comment from your code (kept): PID variables
// PID variables
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float Kp = 2.5;  // Proportional gain
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float Ki = 0;    // Integral gain
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float Kd = 5;    // Derivative gain
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float integral = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float previousError = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float output = 0;
// (blank line to keep code readable)

// Existing comment from your code (kept): Desired position (center of the line)
// Desired position (center of the line)
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int desiredPosition = 2;  // Adjust this value based on the sensor configuration 3
// (blank line to keep code readable)

// Existing comment from your code (kept): gyro lib variables
//gyro lib variables
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG1 0x20
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG2 0x21
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG3 0x22
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG4 0x23
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG5 0x24
// Define a constant or macro that the compiler replaces everywhere in the code
#define CTRL_REG6 0x25
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroI2CAddr = 0x69;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroRaw[3];                // raw sensor data, each axis, pretty useless really but here it is.
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
double gyroDPS[3];             // gyro degrees per second, each axis
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float heading[3] = { 0.0f };   // heading[x], heading[y], heading [z]
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroZeroRate[3];           // Calibration data.  Needed because the sensor does center at zero, but rather always reports a small amount of rotation on each axis.
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroThreshold[3];          // Raw rate change data less than the statistically derived threshold is discarded.
// Define a constant or macro that the compiler replaces everywhere in the code
#define NUM_GYRO_SAMPLES 50    // As recommended in STMicro doc
// Define a constant or macro that the compiler replaces everywhere in the code
#define GYRO_SIGMA_MULTIPLE 3  // As recommended
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
float dpsPerDigit = .00875f;   // for conversion to degrees per second
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int store_location = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int robot_status = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int counts_45 = 90;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int counts_180 = 575;
// Code line performing logic or calling a function; see the next line for details
#endif
