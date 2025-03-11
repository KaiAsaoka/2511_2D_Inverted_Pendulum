#include <Arduino.h>
#define LEDB 2
#define LEDR 8

void setup() {
  // Set pin mode
  pinMode(LEDB,OUTPUT);
  pinMode(LEDR,OUTPUT);
}

void loop() {
  delay(100);
// you can set the delay time by adjusting the parameter of delay();
  digitalWrite(LEDB,HIGH);
  digitalWrite(LEDR,LOW);
  delay(100);
  digitalWrite(LEDB,LOW);
  digitalWrite(LEDR,HIGH);
}