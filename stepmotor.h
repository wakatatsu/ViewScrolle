#ifndef STEPMOTOR_H_INCLUDE
#define STEPMOTOR_H_INCLUDE

#include "Arduino.h"

#define HALF_CYCLE_VALUE 100

class StepMotor {
  public:
    StepMotor();
    StepMotor(int stepPin, int dirPin);
    ~StepMotor();
    void initPin();
    void inputComand();
    void run();
  private:
    const int _step;
    const int _dir;
    void move();
};
#endif
