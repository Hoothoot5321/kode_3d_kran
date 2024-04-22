//Globals.cpp
#include "Arduino.h"

//Fil der indeholder variabler der bliver brugt af flere filer.
#include "Globals.h"

//Max motr steps, afhængig af hvor mange faser motoren har. I dette tilfælde har alle tre motorer tre faser.
int max_step = 3;

//Totale milisekunder siden at programmet startede.
int totale_millis = millis();

//Pins som er forbundet til magneten
int magnet_pins[] = { 22, 23 };

//Variabler der tænder og slukker for kranen og elektro magneten.
bool program_on = false;
bool magnet_on = false;

void toggleElektroMagnet() {
  magnet_on = !magnet_on;
  if (magnet_on) {
    digitalWrite(magnet_pins[0], HIGH);
  } else {
    digitalWrite(magnet_pins[0], LOW);
  }
  digitalWrite(magnet_pins[1], LOW);
}
