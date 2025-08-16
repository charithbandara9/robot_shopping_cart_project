/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments explain purpose without changing behavior.
 * Board target: Arduino Mega 2560.
 */

// Start of a code block (function/if/loop)
void beep_buzzer(int beep_count, int beep_time) {
// Start of a code block (function/if/loop)
  for (int i = 0; i < beep_count; i++) {
// Set a digital output HIGH (5V) or LOW (0V)
    digitalWrite(beep, HIGH);
// Single instruction; see the actual code line for its effect
    delay(beep_time);
// Set a digital output HIGH (5V) or LOW (0V)
    digitalWrite(beep, LOW);
// Single instruction; see the actual code line for its effect
    delay(beep_time);
// End of the current code block
  }
// End of the current code block
}
// Start of a code block (function/if/loop)
void draw() {
// Single instruction; see the actual code line for its effect
  u8g2.drawFrame(0, 0, 128, 31);
// Single instruction; see the actual code line for its effect
  u8g2.drawFrame(0, 33, 128, 31);
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
  u8g2.drawStr(15, 13, "Temperature");
// Single instruction; see the actual code line for its effect
  u8g2.drawUTF8(76, 28, "C");
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
  u8g2.drawStr(30, 46, "Humidity");
// End of the current code block
}
// Existing comment from your code (kept): Interrupt function (called when button is pressed)
// Interrupt function (called when button is pressed)
// Start of a code block (function/if/loop)
void IRAM_ATTR requestRefresh() {
// Single instruction; see the actual code line for its effect
  refreshRequested = true;
// End of the current code block
}
// Start of a code block (function/if/loop)
void IRAM_ATTR button1() {
// Single instruction; see the actual code line for its effect
  M_button_1 = true;
// End of the current code block
}
// Start of a code block (function/if/loop)
void IRAM_ATTR button2() {
// Single instruction; see the actual code line for its effect
  M_button_2 = true;
// End of the current code block
}
// Start of a code block (function/if/loop)
void IRAM_ATTR button3() {
// Single instruction; see the actual code line for its effect
  M_button_3 = true;
// End of the current code block
}
// Start of a code block (function/if/loop)
void progress_screen() {
// Start of a code block (function/if/loop)
  for (int progress = 0; progress < 56; progress++) {
// Existing comment from your code (kept): u8g2.clearBuffer();
    //u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Existing comment from your code (kept): u8g2.drawXBMP(-1, 0, 64, 64, cart_image_bits);
      // u8g2.drawXBMP(-1, 0, 64, 64, cart_image_bits);
// Existing comment from your code (kept): Draw the progress bar frame
      // Draw the progress bar frame
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(68, 39, 56, 8);
// (blank line to keep code readable)

// Existing comment from your code (kept): Draw the filling box (loading progress)
      // Draw the filling box (loading progress)
// Code line calling a function or doing logic
      u8g2.drawBox(68 + 1, 39 + 1, progress, 6);  // 6 height to fit inside the frame
// (blank line to keep code readable)

// (blank line to keep code readable)

// Existing comment from your code (kept): Draw the text above the progress bar
      // Draw the text above the progress bar
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_4x6_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(67, 37, "system loading");
// Single instruction; see the actual code line for its effect
      delay(40);
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// (blank line to keep code readable)

// Code line calling a function or doing logic
    delay(70);  // Slow down the animation
// Single instruction; see the actual code line for its effect
    beep_buzzer(1, 70);
// End of the current code block
  }
// Single instruction; see the actual code line for its effect
  beep_buzzer(10, 70);
// Code line calling a function or doing logic
  delay(2000);  // Wait 2 seconds after full loading
// End of the current code block
}
// Existing comment from your code (kept): Reset the display by toggling the reset pin and re-initializing
// Reset the display by toggling the reset pin and re-initializing
// Start of a code block (function/if/loop)
void resetDisplay() {
// Set a digital output HIGH (5V) or LOW (0V)
  digitalWrite(4, LOW);   // Set the reset pin low to reset the display
// Code line calling a function or doing logic
  delay(100);             // Wait for a brief moment to allow reset
// Set a digital output HIGH (5V) or LOW (0V)
  digitalWrite(4, HIGH);  // Set the reset pin high to release reset
// Code line calling a function or doing logic
  u8g2.begin();           // Re-initialize the display after reset
// End of the current code block
}
// Start of a code block (function/if/loop)
void battery_read() {
// (blank line to keep code readable)

// Infinite loop: keeps running this block forever
  while (1) {
// Declare a variable (type + name, optional initial value)
    unsigned long batt_currentMillis = (millis() / 1000);
// Existing comment from your code (kept): update values
    //update values
// Single instruction; see the actual code line for its effect
    raw_adc = analogRead(BATTERY_PIN);
// Single instruction; see the actual code line for its effect
    v_adc = (raw_adc * ADC_REF_VOLTAGE) / ADC_RESOLUTION;
// Code line calling a function or doing logic
    battery_voltage = ((v_adc * VOLTAGE_DIVIDER_RATIO) / 8.2) * 100;  //calculation of battery percentage
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
    if (batt_previousMillis >= batt_cal_time) {
// Single instruction; see the actual code line for its effect
      beep_buzzer(10, 70);
// Existing comment from your code (kept): Serial.println(battery_voltage, 2);
      //Serial.println(battery_voltage, 2);
// Single instruction; see the actual code line for its effect
      break;
// End of the current code block
    }
// Existing comment from your code (kept): Serial.print("ADC Raw: ");
    // Serial.print("ADC Raw: ");
// Existing comment from your code (kept): Serial.print(raw_adc);
    // Serial.print(raw_adc);
// Existing comment from your code (kept): Serial.print(" | ADC Voltage: ");
    // Serial.print(" | ADC Voltage: ");
// Existing comment from your code (kept): Serial.print(v_adc, 2);
    // Serial.print(v_adc, 2);
// Existing comment from your code (kept): Serial.print("V | Battery Voltage: ");
    // Serial.print("V | Battery Voltage: ");
// Existing comment from your code (kept): Serial.println(battery_voltage, 2);
    //  Serial.println(battery_voltage, 2);
// Existing comment from your code (kept): Serial.println("V");
    // Serial.println("V");
// Single instruction; see the actual code line for its effect
    batt_previousMillis = batt_currentMillis;
// End of the current code block
  }
// End of the current code block
}
// Start of a code block (function/if/loop)
void display_refresh() {
// Existing comment from your code (kept): Check if refresh was requested
  // Check if refresh was requested
// Start of a code block (function/if/loop)
  if (refreshRequested) {
// Single instruction; see the actual code line for its effect
    refreshRequested = false;
// Existing comment from your code (kept): Try connecting to Python script
    // Try connecting to Python script
// Start of a code block (function/if/loop)
    if (client.connect(serverIP, serverPort)) {
// Single instruction; see the actual code line for its effect
      Serial.println("Connected to Python server");
// Single instruction; see the actual code line for its effect
      client.println("Hello from ESP32");
// Start of a code block (function/if/loop)
    } else {
// Single instruction; see the actual code line for its effect
      Serial.println("Connection to Python server failed");
// End of the current code block
    }
// Existing comment from your code (kept): resetDisplay();  // Reset the display if refresh button is pressed
    //resetDisplay();  // Reset the display if refresh button is pressed
// Existing comment from your code (kept): progress = 0;    // Reset the progress bar to 0
    // progress = 0;    // Reset the progress bar to 0
// Existing comment from your code (kept): beep_buzzer(2, 30);
    //beep_buzzer(2, 30);
// End of the current code block
  }
// End of the current code block
}
// Start of a code block (function/if/loop)
void communicate_send(String msg_send) {
// Existing comment from your code (kept): Send Serial Monitor input to Python server
  // Send Serial Monitor input to Python server
// Start of a code block (function/if/loop)
  if (Serial.available() > 0 || client.connected()) {
// Single instruction; see the actual code line for its effect
    String serialInput = Serial.readStringUntil('\n');
// Existing comment from your code (kept): client.println("[ESP32] " + serialInput);  // Tag as ESP32
    // client.println("[ESP32] " + serialInput);  // Tag as ESP32
// Code line calling a function or doing logic
    client.println(msg_send);  // Tag as ESP32
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): // Receive messages from server
  // // Receive messages from server
// Existing comment from your code (kept): while (client.available()) {
  // while (client.available()) {
// Existing comment from your code (kept): String msg = client.readStringUntil('\n');
  //   String msg = client.readStringUntil('\n');
// Existing comment from your code (kept): Serial.println(">> " + msg);
  //   Serial.println(">> " + msg);
// Existing comment from your code (kept): }
  // }
// (blank line to keep code readable)

// Existing comment from your code (kept): delay(10);
  // delay(10);
// Existing comment from your code (kept): client.println(msg_send);  // Tag as ESP32
  //  client.println(msg_send);  // Tag as ESP32
// (blank line to keep code readable)

// Existing comment from your code (kept): while (1) {
  // while (1) {
// Existing comment from your code (kept): unsigned long msg_currentMillis = (millis() / 1000);  //scale factor for data hadle
  //   unsigned long msg_currentMillis = (millis() / 1000);  //scale factor for data hadle
// (blank line to keep code readable)

// Existing comment from your code (kept): // Send Serial Monitor input to Python server
  //   // Send Serial Monitor input to Python server
// Existing comment from your code (kept): // if (Serial.available() > 0 || client.connected()) {
  //   // if (Serial.available() > 0 || client.connected()) {
// Existing comment from your code (kept): //   String serialInput = Serial.readStringUntil('\n');
  //   //   String serialInput = Serial.readStringUntil('\n');
// Existing comment from your code (kept): //   // client.println("[ESP32] " + serialInput);  // Tag as ESP32
  //   //   // client.println("[ESP32] " + serialInput);  // Tag as ESP32
// Existing comment from your code (kept): //   client.println("[ESP32] " + msg_send);  // Tag as ESP32
  //   //   client.println("[ESP32] " + msg_send);  // Tag as ESP32
// Existing comment from your code (kept): // }
  //   // }
// Existing comment from your code (kept): if (msg_previousMillis >= msg_cal_time) {
  //   if (msg_previousMillis >= msg_cal_time) {
// Existing comment from your code (kept): beep_buzzer(10, 70);
  //     beep_buzzer(10, 70);
// Existing comment from your code (kept): break;
  //     break;
// Existing comment from your code (kept): }
  //   }
// Existing comment from your code (kept): msg_previousMillis = msg_currentMillis;
  //   msg_previousMillis = msg_currentMillis;
// Existing comment from your code (kept): Serial.println(msg_currentMillis);
  //   Serial.println(msg_currentMillis);
// Existing comment from your code (kept): }
  // }
// End of the current code block
}
// Start of a code block (function/if/loop)
void cam_on(bool on) {
// Start of a code block (function/if/loop)
  if (on) {
// Set a digital output HIGH (5V) or LOW (0V)
    digitalWrite(cam_on_off, LOW);
// Start of a code block (function/if/loop)
  } else {
// Set a digital output HIGH (5V) or LOW (0V)
    digitalWrite(cam_on_off, HIGH);
// End of the current code block
  }
// End of the current code block
}
