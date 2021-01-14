
#ifndef robot_5sens_h
#define robot_5sens_h
#include <Arduino.h> //libreria de arduino

#include "config.h"
#include "cont_vel.h"

extern int sensor1;
extern int sensor2;
extern int sensor3;
extern int sensor4;
extern int sensor5;

extern bool obs_izq;
extern bool obs_dcha;
extern bool obs_cent;

extern int incomingByte;
extern bool dato_sensor;

void sensores_arduino();

#endif
