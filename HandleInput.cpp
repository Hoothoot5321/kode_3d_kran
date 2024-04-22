//HandleInput.cpp
#include "Arduino.h"

//Fil der indeholder variabler der bliver brugt af flere filer.
#include "HandleInput.h"
#include "Globals.h"b
#include "StepMotor.h"

void HandleInput(int in_char, StepMotor motor_x, StepMotor motor_y, StepMotor motor_z) {
  if (in_char == 'b') {
    program_on = !program_on;
  }
  if (program_on) {
    switch (in_char) {
      case 'a':
        motor_x.turnRight();
        motor_y.turnRight();
        motor_x.driveMotor(25);
        motor_y.driveMotor(25);
        break;
      case 'd':
      
        motor_x.turnLeft();
        motor_y.turnLeft();
        motor_x.driveMotor(25);
        motor_y.driveMotor(25);
        break;
      case 'w':
        motor_x.turnRight();
        motor_y.turnLeft();
        motor_x.driveMotor(25);
        motor_y.driveMotor(25);
        break;
      case 's':
        motor_x.turnLeft();
        motor_y.turnRight();
        motor_x.driveMotor(25);
        motor_y.driveMotor(25);
        break;
      case 'm':
        toggleElektroMagnet();
        break;
      case 'j':
        motor_z.turnRight();
        motor_z.driveMotor(50);
        break;
      case 'k':
        motor_z.turnLeft();
        motor_z.driveMotor(50);
        break;
    }
  }
}