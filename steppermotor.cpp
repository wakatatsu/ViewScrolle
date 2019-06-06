#include "steppermotor.h"

StepperMotor::StepperMotor()
 : _step(3), _dir(4), currentDir(CW) {

}

StepperMotor::StepperMotor(int stepPin, int dirPin)
 : _step(stepPin), _dir(_dir), currentDir(CW) {

}

StepperMotor::~StepperMotor() {

}

void StepperMotor::initPin() {
  pinMode(_step, OUTPUT);
  pinMode(_dir, OUTPUT);
  digitalWrite(_dir, currentDir);
}

void StepperMotor::move(int step) {
  for(int i = 0; i < step; i++) {
    digitalWrite(_step, HIGH);
    delayMicroseconds(DEFALT_CYCLE_VALUE/2);
    digitalWrite(_step, LOW);
    delayMicroseconds(DEFALT_CYCLE_VALUE/2);
  }
}

//the unit of speed value is micro seconds
void StepperMotor::move_Microseconds(int micro_sec, int step) {
  for(int i = 0; i < step; i++) {
    digitalWrite(_step, HIGH);
    delayMicroseconds(micro_sec/2);
    digitalWrite(_step, LOW);
    delayMicroseconds(micro_sec/2);
  }
}

//the unit of speed value is RPM
void StepperMotor::move_RPM(int rpm, int step) {
  double micro_sec = 1.0/(rpm / 60.0) / 200.0 * pow(10, 6);
  move_Microseconds(micro_sec, step);
}

void StepperMotor::setDirection(uint8_t dir) {
  currentDir = dir;
  digitalWrite(_dir, currentDir);
}

void StepperMotor::inverse() {
  if(currentDir == CW) {
    currentDir = CCW;
  }
  else {
    currentDir = CW;
  }
  digitalWrite(_dir, currentDir);
}
