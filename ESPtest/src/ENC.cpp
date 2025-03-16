#include "ENC.h"
#include <Arduino.h>
#include <SPI.h>

ENC::ENC(int miso, int clk, int cs, int mosi) : miso(miso), clk(clk), cs(cs), mosi(mosi) {}

float ENC::readAngle() {
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
  
  // The AS5147 response should contain the 14-bit angle in its lower 14 bits.
  return response & 0x3FFF; // mask non output bits 0b0011 1111 1111 1111
}