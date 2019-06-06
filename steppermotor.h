#ifndef STEPPERMOTOR_H_INCLUDE
#define STEPPERMOTOR_H_INCLUDE

#include "Arduino.h"

#define DEFALT_CYCLE_VALUE 1000
#define CW HIGH
#define CCW LOW

class StepperMotor {
  public:
    StepperMotor();
    StepperMotor(int stepPin, int dirPin);
    ~StepperMotor();
    void initPin();
    void move(int step);
    void move_Microseconds(int micro_sec, int step);
    void move_RPM(int rpm, int step);
    void setDirection(uint8_t dir);
    void inverse();

  private:
    const int _step;
    const int _dir;
    uint8_t currentDir;
};
#endif
