#include "Encoder.h"
#include <Arduino.h>
#include <SPI.h>

Encoder::Encoder(int miso, int clk, int cs, int mosi) : miso(miso), clk(clk), cs(cs), mosi(mosi) {}

void Encoder::begin() {  
  // Configure encoder
  pinMode(cs, OUTPUT);
  digitalWrite(cs, HIGH);  // Deselect encoder by default
  SPI.begin(clk, miso, mosi, cs);
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  Serial.println("AS5147 SPI Encoder Initialized");
}


float Encoder::readAngle() {
  // For AS5147 the command frame is 16 bits:
  // Bit 15: Parity bit (even parity).
  // Bit 14: R/W flag (1 for read).
  // Bits 13:0: Register address (0x3FFF for the angle register).
 
  uint16_t response;
  // Begin SPI transaction
  digitalWrite(cs, LOW);
  
  // printBinary16(command);
  // Send command word; using two-step transfer is possible:
  
  //Serial.print("Command: 0x");
  //Serial.println(command, HEX);
  // A dummy transfer to read back the response:
  response = SPI.transfer16(0x3FFF);
  
  digitalWrite(cs, HIGH);

  float angle = float(response & 0x3FFF) / 16384.00 * 360.00;

  return angle;
}