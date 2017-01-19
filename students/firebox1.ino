#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 8, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(255); // be careful to not overload the arduino
  strip.show();
  for (int pin = 2; pin <= 6; pin++) { // switches and 6 is button
    pinMode(pin, INPUT_PULLUP);
  }
  for (int pin = 9; pin <= 13; pin++) { // LEDs and 13 is the green one
    pinMode(pin, OUTPUT);
  }
  digitalWrite(13, HIGH);
}

void fillStrip(uint32_t color) {
  for (int i = 0; i < 16; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
void fillLeftStrip(uint32_t color) {
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}
void fillRightStrip(uint32_t color) {
  for (int i = 8; i < 16; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

int mode = 0;
unsigned long start_alarm_wait;
unsigned long start_alarm_triggered;

void loop() {
  if (mode == 0) { // not started yet
    strip.clear();
    strip.show();
    if (digitalRead(6) == LOW) {
      mode = 1;
      start_alarm_wait = millis();
    }
  }
  
  if (mode == 1) { // wait for alarm
    fillStrip(strip.Color(255, 255, 255));
    if (millis() - start_alarm_wait > 2000) { // TODO make random wait
      mode = 2;
      start_alarm_triggered = millis();
    }
  }
  
  if (mode == 2) { // alarm triggered
    strip.clear();
    bool show_left = ((millis() - start_alarm_triggered) / 500) % 2 == 0;
    if (show_left) {
      fillLeftStrip(strip.Color(255, 0, 0));
    } else {
      fillRightStrip(strip.Color(255, 0, 0));
    }
    digitalWrite(10, HIGH); // TODO make random LED
    int pin1 = digitalRead(2);
    int pin2 = digitalRead(3);
    int pin3 = digitalRead(4);
    int pin4 = digitalRead(5);
    if ((pin1 == HIGH) && (pin2 == LOW) && (pin3 == HIGH) && (pin4 == HIGH)) {
      mode = 3;
    }
  }
  if (mode == 3) { // correct location chosen
    fillStrip(strip.Color(0, 255, 0));
  }

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