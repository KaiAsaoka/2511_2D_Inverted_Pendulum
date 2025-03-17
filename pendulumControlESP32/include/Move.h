#ifndef Move_H
#define Move_H

#include <Encoder.h>
#include <Driver.h>

class Move {
public:
    Move(Encoder ENC1, Encoder ENC2, Driver DVR1, Driver DVR2);

    float move(int speed, int direction);

    float returnPos();

    float returnVel();

    


private:
    Encoder ENC1;
    Encoder ENC2;
    Driver DVR1;
    Driver DVR2;
    float sumAngle1;
    float sumAngle2;
    float fullRot1;
    float fullRot2;
    float xPos;
    float yPos;

};

#endif // Driver_H