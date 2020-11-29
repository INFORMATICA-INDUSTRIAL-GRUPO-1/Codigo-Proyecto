#ifndef mqtt_h
#define mqtt_h

#include <Arduino.h>

#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

#include "wifi.h"
#include "datos.h"


//Externalizacion de variables
extern PubSubClient client;
extern WiFiClient espClient; 

//Funciones
void callback(char* topic, byte* payload, unsigned int length);

void reconnect();


#endif
