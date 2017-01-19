#include "leds.h"

void setupLEDs() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
}

void clearHomeLED() {
  digitalWrite(A4, LOW);
}

void setHomeLED() {
  digitalWrite(A4, HIGH);
}

void clearFireLEDs() {
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
}

void setFireLED(byte number) {
  switch (number) {
    case 0: digitalWrite(A0, HIGH); break;
    case 1: digitalWrite(A1, HIGH); break;
    case 2: digitalWrite(A2, HIGH); break;
    case 3: digitalWrite(A3, HIGH); break;
  }
}
