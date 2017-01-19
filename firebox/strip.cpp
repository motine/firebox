#include "strip.h"

Adafruit_NeoPixel strip = Adafruit_NeoPixel(STRIP_LED_COUNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);

void setupStrip() {
  strip.begin();
  strip.setBrightness(255); // be careful to not overload the arduino
  clearStrip();
}

void clearStrip() {
  strip.clear();
  strip.show();
}

void fillStrip(uint32_t color) {
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void fillLeftStrip(uint32_t color) {
  strip.clear();
  for (int i = 0; i < STRIP_LED_COUNT/2; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void fillRightStrip(uint32_t color) {
  strip.clear();
  for (int i = STRIP_LED_COUNT/2; i < STRIP_LED_COUNT; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
