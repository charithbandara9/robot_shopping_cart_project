/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments aim to clarify purpose without changing behavior.
 * Note: Some files contain "..." which indicates missing/omitted code in the provided project.
 * This annotation keeps your code compile-ready on Arduino Mega 2560.
 */

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void beep_buzzer(int beep_time) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  for (int i = 0; i < beep_time; i++) {
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
    digitalWrite(beep, HIGH);
// A single instruction; see the code line below for the exact action
    delay(1000);
// Write HIGH (5V) or LOW (0V) to a digital output pin to turn devices ON/OFF
    digitalWrite(beep, LOW);
// A single instruction; see the code line below for the exact action
    delay(1000);
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void left_motor_enc_count() {
// A single instruction; see the code line below for the exact action
  LMEnCount++;
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void right_motor_enc_count() {
// A single instruction; see the code line below for the exact action
  RMEnCount++;
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void line_fallow() {
// Code line performing logic or calling a function; see the next line for details
  readSensors();  // Read the sensor values
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int position = calculatePosition();  // Calculate the position of the line
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minspeed = 50;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxspeed = 70;   //100;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int BaseSpeed = 60;  //80;
// Existing comment from your code (kept): Apply PID control to adjust motor speed
  // Apply PID control to adjust motor speed
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float error = (desiredPosition - position);
// A single instruction; see the code line below for the exact action
  integral += error;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float derivative = error - previousError;
// A single instruction; see the code line below for the exact action
  output = Kp * error + Ki * integral + Kd * derivative;
// A single instruction; see the code line below for the exact action
  previousError = error;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int rightMotorSpeed = constrain((BaseSpeed - output), minspeed, maxspeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int leftMotorSpeed = constrain((BaseSpeed + output), minspeed, maxspeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  motor(leftMotorSpeed, rightMotorSpeed);
// Existing comment from your code (kept): Control motor speeds based on PID output
  // Control motor speeds based on PID output
// (blank line to keep code readable)

// (blank line to keep code readable)

// Existing comment from your code (kept): Serial.print("Position: ");
  // Serial.print("Position: ");
// Existing comment from your code (kept): Serial.println(position);
  // Serial.println(position);
// Existing comment from your code (kept): Serial.print("PID Output: ");
  // Serial.print("PID Output: ");
// Existing comment from your code (kept): Serial.println(output);
  // Serial.println(output);
// Existing comment from your code (kept): Serial.print(leftMotorSpeed);
  // Serial.print(leftMotorSpeed);
// Existing comment from your code (kept): Serial.print("\t");
  // Serial.print("\t");
// Existing comment from your code (kept): Serial.println(rightMotorSpeed);
  // Serial.println(rightMotorSpeed);
// Existing comment from your code (kept): delay(100);
  // delay(100);
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void line_fallow_with_gyro() {
// Code line performing logic or calling a function; see the next line for details
  readSensors();  // Read the sensor values
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int position = calculatePosition();  // Calculate the position of the line
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minspeed = 60;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxspeed = 80;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int BaseSpeed = 70;
// (blank line to keep code readable)

// Existing comment from your code (kept): PID Control for Line
  // PID Control for Line
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float error = (desiredPosition - position);
// A single instruction; see the code line below for the exact action
  integral += error;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float derivative = error - previousError;
// A single instruction; see the code line below for the exact action
  output = Kp * error + Ki * integral + Kd * derivative;
// A single instruction; see the code line below for the exact action
  previousError = error;
// (blank line to keep code readable)

// Existing comment from your code (kept): ---------- Gyroscope correction ----------
  // ---------- Gyroscope correction ----------
// Code line performing logic or calling a function; see the next line for details
  updateGyroValues();  // Get raw gyro data
// Code line performing logic or calling a function; see the next line for details
  updateHeadings();    // Update heading[2] (yaw)
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float gyroError = heading[2];  // Assuming heading[2] = yaw angle
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float gyroGain = 1.5;          // You can tune this gain
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float gyroCorrection = gyroError * gyroGain;
// (blank line to keep code readable)

// Existing comment from your code (kept): Add gyro correction to output
  // Add gyro correction to output
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float totalOutput = output + gyroCorrection;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int rightMotorSpeed = constrain((BaseSpeed - totalOutput), minspeed, maxspeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int leftMotorSpeed = constrain((BaseSpeed + totalOutput), minspeed, maxspeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  motor(leftMotorSpeed, rightMotorSpeed);
// End of the current code block
}
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
void motor(int mL, int mR) {  //motor power range control
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  if (mL > 0) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (mL > 255) {
// A single instruction; see the code line below for the exact action
      mL = 255;
// End of the current code block
    }
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(LFPWM, mL);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(LBPWM, 0);
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  } else {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (mL < -255) {
// A single instruction; see the code line below for the exact action
      mL = -255;
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    mL = mL * -1;
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(LFPWM, 0);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(LBPWM, mL);
// End of the current code block
  }
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  if (mR > 0) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (mR > 255) {
// A single instruction; see the code line below for the exact action
      mR = 255;
// End of the current code block
    }
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(RFPWM, mR);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(RBPWM, 0);
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  } else {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (mR < -255) {
// A single instruction; see the code line below for the exact action
      mR = -255;
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    mR = mR * -1;
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(RFPWM, 0);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
    analogWrite(RBPWM, mR);
// End of the current code block
  }
// End of the current code block
}
// (blank line to keep code readable)

// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void enturnL() {
// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 70;  //40;//45
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int midSpeed = 80;  //50;//55
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 90;  //60;//65
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kp = 0.8;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kd = 0;
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  previousError = 0;
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  do {
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Conditional: run the following block only if the condition is true
    if (digiSensorVals[0] == 1 && digiSensorVals[3] == 1) {  //wait to line
// A single instruction; see the code line below for the exact action
      break_motor(500);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    enError = RMEnCount - LMEnCount;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
// A single instruction; see the code line below for the exact action
    previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    Left(rightMotorSpeed, leftMotorSpeed);  //change
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  } while (1);
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void enturnR() {
// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 70;  //40;//45
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int midSpeed = 80;  //50;//55
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 90;  //60;//65
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kp = 0.8;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kd = 0;
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  previousError = 0;
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  do {
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Conditional: run the following block only if the condition is true
    if (digiSensorVals[7] == 1 && digiSensorVals[4] == 1) {  //wait to line                    //&&  digiSensorVals[4] == 1
// A single instruction; see the code line below for the exact action
      break_motor(500);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    enError = RMEnCount - LMEnCount;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
// A single instruction; see the code line below for the exact action
    previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    Right(rightMotorSpeed, leftMotorSpeed);  //change
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  } while (1);
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void find_L() {
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// A single instruction; see the code line below for the exact action
    line_fallow();
// Existing comment from your code (kept): line_fallow_with_gyro();
    // line_fallow_with_gyro();
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[0] == 1 && digiSensorVals[1] == 1) {
// A single instruction; see the code line below for the exact action
      on_to_line(130);
// Code line performing logic or calling a function; see the next line for details
      Turn_angle(-45);  //pre turn
// A single instruction; see the code line below for the exact action
      enturnL_with_gyro();
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void find_R() {
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// A single instruction; see the code line below for the exact action
    line_fallow();
// Existing comment from your code (kept): line_fallow_with_gyro();
    // line_fallow_with_gyro();
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[4] == 1 && digiSensorVals[7] == 1) {
// A single instruction; see the code line below for the exact action
      on_to_line(130);
// Code line performing logic or calling a function; see the next line for details
      Turn_angle(45);  //
// A single instruction; see the code line below for the exact action
      enturnR_with_gyro();
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Code line performing logic or calling a function; see the next line for details
void go_to_t() {  //find to T junction
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// A single instruction; see the code line below for the exact action
    line_fallow();
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[0] == 1 && digiSensorVals[1] == 1 && digiSensorVals[6] == 1 && digiSensorVals[7] == 1) {
// Existing comment from your code (kept): break_motor(500);
      //break_motor(500);
// A single instruction; see the code line below for the exact action
      on_to_line(20);
// A single instruction; see the code line below for the exact action
      break_motor(500);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void skip_L() {
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// A single instruction; see the code line below for the exact action
    line_fallow();
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[0] == 1 && digiSensorVals[1] == 1) {
// (blank line to keep code readable)

// Existing comment from your code (kept): break_motor(500);
      //break_motor(500);
// A single instruction; see the code line below for the exact action
      on_to_line(200);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void skip_R() {
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// A single instruction; see the code line below for the exact action
    line_fallow();
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[6] == 1 && digiSensorVals[7] == 1) {
// (blank line to keep code readable)

// Existing comment from your code (kept): break_motor(500);
      //break_motor(500);
// A single instruction; see the code line below for the exact action
      on_to_line(200);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void on_to_line(int totalCount) {
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
    while (RMEnCount < totalCount || LMEnCount < totalCount) {
// A single instruction; see the code line below for the exact action
      line_fallow();
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    break_motor(50);
// A single instruction; see the code line below for the exact action
    break;
// End of the current code block
  }
// End of the current code block
}
// Code line performing logic or calling a function; see the next line for details
void Left(int rms, int lms) {  //minspeed
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LFPWM, 0);       // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LBPWM, lms);
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RFPWM, rms);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RBPWM, 0);
// End of the current code block
}
// Code line performing logic or calling a function; see the next line for details
void Right(int rms, int lms) {  //minspeed
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LFPWM, lms);      // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LBPWM, 0);
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RFPWM, 0);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RBPWM, rms);
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void break_motor(int dly) {
// Existing comment from your code (kept): Stop
  // Stop
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LFPWM, 0);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(LBPWM, 0);
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RFPWM, 0);  // PWM between 0-255
// Output PWM signal to a pin (0–255 duty cycle) for speed/brightness control
  analogWrite(RBPWM, 0);
// A single instruction; see the code line below for the exact action
  delay(dly);
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void gyroTurnAngle(int angle) {
// A single instruction; see the code line below for the exact action
  break_motor(20);
// A single instruction; see the code line below for the exact action
  updateGyroValues();
// A single instruction; see the code line below for the exact action
  updateHeadings();
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 50;  //initial values
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 80;
// A single instruction; see the code line below for the exact action
  Kp = 5;
// A single instruction; see the code line below for the exact action
  Kd = 25;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float error, controlSpeed;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int lastError;
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  switch (angle) {
// Code line performing logic or calling a function; see the next line for details
    case -90:
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
      while (1) {
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        error = heading[2] + 90;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
        int controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        Left(controlSpeed, controlSpeed);
// A single instruction; see the code line below for the exact action
        lastError = error;
// A single instruction; see the code line below for the exact action
        updateGyroValues();
// A single instruction; see the code line below for the exact action
        updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
        if (heading[2] <= -82) break;
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// A single instruction; see the code line below for the exact action
      updateGyroValues();
// A single instruction; see the code line below for the exact action
      updateHeadings();
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
      if (heading[2] < -90 || heading[2] > -90) {
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
        for (int i = 0; i < 100; i++) {
// A single instruction; see the code line below for the exact action
          error = abs(heading[2] + 90);
// A single instruction; see the code line below for the exact action
          controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] < -90) Right(controlSpeed, controlSpeed);
// Additional condition checked if previous if/else-if was false
          else if (heading[2] > -90) Left(controlSpeed, controlSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          lastError = error;
// A single instruction; see the code line below for the exact action
          updateGyroValues();
// A single instruction; see the code line below for the exact action
          updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] >= -90.5 && heading[2] <= 89.5) break;
// End of the current code block
        }
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// A single instruction; see the code line below for the exact action
      break;
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    case 90:
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
      while (1) {
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        error = 90 - heading[2];
// A single instruction; see the code line below for the exact action
        controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        Right(controlSpeed, controlSpeed);
// A single instruction; see the code line below for the exact action
        lastError = error;
// A single instruction; see the code line below for the exact action
        updateGyroValues();
// A single instruction; see the code line below for the exact action
        updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
        if (heading[2] >= 82) break;
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// Existing comment from your code (kept): Kp = 30;
      //      Kp = 30;
// Existing comment from your code (kept): Kd = 100;
      //      Kd = 100;
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
      if (heading[2] > 90 || heading[2] < 90) {
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
        for (int i = 0; i < 100; i++) {
// A single instruction; see the code line below for the exact action
          error = abs(heading[2] - 90);
// A single instruction; see the code line below for the exact action
          controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] > 90) Left(controlSpeed, controlSpeed);
// Additional condition checked if previous if/else-if was false
          else if (heading[2] < 90) Right(controlSpeed, controlSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          lastError = error;
// A single instruction; see the code line below for the exact action
          updateGyroValues();
// A single instruction; see the code line below for the exact action
          updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] <= 90.5 && heading[2] >= 89.5) break;
// End of the current code block
        }
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// A single instruction; see the code line below for the exact action
      break;
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    case 180:
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
      while (1) {
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        error = 180 - heading[2];
// A single instruction; see the code line below for the exact action
        controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
        Right(controlSpeed, controlSpeed);
// A single instruction; see the code line below for the exact action
        lastError = error;
// A single instruction; see the code line below for the exact action
        updateGyroValues();
// A single instruction; see the code line below for the exact action
        updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
        if (heading[2] >= 170) break;
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
      if (heading[2] > 180 || heading[2] < 180) {
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
        for (int i = 0; i < 100; i++) {
// A single instruction; see the code line below for the exact action
          error = abs(heading[2] - 180);
// A single instruction; see the code line below for the exact action
          controlSpeed = Kp * error + Kd * (error - lastError);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          controlSpeed = constrain(controlSpeed, minSpeed, maxSpeed);
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] > 180) Left(controlSpeed, controlSpeed);
// Additional condition checked if previous if/else-if was false
          else if (heading[2] < 180) Right(controlSpeed, controlSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
          lastError = error;
// A single instruction; see the code line below for the exact action
          updateGyroValues();
// A single instruction; see the code line below for the exact action
          updateHeadings();
// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
          if (heading[2] <= 90.5 && heading[2] >= 89.5) break;
// End of the current code block
        }
// End of the current code block
      }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      break_motor(3);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
  }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  setupGyro();
// A single instruction; see the code line below for the exact action
  calibrateGyro();
// A single instruction; see the code line below for the exact action
  heading[2] = 0;
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void enturnR_with_gyro() {
// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 60;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int midSpeed = 70;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 80;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kp = 0.8;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kd = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float g_Kp = 2.0;  // Gain for gyro correction (adjust as needed)
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  previousError = 0;
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  do {
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[4] == 1 && digiSensorVals[3] == 1) {
// A single instruction; see the code line below for the exact action
      break_motor(500);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// (blank line to keep code readable)

// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    updateGyroValues();  // Update gyro raw values
// Code line performing logic or calling a function; see the next line for details
    updateHeadings();    // Update yaw (heading[2])
// (blank line to keep code readable)

// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    enError = RMEnCount - LMEnCount;  // Encoder diff
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float gyroError = heading[2];     // Assuming heading[2] starts from 0 and accumulates during turn
// (blank line to keep code readable)

// Existing comment from your code (kept): Combine encoder + gyro error
    // Combine encoder + gyro error
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float totalError = enError * t_Kp + gyroError * g_Kp;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float derivative = (enError - previousError) * t_Kd;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int motorSpeed = totalError + derivative;
// A single instruction; see the code line below for the exact action
    previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    Right(rightMotorSpeed, leftMotorSpeed);  // Turn right function
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  } while (1);
// A single instruction; see the code line below for the exact action
  setupGyro();
// A single instruction; see the code line below for the exact action
  calibrateGyro();
// A single instruction; see the code line below for the exact action
  heading[2] = 0;
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void enturnL_with_gyro() {
// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 60;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int midSpeed = 70;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 80;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kp = 0.8;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kd = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float g_Kp = 2.0;  // Gyroscope correction gain
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  previousError = 0;
// (blank line to keep code readable)

// Existing comment from your code (kept): Optional: Save start heading angle
  // Optional: Save start heading angle
// Existing comment from your code (kept): float startAngle = heading[2];
  //float startAngle = heading[2];
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  do {
// A single instruction; see the code line below for the exact action
    get_sensor_values();
// (blank line to keep code readable)

// Existing comment from your code (kept): Exit condition: line detected by left sensors
    // Exit condition: line detected by left sensors
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (digiSensorVals[1] == 1 && digiSensorVals[2] == 1) {
// A single instruction; see the code line below for the exact action
      break_motor(500);
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    updateGyroValues();  // Update gyro raw values
// Code line performing logic or calling a function; see the next line for details
    updateHeadings();    // Update yaw (heading[2])
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    enError = RMEnCount - LMEnCount;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float gyroError = heading[2];  // For left turn, heading usually goes negative
// (blank line to keep code readable)

// Existing comment from your code (kept): Combine encoder + gyro errors
    // Combine encoder + gyro errors
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float totalError = enError * t_Kp + gyroError * g_Kp;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float derivative = (enError - previousError) * t_Kd;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int motorSpeed = totalError + derivative;
// A single instruction; see the code line below for the exact action
    previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int rightMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int leftMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    Left(rightMotorSpeed, leftMotorSpeed);  // Left turning function
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  } while (1);
// A single instruction; see the code line below for the exact action
  setupGyro();
// A single instruction; see the code line below for the exact action
  calibrateGyro();
// A single instruction; see the code line below for the exact action
  heading[2] = 0;
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void align_With_Gyro() {
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float targetAngle = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float error = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float previousError = 0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float gyro_Kp = 3.0;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float gyro_Kd = 0.5;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int baseTurn = 0;
// (blank line to keep code readable)

// for-loop: repeat a block of code a specific number of times/over a range
  for (int i = 0; i < 100; i++) {  // limit loop to avoid getting stuck
// A single instruction; see the code line below for the exact action
    updateGyroValues();
// A single instruction; see the code line below for the exact action
    updateHeadings();
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    error = heading[2] - targetAngle;
// (blank line to keep code readable)

// Existing comment from your code (kept): Normalize angle to [-180, 180]
    // Normalize angle to [-180, 180]
// Conditional: run the following block only if the condition is true
    if (error > 180) error -= 360;
// Conditional: run the following block only if the condition is true
    if (error < -180) error += 360;
// (blank line to keep code readable)

// Existing comment from your code (kept): Stop condition
    // Stop condition
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (abs(error) < 0.5) {
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
    }
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    float derivative = error - previousError;
// A single instruction; see the code line below for the exact action
    previousError = error;
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    baseTurn = gyro_Kp * error + gyro_Kd * derivative;
// Code line performing logic or calling a function; see the next line for details
    baseTurn = constrain(baseTurn, -70, 70);  // slower speed for precision
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int leftSpeed = constrain(-baseTurn, -70, 70);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
    int rightSpeed = constrain(baseTurn, -70, 70);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
    motor(leftSpeed, rightSpeed);  // turn robot in place
// Code line performing logic or calling a function; see the next line for details
    delay(20);                     // short delay for stability
// End of the current code block
  }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  break_motor(500);
// A single instruction; see the code line below for the exact action
  setupGyro();
// A single instruction; see the code line below for the exact action
  calibrateGyro();
// A single instruction; see the code line below for the exact action
  heading[2] = 0;
// End of the current code block
}
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
void communicate() {
// Infinite loop: keeps the robot running this block forever (common in embedded systems)
  while (1) {
// Existing comment from your code (kept): Send data from Serial Monitor to ESP01
    // Send data from Serial Monitor to ESP01
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (Serial.available()) {
// A single instruction; see the code line below for the exact action
      String input = Serial.readStringUntil('\n');
// A single instruction; see the code line below for the exact action
      input.trim();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
      if (input.length() > 0) {
// Code line performing logic or calling a function; see the next line for details
        mySerial.println(input);  // Send to ESP01
// A single instruction; see the code line below for the exact action
        Serial.println(">> Sent to ESP01: " + input);
// End of the current code block
      }
// End of the current code block
    }
// (blank line to keep code readable)

// Existing comment from your code (kept): Receive data from ESP01
    // Receive data from ESP01
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (mySerial.available()) {
// A single instruction; see the code line below for the exact action
      String received = mySerial.readStringUntil('\n');
// A single instruction; see the code line below for the exact action
      received.trim();
// Begin a code block (the following lines belong to this function/loop/if until the matching })
      if (received.length() > 0) {
// (blank line to keep code readable)

// Existing comment from your code (kept): Find the last space
        // Find the last space
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
        int lastSpace = received.lastIndexOf(' ');
// (blank line to keep code readable)

// Existing comment from your code (kept): Extract everything after the last space
        // Extract everything after the last space
// A single instruction; see the code line below for the exact action
        String lastNumber = received.substring(lastSpace + 1);
// (blank line to keep code readable)

// Existing comment from your code (kept): Serial.println(lastNumber);  // Output: 1
        //Serial.println(lastNumber);  // Output: 1
// A single instruction; see the code line below for the exact action
        store_location = lastNumber.toInt();
// A single instruction; see the code line below for the exact action
        Serial.println(store_location);
// End of the current code block
      }
// End of the current code block
    }
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    if (robot_status == 0) {
// Conditional: run the following block only if the condition is true
      if (store_location == 1 || store_location == 2 || store_location == 3 || store_location == 4) { break; }
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    } else if (robot_status == 1) {
// Conditional: run the following block only if the condition is true
      if (store_location == 5) { break; }
// End of the current code block
    }
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void path_find_1(int location) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  switch (location) {
// Code line performing logic or calling a function; see the next line for details
    case 1:
// A single instruction; see the code line below for the exact action
      skip_L();
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      beep_buzzer(2);
// A single instruction; see the code line below for the exact action
      break;
// Code line performing logic or calling a function; see the next line for details
    case 2:
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      skip_L();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      beep_buzzer(5);
// A single instruction; see the code line below for the exact action
      break;
// Code line performing logic or calling a function; see the next line for details
    case 3:
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      skip_R();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      beep_buzzer(5);
// A single instruction; see the code line below for the exact action
      break;
// Code line performing logic or calling a function; see the next line for details
    case 4:
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      beep_buzzer(5);
// A single instruction; see the code line below for the exact action
      break;
// Code line performing logic or calling a function; see the next line for details
    case 5:
// A single instruction; see the code line below for the exact action
      enturnL_with_gyro();
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
  }
// End of the current code block
}
// Begin a code block (the following lines belong to this function/loop/if until the matching })
void path_find_2(int location) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
  switch (location) {
// Code line performing logic or calling a function; see the next line for details
    case 5:
// A single instruction; see the code line below for the exact action
      Turn_angle(-180);
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      find_L();
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      break;
// Code line performing logic or calling a function; see the next line for details
    case 6:
// A single instruction; see the code line below for the exact action
      Turn_angle(-180);
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      find_R();
// A single instruction; see the code line below for the exact action
      go_to_t();
// A single instruction; see the code line below for the exact action
      break;
// End of the current code block
  }
// End of the current code block
}
// Code line performing logic or calling a function; see the next line for details
void Turn_angle(int angle) {  //45 clockwise //-45 antie
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int counts;
// Existing comment from your code (kept): if (angle == -45) angle = 45;
  // if (angle == -45) angle = 45;
// Conditional: run the following block only if the condition is true
  if (abs(angle) == 45) counts = counts_45;  // -45
// Additional condition checked if previous if/else-if was false
  else if (abs(angle) == 180) counts = counts_180;
// (blank line to keep code readable)

// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  RMEnCount = 0;
// A single instruction; see the code line below for the exact action
  LMEnCount = 0;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int minSpeed = 60;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int midSpeed = 70;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  int maxSpeed = 80;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kp = 0.8;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
  float t_Kd = 0;
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
  previousError = 0;
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  if (angle > 0) {
// Begin a code block (the following lines belong to this function/loop/if until the matching })
    while ((RMEnCount + LMEnCount) / 2 < counts) {
// A single instruction; see the code line below for the exact action
      enError = RMEnCount - LMEnCount;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
// A single instruction; see the code line below for the exact action
      previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// Code line performing logic or calling a function; see the next line for details
      Right(rightMotorSpeed, leftMotorSpeed);  //change
// End of the current code block
    }
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
    break_motor(20);
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
  } else if (angle < 0) {
// (blank line to keep code readable)

// Begin a code block (the following lines belong to this function/loop/if until the matching })
    while ((RMEnCount + LMEnCount) / 2 < counts) {
// A single instruction; see the code line below for the exact action
      enError = RMEnCount - LMEnCount;
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int motorSpeed = enError * t_Kp + (enError - previousError) * t_Kd;
// A single instruction; see the code line below for the exact action
      previousError = enError;
// (blank line to keep code readable)

// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int rightMotorSpeed = constrain((midSpeed - motorSpeed), minSpeed, maxSpeed);
// Declare a variable that stores data used by the program (type + name, optionally with an initial value)
      int leftMotorSpeed = constrain((midSpeed + motorSpeed), minSpeed, maxSpeed);
// (blank line to keep code readable)

// A single instruction; see the code line below for the exact action
      Left(rightMotorSpeed, leftMotorSpeed);
// (blank line to keep code readable)

// (blank line to keep code readable)

// Conditional: run the following block only if the condition is true
      if ((RMEnCount + LMEnCount) / 2 > counts) {  //countRange
// A single instruction; see the code line below for the exact action
        break;
// End of the current code block
      }
// End of the current code block
    }
// A single instruction; see the code line below for the exact action
    break_motor(20);
// End of the current code block
  }
// End of the current code block
}
