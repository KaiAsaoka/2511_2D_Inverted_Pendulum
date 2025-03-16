#include "Driver.h"
#include <Arduino.h>
#include <SPI.h>

Driver::Driver(int PWM, int DIR) : PWM(PWM), DIR(DIR) {}

void Driver::begin() {  
  // Set pin mode
  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);
}


float Driver::move(int speed, int direction) {
  // Reads encoder angle and outputs in degrees
  digitalWrite(DIR, direction);
  analogWrite(PWM, speed);
  return speed, direction;
}