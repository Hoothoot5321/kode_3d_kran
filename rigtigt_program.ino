//Initialisere program pins. Referer til eldiagram.
#include "StepMotor.h"
#include "Globals.h"
#include "HandleInput.h"
//Pins på arduino som er forbundet til motorerne
//X venstre motor
int x_motor_pins[] = { 2, 3, 4, 5 };
//Y Højre motor
int y_motor_pins[] = { 6, 7, 8, 9 };
//Z midter motor
int z_motor_pins[] = { 10, 11, 12, 13 };



//Step nummeret der kontrollere hvad for en pin skal være aktiv for motorerne.
int x_step_num = 0;
int y_step_num = 0;
int z_step_num = 0;

//Totale step der tæller hvor mange steps kran hovedet er fra siden.
int x_step_total = 0;
int y_step_total = 0;
int z_step_total = 0;

//Variabler der bestemmer hvor meget de forskellige motorer kan dreje
int x_max_total = 500;
int y_max_total = 500;
int z_max_total = 500;

//Variabler der bestemmer hvor lang pause der skal være mellem hvert motor step. Lavere værdi øger hastigheden af motoren, men for lav værdi gør at motoren ikke drejer.
int x_motor_delay_ms = 10;
int y_motor_delay_ms = 10;
int z_motor_delay_ms = 10;

//Variabler der styrer motorernes omdrejnings retninger.
bool x_turn_right = true;
bool y_turn_right = true;
bool z_turn_right = true;

//Variabler der styrer activation
bool x_high_activation = true;
bool y_high_activation = true;
bool z_high_activation = true;

//Initialiserer step motorer objekter.
StepMotor x_motor(x_motor_pins,x_step_num,x_step_total,x_max_total,x_motor_delay_ms,x_turn_right,x_high_activation);
StepMotor y_motor(y_motor_pins,y_step_num,y_step_total,y_max_total,y_motor_delay_ms,y_turn_right,y_high_activation);
StepMotor z_motor(z_motor_pins,z_step_num,z_step_total,z_max_total,z_motor_delay_ms,z_turn_right,z_high_activation);


void setup() {
  //Sætter alle pins til output.
  for (int pin_num = 0; pin_num < 4; pin_num++) {
    pinMode(x_motor_pins[pin_num], OUTPUT);
    pinMode(y_motor_pins[pin_num], OUTPUT);
    pinMode(z_motor_pins[pin_num], OUTPUT);
    if (pin_num < 2) {
      pinMode(magnet_pins[pin_num], OUTPUT);
    }
  }
  Serial.begin(9600);
}

void loop() {
  totale_millis = millis();

  int input_char = Serial.read();
  HandleInput(input_char,x_motor,y_motor,z_motor);
};

