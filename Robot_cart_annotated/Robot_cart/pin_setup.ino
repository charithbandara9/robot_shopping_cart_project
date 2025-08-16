/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments aim to clarify purpose without changing behavior.
 * Note: Some files contain "..." which indicates missing/omitted code in the provided project.
 * This annotation keeps your code compile-ready on Arduino Mega 2560.
 */

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void pin_setup() {
// Start USB serial communication with the PC at the given baud rate (open Serial Monitor to see messages)
  Serial.begin(9600);
// Start the SoftwareSerial port at the given baud; talk to external module (e.g., ESP-01)
  mySerial.begin(9600);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.begin();  //i2c
// (blank line to keep code readable)

// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(button1, INPUT_PULLUP);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(button2, INPUT_PULLUP);
// (blank line to keep code readable)

// (blank line to keep code readable)

// (blank line to keep code readable)

// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(beep, OUTPUT);  //right forword
// Existing comment from your code (kept): /////////////////////////////////////////motor drive setup//////////////////////////////////////////////////////////////
  ///////////////////////////////////////////motor drive setup//////////////////////////////////////////////////////////////
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(RFPWM, OUTPUT);  //right forword
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(RBPWM, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(RF_EN, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(RB_EN, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(LFPWM, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(LBPWM, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(LF_EN, OUTPUT);
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
  pinMode(LB_EN, OUTPUT);
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
  digitalWrite(RF_EN, HIGH);
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
  digitalWrite(RB_EN, HIGH);
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
  digitalWrite(LF_EN, HIGH);
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
  digitalWrite(LB_EN, HIGH);
// Attach an interrupt to a pin; when a signal change happens, a function (ISR) runs immediately
  attachInterrupt(digitalPinToInterrupt(2), left_motor_enc_count, CHANGE);
// Attach an interrupt to a pin; when a signal change happens, a function (ISR) runs immediately
  attachInterrupt(digitalPinToInterrupt(3), right_motor_enc_count, CHANGE);
// A single instruction; see the code line below for the exact action
  Serial.println("sensor_arry_instalation_start");
// A single instruction; see the code line below for the exact action
  Initsensors();
// A single instruction; see the code line below for the exact action
  Serial.println("sensor_arry_instalation_done");
// A single instruction; see the code line below for the exact action
  beep_buzzer(1);
// Existing comment from your code (kept): calibrateSensors();
  //calibrateSensors();
// Existing comment from your code (kept): beep_buzzer(5);
  //beep_buzzer(5);
// A single instruction; see the code line below for the exact action
  sensors_Load();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i <3; i++) {
// A single instruction; see the code line below for the exact action
    setupGyro();
// A single instruction; see the code line below for the exact action
    calibrateGyro();
// A single instruction; see the code line below for the exact action
    heading[2] = 0;
// End of the current code block
  }
// Existing comment from your code (kept): mySerial.println("Hello ESP-01 from Mega");
  //  mySerial.println("Hello ESP-01 from Mega");
// A single instruction; see the code line below for the exact action
  beep_buzzer(1);
// End of the current code block
}
