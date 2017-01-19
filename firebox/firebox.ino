#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 8, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(255); // be careful to not overload the arduino
  strip.show();
  // for (int pin = 2; pin <= 6; pin++) { // switches and 6 is button
  //   pinMode(pin, INPUT_PULLUP);
  // }
  // for (int pin = 9; pin <= 13; pin++) { // LEDs and 13 is the green one
  //   pinMode(pin, OUTPUT);
  // }
  // digitalWrite(13, HIGH);
}

void fillStrip(uint32_t color) {
  for (int i = 0; i < 16; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void loop() {
  // uint32_t no_color = strip.Color(0, 255, 0);
  // uint32_t color = strip.Color(255, 0, 255);
  
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