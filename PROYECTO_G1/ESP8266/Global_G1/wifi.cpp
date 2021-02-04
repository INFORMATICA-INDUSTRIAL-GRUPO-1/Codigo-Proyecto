// Programa Asignatura INFORMATICA INDUSTRIAL Grupo1
// Codigo ESP8266
// Version V.1
//
// Autores
//
//  ANTONIO JESUS PEREZ BAZUELO
//  MANUEL VALLE DELGADO
//  MATHIAS LOFEUDO CLINCKSPOOR
//  PABLO ROLDAN PEREZ
//  PABLO VERA SOTO
//
// Pestaña: debug
//
// Descripcion del codigo
//
// Esta funcion se encarga de establecer la conexión WiFi con un router
// o para crear un punto de acceso desde la misma ESP8266.
//

//-------------------------  Seccion librerias y pestañas  -------------------------  

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h >
#include <WiFiManager.h>

#include <Arduino.h>
#include "config.h"
#include "datos.h"
#include "debug.h"
#include "wifi.h"

//-------------------------  Declaraciones  -------------------------  

WiFiClient espClient;     // Cliente wifi para conexion generica.
WiFiManager wifiManager;  // Crea un AccesPoint (nueva red wifi) para configurar la red wifi (de trabajo) desde otro dispositivo.
String ip = "0.0.0.0";    // IP inicializada con "direccion" 0.
long rssi = 0;

//-------------------------  Funciones-------------------------  

void setup_wifi()  // Funcion de conexion del WiFi
{
  byte attempt = 0; // Inicializo una variable que cuenta los intentos de conexion al wifi.
  delay(10);
  Serial.println();
  Serial.print("Conectandose a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);       //Funcion para conectarse al punto de acceso deseado (configurado en config).

  while (WiFi.status() != WL_CONNECTED) //Bucle que añade "." en el monitor serie y que cuenta los intentos de conexion.
  {
    attempt ++;
    delay(500);
    Serial.print(".");
    
    if (attempt >= max_reconnect) // Comprueba los intentos de reconexion. Si es superior al umbral, configura un AP (Access Point o punto de acceso)
    {
      debugFunction ("AP activado",1);
      debugFunction ("Nuevo WiFi creado: ", 0);
      debugFunction (String(AP_ssid)+String(datos.chipId),0);
      WiFiConfig(); //Llama a una funcion para crear el punto de acceso.
    }
  }

  randomSeed(micros());

  ip=WiFi.localIP().toString().c_str(); //Guarda en una variable la IP.
  Serial.println("");
  Serial.println("WiFi conectado");
}


void WiFiConfig()   //Funcion que crea el punto de acceso de la ESP8266.
{ 
  wifiManager.autoConnect(AP_ssid, AP_password);    //Punto de acceso con SSID y contraseña configurada en config.cpp.
  debugFunction ("Conectado",1);
}


int ssidReq() //Funcion que obtiene el valor de RSSI (Intensidad de la señal WiFi)
{
  rssi = WiFi.RSSI();
  return rssi;
}
