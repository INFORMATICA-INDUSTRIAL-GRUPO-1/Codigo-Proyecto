// Programa Asignatura INFORMATICA INDUSTRIAL Grupo1
// Codigo ESP8266
// Version V.0.0.01a
// Autores
//
//
//
//
//
// Fecha de creacion: 28/11/2020
// 
// Pestaña:config.cpp
// Descripcion del codigo
//    Aqui se recogen las distintas variables que requieren configuracion
//


#ifndef config_h
#define config_h

#include <Arduino.h>

extern bool debug;

////////////////////Funciones//////////////////////////////
//// CONFIGURACION DE LOS PARÁMETROS DEL SERVIDOR DE ACTUALIZACIONES FOTA///////////////////////
#define HTTP_OTA_ADDRESS      F("192.168.0.169")       // Address of OTA update server
#define HTTP_OTA_PATH         F("/esp8266-ota/update") // Path to update firmware
#define HTTP_OTA_PORT         1880                     // Port of update server
                                                       // Name of firmware
#define HTTP_OTA_VERSION      String(__FILE__).substring(String(__FILE__).lastIndexOf('\\')+1) + ".nodemcu" 

extern byte DHT_PIN;
extern byte SWITCH_PIN;
extern byte LED_PIN;

//extern struct Config;
extern const char* ssid ;
extern const char* password;
extern const char* mqtt_server;
extern int mqtt_port;
extern const char* mqtt_user;
extern const char* mqtt_psw;
extern const char* AP_ssid;
extern const char* AP_password;
extern byte max_reconnect;

/////////////////Parametros ////////////////////


extern int dataSampRate ; //En Segundos
extern int fotaSampRate ;//En minutos
extern int ledspeed;

#endif
