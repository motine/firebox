#ifndef STRIP_H
#define STRIP_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define STRIP_LED_COUNT 16
#define STRIP_PIN 7

extern Adafruit_NeoPixel strip;

void setupStrip();
void clearStrip();
void fillStrip(uint32_t color);

#endif