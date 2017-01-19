#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 7, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.clear();
  strip.setBrightness(255); // be careful to not overload the arduino
  strip.show();
  
  // for (int pin = 10; pin <= 13; pin++) { // LEDs
  //   pinMode(pin, OUTPUT);
  // }
  // pinMode(2, INPUT_PULLUP); // button
  //
  // // 3 .. 8 pad
  // pinMode(3, OUTPUT);
  // pinMode(4, OUTPUT);
  // pinMode(5, OUTPUT);
  // pinMode(6, INPUT);
  // pinMode(7, INPUT);
  // pinMode(8, INPUT);
}

// void fillStrip(uint32_t color) {
//   for (int i = 0; i < 16; i++) {
//     strip.setPixelColor(i, color);
//   }
//   strip.show();
// }
//
// int mode = 0;
// int blue_led_count = 0;
// unsigned long started_blinky;
// unsigned long started_siren;

void loop() {
  // if (mode == 0) { // nothing
  //   strip.clear();
  //   for (int pin = 10; pin <= 13; pin++) {
  //     digitalWrite(pin, LOW);
  //   }
  //
  //   int button = digitalRead(2);
  //   if (button == LOW) {
  //     mode = 1;
  //   }
  // }
  //
  // if (mode == 1) { // started
  //   uint32_t color = strip.Color(255, 0, 0);
  //   for (int i = 3; i < 13; i++) {
  //     strip.setPixelColor(i, color);
  //   }
  //   strip.show();
  //   digitalWrite(11, HIGH);
  //
  //   delay(200);
  //
  //   int button = digitalRead(2); // TODO read pad number 2
  //   if (button == LOW) {
  //     started_blinky = millis();
  //     mode = 2;
  //   }
  // }
  //
  // if (mode == 2) { // blinky LED
  //   uint32_t red = strip.Color(255, 0, 0);
  //   uint32_t blue = strip.Color(0, 0, 255);
  //   fillStrip(red);
  //   for (int i = 0; i < blue_led_count; i++) {
  //     strip.setPixelColor(i, blue);
  //     strip.setPixelColor(15-i, blue);
  //   }
  //   strip.show();
  //
  //   bool is_on = ((millis() - started_blinky) / 500) % 2 == 0;
  //   if (is_on) {
  //     digitalWrite(11, HIGH);
  //   } else {
  //     digitalWrite(11, LOW);
  //   }
  //
  //   delay(200);
  //   int button = digitalRead(2); // TODO read pad number *
  //   if (button == LOW) {
  //     blue_led_count++;
  //   }
  //   if (blue_led_count >= 8) {
  //     mode = 3;
  //   }
  // }
  // if (mode == 3) { // green everything
  //   fillStrip(strip.Color(0, 255, 0));
  //   delay(200);
  //   int button = digitalRead(2); // TODO read pad number #
  //   if (button == LOW) {
  //     mode = 4;
  //     started_siren = millis();
  //   }
  // }
  // if (mode == 4) { // siren
  //   bool is_on = ((millis() - started_blinky) / 300) % 2 == 0;
  //   uint32_t blue = strip.Color(0, 0, 255);
  //   uint32_t red = strip.Color(255, 0, 0);
  //   strip.clear();
  //   if (is_on) {
  //     for (int i = 0; i < 8; i++) {
  //       strip.setPixelColor(i, red);
  //     }
  //   } else {
  //     for (int i = 8; i < 16; i++) {
  //       strip.setPixelColor(i, blue);
  //     }
  //   }
  //   strip.show();
  // }

  // --- strip test
  uint32_t color = strip.Color(255, 0, 255);
  for (int i = 0; i < 8; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  
  // --- LEDs
  // for (int pin = 10; pin <= 13; pin++) {
  //   digitalWrite(pin, HIGH);
  // }

  // --- Button
  // int button = digitalRead(2);
  // if (button == LOW) {
  //   fillStrip(strip.Color(255, 0, 0));
  // } else {
  //   fillStrip(strip.Color(0, 255, 0));
  // }
  // --- pad
  // uint32_t green = strip.Color(0, 255, 0);
  // uint32_t red = strip.Color(255, 0, 0);
  // digitalWrite(3, HIGH);
  // digitalWrite(4, LOW);
  // digitalWrite(5, LOW);
  // int in1 = digitalRead(6);
  // int in2 = digitalRead(7);
  // int in3 = digitalRead(8);
  //
  // if (in1 == HIGH) {
  //   strip.setPixelColor(0, green);
  // } else {
  //   strip.setPixelColor(0, red);
  // }
  // strip.show();
}