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

#include <Arduino.h>

#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "debug.h"
#include "datos.h"
#include "mqtt.h"
#include "pulsos.h"
#include "wifi.h"


////////////////////Declaraciones//////////////////////////////

PubSubClient client(espClient);


////////////////////Funciones//////////////////////////////





void callback(char* topic, byte* payload, unsigned int length) { // Funcion de callback (comprueba nuevas publicaciones en los topics suscritos)
  char *mensaje=(char *)malloc(length+1); // reservo memoria para copia del mensaje
  strncpy(mensaje,(char*)payload,length); // copio el mensaje en cadena de caracteres
  
  Serial.print("Message arrived ["); //DEBUG por puerto Serie
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  if(strcmp(topic,"infind/GRUPO1/led/cmd")==0) //Comprobacion topic para led
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      Serial.print("Error deserializeJson() failed: ");
      Serial.println(error.c_str());
    }
    else if(root.containsKey("level"))  // comprobar si existe el campo/clave que estamos buscando
    {
     int valor_led_mqtt = root["level"];
     Serial.print("Mensaje OK, level = ");
     Serial.println(valor_led_mqtt);
     led_valor1 = valor_led_mqtt;
     led_mqtt();
    }
    else
    {
      Serial.print("Error : ");
      Serial.println("\"level\" key not found in JSON");
    }
    
  }
  else //Topic erroneo 
  {
    Serial.print("Topic:");
    Serial.println(topic);
    Serial.println("Error: Topic desconocido");
  }

if(strcmp(topic,"infind/GRUPO1/config")==0) //Comprobacion topic para led
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      Serial.print("Error deserializeJson() failed: ");
      Serial.println(error.c_str());
    }
    else if(root.containsKey("tiempo"))  // comprobar si existe el campo/clave que estamos buscando
    {
     int ledspeed_mqtt = root["tiempo"];
     Serial.print("Mensaje OK, level = ");
     Serial.println(ledspeed_mqtt);
     ledspeed = ledspeed_mqtt;
    }
    else
    {
      Serial.print("Error : ");
      Serial.println("\"level\" key not found in JSON");
    }
    
  }
   else if(strcmp(topic,"infind/GRUPO1/FOTA")==0)
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      Serial.print("Error deserializeJson() failed: ");
      Serial.println(error.c_str());
    }
    else if(root.containsKey("actualiza"))  // comprobar si existe el campo/clave que estamos buscando
    {
     actualiza = root["actualiza"];
     Serial.print("Mensaje OK, actualiza = ");
     Serial.println(actualiza);
     
    }
    else
    {
      Serial.print("Error : ");
      Serial.println("\"actualiza\" key not found in JSON");
    }
  } 
  free(mensaje); // libero memoria

}// END CALLBACK



void reconnect() { // Funcion de reconexion en caso de fallo (además de la primera conexion) del cliente mqtt
  // Loop until we're reconnected
  while (!client.connected()) { // intenta reconectar el mqtt (hasta exito)
    Serial.print("Attempting MQTT connection...");
    // Create client ID based on ChipID number
    String clientId = "ESP8266Client-";
    datos.chipId= ESP.getChipId (); // Asegura que el chipId sea el correcto antes de utilizarlo en cada reconexion;
    clientId += String(datos.chipId) ; // establece el id del cliente mqtt
    debugFunction (clientId.c_str(),1);
    char* JSon_Msg="";
    //sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"false\"} ",datos.chipId.c_str());
       debugFunction("mqtt:set LWill to :",1);
      debugFunction(JSon_Msg,1);
    // Attempt to connect
    if (client.connect(clientId.c_str(),mqtt_user,mqtt_psw,"infind/GRUPO1/conexion",0 ,true ,(const char*)JSon_Msg )) { //Establece la conexion al mqtt y configura LWT: "conexion:false"  //ej:  boolean rc = mqttClient.connect("myClientID", willTopic, willQoS, willRetain, willMessage); 
       JSon_Msg="";
       //sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"true\"} ",datos.chipId.c_str());
      debugFunction("mqtt:connected",1);
      debugFunction(JSon_Msg,1);
      // Once connected, publish an announcement...
   
     
      // ... and resubscribe
      client.setBufferSize(512); // Tamaño bufer 512bytes
      //client.subscribe("infind/GRUPO1/datos"); // Subscripcion al topic "datos"
      client.subscribe("infind/GRUPO1/led/cmd");  // Subscripcion al topic "led/cmd"
      client.subscribe("infind/GRUPO1/config");
      client.subscribe("infind/GRUPO1/FOTA");
      client.publish("infind/GRUPO1/conexion",(const char*)JSon_Msg,true); //publica el estado de la conexion=true en el topic "conexion"
    
    JSon_Msg="";
       sprintf (JSon_Msg,"");
    
    } else { // fallo en la conexion mqtt
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}// END RECONECT



void mqttSetup (){
  debugFunction ("mqttServer:",0);
  debugFunction (mqtt_server,1);
  client.setServer(mqtt_server, mqtt_port); // Establecimiento de la conexion al mqtt
  client.setCallback(callback); 
  
  }
