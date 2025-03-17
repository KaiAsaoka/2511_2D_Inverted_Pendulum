#include "BTSerial.h"

BTSerial::BTSerial() {}

bool BTSerial::begin(const char* deviceName) {
    // Initialize Bluetooth with the provided device name.
    // Returns true if Bluetooth was successfully started, false otherwise.
    if (!SerialBT.begin(deviceName)) {
        return false;
    }
    return true;
}

void BTSerial::sendData(const String &data) {
    // Send data along with a newline character.
    SerialBT.println(data);
}

String BTSerial::readData() {
    String received = "";
    while (SerialBT.available()) {
        received += char(SerialBT.read());
    }
    return received;
}