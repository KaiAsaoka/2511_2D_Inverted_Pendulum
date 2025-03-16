#ifndef Encoder_H
#define Encoder_H

class Encoder {
public:
    Encoder(int miso, int clk, int cs, int mosi);
    void begin();
    float readAngle();

private:
    float miso;
    float clk;
    float cs;
    float mosi;
};

#endif // Encoder_H