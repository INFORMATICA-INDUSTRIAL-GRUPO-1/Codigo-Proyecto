
#ifndef robot_2sens_h
#define robot_2sens_h
#include <Arduino.h> //libreria de arduin

#include "config.h"
#include "mqtt.h"
#include "cont_vel.h"

extern int sensor1;
extern int sensor2;

extern bool obs_izq;
extern bool obs_dcha;
 
extern int incomingByte;
extern bool dato_sensor;

void sensores_arduino();


#endif
