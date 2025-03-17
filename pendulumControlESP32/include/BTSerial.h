#ifndef BTSERIAL_H
#define BTSERIAL_H

#include <BluetoothSerial.h>
#include <Arduino.h> // For String type

class BTSerial {
public:
    BTSerial();
    bool begin(const char* deviceName);
    void sendData(const String &data);
    String readData();

private:
    BluetoothSerial SerialBT;
};

#endif // BTSERIAL_H