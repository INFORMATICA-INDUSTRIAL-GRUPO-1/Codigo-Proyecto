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


#include <Arduino.h>
#include "config.h"

/////////////////////GPIO's///////////////////////////////////////////////////////////

byte DHT_PIN=5; ///Pin de conexion de datos del DHT11
//byte SWITCH_PIN=16; //Pin de conexion del swich
unsigned LED_PIN_2 = 16;
byte LED_PIN=BUILTIN_LED; // Led de la placa
byte BUTTON_PIN = 0; // Boton de Flash de la placa ESP8266

////////////////////////////Debug Por Puerto Serie////////////////////////////////////
bool debug = true;


///////////////////// WiFi & MQTT CONFIGURATION////////////////////////////////////////////////////

const char* ssid = "TOTOLINK_N300RH_Pri"; // PONER EL NOMBRE DE LA RED WIFI
const char* password = "AlHaMbRa_2.718"; // CLAVE DE LA RED WIFI
//const char* ssid = "Martin Router King"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "laclaveestenerdinero666"; // CLAVE DE LA RED WIFI
//const char* ssid = "TP_LINK_ENCHUFE"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = ""; // CLAVE DE LA RED WIFI
//const char* ssid = "Pabloski587"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "pablovera"; // CLAVE DE LA RED WIFI
const char* mqtt_server = "iot.ac.uma.es" ;//  IP DEL BROKER MQTT (IP de la maquina Fisica (PC,RPI,iot.uma...,etc) (NO de la maquina virtual)) 
int mqtt_port = 1883;
const char* mqtt_user = "infind";
const char* mqtt_psw = "zancudo";

const char* AP_ssid = "ESP8266_"; //"ESP8266_ChipId" SSid del AccesPoint para wificonfig
const char* AP_password = "ESP8266"; //psw del AccesPoint para wificonfig

byte max_reconnect = 5; // intentos de reconexion antes de configurar el "AccesPoint"
/////////////////Parametros ////////////////////

int dataSampRate = 5*60; // Tiempo entre publicaciones de los datos en SEGUNDOS
int fotaSampRate = 0; // Tiempo entre busqueda de nuevas actualizaciones en MINUTOS (0 para deshabilitar la comprobacion por tiempo)
int ledspeed = 10 ; // Velocidad a la que se modifica los cambios en la intensidad del led

int actualiza = 0; 
