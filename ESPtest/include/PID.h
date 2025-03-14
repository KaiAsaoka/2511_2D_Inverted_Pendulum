#ifndef PID_H
#define PID_H

class PID {
public:
    PID(float kp, float ki, float kd);
    float calculate(float setpoint, float measured_value);

private:
    float kp;
    float ki;
    float kd;
    float previous_error;
    float integral;
};

#endif // PID_H