#ifndef cont_vel_h
#define cont_vel_h

#include <Arduino.h>


#include <ArduinoJson.h>

#include "wifi.h"
#include "datos.h"
#include "config.h"
#include "mqtt.h"
#include "robot_2sens.h"
//#include "robot_5sens.h"

extern uint8_t vel_envio[2];
void control_modo();
void velocidad();

#endif
