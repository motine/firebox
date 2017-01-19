#ifndef KEYS_H
#define KEYS_H

#include <Arduino.h>
#include <Keypad.h>

extern Keypad keypad;

#define NONE_KEY 20
#define STAR_KEY 21
#define HASH_KEY 22

// returns NO_KEY, STAR_KEY, HASH_KEY or a number from 0 to 9
// only the first key down is considered
byte keyPressed();


#endif
