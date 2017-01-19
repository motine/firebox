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
  randomSeed(analogRead(0));
  setupLEDs();
  setupStrip();
  setupSwitches();
  setIdle();
}

void setIdle() {
  mode = MODE_IDLE;
  clearStrip();
  setHomeLED();
  setBurning(); // TODO remove me
}

void modeIdle() {
  if (startPressed()) {
    setAlarm();
  }
  delay(100);
}

void setAlarm() {
  mode = MODE_ALARM;
  saveTime();
}

void modeAlarm() {
  if (millisSince() > ALARM_DURATION) {
    setBurning();
  }
  if (alternatingState(ALARM_PHASE_DURATION)) {
    fillLeftStrip(strip.Color(255, 0, 0));
  } else {
    fillRightStrip(strip.Color(0, 0, 255));
  }
}

byte fire_number;
void setBurning() {
  mode = MODE_BURNING;
  saveTime();
  fire_number = random(0, 3);;
  clearFireLEDs();
  setFireLED(fire_number);
}

void modeBurning() {
  pulseMountain(1000, millisSince());
}

void setExtingushed() {
  mode = MODE_BURNING;
  clearFireLEDs();
}
void modeExtinguished() {
}

void loop() {
  switch (mode) {
    case MODE_IDLE: modeIdle(); break;
    case MODE_ALARM: modeAlarm(); break;
    case MODE_BURNING: modeBurning(); break;
    case MODE_EXTINGUISHED: modeExtinguished(); break;
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