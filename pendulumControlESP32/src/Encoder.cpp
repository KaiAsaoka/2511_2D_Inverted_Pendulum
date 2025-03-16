#include "Encoder.h"
#include <Arduino.h>
#include <SPI.h>

Encoder::Encoder(int MISO, int CLK, int CS, int MOSI) : MISO(MISO), CLK(CLK), CS(CS), MOSI(MOSI) {}

void Encoder::begin() {  
  // Configure encoder
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);  // Deselect encoder by default
  SPI.begin(CLK, MISO, MOSI, CS);
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  Serial.println("AS5147 SPI Encoder Initialized");
}


float Encoder::readAngle() {
  // Reads encoder angle and outputs in degrees
  uint16_t response;
  digitalWrite(CS, LOW);
  response = SPI.transfer16(0x3FFF);
  digitalWrite(CS, HIGH);
  float angle = float(response & 0x3FFF) / 16384.00 * 360.00;
  return angle;
}