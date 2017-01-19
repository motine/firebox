#include <Adafruit_NeoPixel.h>
#include "strip.h"
#include "leds.h"
#include "switches.h"
#include "timing.h"

#define MODE_IDLE 0
#define MODE_ALARM 1
#define MODE_BURNING 2
#define MODE_EXTINGUISHED 3

#define ALARM_DURATION 5000 // ms
#define ALARM_PHASE_DURATION 250 // ms, how fast does it change between red and blue

byte mode = MODE_IDLE;

void setup() {
  setupLEDs();
  setupStrip();
  setupSwitches();
}

void mode_idle() {
  clearStrip();
  setHomeLED();
  if (startPressed()) {
    mode = MODE_ALARM;
    saveTime();
  }
}

void mode_alarm() {
  if (millisSince() > ALARM_DURATION) {
    mode = MODE_BURNING;
  }
  if (alternatingState(ALARM_PHASE_DURATION)) {
    fillLeftStrip(strip.Color(255, 0, 0));
  } else {
    fillRightStrip(strip.Color(0, 0, 255));
  }
}

void mode_burning() {
  clearStrip();
}

void mode_extinguished() {
}

void loop() {
  switch (mode) {
    case MODE_IDLE: mode_idle(); break;
    case MODE_ALARM: mode_alarm(); break;
    case MODE_BURNING: mode_burning(); break;
    case MODE_EXTINGUISHED: mode_extinguished(); break;
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