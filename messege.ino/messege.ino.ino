#include <MD_MAX72XX.h>
#include <MD_Parola.h>
#include <SPI.h>

#define MAX_DEVICES 4  // Number of 8x8 matrices you have
#define CLK_PIN 14     // D5
#define DATA_PIN 13    // D7
#define CS_PIN 15      // D8

MD_Parola display = MD_Parola(MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

const char* message = "Hello, World!";

void setup() {
  display.begin();
  display.setIntensity(5);  // Set brightness level (0-15)
  display.displayText(message, PA_CENTER, 100, 50, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  if (display.displayAnimate()) {
    display.displayReset();
  }
}
