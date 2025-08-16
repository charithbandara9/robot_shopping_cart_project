/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments aim to clarify purpose without changing behavior.
 * Note: Some files contain "..." which indicates missing/omitted code in the provided project.
 * This annotation keeps your code compile-ready on Arduino Mega 2560.
 */

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void updateHeadings() {
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float deltaT = getDeltaTMicros();
// (blank line to keep code readable)

// for-loop: repeat a block of code a specific number of times/over a range
  for (int j = 0; j < 3; j++)
// A single instruction; see the code line below for the exact action
    heading[j] -= (gyroDPS[j] * deltaT) / 1000000.0f;
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): this simply returns the elapsed time since the last call.
// this simply returns the elapsed time since the last call.
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
unsigned long getDeltaTMicros() {
// A single instruction; see the code line below for the exact action
  static unsigned long lastTime = 0;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  unsigned long currentTime = micros();
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  unsigned long deltaT = currentTime - lastTime;
// Conditional: run the following block only if the condition is true
  if (deltaT < 0.0)
// A single instruction; see the code line below for the exact action
    deltaT = currentTime + (4294967295 - lastTime);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  lastTime = currentTime;
// (blank line to keep code readable)

// Return a value (or exit a function)
  return deltaT;
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): I called this from the loop function to see what the right values were for the calibration constants.
// I called this from the loop function to see what the right values were for the calibration constants.
// Existing comment from your code (kept): If you are trying to reduce the amount of time needed for calibration just try not to go so low that consecutive
// If you are trying to reduce the amount of time needed for calibration just try not to go so low that consecutive
// Existing comment from your code (kept): calibration calls give you completely unrelated data.  Some sensors are probably better than others.
// calibration calls give you completely unrelated data.  Some sensors are probably better than others.
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void testCalibration() {
// A single instruction; see the code line below for the exact action
  calibrateGyro();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int j = 0; j < 3; j++) {
// A single instruction; see the code line below for the exact action
    Serial.print(gyroZeroRate[j]);
// A single instruction; see the code line below for the exact action
    Serial.print("  ");
// A single instruction; see the code line below for the exact action
    Serial.print(gyroThreshold[j]);
// A single instruction; see the code line below for the exact action
    Serial.print("  ");
// End of the current code block
  }
// A single instruction; see the code line below for the exact action
  Serial.println();
// Return a value (or exit a function)
  return;
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): The settings here will suffice unless you want to use the interrupt feature.
// The settings here will suffice unless you want to use the interrupt feature.
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void setupGyro() {
// Code line performing logic or calling a function; see the next line for details
  gyroWriteI2C(CTRL_REG1, 0x1F);  // Turn on all axes, disable power down
// Code line performing logic or calling a function; see the next line for details
  gyroWriteI2C(CTRL_REG3, 0x08);  // Enable control ready signal
// A single instruction; see the code line below for the exact action
  setGyroSensitivity500();
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  delay(100);
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): Call this at start up.  It's critical that your device is completely stationary during calibration.
// Call this at start up.  It's critical that your device is completely stationary during calibration.
// Existing comment from your code (kept): The sensor needs recalibration after lots of movement, lots of idle time, temperature changes, etc, so try to work that in to your design.
// The sensor needs recalibration after lots of movement, lots of idle time, temperature changes, etc, so try to work that in to your design.
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void calibrateGyro() {
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  long int gyroSums[3] = { 0 };
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  long int gyroSigma[3] = { 0 };
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < NUM_GYRO_SAMPLES; i++) {
// A single instruction; see the code line below for the exact action
    updateGyroValues();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    for (int j = 0; j < 3; j++) {
// A single instruction; see the code line below for the exact action
      gyroSums[j] += gyroRaw[j];
// A single instruction; see the code line below for the exact action
      gyroSigma[j] += gyroRaw[j] * gyroRaw[j];
// End of the current code block
    }
// End of the current code block
  }
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int j = 0; j < 3; j++) {
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int averageRate = gyroSums[j] / NUM_GYRO_SAMPLES;
// (blank line to keep code readable)

// Existing comment from your code (kept): Per STM docs, we store the average of the samples for each axis and subtract them when we use the data.
    // Per STM docs, we store the average of the samples for each axis and subtract them when we use the data.
// A single instruction; see the code line below for the exact action
    gyroZeroRate[j] = averageRate;
// (blank line to keep code readable)

// Existing comment from your code (kept): Per STM docs, we create a threshold for each axis based on the standard deviation of the samples times 3.
    // Per STM docs, we create a threshold for each axis based on the standard deviation of the samples times 3.
// A single instruction; see the code line below for the exact action
    gyroThreshold[j] = sqrt((double(gyroSigma[j]) / NUM_GYRO_SAMPLES) - (averageRate * averageRate)) * GYRO_SIGMA_MULTIPLE;
// End of the current code block
  }
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void updateGyroValues() {
// (blank line to keep code readable)

// while-loop: repeat a block of code while the condition stays true
  while (!(gyroReadI2C(0x27) & B00001000)) {}  // Without this line you will get bad data occasionally
// (blank line to keep code readable)

// Existing comment from your code (kept): if (gyroReadI2C(0x27) & B01000000)
  //if (gyroReadI2C(0x27) & B01000000)
// Existing comment from your code (kept): Serial.println("Data missed!  Consider using an interrupt");
  //  Serial.println("Data missed!  Consider using an interrupt");
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int reg = 0x28;
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int j = 0; j < 3; j++) {
// A single instruction; see the code line below for the exact action
    gyroRaw[j] = (gyroReadI2C(reg) | (gyroReadI2C(reg + 1) << 8));
// A single instruction; see the code line below for the exact action
    reg += 2;
// End of the current code block
  }
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int deltaGyro[3];
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int j = 0; j < 3; j++) {
// Code line performing logic or calling a function; see the next line for details
    deltaGyro[j] = gyroRaw[j] - gyroZeroRate[j];  // Use the calibration data to modify the sensor value.
// Conditional: run the following block only if the condition is true
    if (abs(deltaGyro[j]) < gyroThreshold[j])
// A single instruction; see the code line below for the exact action
      deltaGyro[j] = 0;
// Code line performing logic or calling a function; see the next line for details
    gyroDPS[j] = dpsPerDigit * deltaGyro[j];  // Multiply the sensor value by the sensitivity factor to get degrees per second.
// End of the current code block
  }
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void setGyroSensitivity250(void) {
// A single instruction; see the code line below for the exact action
  dpsPerDigit = .00875f;
// Code line performing logic or calling a function; see the next line for details
  gyroWriteI2C(CTRL_REG4, 0x80);  // Set scale (250 deg/sec)
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void setGyroSensitivity500(void) {
// A single instruction; see the code line below for the exact action
  dpsPerDigit = .0175f;
// Code line performing logic or calling a function; see the next line for details
  gyroWriteI2C(CTRL_REG4, 0x90);  // Set scale (500 deg/sec)
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void setGyroSensitivity2000(void) {
// A single instruction; see the code line below for the exact action
  dpsPerDigit = .07f;
// A single instruction; see the code line below for the exact action
  gyroWriteI2C(CTRL_REG4, 0xA0);
// End of the current code block
}
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroReadI2C(byte regAddr) {
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.beginTransmission(gyroI2CAddr);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.write(regAddr);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.endTransmission();
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.requestFrom(gyroI2CAddr, 1);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  while (!Wire.available()) {};
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  return (Wire.read());
// End of the current code block
}
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int gyroWriteI2C(byte regAddr, byte val) {
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.beginTransmission(gyroI2CAddr);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.write(regAddr);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.write(val);
// Use I2C (Wire) functions to communicate with sensors/IMU over SDA/SCL
  Wire.endTransmission();
// End of the current code block
}
