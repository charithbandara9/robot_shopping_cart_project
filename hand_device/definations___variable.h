/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments explain purpose without changing behavior.
 * Board target: Arduino Mega 2560.
 */

// Code line calling a function or doing logic
#ifndef _VAR_H
// Define a constant or macro replaced by the compiler
#define _VAR_H
// Define a constant or macro replaced by the compiler
#define beep 13  //buzzer pin
// (blank line to keep code readable)

// Existing comment from your code (kept): WiFi credentials
// WiFi credentials
// Single instruction; see the actual code line for its effect
const char* ssid = "wifi_123";
// Single instruction; see the actual code line for its effect
const char* password = "kalana123";
// (blank line to keep code readable)

// Existing comment from your code (kept): Server (Python script) IP and port
// Server (Python script) IP and port
// Code line calling a function or doing logic
const char* serverIP = "192.168.1.102";  // Replace with your PC/server IP
// Single instruction; see the actual code line for its effect
const uint16_t serverPort = 9999;
// (blank line to keep code readable)

// Declare a variable (type + name, optional initial value)
int frameIndex = 0;
// Existing comment from your code (kept): Define your refresh button pin
// Define your refresh button pin
// Declare a variable (type + name, optional initial value)
volatile bool refreshRequested = false;
// Declare a variable (type + name, optional initial value)
volatile bool M_button_1 = false;
// Declare a variable (type + name, optional initial value)
volatile bool M_button_2 = false;
// Declare a variable (type + name, optional initial value)
volatile bool M_button_3 = false;
// Define a constant or macro replaced by the compiler
#define cam_on_off 21
// Define a constant or macro replaced by the compiler
#define REFRESH_BUTTON 33  // GPIO pin for refresh button
// Define a constant or macro replaced by the compiler
#define button_1 25        //3
// Define a constant or macro replaced by the compiler
#define button_2 19        //1
// Define a constant or macro replaced by the compiler
#define button_3 22        //2
// Declare a variable (type + name, optional initial value)
int screen = 0;
// Define a constant or macro replaced by the compiler
#define BATTERY_PIN 27                     // ADC pin connected to the voltage divider
// Code line calling a function or doing logic
const float VOLTAGE_DIVIDER_RATIO = 3.13;  // (10k + 4.7k) / 4.7k
// Code line calling a function or doing logic
const float ADC_REF_VOLTAGE = 3.3;         // ESP32 ADC reference voltage
// Code line calling a function or doing logic
const int ADC_RESOLUTION = 4095;           // 12-bit ADC
// Declare a variable (type + name, optional initial value)
int raw_adc;
// Declare a variable (type + name, optional initial value)
float v_adc;
// Declare a variable (type + name, optional initial value)
float battery_voltage;
// Declare a variable (type + name, optional initial value)
unsigned long batt_previousMillis = 0;
// Single instruction; see the actual code line for its effect
const int batt_cal_time = 10;
// Declare a variable (type + name, optional initial value)
unsigned long msg_previousMillis = 0;
// Single instruction; see the actual code line for its effect
const int msg_cal_time = 2;
// Declare a variable (type + name, optional initial value)
int select_box_1 = 5;
// Declare a variable (type + name, optional initial value)
int select_box_2 = 0;
// Declare a variable (type + name, optional initial value)
int select_box_3 = 1;
// Declare a variable (type + name, optional initial value)
int select_box_4 = 0;
// Code line calling a function or doing logic
#endif
