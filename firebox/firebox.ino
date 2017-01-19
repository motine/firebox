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
#define EXTINGUISHED_DURATION 5000 // ms

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
  if (isOnlyThisSwitchOn(fire_number)) {
    setExtingushed();
  }
}

void setExtingushed() {
  mode = MODE_EXTINGUISHED;
  clearFireLEDs();
  saveTime();
}

void modeExtinguished() {
  unsigned long ms = millisSince();
  successFade(EXTINGUISHED_DURATION, ms);
  if (ms > EXTINGUISHED_DURATION) {
    setIdle();
  }
}

void debug_switch_states() {
  // test switch states
  uint32_t off_color = strip.Color(0, 0, 0);
  uint32_t on_color = strip.Color(255, 255, 0);
  strip.clear();
  for (int pin = 8; pin <= 11; pin++) {
    int pin_state = digitalRead(pin);
    if (pin_state == LOW) {
      strip.setPixelColor(pin, off_color);
    } else {
      strip.setPixelColor(pin, on_color);
    }
    strip.show();
  }  
}

void loop() {
  switch (mode) {
    case MODE_IDLE: modeIdle(); break;
    case MODE_ALARM: modeAlarm(); break;
    case MODE_BURNING: modeBurning(); break;
    case MODE_EXTINGUISHED: modeExtinguished(); break;
  }
  // debug_switch_states();
}