/*
 * === AUTO-ANNOTATED FOR BEGINNERS ===
 * Every code line is preceded by an explanatory comment.
 * Comments explain purpose without changing behavior.
 * Board target: Arduino Mega 2560.
 */

// Include a header/library required by the sketch
#include "definations___variable.h"
// Include a header/library required by the sketch
#include <U8g2lib.h>
// Include a header/library required by the sketch
#include <WiFi.h>
// Single instruction; see the actual code line for its effect
WiFiClient client;
// Single instruction; see the actual code line for its effect
U8G2_ST7920_128X64_1_SW_SPI u8g2(U8G2_R0, /* clock=*/18, /* data=*/23, /* CS=*/5, /* reset=*/4);
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
static const unsigned char cart_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xf0, 0x03, 0xc0, 0x01, 0x30, 0x00, 0x7c, 0x00, 0xf0, 0x03, 0xc0, 0x01, 0x30, 0x00, 0x7e, 0x00, 0xe0, 0x03, 0xc0, 0x01, 0x30, 0x00, 0x7e, 0x00, 0xe0, 0x07, 0xc0, 0x01, 0x30, 0x00, 0x7e, 0x00, 0xe0, 0x07, 0xc0, 0x01, 0x30, 0x00, 0x3e, 0x00, 0xe0, 0x07, 0xc0, 0x01, 0x30, 0x00, 0x3e, 0x00, 0xc0, 0x07, 0xc0, 0x01, 0x30, 0x00, 0x3f, 0x00, 0xc0, 0x0f, 0xc0, 0x01, 0x30, 0x00, 0x3f, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x80, 0x1f, 0xc0, 0x01, 0x30, 0x00, 0x1f, 0x00, 0x00, 0x1f, 0xc0, 0x01, 0x30, 0x80, 0x1f, 0x00, 0x00, 0x1f, 0xc0, 0x01, 0x30, 0x80, 0x1f, 0x00, 0x00, 0x3f, 0xc0, 0x01, 0x30, 0x80, 0x0f, 0x00, 0x00, 0x3f, 0xc0, 0x01, 0x30, 0x80, 0x0f, 0x00, 0x00, 0x3e, 0xc0, 0x01, 0x30, 0x80, 0x0f, 0x00, 0x00, 0x7e, 0xc0, 0x01, 0x30, 0xc0, 0x0f, 0x00, 0x00, 0x7e, 0xc0, 0x01, 0x30, 0xfc, 0x0f, 0x00, 0x00, 0x7c, 0xc0, 0x01, 0xfc, 0xff, 0x0f, 0x00, 0x00, 0xfc, 0xc0, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0x07, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0x3c, 0x80, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0xf0, 0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0xff, 0x07, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0xff, 0x07, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0xff, 0x07, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x80, 0xff, 0x01, 0x00, 0x00, 0xfe, 0x03, 0x00, 0x80, 0xff, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char wifi_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x80, 0x0f, 0x00, 0xe0, 0x3f, 0x00, 0x78, 0xf0, 0x00, 0x9c, 0xcf, 0x01, 0xee, 0xbf, 0x03, 0xf7, 0x78, 0x07, 0x3a, 0xe7, 0x02, 0xdc, 0xdf, 0x01, 0xe8, 0xb8, 0x00, 0x70, 0x77, 0x00, 0xa0, 0x2f, 0x00, 0xc0, 0x1d, 0x00, 0x80, 0x0a, 0x00, 0x00, 0x07, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char battery_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x00, 0x00, 0xf0, 0xff, 0x7f, 0x08, 0x00, 0x80, 0x68, 0xdb, 0xb6, 0x6e, 0xdb, 0xb6, 0x61, 0xdb, 0xb6, 0x61, 0xdb, 0xb6, 0x61, 0xdb, 0xb6, 0x61, 0xdb, 0xb6, 0x61, 0xdb, 0xb6, 0x6e, 0xdb, 0xb6, 0x68, 0xdb, 0xb6, 0x08, 0x00, 0x80, 0xf0, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char start_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x81, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xf0, 0x38, 0xe0, 0x3e, 0x18, 0x70, 0x00, 0x70, 0x20, 0x40, 0x3c, 0x10, 0x60, 0x00, 0x30, 0x00, 0x40, 0x38, 0x00, 0x60, 0x00, 0x30, 0xc6, 0x38, 0x38, 0xe2, 0x7c, 0x00, 0x30, 0xfc, 0x38, 0x38, 0xe2, 0x78, 0x00, 0x30, 0xf0, 0x18, 0x30, 0x60, 0x78, 0x00, 0x70, 0xe0, 0x18, 0x31, 0x70, 0x78, 0x00, 0xf0, 0xc3, 0x18, 0x30, 0x78, 0x78, 0x00, 0x10, 0xc7, 0x08, 0x20, 0x70, 0x78, 0x00, 0x10, 0xc0, 0x08, 0x20, 0x61, 0x78, 0x00, 0x30, 0xe0, 0x88, 0x27, 0x62, 0x78, 0x00, 0x70, 0xf0, 0xc8, 0x27, 0xe6, 0x7c, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x0f, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char setting_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0xff, 0xff, 0xff, 0x7f, 0xc0, 0xff, 0x03, 0xff, 0xff, 0xff, 0x3f, 0x80, 0xff, 0x03, 0xff, 0xff, 0xff, 0x3b, 0x80, 0xfb, 0x03, 0xff, 0xff, 0xff, 0x20, 0x84, 0xe0, 0x03, 0xff, 0xff, 0x7f, 0x00, 0x04, 0xc0, 0x03, 0xff, 0xff, 0x3f, 0x00, 0x0e, 0x80, 0x03, 0xff, 0xff, 0x3f, 0x04, 0x1f, 0x84, 0x03, 0xff, 0xff, 0x3f, 0xce, 0x7f, 0x8e, 0x03, 0xff, 0xff, 0x3f, 0xfc, 0xff, 0x87, 0x03, 0xff, 0xff, 0x7f, 0x78, 0xc0, 0xc3, 0x03, 0xff, 0xff, 0x7f, 0x38, 0x80, 0xc3, 0x03, 0xff, 0xff, 0x0f, 0x1c, 0x00, 0x07, 0x02, 0xff, 0xff, 0x07, 0x1c, 0x04, 0x06, 0x00, 0xff, 0x7f, 0x06, 0x0e, 0x1f, 0x0e, 0x00, 0xff, 0x3f, 0x86, 0x0f, 0x1f, 0x3e, 0x00, 0x7f, 0x3c, 0xc6, 0x8f, 0x3f, 0x7e, 0x00, 0x3f, 0x18, 0x06, 0x0e, 0x1f, 0x0e, 0x00, 0x1f, 0x00, 0x06, 0x0c, 0x1f, 0x06, 0x00, 0x0f, 0x00, 0x0e, 0x1c, 0x00, 0x07, 0x02, 0x07, 0x83, 0x1f, 0x38, 0x00, 0x07, 0x03, 0x87, 0xe7, 0x7f, 0x78, 0xc0, 0xc3, 0x03, 0x87, 0xff, 0x3f, 0xf8, 0xe0, 0x83, 0x03, 0x07, 0xff, 0x30, 0xfc, 0xff, 0x87, 0x03, 0x0f, 0x3e, 0x20, 0x8e, 0x3f, 0x8e, 0x03, 0x1f, 0x1e, 0x20, 0x00, 0x0e, 0x80, 0x03, 0x0f, 0x0f, 0x38, 0x00, 0x0e, 0x80, 0x03, 0x01, 0x07, 0x7f, 0x00, 0x04, 0xc0, 0x03, 0x80, 0x83, 0xff, 0x31, 0x80, 0xf1, 0x03, 0x80, 0xc3, 0xff, 0x3f, 0x80, 0xff, 0x03, 0xf0, 0xc3, 0xff, 0x79, 0xc0, 0xff, 0x03, 0xf8, 0xe3, 0xff, 0xf0, 0xe0, 0xff, 0x03, 0xf8, 0xe3, 0xff, 0xf0, 0xff, 0xff, 0x03, 0xf0, 0xc3, 0xff, 0xf0, 0xfb, 0xff, 0x03, 0x80, 0xc3, 0xff, 0x78, 0xe0, 0xff, 0x03, 0x80, 0x83, 0x7f, 0x38, 0xe0, 0xff, 0x03, 0x01, 0x07, 0x3f, 0x38, 0xf0, 0xff, 0x03, 0x0f, 0x0f, 0x00, 0x3c, 0xfe, 0xff, 0x03, 0x1f, 0x1e, 0x00, 0x1e, 0xfe, 0xff, 0x03, 0x0f, 0x3e, 0x00, 0x1f, 0xfe, 0xff, 0x03, 0x07, 0xff, 0xc0, 0x3f, 0xfc, 0xff, 0x03, 0x87, 0xff, 0xff, 0x3f, 0xf8, 0xff, 0x03, 0x87, 0xe7, 0xff, 0x79, 0xf8, 0xff, 0x03, 0x07, 0x83, 0x3f, 0x30, 0xfc, 0xff, 0x03, 0x0f, 0x00, 0x1e, 0x00, 0xfc, 0xff, 0x03, 0x1f, 0x00, 0x1e, 0x00, 0xfe, 0xff, 0x03, 0x3f, 0x18, 0x0e, 0x02, 0xff, 0xff, 0x03, 0x7f, 0x3c, 0x0e, 0xcf, 0xff, 0xff, 0x03, 0xff, 0x3f, 0x00, 0xff, 0xff, 0xff, 0x03, 0xff, 0x3f, 0x80, 0xff, 0xff, 0xff, 0x03, 0xff, 0x7f, 0x80, 0xff, 0xff, 0xff, 0x03
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char back_arrow_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x80, 0x07, 0x00, 0xc0, 0x07, 0x00, 0xe0, 0x03, 0x00, 0xf0, 0x01, 0x00, 0xf8, 0xff, 0x03, 0xf8, 0xff, 0x07, 0xf8, 0xff, 0x0f, 0xe0, 0x03, 0x1f, 0xc0, 0x07, 0x1e, 0x80, 0x07, 0x1e, 0x00, 0x07, 0x1c, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x1f, 0x00, 0x80, 0x0f, 0xf8, 0xff, 0x0f, 0xf8, 0xff, 0x07, 0xf8, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char letter_A_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0xff, 0x00, 0xc0, 0xff, 0x03, 0xf0, 0xff, 0x0f, 0xf8, 0xff, 0x1f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xfe, 0xe7, 0x7f, 0xfe, 0xc3, 0x7f, 0xff, 0xc3, 0xff, 0xff, 0xdb, 0xff, 0xff, 0x99, 0xff, 0xff, 0x99, 0xff, 0xff, 0x3c, 0xff, 0xff, 0x3c, 0xff, 0xff, 0x00, 0xff, 0x7f, 0x00, 0xfe, 0x7e, 0x7e, 0x7e, 0x3e, 0x7e, 0x7c, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xf8, 0xff, 0x1f, 0xf0, 0xff, 0x0f, 0xc0, 0xff, 0x03, 0x00, 0xff, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char letter_B_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0xff, 0x00, 0xc0, 0xff, 0x03, 0xf0, 0xff, 0x0f, 0xf8, 0xff, 0x1f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xfe, 0xe0, 0x7f, 0xfe, 0x80, 0x7f, 0xff, 0x3c, 0xff, 0xff, 0x3c, 0xff, 0xff, 0xbc, 0xff, 0xff, 0x80, 0xff, 0xff, 0x80, 0xff, 0xff, 0x3c, 0xff, 0xff, 0x3c, 0xff, 0xff, 0x3c, 0xff, 0xfe, 0x80, 0x7f, 0xfe, 0xe0, 0x7f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xf8, 0xff, 0x1f, 0xf0, 0xff, 0x0f, 0xc0, 0xff, 0x03, 0x00, 0xff, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char letter_C_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0xff, 0x00, 0xc0, 0xff, 0x03, 0xf0, 0xff, 0x0f, 0xf8, 0xff, 0x1f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xfe, 0xc3, 0x7f, 0xfe, 0x00, 0x7f, 0x7f, 0x3c, 0xfe, 0x7f, 0x7e, 0xfe, 0x3f, 0xfe, 0xff, 0x3f, 0xfe, 0xff, 0x3f, 0xfe, 0xff, 0x3f, 0x7e, 0xfc, 0x7f, 0x7e, 0xfe, 0x7f, 0x3c, 0xfe, 0xfe, 0x00, 0x7f, 0xfe, 0xc3, 0x7f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xf8, 0xff, 0x1f, 0xf0, 0xff, 0x0f, 0xc0, 0xff, 0x03, 0x00, 0xff, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char letter_D_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0xff, 0x00, 0xc0, 0xff, 0x03, 0xf0, 0xff, 0x0f, 0xf8, 0xff, 0x1f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0x7e, 0xf0, 0x7f, 0x7e, 0x80, 0x7f, 0x7f, 0x0e, 0xff, 0x7f, 0x3e, 0xff, 0x7f, 0x3e, 0xfe, 0x7f, 0x7e, 0xfe, 0x7f, 0x7e, 0xfe, 0x7f, 0x3e, 0xfe, 0x7f, 0x3e, 0xff, 0x7f, 0x0e, 0xff, 0x7e, 0x80, 0x7f, 0x7e, 0xf0, 0x7f, 0xfc, 0xff, 0x3f, 0xfc, 0xff, 0x3f, 0xf8, 0xff, 0x1f, 0xf0, 0xff, 0x0f, 0xc0, 0xff, 0x03, 0x00, 0xff, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char small_arrow_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x06, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x12, 0x00, 0x00, 0x22, 0x00, 0xfe, 0x4b, 0x00, 0x01, 0x98, 0x00, 0xfd, 0x3f, 0x01, 0xfd, 0x7f, 0x02, 0xfd, 0x3f, 0x01, 0x01, 0x98, 0x00, 0xfe, 0x4b, 0x00, 0x00, 0x22, 0x00, 0x00, 0x12, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x06, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char barcode_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x7e, 0x00, 0x00, 0x7e, 0x02, 0x00, 0x00, 0x40, 0xb2, 0xd5, 0xad, 0x4c, 0xb2, 0xd5, 0xad, 0x4c, 0xb2, 0xd5, 0xad, 0x4c, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x7f, 0xfe, 0xff, 0xff, 0x7f, 0x00, 0x00, 0x00, 0x00, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0xb0, 0xd5, 0xad, 0x0c, 0xb2, 0xd5, 0xad, 0x4c, 0xb2, 0xd5, 0xad, 0x4c, 0xb2, 0xd5, 0xad, 0x4c, 0x02, 0x00, 0x00, 0x40, 0x7e, 0x00, 0x00, 0x7e, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char capture_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xc0, 0xff, 0x03, 0xf0, 0xc3, 0x0f, 0xf8, 0x00, 0x1f, 0x38, 0x00, 0x1c, 0x1c, 0xff, 0x38, 0x9c, 0xff, 0x39, 0xce, 0xff, 0x73, 0xce, 0xff, 0x73, 0xc6, 0xff, 0x63, 0xc6, 0xff, 0x63, 0xc6, 0xff, 0x63, 0xc6, 0xff, 0x63, 0xce, 0xff, 0x73, 0xce, 0xff, 0x73, 0x9c, 0xff, 0x39, 0x1c, 0xff, 0x38, 0x38, 0x00, 0x1c, 0xf8, 0x00, 0x1f, 0xf0, 0xc3, 0x0f, 0xc0, 0xff, 0x03, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00
// Single instruction; see the actual code line for its effect
};
// Start of a code block (function/if/loop)
static const unsigned char Done_image_bits[] U8X8_PROGMEM = {
// Code line calling a function or doing logic
  0x80, 0xff, 0x01, 0xe0, 0xff, 0x07, 0xf0, 0xff, 0x0f, 0xf8, 0xff, 0x1f, 0xfc, 0xff, 0x3f, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfc, 0xff, 0x7f, 0xfe, 0xff, 0x3f, 0xff, 0xbf, 0x9f, 0xff, 0x3f, 0xcf, 0xff, 0x7f, 0xe6, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf9, 0xff, 0xfe, 0xff, 0x7f, 0xfe, 0xff, 0x7f, 0xfc, 0xff, 0x3f, 0xf8, 0xff, 0x1f, 0xf0, 0xff, 0x0f, 0xe0, 0xff, 0x07, 0x80, 0xff, 0x01
// Single instruction; see the actual code line for its effect
};
// (blank line to keep code readable)

// setup(): runs once after reset; set pin modes, start serial, init sensors here
void setup() {
// Single instruction; see the actual code line for its effect
  pin_setup();
// Single instruction; see the actual code line for its effect
  cam_on(true);
// End of the current code block
}
// (blank line to keep code readable)

// loop(): repeats forever; main program logic
void loop() {
// Start of a code block (function/if/loop)
  while(1){
// Single instruction; see the actual code line for its effect
    display_refresh();
// (blank line to keep code readable)
    
// End of the current code block
  }
// Existing comment from your code (kept): screen = 0;
  // screen = 0;
// Start of a code block (function/if/loop)
  while (screen < 1) {
// Single instruction; see the actual code line for its effect
    static int progress = 0;
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
    display_refresh();
// (blank line to keep code readable)

// Existing comment from your code (kept): Loop to animate the progress bar from 0 to 56
    // Loop to animate the progress bar from 0 to 56
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.drawXBMP(-1, 0, 64, 64, cart_image_bits);
// Existing comment from your code (kept): Draw the loading screen with progress bar
      // Draw the loading screen with progress bar
// Code line calling a function or doing logic
      u8g2.drawFrame(68, 39, 56, 8);      // Draw outer frame for progress bar
// Code line calling a function or doing logic
      u8g2.drawBox(69, 40, progress, 6);  // Draw the progress inside the frame
// (blank line to keep code readable)

// Existing comment from your code (kept): Draw the text above the progress bar
      // Draw the text above the progress bar
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_4x6_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(67, 37, "System loading");
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// (blank line to keep code readable)

// Existing comment from your code (kept): Update the progress bar with delay
    // Update the progress bar with delay
// Single instruction; see the actual code line for its effect
    progress++;
// Start of a code block (function/if/loop)
    if (progress > 55) {
// Code line calling a function or doing logic
      progress = 0;  // Reset progress after completion
// Single instruction; see the actual code line for its effect
      screen = 1;
// End of the current code block
    }
// (blank line to keep code readable)

// Existing comment from your code (kept): delay(2000);  // Adjust delay for smoother animation and refresh
    //delay(2000);  // Adjust delay for smoother animation and refresh
// Single instruction; see the actual code line for its effect
    beep_buzzer(1, 70);
// End of the current code block
  }
// (blank line to keep code readable)

// (blank line to keep code readable)

// Existing comment from your code (kept): ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of a code block (function/if/loop)
  while (screen == 1) {
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Existing comment from your code (kept): battery_read();
    // battery_read();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(0, 1, 19, 16, wifi_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(103, 0, 24, 16, battery_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_5x8_tr);
// Existing comment from your code (kept): String battery_level = String((int)battery_voltage) + "%";
      //String battery_level = String((int)battery_voltage) + "%";
// Existing comment from your code (kept): u8g2.drawStr(86, 11, battery_level.c_str());
      //u8g2.drawStr(86, 11, battery_level.c_str());
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_6x13_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(4, 30, "Cart is Active");
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// Existing comment from your code (kept): delay(500);
    // delay(500);
// Single instruction; see the actual code line for its effect
    screen = 2;
// End of the current code block
  }
// (blank line to keep code readable)

// Existing comment from your code (kept): ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start of a code block (function/if/loop)
  while (screen == 2) {
// Start of a code block (function/if/loop)
    if (M_button_3) {
// Single instruction; see the actual code line for its effect
      M_button_3 = false;
// Single instruction; see the actual code line for its effect
      select_box_1 = 5;
// Single instruction; see the actual code line for its effect
      beep_buzzer(1, 70);
// End of the current code block
    }
// Start of a code block (function/if/loop)
    if (M_button_1) {
// Single instruction; see the actual code line for its effect
      M_button_1 = false;
// Single instruction; see the actual code line for its effect
      select_box_1 = 69;
// Single instruction; see the actual code line for its effect
      beep_buzzer(1, 70);
// End of the current code block
    }
// Run the next block only if the condition is true
    if (M_button_2) {  //selection button
// Single instruction; see the actual code line for its effect
      M_button_2 = false;
// Run the next block only if the condition is true
      if (select_box_1 == 69) {  //check for what is selected
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      } else if (select_box_1 == 5) {
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 3;
// End of the current code block
      }
// End of the current code block
    }
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(7, 16, 50, 26, start_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(71, 4, 50, 50, setting_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_1, 2, 54, 54);
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// Existing comment from your code (kept): delay(2000);
    //delay(2000);
// Existing comment from your code (kept): resetDisplay();
    //resetDisplay();
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 3) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Start of a code block (function/if/loop)
    if (M_button_3) {
// Single instruction; see the actual code line for its effect
      M_button_3 = false;
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
      select_box_2 -= 25;
// Single instruction; see the actual code line for its effect
      beep_buzzer(1, 70);
// Start of a code block (function/if/loop)
      if (select_box_2 < 0) {
// Single instruction; see the actual code line for its effect
        select_box_2 = 100;
// End of the current code block
      }
// End of the current code block
    }
// Start of a code block (function/if/loop)
    if (M_button_1) {
// Single instruction; see the actual code line for its effect
      M_button_1 = false;
// Single instruction; see the actual code line for its effect
      select_box_2 += 25;
// Single instruction; see the actual code line for its effect
      beep_buzzer(1, 70);
// Start of a code block (function/if/loop)
      if (select_box_2 > 100) {
// Single instruction; see the actual code line for its effect
        select_box_2 = 0;
// End of the current code block
      }
// End of the current code block
    }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
    if (M_button_2) {
// Single instruction; see the actual code line for its effect
      M_button_2 = false;
// Run the next block only if the condition is true
      if (select_box_2 == 0) {  //back button
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 2;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 25) {
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 4;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 50) {
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 4;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 75) {
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 4;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 100) {
// Single instruction; see the actual code line for its effect
        u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
        screen = 4;
// End of the current code block
      }
// End of the current code block
    }
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_2, 34, 28, 26);
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_timR10_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(2, 14, "Where are you going?");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(1, 35, 24, 24, back_arrow_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(27, 35, 24, 24, letter_A_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(52, 35, 24, 24, letter_B_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(77, 35, 24, 24, letter_C_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(102, 35, 24, 24, letter_D_image_bits);
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// End of the current code block
  }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
  while (screen == 4) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_timR10_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(2, 14, "Go, I will follow you.");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(1, 35, 24, 24, back_arrow_image_bits);
// (blank line to keep code readable)

// Run the next block only if the condition is true
      if (select_box_2 == 0) {  //back button
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 25) {
// Single instruction; see the actual code line for its effect
        u8g2.drawXBM(29, 24, 18, 15, small_arrow_image_bits);
// Single instruction; see the actual code line for its effect
        u8g2.setFont(u8g2_font_haxrcorp4089_tr);
// Single instruction; see the actual code line for its effect
        u8g2.drawStr(53, 35, "Section    A");
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
        screen = 5;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 50) {
// Single instruction; see the actual code line for its effect
        u8g2.drawXBM(29, 24, 18, 15, small_arrow_image_bits);
// Single instruction; see the actual code line for its effect
        u8g2.setFont(u8g2_font_haxrcorp4089_tr);
// Single instruction; see the actual code line for its effect
        u8g2.drawStr(53, 35, "Section    B");
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
        screen = 5;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 75) {
// Single instruction; see the actual code line for its effect
        u8g2.drawXBM(29, 24, 18, 15, small_arrow_image_bits);
// Single instruction; see the actual code line for its effect
        u8g2.setFont(u8g2_font_haxrcorp4089_tr);
// Single instruction; see the actual code line for its effect
        u8g2.drawStr(53, 35, "Section    C");
// Single instruction; see the actual code line for its effect
        screen = 5;
// Start of a code block (function/if/loop)
      } else if (select_box_2 == 100) {
// Single instruction; see the actual code line for its effect
        u8g2.drawXBM(29, 24, 18, 15, small_arrow_image_bits);
// Single instruction; see the actual code line for its effect
        u8g2.setFont(u8g2_font_haxrcorp4089_tr);
// Single instruction; see the actual code line for its effect
        u8g2.drawStr(53, 35, "Go to the cashier");
// Single instruction; see the actual code line for its effect
        screen = 5;
// End of the current code block
      }
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 5) {
// Start of a code block (function/if/loop)
    if (select_box_2 == 25) {
// Single instruction; see the actual code line for its effect
      communicate_send("1");
// Start of a code block (function/if/loop)
    } else if (select_box_2 == 50) {
// Single instruction; see the actual code line for its effect
      communicate_send("2");
// Start of a code block (function/if/loop)
    } else if (select_box_2 == 75) {
// Single instruction; see the actual code line for its effect
      communicate_send("3");
// Start of a code block (function/if/loop)
    } else if (select_box_2 == 100) {
// Single instruction; see the actual code line for its effect
      communicate_send("4");
// End of the current code block
    }
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
    screen = 6;
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 6) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_4x6_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(51, 8, "Pressed to scanning");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(1, 35, 24, 24, back_arrow_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(72, 13, 32, 32, barcode_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_3, 35, 28, 26);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(30, 36, 24, 24, capture_image_bits);
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_3) {
// Single instruction; see the actual code line for its effect
        M_button_3 = false;
// (blank line to keep code readable)

// Existing comment from your code (kept): select_box_3 -= 27;
        // select_box_3 -= 27;
// Single instruction; see the actual code line for its effect
        select_box_3 = 1;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_3 < 0) {
        // if (select_box_3 < 0) {
// Existing comment from your code (kept): select_box_3 = 28;
        //   select_box_3 = 28;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// Start of a code block (function/if/loop)
      if (M_button_1) {
// Single instruction; see the actual code line for its effect
        M_button_1 = false;
// Existing comment from your code (kept): select_box_3 += 27;
        //select_box_3 += 27;
// Single instruction; see the actual code line for its effect
        select_box_3 = 28;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_3 > 28) {
        // if (select_box_3 > 28) {
// Existing comment from your code (kept): select_box_3 = 1;
        //   select_box_3 = 1;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_2) {
// Single instruction; see the actual code line for its effect
        M_button_2 = false;
// Run the next block only if the condition is true
        if (select_box_3 == 1) {  //back button
// Single instruction; see the actual code line for its effect
          delay(400);
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          cam_on(false);
// Single instruction; see the actual code line for its effect
          screen = 3;
// Start of a code block (function/if/loop)
        } else if (select_box_3 == 28) {
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          cam_on(true);
// Single instruction; see the actual code line for its effect
          screen = 7;
// End of the current code block
        }
// End of the current code block
      }
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// Code line calling a function or doing logic
  }  /////////////////////////////////////////////////////scanning process
// Start of a code block (function/if/loop)
  while (screen == 7) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_4x6_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(76, 31, "P_code = ");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(36, 8, "Now scanning");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(1, 35, 24, 24, back_arrow_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(43, 13, 32, 32, barcode_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_4, 35, 28, 26);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(101, 36, 24, 24, Done_image_bits);
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_3) {
// Single instruction; see the actual code line for its effect
        M_button_3 = false;
// (blank line to keep code readable)

// Existing comment from your code (kept): select_box_4 -= 99;
        // select_box_4 -= 99;
// (blank line to keep code readable)

// Single instruction; see the actual code line for its effect
        select_box_4 = 0;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 < 0) {
        // if (select_box_4 < 0) {
// Existing comment from your code (kept): select_box_4 = 99;
        //   select_box_4 = 99;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// Start of a code block (function/if/loop)
      if (M_button_1) {
// Single instruction; see the actual code line for its effect
        M_button_1 = false;
// Existing comment from your code (kept): select_box_4 += 99;
        // select_box_4 += 99;
// Single instruction; see the actual code line for its effect
        select_box_4 = 99;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 > 99) {
        // if (select_box_4 > 99) {
// Existing comment from your code (kept): select_box_4 = 0;
        //   select_box_4 = 0;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_2) {
// Single instruction; see the actual code line for its effect
        M_button_2 = false;
// Run the next block only if the condition is true
        if (select_box_4 == 0) {  //back button
// Single instruction; see the actual code line for its effect
          delay(400);
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          screen = 6;
// Code line calling a function or doing logic
        } else if (select_box_4 == 99) {  //every thing is done go to
// Single instruction; see the actual code line for its effect
          cam_on(false);
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          screen = 8;
// End of the current code block
        }
// End of the current code block
      }
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 8) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_4x6_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(-3, 16, " Press the button and go to the");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(-3, 23, " cashier.");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(1, 9, "Are you sure everything is done? ");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(1, 35, 24, 24, back_arrow_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_4, 35, 28, 26);
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(101, 36, 24, 24, Done_image_bits);
// Start of a code block (function/if/loop)
      if (M_button_3) {
// Single instruction; see the actual code line for its effect
        M_button_3 = false;
// (blank line to keep code readable)

// Existing comment from your code (kept): select_box_4 -= 99;
        // select_box_4 -= 99;
// Single instruction; see the actual code line for its effect
        select_box_4 = 0;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 < 0) {
        // if (select_box_4 < 0) {
// Existing comment from your code (kept): select_box_4 = 99;
        //   select_box_4 = 99;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// Start of a code block (function/if/loop)
      if (M_button_1) {
// Single instruction; see the actual code line for its effect
        M_button_1 = false;
// Existing comment from your code (kept): select_box_4 += 99;
        // select_box_4 += 99;
// Single instruction; see the actual code line for its effect
        select_box_4 = 99;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 > 99) {
        // if (select_box_4 > 99) {
// Existing comment from your code (kept): select_box_4 = 0;
        //   select_box_4 = 0;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_2) {
// Single instruction; see the actual code line for its effect
        M_button_2 = false;
// Run the next block only if the condition is true
        if (select_box_4 == 0) {  //back button
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          screen = 7;
// Code line calling a function or doing logic
        } else if (select_box_4 == 99) {  //every thing is done go to
// Single instruction; see the actual code line for its effect
          screen = 9;
// End of the current code block
        }
// End of the current code block
      }
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 9) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_5x7_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(1, 9, "Go to the cashier, ");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(25, 20, "I'll follow you.");
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// Single instruction; see the actual code line for its effect
    communicate_send("5");
// Single instruction; see the actual code line for its effect
    delay(3000);
// Code line calling a function or doing logic
    screen = 10;  //skip to
// End of the current code block
  }
// Start of a code block (function/if/loop)
  while (screen == 10) {
// Single instruction; see the actual code line for its effect
    display_refresh();
// Single instruction; see the actual code line for its effect
    u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
    u8g2.firstPage();
// Start of a code block (function/if/loop)
    do {
// Single instruction; see the actual code line for its effect
      u8g2.setFont(u8g2_font_5x7_tr);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(1, 9, "If you think the work is");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(-3, 19, " finished, you can select");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(-3, 28, " the done button.");
// Single instruction; see the actual code line for its effect
      u8g2.drawXBM(101, 36, 24, 24, Done_image_bits);
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(2, 37, "Put my remote back.");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(2, 47, "Goodbye, I hope to ");
// Single instruction; see the actual code line for its effect
      u8g2.drawStr(2, 56, "see you again.");
// Single instruction; see the actual code line for its effect
      u8g2.drawFrame(select_box_4, 35, 28, 26);
// Start of a code block (function/if/loop)
      if (M_button_3) {
// Single instruction; see the actual code line for its effect
        M_button_3 = false;
// (blank line to keep code readable)

// Existing comment from your code (kept): select_box_4 -= 99;
        // select_box_4 -= 99;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 < 0) {
        // if (select_box_4 < 0) {
// Existing comment from your code (kept): select_box_4 = 99;
        //   select_box_4 = 99;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// Start of a code block (function/if/loop)
      if (M_button_1) {
// Single instruction; see the actual code line for its effect
        M_button_1 = false;
// Existing comment from your code (kept): select_box_4 += 99;
        //  select_box_4 += 99;
// Single instruction; see the actual code line for its effect
        select_box_4 = 99;
// Single instruction; see the actual code line for its effect
        beep_buzzer(1, 70);
// Existing comment from your code (kept): if (select_box_4 > 99) {
        // if (select_box_4 > 99) {
// Existing comment from your code (kept): select_box_4 = 99;
        //   select_box_4 = 99;
// Existing comment from your code (kept): }
        // }
// End of the current code block
      }
// (blank line to keep code readable)

// Start of a code block (function/if/loop)
      if (M_button_2) {
// Single instruction; see the actual code line for its effect
        M_button_2 = false;
// Run the next block only if the condition is true
        if (select_box_4 == 99) {  //back button
// Single instruction; see the actual code line for its effect
          beep_buzzer(1, 70);
// Single instruction; see the actual code line for its effect
          u8g2.clearBuffer();
// Single instruction; see the actual code line for its effect
          screen = 2;
// End of the current code block
        }
// End of the current code block
      }
// Single instruction; see the actual code line for its effect
    } while (u8g2.nextPage());
// End of the current code block
  }
// End of the current code block
}
