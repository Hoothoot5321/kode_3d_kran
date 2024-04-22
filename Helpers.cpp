#include "Arduino.h"
//Helpers.cpp
//Fil der indeholder hjælpe funktioner
#include "Helpers.h"
#include "Globals.h"

//Sender strøm ud til step driver. Boolean der bestemmer om aktivations pin skal være høj eller low, afhængig af stepper driver.
void stepDrive(int motor_pins[], int motor_step_num, bool high_activation) {

  int activation_num;
  int passive_num;
  //Checkker om stepper driveren aktiveres på høj eller lav.
  if (high_activation) {
    activation_num = HIGH;
    passive_num = LOW;
  } else {
    activation_num = LOW;
    passive_num = HIGH;
  }
  for (int pin_num = 0; pin_num < 4; pin_num++) {
    //Aktivere motor pins i den korrekte rækkefølge.
    if (pin_num == motor_step_num) {
      digitalWrite(motor_pins[pin_num], activation_num);
    } else {
      digitalWrite(motor_pins[pin_num], passive_num);
    }
  }
};

int* stepMotor(int motor_pins[], int motor_step_num, int motor_total_step, int max_motor_step, bool motor_turn_right, bool high_activation, int step_amount, int motor_delay, int gamle_tid) {
  static int return_vals[3];
  bool pause = false;
  gamle_tid = totale_millis;
  for (int step_num = 0; step_num < step_amount; step_num++) {
    if (!pause) {
      //Checkker om motoren har overskredet dens totale step.
      if (motor_total_step < max_motor_step && motor_total_step > 0) {
        //Aktivere stepper driveren som aktiverer motoren
        stepDrive(motor_pins, motor_step_num, true);
        //Chekker rentningen motoren drejer.
        if (motor_turn_right) {
          motor_step_num += 1;
          if (motor_step_num > max_step) {
            motor_step_num = 0;
          }
          motor_total_step += 1;
        } else {
          motor_step_num -= 1;
          if (motor_step_num < max_step) {
            motor_step_num = max_step;
          }
          motor_total_step -= 1;
        }
      }
    }
    //Pauser motoren den tid som der er sat delay på.
    if ((totale_millis - gamle_tid) < motor_delay) {
      pause = true;
      step_num -= 1;
    } else {
      pause = false;
      gamle_tid = totale_millis;
    }
  }
  return_vals[0] = motor_step_num;
  return_vals[1] = motor_total_step;
  return_vals[2] = gamle_tid;
  return return_vals;
};

