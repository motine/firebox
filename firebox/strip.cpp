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

void pulseMountain(unsigned long pulse_duration, unsigned long elapsed_ms) {
  uint32_t color;
  double pos_in_pulse = (elapsed_ms % pulse_duration) / (double)pulse_duration; // 0.0 .. 1.0
  double intensity = sin(pos_in_pulse * PI); // 0.0 .. 1.0 .. 0.0
  double mountainFactor; // factor per LED, so we have the inner ones brigther than the ones on the edge
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    mountainFactor = 0.1 + 0.9 * sin((i * PI) / (STRIP_LED_COUNT-1));
    color = strip.Color(intensity * mountainFactor * 255, 0, 0);
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void successFade(unsigned long duration, unsigned long elapsed_ms) {
  uint32_t color;
  if (elapsed_ms > duration)
    return;
  double pos = elapsed_ms / (double)duration; // 0.0 .. 1.0
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    color = strip.Color(max(0, cos(pos * PI) * 255), sin(pos * PI) * 255, 0);
    strip.setPixelColor(i, color);
  }
  strip.show();
}
