
#ifndef robot_5sens_h
#define robot_5sens_h
#include <Arduino.h> //libreria de arduino

#include "config.h"

extern int sensor1;
extern int sensor2;
extern int sensor3;
extern int sensor4;
extern int sensor5;

extern int incomingByte;
extern bool dato_sensor;

void sensores_arduino();

#endif
