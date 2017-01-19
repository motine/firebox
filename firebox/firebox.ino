#include <Adafruit_NeoPixel.h>
#include "strip.h"
#include "leds.h"
#include "switches.h"
#include "timing.h"
#include "keys.h"

#define MODE_IDLE 0
#define MODE_ALARM 1
#define MODE_BURNING 2
#define MODE_EXTINGUISHED 3

#define ALARM_DURATION 5000 // ms
#define ALARM_PHASE_DURATION 250 // ms, how fast does it change between red and blue
#define EXTINGUISHED_DURATION 5000 // ms

byte mode = MODE_IDLE;

void setup() {
  setupLEDs();
  setupStrip();
  setupSwitches();
  
  randomSeed(analogRead(7));
  setIdle();
}

void setIdle() {
  mode = MODE_IDLE;
  clearStrip();
  setHomeLED();
  saveTime();
}

void modeIdle() {
  if (startPressed()) {
    setAlarm();
  }
  handleKeypad();
}

void handleKeypad() {
  switch (keyPressed()) {
    case NONE_KEY: clearStrip(); return;
    case 1: fillStrip(strip.Color(255, 0, 0)); return;
    case 2: fillStrip(strip.Color(0, 255, 0)); return;
    case 3: fillStrip(strip.Color(0, 0, 255)); return;
    case 4: pulseMountain(500, millisSince(), 1, 1, 1); return;
    case 5: pulseMountain(1000, millisSince(), 1, 1, 0); return;
    case 6: pulseMountain(200, millisSince(), 0, 1, 1); return;
    case 7: glitter(200, millisSince(), strip.Color(255, 0, 0), strip.Color(255, 255, 255)); return;
    case 8: glitter(300, millisSince(), strip.Color(255, 0, 0), strip.Color(0, 0, 255)); return;
    case 9: glitter(500, millisSince(), strip.Color(0, 0, 0), strip.Color(0, 0, 255)); return;
    case 0:
      if (alternatingState(ALARM_PHASE_DURATION)) {
        fillLeftStrip(strip.Color(255, 0, 0));
      } else {
        fillRightStrip(strip.Color(0, 0, 255));
      }
      return;
    case STAR_KEY: knightRider(millisSince()); return;
    case HASH_KEY: noiseStrip(200); return;
  }
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
  pulseMountain(1000, millisSince(), 1, 0, 0);
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