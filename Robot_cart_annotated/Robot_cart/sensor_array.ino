/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments aim to clarify purpose without changing behavior.
 * Note: Some files contain "..." which indicates missing/omitted code in the provided project.
 * This annotation keeps your code compile-ready on Arduino Mega 2560.
 */

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void Initsensors() {
// Existing comment from your code (kept): Set analog pins as input (good practice even if not strictly needed on Mega)
  // Set analog pins as input (good practice even if not strictly needed on Mega)
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Set the mode of a pin: INPUT, INPUT_PULLUP, or OUTPUT so Arduino knows how to use it
    pinMode(sensorPins[i], INPUT);
// End of the current code block
  }
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): Calibration function
// Calibration function
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void calibrateSensors() {
// A single instruction; see the code line below for the exact action
  Serial.println("sensor_arry_calibration_start");
// (blank line to keep code readable)

// Existing comment from your code (kept): Initialize the minimum and maximum values
  // Initialize the minimum and maximum values
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Code line performing logic or calling a function; see the next line for details
    minimum[i] = 1023;  // Set initial min value as max possible
// Code line performing logic or calling a function; see the next line for details
    maximum[i] = 0;     // Set initial max value as min possible
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): Take multiple readings for calibration
  // Take multiple readings for calibration
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (uint16_t i = 0; i < 400; i++) {
// Existing comment from your code (kept): Read sensor values
    // Read sensor values
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    for (int j = 0; j < SensorCount; j++) {
// A single instruction; see the code line below for the exact action
      rawValues[j] = analogRead(sensorPins[j]);
// Code line performing logic or calling a function; see the next line for details
      minimum[j] = min(minimum[j], rawValues[j]);  // Update minimum value
// Code line performing logic or calling a function; see the next line for details
      maximum[j] = max(maximum[j], rawValues[j]);  // Update maximum value
// End of the current code block
    }
// Code line performing logic or calling a function; see the next line for details
    delay(40);  // Small delay between readings
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): Store the calibrated values in EEPROM
  // Store the calibrated values in EEPROM
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Access EEPROM (non-volatile memory) to store or load settings that persist after power-off
    EEPROM.write(i, (minimum[i] / 2));      // Store minimum value
// Access EEPROM (non-volatile memory) to store or load settings that persist after power-off
    EEPROM.write(i + 8, (maximum[i] / 4));  // Store maximum value
// End of the current code block
  }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  Serial.println("sensor_arry_calibration_done");
// (blank line to keep code readable)

// Existing comment from your code (kept): Beep to indicate completion
  // Beep to indicate completion
// A single instruction; see the code line below for the exact action
  beep_buzzer(3);
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): ---------- Load from EEPROM ----------
// ---------- Load from EEPROM ----------
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void sensors_Load() {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Access EEPROM (non-volatile memory) to store or load settings that persist after power-off
    minimum[i] = 2 * EEPROM.read(i);
// Access EEPROM (non-volatile memory) to store or load settings that persist after power-off
    maximum[i] = 4 * EEPROM.read(i + 8);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    Serial.print("Min: ");
// A single instruction; see the code line below for the exact action
    Serial.print(minimum[i]);
// A single instruction; see the code line below for the exact action
    Serial.print("  Max: ");
// A single instruction; see the code line below for the exact action
    Serial.println(maximum[i]);
// End of the current code block
  }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  beep_buzzer(2);
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): ---------- Read Sensor Values ----------
// ---------- Read Sensor Values ----------
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void readSensors() {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// A single instruction; see the code line below for the exact action
    rawValues[i] = analogRead(sensorPins[i]);
// End of the current code block
  }
// End of the current code block
}
// (blank line to keep code readable)

// Existing comment from your code (kept): ---------- Calculate Position ----------
// ---------- Calculate Position ----------
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int calculatePosition() {
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  long weightedSum = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  long totalWeight = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int threshold = 850;  // Threshold to detect the white line
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int sensorValue = rawValues[i];    // Use raw sensor readings
// Conditional: run the following block only if the condition is true
    if (sensorValue < threshold) {     // Only consider sensors below the threshold (white)
// Code line performing logic or calling a function; see the next line for details
      weightedSum += i * sensorValue;  // Weighted sum of sensor values
// Code line performing logic or calling a function; see the next line for details
      totalWeight += sensorValue;      // Total weight (sum of sensor values)
// End of the current code block
    }
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): Avoid division by zero if no sensors detect the line
  // Avoid division by zero if no sensors detect the line
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  if (totalWeight == 0) {
// Return a value (or exit a function)
    return -1;  // Return an error code (or center position) if no line is detected
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): Calculate the position based on the weighted sum of the sensor readings
  // Calculate the position based on the weighted sum of the sensor readings
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int position = weightedSum / totalWeight;
// (blank line to keep code readable)

// Return a value (or exit a function)
  return position;
// End of the current code block
}
// Existing comment from your code (kept): void get_sensor_values() {
// void get_sensor_values() {
// Existing comment from your code (kept): for (int i = 0; i < SensorCount; i++) {
//   for (int i = 0; i < SensorCount; i++) {
// Existing comment from your code (kept): int raw = analogRead(sensorPins[i]);  // Read analog value
//     int raw = analogRead(sensorPins[i]);  // Read analog value
// (blank line to keep code readable)

// Existing comment from your code (kept): // Print the sensor index and its raw value
//     // Print the sensor index and its raw value
// Existing comment from your code (kept): Serial.print("S");
//     Serial.print("S");
// Existing comment from your code (kept): Serial.print(i);
//     Serial.print(i);
// Existing comment from your code (kept): Serial.print(": ");
//     Serial.print(": ");
// Existing comment from your code (kept): Serial.print(raw);
//     Serial.print(raw);
// Existing comment from your code (kept): Serial.print("  ");
//     Serial.print("  ");
// Existing comment from your code (kept): }
//   }
// Existing comment from your code (kept): Serial.println();  // Move to next line after all sensors are printed
//   Serial.println();  // Move to next line after all sensors are printed
// Existing comment from your code (kept): }
// }
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int sensorValues[8];      // Raw values
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
int binarySensorVals[8];  // 0 or 1 (black or white)
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void get_sensor_values() {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < SensorCount; i++) {
// Code line performing logic or calling a function; see the next line for details
    sensorValues[i] = analogRead(sensorPins[i]);  // Raw analog value
// (blank line to keep code readable)

// Existing comment from your code (kept): Binary decision
    // Binary decision
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (sensorValues[i] > blackWhiteThreshold ) {
// Code line performing logic or calling a function; see the next line for details
      digiSensorVals[i] = 1;  // White surface
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    } else {
// Code line performing logic or calling a function; see the next line for details
     digiSensorVals[i] = 0;  // Black line
// End of the current code block
    }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    Serial.print("S");
// A single instruction; see the code line below for the exact action
    Serial.print(i);
// A single instruction; see the code line below for the exact action
    Serial.print(": ");
// A single instruction; see the code line below for the exact action
    Serial.print(sensorValues[i]);
// A single instruction; see the code line below for the exact action
    Serial.print(" (");
// A single instruction; see the code line below for the exact action
    Serial.print(digiSensorVals[i]);
// A single instruction; see the code line below for the exact action
    Serial.print(")  ");
// End of the current code block
  }
// A single instruction; see the code line below for the exact action
  Serial.println();
// End of the current code block
}
