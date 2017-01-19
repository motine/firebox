#include <Adafruit_NeoPixel.h>
#include "strip.h"
#include "leds.h"
#include "switches.h"

#define MODE_IDLE 0
#define MODE_ALARM 1
#define MODE_BURNING 2
#define MODE_EXTINGUISHED 3

byte mode = MODE_IDLE;

void setup() {
  setupLEDs();
  setupStrip();
  setupSwitches();
  // for (int pin = 2; pin <= 6; pin++) { // switches and 6 is button
  //   pinMode(pin, INPUT_PULLUP);
  // }
  // for (int pin = 9; pin <= 13; pin++) { // LEDs and 13 is the green one
  //   pinMode(pin, OUTPUT);
  // }
  // digitalWrite(13, HIGH);
}

void mode_idle() {
  clearStrip();
  setHomeLED();
  if (startPressed()) {
    mode = MODE_ALARM;
  }
}

void mode_alarm() {
  
}
void mode_burning() {
}
void mode_extinguished() {
}

void loop() {
  switch (mode) {
    case MODE_IDLE: mode_idle();
    case MODE_ALARM: mode_alarm();
    case MODE_BURNING: mode_burning();
    case MODE_EXTINGUISHED: mode_extinguished();
  }
  // uint32_t no_color = strip.Color(0, 255, 0);
  // uint32_t color = strip.Color(255, 0, 255);
  // fillStrip(no_color);
  // --- switch test
  // for (int pin = 2; pin <= 6; pin++) {
  //   int pin_state = digitalRead(pin);
  //   if (pin_state) {
  //     strip.setPixelColor(pin, no_color);
  //   } else {
  //     strip.setPixelColor(pin, color);
  //   }
  // }
  // strip.show();
  // --- LEDs
  // for (int pin = 9; pin <= 13; pin++) {
  //   digitalWrite(pin, HIGH);
  // }
}