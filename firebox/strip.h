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
void fillLeftStrip(uint32_t color);
void fillRightStrip(uint32_t color);
// r, g, b determines which color component should pulsate. Please pass 0 or 1.
void pulseMountain(unsigned long pulse_duration, unsigned long elapsed_ms, bool r, bool g, bool b);
void successFade(unsigned long duration, unsigned long elapsed_ms);
void glitter(unsigned long pulse_duration, unsigned long elapsed_ms, uint32_t color1, uint32_t color2);
// do the knight rider thing. this function uses delay to influence the decay.
void knightRider(unsigned long elapsed_ms);
void noiseStrip(unsigned int ms_delay);

#endif
