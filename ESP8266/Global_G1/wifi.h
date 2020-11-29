#ifndef wifi_h
#define wifi_h



#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "config.h"

extern WiFiClient espClient; 
extern String ip;

void setup_wifi();

int ssidReq ();

#endif
