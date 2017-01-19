#include "switches.h"

void setupSwitches() {
  for (int i = 8; i <= 12; i++)
    pinMode(i, INPUT_PULLUP);
}

bool startPressed() {
  return digitalRead(12) == LOW;
}

bool isCorrectFire() {
  // for (int i = 8; i <= 12; i++) {
  //   if (digitalRead(i) == LOW)
  // }
  // TODO
}
