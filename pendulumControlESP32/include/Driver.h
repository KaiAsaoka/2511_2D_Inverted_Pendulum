#ifndef Driver_H
#define Driver_H

class Driver {
public:
    Driver(int PWM, int DIR);
    void begin();
    float move(int speed, int direction);

private:
    float PWM;
    float DIR;
    float speed;
    float direction;
};

#endif // Driver_H