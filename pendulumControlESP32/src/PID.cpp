#include "PID.h"

PID::PID(float kp, float ki, float kd) : kp(kp), ki(ki), kd(kd), previous_error(0), integral(0) {}

float PID::calculate(float setpoint, float measured_value) {
    float error = setpoint - measured_value;
    integral += error;
    float derivative = error - previous_error;
    previous_error = error;
    return kp * error + ki * integral + kd * derivative;
}