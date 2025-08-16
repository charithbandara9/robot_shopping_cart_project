/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Comment before each code line explains purpose.
 * Target: ESP32-CAM board.
 */

// Existing comment from your code (kept): working final2024.4.19
//working final2024.4.19
// Include a required library/header file
#include "esp_camera.h"
// Include WiFi library to connect ESP32 to WiFi networks
#include <WiFi.h>
// Include a required library/header file
#include "esp_timer.h"
// Include a required library/header file
#include "img_converters.h"
// Include a required library/header file
#include "Arduino.h"
// Include a required library/header file
#include "fb_gfx.h"
// Include a required library/header file
#include "soc/soc.h" //disable brownout problems
// Include a required library/header file
#include "soc/rtc_cntl_reg.h"  //disable brownout problems
// Include a required library/header file
#include "esp_http_server.h"
// (blank line to keep code readable)

// Define a constant or macro for compilation
#define BUTTON_PIN 13
// Declare a variable with type and optional initial value
volatile bool toggleRequested = false;
// Declare a variable with type and optional initial value
bool streamEnabled = false;
// Declare a variable with type and optional initial value
unsigned long lastDebounceTime = 0;
// (blank line to keep code readable)

// Execute this instruction
const char* ssid = "wifi_123";
// Execute this instruction
const char* password = "kalana123";
// (blank line to keep code readable)

// Define a constant or macro for compilation
#define PART_BOUNDARY "123456789000000000000987654321"
// (blank line to keep code readable)

// Define a constant or macro for compilation
#define CAMERA_MODEL_AI_THINKER
// Execute function or logic
#if defined(CAMERA_MODEL_AI_THINKER)
// Define a constant or macro for compilation
  #define PWDN_GPIO_NUM     32
// Define a constant or macro for compilation
  #define RESET_GPIO_NUM    -1
// Define a constant or macro for compilation
  #define XCLK_GPIO_NUM      0
// Define a constant or macro for compilation
  #define SIOD_GPIO_NUM     26
// Define a constant or macro for compilation
  #define SIOC_GPIO_NUM     27
// Define a constant or macro for compilation
  #define Y9_GPIO_NUM       35
// Define a constant or macro for compilation
  #define Y8_GPIO_NUM       34
// Define a constant or macro for compilation
  #define Y7_GPIO_NUM       39
// Define a constant or macro for compilation
  #define Y6_GPIO_NUM       36
// Define a constant or macro for compilation
  #define Y5_GPIO_NUM       21
// Define a constant or macro for compilation
  #define Y4_GPIO_NUM       19
// Define a constant or macro for compilation
  #define Y3_GPIO_NUM       18
// Define a constant or macro for compilation
  #define Y2_GPIO_NUM        5
// Define a constant or macro for compilation
  #define VSYNC_GPIO_NUM    25
// Define a constant or macro for compilation
  #define HREF_GPIO_NUM     23
// Define a constant or macro for compilation
  #define PCLK_GPIO_NUM     22
// Execute function or logic
#else
// Execute function or logic
  #error "Camera model not selected"
// Execute function or logic
#endif
// (blank line to keep code readable)

// Execute this instruction
httpd_handle_t stream_httpd = NULL;
// (blank line to keep code readable)

// Execute this instruction
static const char* _STREAM_CONTENT_TYPE = "multipart/x-mixed-replace;boundary=" PART_BOUNDARY;
// Execute this instruction
static const char* _STREAM_BOUNDARY = "\r\n--" PART_BOUNDARY "\r\n";
// Execute this instruction
static const char* _STREAM_PART = "Content-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n";
// (blank line to keep code readable)

// Start of a block of code
static esp_err_t stream_handler(httpd_req_t *req) {
// Execute this instruction
  camera_fb_t * fb = NULL;
// Execute this instruction
  esp_err_t res = ESP_OK;
// Execute this instruction
  size_t _jpg_buf_len = 0;
// Execute this instruction
  uint8_t * _jpg_buf = NULL;
// Declare a variable with type and optional initial value
  char * part_buf[64];
// (blank line to keep code readable)

// Execute this instruction
  res = httpd_resp_set_type(req, _STREAM_CONTENT_TYPE);
// Start of a block of code
  if (res != ESP_OK) {
// Return a value or end the function
    return res;
// End of a code block
  }
// (blank line to keep code readable)

// Start of a block of code
  while (streamEnabled) {
// Execute this instruction
    fb = esp_camera_fb_get();
// Start of a block of code
    if (!fb) {
// Execute this instruction
      Serial.println("Camera capture failed");
// Execute this instruction
      res = ESP_FAIL;
// Start of a block of code
    } else {
// Start of a block of code
      if (fb->format != PIXFORMAT_JPEG) {
// Declare a variable with type and optional initial value
        bool jpeg_converted = frame2jpg(fb, 60, &_jpg_buf, &_jpg_buf_len);
// Return a value or end the function
        esp_camera_fb_return(fb);
// Execute this instruction
        fb = NULL;
// Start of a block of code
        if (!jpeg_converted) {
// Execute this instruction
          Serial.println("JPEG compression failed");
// Execute this instruction
          res = ESP_FAIL;
// End of a code block
        }
// Start of a block of code
      } else {
// Execute this instruction
        _jpg_buf_len = fb->len;
// Execute this instruction
        _jpg_buf = fb->buf;
// End of a code block
      }
// End of a code block
    }
// (blank line to keep code readable)

// Start of a block of code
    if (res == ESP_OK) {
// Execute this instruction
      size_t hlen = snprintf((char *)part_buf, 64, _STREAM_PART, _jpg_buf_len);
// Execute this instruction
      res = httpd_resp_send_chunk(req, (const char *)part_buf, hlen);
// End of a code block
    }
// Start of a block of code
    if (res == ESP_OK) {
// Execute this instruction
      res = httpd_resp_send_chunk(req, (const char *)_jpg_buf, _jpg_buf_len);
// End of a code block
    }
// Start of a block of code
    if (res == ESP_OK) {
// Execute this instruction
      res = httpd_resp_send_chunk(req, _STREAM_BOUNDARY, strlen(_STREAM_BOUNDARY));
// End of a code block
    }
// (blank line to keep code readable)

// Start of a block of code
    if (fb) {
// Return a value or end the function
      esp_camera_fb_return(fb);
// Start of a block of code
    } else if (_jpg_buf) {
// Execute this instruction
      free(_jpg_buf);
// End of a code block
    }
// (blank line to keep code readable)

// Start of a block of code
    if (res != ESP_OK) {
// Execute this instruction
      break;
// End of a code block
    }
// (blank line to keep code readable)

// Existing comment from your code (kept): Check if toggle is requested
    // Check if toggle is requested
// Conditional statement: execute if condition is true
    if (toggleRequested) break;
// End of a code block
  }
// (blank line to keep code readable)

// Return a value or end the function
  return res;
// End of a code block
}
// (blank line to keep code readable)

// Start of a block of code
void startCameraServer() {
// Execute this instruction
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
// Execute this instruction
  config.server_port = 80;
// (blank line to keep code readable)

// Start of a block of code
  httpd_uri_t index_uri = {
// Execute function or logic
    .uri       = "/",
// Execute function or logic
    .method    = HTTP_GET,
// Execute function or logic
    .handler   = stream_handler,
// Execute function or logic
    .user_ctx  = NULL
// Execute this instruction
  };
// (blank line to keep code readable)

// Start of a block of code
  if (httpd_start(&stream_httpd, &config) == ESP_OK) {
// Execute this instruction
    httpd_register_uri_handler(stream_httpd, &index_uri);
// Execute this instruction
    Serial.println("Camera stream started");
// End of a code block
  }
// End of a code block
}
// (blank line to keep code readable)

// Start of a block of code
void stopCameraServer() {
// Start of a block of code
  if (stream_httpd) {
// Execute this instruction
    httpd_stop(stream_httpd);
// Execute this instruction
    stream_httpd = NULL;
// Execute this instruction
    Serial.println("Camera stream stopped");
// End of a code block
  }
// End of a code block
}
// (blank line to keep code readable)

// Start of a block of code
void IRAM_ATTR handleButtonInterrupt() {
// Declare a variable with type and optional initial value
  unsigned long currentMillis = millis();
// Conditional statement: execute if condition is true
  if (currentMillis - lastDebounceTime > 300) { // debounce
// Execute this instruction
    toggleRequested = true;
// Execute this instruction
    lastDebounceTime = currentMillis;
// End of a code block
  }
// End of a code block
}
// (blank line to keep code readable)

// setup(): runs once after boot/reset; initialize peripherals here
void setup() {
// Execute function or logic
  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
// (blank line to keep code readable)

// Start serial communication for debugging at a specified baud rate
  Serial.begin(115200);
// (blank line to keep code readable)

// Set pin mode: INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(BUTTON_PIN, INPUT_PULLUP);
// Set pin mode: INPUT, INPUT_PULLUP, or OUTPUT
  pinMode(4, OUTPUT);  // Built-in LED on pin 4
// Execute this instruction
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonInterrupt, FALLING);
// (blank line to keep code readable)

// Existing comment from your code (kept): Init camera
  // Init camera
// Execute this instruction
  camera_config_t config;
// Execute this instruction
  config.ledc_channel = LEDC_CHANNEL_0;
// Execute this instruction
  config.ledc_timer = LEDC_TIMER_0;
// Execute this instruction
  config.pin_d0 = Y2_GPIO_NUM;
// Execute this instruction
  config.pin_d1 = Y3_GPIO_NUM;
// Execute this instruction
  config.pin_d2 = Y4_GPIO_NUM;
// Execute this instruction
  config.pin_d3 = Y5_GPIO_NUM;
// Execute this instruction
  config.pin_d4 = Y6_GPIO_NUM;
// Execute this instruction
  config.pin_d5 = Y7_GPIO_NUM;
// Execute this instruction
  config.pin_d6 = Y8_GPIO_NUM;
// Execute this instruction
  config.pin_d7 = Y9_GPIO_NUM;
// Execute this instruction
  config.pin_xclk = XCLK_GPIO_NUM;
// Execute this instruction
  config.pin_pclk = PCLK_GPIO_NUM;
// Execute this instruction
  config.pin_vsync = VSYNC_GPIO_NUM;
// Execute this instruction
  config.pin_href = HREF_GPIO_NUM;
// Execute this instruction
  config.pin_sccb_sda = SIOD_GPIO_NUM;
// Execute this instruction
  config.pin_sccb_scl = SIOC_GPIO_NUM;
// Execute this instruction
  config.pin_pwdn = PWDN_GPIO_NUM;
// Execute this instruction
  config.pin_reset = RESET_GPIO_NUM;
// Execute this instruction
  config.xclk_freq_hz = 20000000;
// Execute this instruction
  config.pixel_format = PIXFORMAT_JPEG;
// (blank line to keep code readable)

// Start of a block of code
  if (psramFound()) {
// Execute this instruction
    config.frame_size = FRAMESIZE_VGA;
// Execute this instruction
    config.jpeg_quality = 10;
// Execute this instruction
    config.fb_count = 2;
// Start of a block of code
  } else {
// Execute this instruction
    config.frame_size = FRAMESIZE_QVGA;
// Execute this instruction
    config.jpeg_quality = 12;
// Execute this instruction
    config.fb_count = 1;
// End of a code block
  }
// (blank line to keep code readable)

// Execute this instruction
  esp_err_t err = esp_camera_init(&config);
// Start of a block of code
  if (err != ESP_OK) {
// Execute this instruction
    Serial.printf("Camera init failed with error 0x%x", err);
// Return a value or end the function
    return;
// End of a code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): Connect Wi-Fi
  // Connect Wi-Fi
// Connect ESP32 to WiFi with provided SSID and password
  WiFi.begin(ssid, password);
// Call WiFi library functions to manage WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
// Execute this instruction
    delay(500);
// Execute this instruction
    Serial.print(".");
// End of a code block
  }
// Execute this instruction
  Serial.println("\nWiFi connected.");
// Execute this instruction
  Serial.print("ESP32-CAM IP address: http://");
// Call WiFi library functions to manage WiFi connection
  Serial.println(WiFi.localIP());
// End of a code block
}
// (blank line to keep code readable)

// loop(): runs repeatedly after setup(); main program logic
void loop() {
// Start of a block of code
  if (toggleRequested) {
// Execute this instruction
    toggleRequested = false;
// Execute this instruction
    streamEnabled = !streamEnabled;
// Start of a block of code
    if (streamEnabled) {
// Write HIGH or LOW to a digital pin
      digitalWrite(4, HIGH);  // Turn on LED
// Execute this instruction
      startCameraServer();
// Start of a block of code
    } else {
// Write HIGH or LOW to a digital pin
      digitalWrite(4, LOW);   // Turn off LED
// Execute this instruction
      stopCameraServer();
// End of a code block
    }
// End of a code block
  }
// (blank line to keep code readable)

// Execute this instruction
  delay(10);
// End of a code block
}
