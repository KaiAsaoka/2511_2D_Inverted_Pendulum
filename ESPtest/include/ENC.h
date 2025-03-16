#ifndef ENC_H
#define ENC_H

class ENC {
public:
    ENC(int miso, int clk, int cs, int mosi);
    float readAngle();

private:
    float miso;
    float clk;
    float cs;
    float mosi;
};

#endif // ENC_H