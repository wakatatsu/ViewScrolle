#include "steppermotor.h"
StepperMotor *motor;
String str_buf;
int count = 0;


void readString() {
  while(1) {
    if(Serial.available() > 0) {
      str_buf = Serial.readStringUntil('\0');
      break;
    }
  }
}

void setup() {
  Serial.begin(9600);
  motor = new StepperMotor();
  motor -> initPin();
}

void loop() {
  Serial.print("comand:");
  readString();
  Serial.println(str_buf);
  motor -> move(200);

}
