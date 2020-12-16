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
#include <DNSServer.h>
#include <ESP8266WebServer.h >
#include <WiFiManager.h>

#include <Arduino.h>
#include "config.h"
#include "datos.h"
#include "debug.h"


#include "wifi.h"
////////////////////Declaraciones//////////////////////////////
WiFiClient espClient; // cliente wifi Para conexion generica
WiFiManager wifiManager; // crea un AccesPoint (nueva red wifi) para configurar la red wifi (de trabajo) desde otro dispositivo
String ip = "0.0.0.0";
long rssi = 0;
////////////////////Funciones//////////////////////////////

void setup_wifi() { // Funcion de conexion dal WiFi
  byte attempt = 0; // inicializo una variable que cuenta los intentos de conexion al wifi(de trabajo)


  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    attempt ++;
    delay(500);
    Serial.print(".");
    if (attempt >= max_reconnect) // comprueba los intentos de reconexion => si superior a umbral =>> configura un AP 
      debugFunction ("AP-enabled",1);
      debugFunction ("New Wifi created:", 0);
      debugFunction (String(AP_ssid)+String(datos.chipId),0);
      WiFiConfig ();

    
  }

  randomSeed(micros());

  ip=WiFi.localIP().toString().c_str();
  Serial.println("");
  Serial.println("WiFi connected");
  ip= WiFi.localIP().toString().c_str(); //Repetido?
  Serial.println("IP address: ");
  //Serial.println(ip);
  debugFunction (ip,1);
}



  int ssidReq (){
  rssi = WiFi.RSSI();
  return rssi;
  }


  void WiFiConfig (){
   // char APSSID [20];
   // strcat (AP_ssid, datos.chipId) 
    //AP_ssid += datos.chipId 
    wifiManager.autoConnect("ESP", "12345678");
    debugFunction ("Connected",1);
    
    }
