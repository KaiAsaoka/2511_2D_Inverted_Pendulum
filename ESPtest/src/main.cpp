#include <Arduino.h>
#define LEDB 2
#define LEDR 8

void setup() {
  // Set pin mode
  pinMode(LEDB, OUTPUT);
  pinMode(LEDR, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(LEDB, brightness);
    analogWrite(LEDR, 255 - brightness);
    delay(2);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(LEDB, brightness);
    analogWrite(LEDR, 255 - brightness);
    delay(2);
  }
}