#include "switches.h"

void setupSwitches() {
  for (int i = 8; i <= 12; i++)
    pinMode(i, INPUT_PULLUP);
}

bool startPressed() {
  return digitalRead(12) == LOW;
}

bool isOnlyThisSwitchOn(byte switch_number) {
  for (int pin = 8; pin <= 11; pin++) {
    byte cur_no = pin - 8;
    if (cur_no == switch_number) {  // this one should be off
      if (digitalRead(pin) == HIGH) // but it is on
        return false;
    } else { // this one should be off
      if (digitalRead(pin) == LOW) // but it is on
        return false;
    }
  }
  return true;
}
