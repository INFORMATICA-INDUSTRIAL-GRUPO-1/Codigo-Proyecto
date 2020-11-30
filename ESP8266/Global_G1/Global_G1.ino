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
// Pestaña:Global
// Descripcion del codigo
//
//




////////////////////Seccion librerias y pestañas//////////////////////////////
//Librerias//
// Incluir aqui las librerias//

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
#include <ESP8266httpUpdate.h>
#include <ArduinoJson.h>


////////////////////Seccion variables globales//////////////////////////////
// Declarar aqui las variables globales//




unsigned long lastMsg = 0;

bool ledState = false;
byte times = 0;






//Pestañas//
// Incluir aqui las pestañas//
#include "config.h"
#include "wifi.h"
#include "mqtt.h"
#include "fota.h"
#include "datos.h"
#include "debug.h"








void setup() {
 // Configuracion Inicial del ESP8266
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200); // Puerto serie Establecimiento
  setup_wifi(); //llamada a la funcion de config. del WiFi

  FuncionActualizacion(); //LLamamos a la funcion para que actualice el programa

  debugFunction ("Establecimiento de MQTT",1);
  mqttSetup (); //Llamada a la funcion de setup de mqtt
  
  dht.setup(DHT_PIN, DHTesp::DHT11); // Connect DHT sensor to GPIO 17

  if(debug){
    debugFunction ("Datos para debug",0);
    tomaDatos(datos);
    serializa_datos_JSON ().toCharArray (msg,512); // Serializacion de los datos del archivo json para su publicacion
    }
  

}// END SETUP

void loop() {
  
  if (!client.connected()) { // Comprobacion y reconexion (en caso de fallo) del cliente mqtt
    reconnect();
  }
  client.loop(); // look for new message in MQTTprotocol

  unsigned long now = millis(); // Toma del tiempo actual en ms
  
// END comprobacion y reconexion




if (now - lastMsg > dataSampRate*1000) //DATOS =>> ejecucion cada 5 min (por defecto) =>> Asigna los valores y Publica el topic datos
{
  lastMsg = now;

  
  tomaDatos(datos); //actualiza los valores de "datos"
  
 serializa_datos_JSON ().toCharArray (msg,512); // Serializacion de los datos del archivo json para su publicacion
 client.publish("infind/GRUPO1/datos", msg, true); //publicacion del mensaje "datos" como retenido
  
  
}//END DATOS 
   
  



  
}// END LOOP
