#ifndef SWITCHES_H
#define SWITCHES_H

#include <Arduino.h>

void setupSwitches();
bool startPressed();
bool isOnlyThisSwitchOn(byte switch_number);

#endif
