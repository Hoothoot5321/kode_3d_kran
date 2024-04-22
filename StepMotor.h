//StepMotor.h
#ifndef StepMotor_h
#define StepMotor_h

#include <Arduino.h>
//Laver en template for StepMotor klassen.
class StepMotor {
private:
  int motor_pins[4];
  int step_num;
  int step_total;
  int step_max_total;
  int motor_delay_ms;
  int old_time = 0;
  bool turn_right;
  bool high_activation;
public:
  StepMotor(int motor_pins2[], int step_num2, int step_total2, int step_max_total2, int motor_delay2, bool turn_right2, bool high_activation2);
  void driveMotor(int step_amount);
  void turnLeft();
  void turnRight();
};

#endif