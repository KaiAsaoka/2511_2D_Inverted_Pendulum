#include <Arduino.h>
#include <SPI.h>

// Define encoder SPI pins
#define ENC_MISO 12    // Encoder data output (MISO)
#define ENC_CLK  14    // SPI clock (SCK)
#define ENC_CS   15    // Chip Select (active LOW)
#define ENC_MOSI 13    // MOSI pin for encoder communication

// Function to calculate even parity for the lower 15 bits of a 16-bit word.
uint8_t calcEvenParity(uint16_t data) {
  uint8_t parity = 0;
  // Calculate parity over bits 0 through 14 (don't include the parity bit itself)
  for (uint8_t i = 0; i < 15; i++) {
    if (data & (1 << i))
      parity++;
  }
  // Return 1 if the number of 1s is odd (so that setting the parity bit makes total even)
  return (parity & 1);
}

unsigned int readAngle() {
  // For AS5147 the command frame is 16 bits:
  // Bit 15: Parity bit (even parity).
  // Bit 14: R/W flag (1 for read).
  // Bits 13:0: Register address (0x3FFF for the angle register).
  uint16_t command = 0;
  command = (1 << 14) | (0x3FFF & 0x3FFF); // Set R/W bit and address
  
  // Calculate parity over lower 15 bits and set bit15 accordingly.
  if (calcEvenParity(command))
    command |= 0x8000;  // Set parity bit if needed. 1000 0000 0000 0000
  else
    command &= 0x7FFF;  // Ensure parity bit is clear otherwise. 0111 1111 1111 1111
  
  uint16_t response;
  // Begin SPI transaction
  digitalWrite(ENC_CS, LOW);
  
  // Send command word; using two-step transfer is possible:
  SPI.transfer16(command);
  //Serial.print("Command: 0x");
  //Serial.println(command, HEX);
  // A dummy transfer to read back the response:
  response = SPI.transfer16(0x0000);
  
  digitalWrite(ENC_CS, HIGH);
  
  // The AS5147 response should contain the 14-bit angle in its lower 14 bits.
  return response & 0x3FFF; // mask non output bits 0b0011 1111 1111 1111
}

void setup() {
  Serial.begin(115200);
  
  // Configure the chip select pin
  pinMode(ENC_CS, OUTPUT);
  digitalWrite(ENC_CS, HIGH);  // Deselect encoder by default
  
  // Begin SPI with custom pins:
  // On ESP32, SPI.begin(SCK, MISO, MOSI, SS);
  SPI.begin(ENC_CLK, ENC_MISO, ENC_MOSI, ENC_CS);
  
  // Setup SPI transaction parameters:
  // Adjust clock speed, bit order, and SPI mode as required by your encoder.
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  
  Serial.println("AS5147 SPI Encoder Example Started");
}

void loop() {
  // Read the 14-bit angle
  unsigned int angle = readAngle();
  
  Serial.print("Angle: ");
  Serial.println(angle);


  
  delay(100);
}