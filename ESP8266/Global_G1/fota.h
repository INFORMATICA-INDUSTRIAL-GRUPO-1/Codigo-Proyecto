#ifndef fota_h
#define fota_h

#include <Arduino.h>

#include <ESP8266httpUpdate.h>

#include "datos.h"
#include "mqtt.h"
#include "config.h"


void progreso_OTA(int,int);
void final_OTA();
void inicio_OTA();
void error_OTA(int);
void FuncionActualizacion();


#endif
