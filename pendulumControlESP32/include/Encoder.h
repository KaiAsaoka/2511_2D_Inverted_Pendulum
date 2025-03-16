#ifndef Encoder_H
#define Encoder_H

class Encoder {
public:
    Encoder(int MISO, int CLK, int CS, int MOSI);
    void begin();
    float readAngle();

private:
    float MISO;
    float CLK;
    float CS;
    float MOSI;
};

#endif // Encoder_H