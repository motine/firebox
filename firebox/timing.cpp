#include "timing.h"

unsigned long lastTime;

void saveTime() {
  lastTime = millis();
}

unsigned long millisSince() {
  return millis() - lastTime;
}

bool alternatingState(int phase_duration) {
  return (millisSince() / phase_duration) % 2 == 0;
}
