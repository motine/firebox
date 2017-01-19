#ifndef LEDS_H
#define LEDS_H

#include <Arduino.h>

void setupLEDs();

void clearHomeLED();
void setHomeLED();
void clearFireLEDs();
void setFireLED(byte number);

#endif
