#ifndef wifi_h
#define wifi_h



#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h >
#include <WiFiManager.h>
#include <Arduino.h>
#include "config.h"

extern WiFiClient espClient; 
extern String ip;
extern const char* AP_ssid;
extern const char* AP_password;
extern byte max_reconnect;
extern struct registro_datos datos ;



void setup_wifi();

int ssidReq ();

void WiFiConfig ();

#endif
