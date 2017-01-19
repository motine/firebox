#include "keys.h"

const byte rows = 4; // four rows
const byte cols = 3; // three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[rows] = {4, 3, 5, 6};
byte colPins[cols] = {0, 1, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

byte keyPressed() {
  keypad.getKeys();
  if ((keypad.key[0].kstate != RELEASED) && (keypad.key[0].kstate != IDLE)) { // we have a key
    switch (keypad.key[0].kchar) {
      case NO_KEY: return NONE_KEY;
      case '0': return 0;
      case '1': return 1;
      case '2': return 2;
      case '3': return 3;
      case '4': return 4;
      case '5': return 5;
      case '6': return 6;
      case '7': return 7;
      case '8': return 8;
      case '9': return 9;
      case '*': return STAR_KEY;
      case '#': return HASH_KEY;
    }
  }
  return NONE_KEY;
}

// keypad tests
// char key = keypad.getKey();
// uint32_t red = strip.Color(255, 0, 0);
// strip.clear();
// if (key != NO_KEY){
//   switch (key) {
//     case '1': strip.setPixelColor(1, red); break;
//     case '2': strip.setPixelColor(2, red); break;
//     case '3': strip.setPixelColor(3, red); break;
//     case '4': strip.setPixelColor(4, red); break;
//     case '5': strip.setPixelColor(5, red); break;
//     case '6': strip.setPixelColor(6, red); break;
//     case '7': strip.setPixelColor(7, red); break;
//     case '8': strip.setPixelColor(8, red); break;
//     case '9': strip.setPixelColor(9, red); break;
//     case '#': strip.setPixelColor(10, red); break;
//     case '0': strip.setPixelColor(11, red); break;
//     case '*': strip.setPixelColor(12, red); break;
//   }
// }
// strip.show();
