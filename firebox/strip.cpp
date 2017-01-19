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

void pulseMountain(unsigned long pulse_duration, unsigned long elapsed_ms, bool r, bool g, bool b) {
  uint32_t color;
  double pos_in_pulse = (elapsed_ms % pulse_duration) / (double)pulse_duration; // 0.0 .. 1.0
  double intensity = sin(pos_in_pulse * PI); // 0.0 .. 1.0 .. 0.0
  double mountainFactor; // factor per LED, so we have the inner ones brigther than the ones on the edge
  uint8_t component;
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    mountainFactor = 0.1 + 0.9 * sin((i * PI) / (STRIP_LED_COUNT-1));
    component = intensity * mountainFactor * 255;
    color = strip.Color(r * component, g * component, b * component);
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

void glitter(unsigned long pulse_duration, unsigned long elapsed_ms, uint32_t color1, uint32_t color2) {
  byte add = (elapsed_ms / pulse_duration);
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    if ((i + add) % 2 == 0) {
      strip.setPixelColor(i, color1);
    } else {
      strip.setPixelColor(i, color2);
    }
  }
  strip.show();
}

uint8_t knight_rider_strip_value[STRIP_LED_COUNT]; // each value from 0..255
void knightRider(unsigned long elapsed_ms) {
  unsigned long stepDuration = 150;
  int decayValue = 20;

  // decay strip_value
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    // knight_rider_strip_value[i] = max(0, (int)knight_rider_strip_value[i] - decayValue);
    knight_rider_strip_value[i] = max(0, knight_rider_strip_value[i] - decayValue);
  }
  // add full color dot to knight_rider_strip_value
  int pos = (elapsed_ms / stepDuration) % (2 * STRIP_LED_COUNT - 2);
  if (pos < STRIP_LED_COUNT) { // we are in the first half
    knight_rider_strip_value[pos] = 255;
  } else { // we are in the second half
    knight_rider_strip_value[2 * STRIP_LED_COUNT - pos - 2] = 255;
  }
  // draw strip
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(knight_rider_strip_value[i], 0, 0));
  }
  strip.show();
  delay(50);
}

void noiseStrip(unsigned int ms_delay) {
  for (int i = 0; i < STRIP_LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(random(255), random(255), random(255)));
  }
  strip.show();
  delay(ms_delay);
}
