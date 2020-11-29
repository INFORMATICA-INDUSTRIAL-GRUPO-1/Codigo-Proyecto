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
// Pestaña:datos.cpp
// Descripcion del codigo
//    Aqui se recogen las distintas variables que requieren configuracion
//

////////////////////Seccion librerias y pestañas//////////////////////////////




#include <ESP8266WiFi.h>
#include <Arduino.h>
#include "config.h"
#include "debug.h"


#include "wifi.h"
////////////////////Declaraciones//////////////////////////////
WiFiClient espClient; 
String ip = "0.0.0.0";
long rssi = 0;
////////////////////Funciones//////////////////////////////

void setup_wifi() { // Funcion de conexion dal WiFi

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  ip=WiFi.localIP().toString().c_str();
  Serial.println("");
  Serial.println("WiFi connected");
  ip= WiFi.localIP().toString().c_str();
  Serial.println("IP address: ");
  Serial.println(ip);
  debugFunction (ip);
}



  int ssidReq (){
  rssi = WiFi.RSSI();
  return rssi;
  }
