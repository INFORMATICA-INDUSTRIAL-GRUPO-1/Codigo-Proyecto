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
byte SWITCH_PIN=16; //Pin de conexion del swich
byte LED_PIN=BUILTIN_LED; // Led de la placa

////////////////////////////Debug Por Puerto Serie////////////////////////////////////
bool debug = true;


///////////////////// WiFi CONFIGURATION////////////////////////////////////////////////////
// Update these with values suitable for your network.
const char* ssid = "wifiSSID"; // PONER EL NOMBRE DE LA RED WIFI
const char* password = "123456789"; // CLAVE DE LA RED WIFI
const char* mqtt_server = "192.168.0.24" ;//  IP DEL BROKER MQTT (IP de la maquina Fisica (PC,RPI,iot.uma...,etc) (NO de la maquina virtual)) 




/////////////////Parametros ////////////////////

int dataSampRate = 5*60; // Tiempo entre publicaciones de los datos en SEGUNDOS
int fotaSampRate = 0; // Tiempo entre busqueda de nuevas actualizaciones en MINUTOS (0 para deshabilitar la comprobacion por tiempo)
int ledSpeed = 0 ; // Velocidad a la que se modifica los cambios en la intensidad del led
 


