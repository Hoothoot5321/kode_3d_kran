//StepMotor.cpp
//Fil der indeholder en klasse for step motoren.
#include "StepMotor.h"
#include "Helpers.h"
//Konstruktor for klassen.
StepMotor::StepMotor(int motor_pins2[4], int step_num2, int step_total2, int step_max_total2, int motor_delay2, bool turn_right2, bool high_activation2) {
  motor_pins[0] = motor_pins2[0];
  motor_pins[1] = motor_pins2[1];
  motor_pins[2] = motor_pins2[2];
  motor_pins[3] = motor_pins2[3];
  step_num = step_num2;
  step_total = step_total2;
  step_max_total = step_max_total2;
  motor_delay_ms = motor_delay2;
  turn_right = turn_right2;
  high_activation = high_activation2;
};
//Metode til at kører motoren.
void StepMotor::driveMotor(int step_amount) {
  int *return_val = stepMotor(motor_pins, step_num, step_total, step_max_total, turn_right, high_activation, step_amount, motor_delay_ms, old_time);
  //Opdatere værdien for step nummer og totale steps.
  step_num = return_val[0];
  step_total = return_val[1];
  old_time = return_val[2];
};

void StepMotor::turnLeft() {
  turn_right = false;
}

void StepMotor::turnRight() {
  turn_right = true;
}