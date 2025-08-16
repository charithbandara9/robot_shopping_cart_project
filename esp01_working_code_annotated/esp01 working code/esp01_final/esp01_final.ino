/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Comment before each code line explains purpose.
 * Target: ESP-01 (ESP8266) board.
 */

// Existing comment from original code: last update
//last update
// Include WiFi library for ESP8266 boards to manage WiFi connection
#include <ESP8266WiFi.h>
// (blank line for readability)

// Existing comment from original code: Updated network and server settings
// Updated network and server settings
// Code execution line
const char* ssid = "wifi_123";       // WiFi SSID
// Code execution line
const char* password = "kalana123";  // WiFi password
// Code execution line
const char* host = "192.168.43.20";  // Python server IP
// Code execution line
const int port = 8888;               // Port for TCP server
// (blank line for readability)

// Execute statement
WiFiClient client;
// (blank line for readability)

// setup(): runs once after boot/reset; initialize hardware and connections here
void setup() {
// Initialize serial communication for debugging at given baud rate
  Serial.begin(9600);  // For debugging (Serial Monitor)
// (blank line for readability)

// Set pin mode as INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(2, OUTPUT);  // GPIO2 is D4 in ESP8266 (used for LED or other output)
// (blank line for readability)

// Call WiFi library function
  Serial.println("Connecting to WiFi...");
// Connect to WiFi network with given credentials
  WiFi.begin(ssid, password);
// (blank line for readability)

// Existing comment from original code: Wait for WiFi connection
  // Wait for WiFi connection
// Call WiFi library function
  while (WiFi.status() != WL_CONNECTED) {
// Execute statement
    delay(500);
// Execute statement
    Serial.print(".");
// End of a block
  }
// (blank line for readability)

// Execute statement
  Serial.println("\nWiFi connected. IP address: ");
// Call WiFi library function
  Serial.println(WiFi.localIP());
// (blank line for readability)

// Existing comment from original code: Connect to the Python server
  // Connect to the Python server
// Start of a block
  if (client.connect(host, port)) {
// Execute statement
    Serial.println("Connected to Python server");
// Code execution line
    client.println("esp01");  // Send identification to the server
// Start of a block
  } else {
// Execute statement
    Serial.println("Connection to server failed");
// End of a block
  }
// End of a block
}
// (blank line for readability)

// loop(): runs repeatedly; main logic here
void loop() {
// Existing comment from original code: Check if data is coming from Mega (Serial1)
  // Check if data is coming from Mega (Serial1)
// Start of a block
  if (Serial.available()) {
// Write HIGH or LOW to a digital output pin
    digitalWrite(2, HIGH);  // Example: Turn on LED when data is received from Mega
// Execute statement
    String msg = Serial.readStringUntil('\n');
// Execute statement
    msg.trim();
// Start of a block
    if (msg.length() > 0 && client.connected()) {
// Execute statement
      client.println("[Mega] " + msg);
// Existing comment from original code: Serial.println("Sent to server: " + msg);
     // Serial.println("Sent to server: " + msg);
// End of a block
    }
// End of a block
  }
// (blank line for readability)

// Existing comment from original code: Check if server sent data to ESP01
  // Check if server sent data to ESP01
// Start of a block
  if (client.available()) {
// Execute statement
    String fromServer = client.readStringUntil('\n');
// Execute statement
    fromServer.trim();
// Start of a block
    if (fromServer.length() > 0) {
// Existing comment from original code: Serial.println("From server: " + fromServer);
      //Serial.println("From server: " + fromServer);
// Code execution line
      Serial.println(fromServer);  // Forward to Mega via Serial1
// End of a block
    }
// End of a block
  }
// (blank line for readability)

// Existing comment from original code: If the server disconnects, try reconnecting
  // If the server disconnects, try reconnecting
// Start of a block
  if (!client.connected()) {
// Call server object to manage HTTP requests/responses
    Serial.println("Disconnected from server. Reconnecting...");
// Execute statement
    client.stop();
// Code execution line
    delay(5000);  // Wait for 5 seconds before reconnecting
// Start of a block
    if (client.connect(host, port)) {
// Execute statement
      Serial.println("Reconnected to Python server");
// Execute statement
      client.println("esp01");
// End of a block
    }
// End of a block
  }
// (blank line for readability)

// Code execution line
  delay(10);  // Small delay for stability
// End of a block
}
