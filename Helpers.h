//Helpers.h
#ifndef Helpers_h
#define Helpers_h

#include <Arduino.h>

void stepDrive(int motor_pins[], int motor_step_num, bool high_activation);

int* stepMotor(int motor_pins[], int motor_step_num, int motor_total_step, int max_motor_step, bool motor_turn_right, bool high_activation, int step_amount, int motor_delay, int gamle_tid);


#endif