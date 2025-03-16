#include <Arduino.h>
#include <SPI.h>

// Define encoder SPI pins
#define ENC_MISO 12    // Encoder data output (MISO)
#define ENC_CLK  14    // SPI clock (SCK)
#define ENC_CS   15    // Chip Select (active LOW)
#define ENC_MOSI 13    // MOSI pin for encoder communication


void printBinary16(uint16_t n) {
  for (int i = 15; i >= 0; i--) {
    Serial.print((n >> i) & 1);
  }
  Serial.println();
}

unsigned int readAngle() {
  // For AS5147 the command frame is 16 bits:
  // Bit 15: Parity bit (even parity).
  // Bit 14: R/W flag (1 for read).
  // Bits 13:0: Register address (0x3FFF for the angle register).
 
  uint16_t response;
  // Begin SPI transaction
  digitalWrite(ENC_CS, LOW);
  
  // printBinary16(command);
  // Send command word; using two-step transfer is possible:
  
  //Serial.print("Command: 0x");
  //Serial.println(command, HEX);
  // A dummy transfer to read back the response:
  response = SPI.transfer16(0x3FFF);
  
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
  float angle = float(readAngle()) / 16384.00 * 360.00;
  
  Serial.print("Angle: ");
  Serial.println(angle);

  delay(100);
}