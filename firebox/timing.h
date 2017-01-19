#ifndef TIMING_H
#define TIMING_H

#include <Arduino.h>

// resets the time for bang!
void saveTime();
// returns number of milliseconds since bang!
unsigned long millisSince();
// returns true if an even number of phases with the given number have passed
bool alternatingState(int phase_duration);

#endif
