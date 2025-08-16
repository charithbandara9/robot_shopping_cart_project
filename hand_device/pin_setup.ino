/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments explain purpose without changing behavior.
 * Board target: Arduino Mega 2560.
 */

// Start of a code block (function/if/loop)
void pin_setup() {
// Start USB serial with the PC at the specified baud rate (open Serial Monitor)
  Serial.begin(115200);
// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(cam_on_off,OUTPUT);
// Set a digital output HIGH (5V) or LOW (0V)
  digitalWrite(cam_on_off, HIGH);
// Read an analog sensor value (0–1023) from an analog pin
  analogReadResolution(12);  // Optional on ESP32 (default is 12-bit)
// Single instruction; see the actual code line for its effect
  delay(1000);
// (blank line to keep code readable)

// Existing comment from your code (kept): Set custom hostname BEFORE WiFi.begin()
  // Set custom hostname BEFORE WiFi.begin()
// Single instruction; see the actual code line for its effect
  WiFi.setHostname("remote");
// Single instruction; see the actual code line for its effect
  WiFi.begin(ssid, password);
// NOTE: "..." indicates omitted/missing code in the source you provided
  Serial.println("Connecting to WiFi...");
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
  while (WiFi.status() != WL_CONNECTED) {
// Single instruction; see the actual code line for its effect
    delay(500);
// Single instruction; see the actual code line for its effect
    Serial.print(".");
// End of the current code block
  }
// Single instruction; see the actual code line for its effect
  Serial.println("\nConnected to WiFi");
// (blank line to keep code readable)

// (blank line to keep code readable)
 
// (blank line to keep code readable)

// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(REFRESH_BUTTON, INPUT);
// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(button_1, INPUT);
// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(button_2, INPUT);
// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(button_3, INPUT);                                                         // Set the refresh button pin as input with pull-up
// Attach an interrupt so a function (ISR) runs when the pin changes
  attachInterrupt(digitalPinToInterrupt(REFRESH_BUTTON), requestRefresh, FALLING);  // Set up interrupt
// Attach an interrupt so a function (ISR) runs when the pin changes
  attachInterrupt(digitalPinToInterrupt(button_1), button1, FALLING);               // Set up interrupt
// Attach an interrupt so a function (ISR) runs when the pin changes
  attachInterrupt(digitalPinToInterrupt(button_2), button2, FALLING);               // Set up interrupt
// Attach an interrupt so a function (ISR) runs when the pin changes
  attachInterrupt(digitalPinToInterrupt(button_3), button3, FALLING);               // Set up interrupt
// Configure a pin as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(beep, OUTPUT);
// Single instruction; see the actual code line for its effect
  u8g2.begin();
// Single instruction; see the actual code line for its effect
  u8g2.setContrast(128);
// Single instruction; see the actual code line for its effect
  u8g2.enableUTF8Print();
// Single instruction; see the actual code line for its effect
  u8g2.setFont(u8g2_font_helvB10_tf);
// Single instruction; see the actual code line for its effect
  u8g2.setColorIndex(1);
// Code line calling a function or doing logic
  u8g2.setFontMode(1);    // Enable font mode
// Code line calling a function or doing logic
  u8g2.setBitmapMode(1);  // Enable bitmap mode
// End of the current code block
}
