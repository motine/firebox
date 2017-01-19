#include "timing.h"

unsigned long lastTime;

void saveTime() {
  lastTime = millis();
}

unsigned long millisSince() {
  return millis() - lastTime;
}
