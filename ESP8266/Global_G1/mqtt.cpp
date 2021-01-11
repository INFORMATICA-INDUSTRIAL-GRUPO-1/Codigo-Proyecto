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


/* ---------------------- Declaraciones ---------------------- */

PubSubClient client(espClient);


/* ---------------------- Funciones ---------------------- */

void callback(char* topic, byte* payload, unsigned int length) { // Funcion de callback (comprueba nuevas publicaciones en los topics suscritos)
  char *mensaje=(char *)malloc(length+1); // reservo memoria para copia del mensaje
  strncpy(mensaje,(char*)payload,length); // copio el mensaje en cadena de caracteres
  
 /* Serial.print("Message arrived ["); //DEBUG por puerto Serie
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
*/

/* ---------------------- LED_CMD ---------------------- */

  if(strcmp(topic,TOP_ledCmd)==0) //Comprobacion topic para led
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("level"))  // comprobar si existe el campo/clave que estamos buscando
    {
     int valor_led_mqtt = root["level"];
     debugFunction("Mensaje OK, level = ",0);
     debugFunction(String(valor_led_mqtt),1);
     led_actual = valor_led_mqtt;
     led_mqtt();
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"level\" key not found in JSON",1);
    }
    
  }
  /*else //Topic erroneo 
  {
    Serial.print("Topic:");
    Serial.println(topic);
    Serial.println("Error: Topic desconocido");
  }*/

/* ---------------------- SWITCH_CMD ---------------------- */

    if(strcmp(topic,TOP_switchCmd)==0) //Comprobacion topic para led
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("level"))  // comprobar si existe el campo/clave que estamos buscando
    {
     int valor_switch_mqtt = root["level"];
     debugFunction("Mensaje OK, level = ",0);
     debugFunction(String(valor_switch_mqtt),1);
     
     if(valor_switch_mqtt)
        switch_valor = 0;
     else
        switch_valor = 1;
     ready_switch = true;
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"level\" key not found in JSON",1);
    }
    
  }
  /*else //Topic erroneo 
  {
    Serial.print("Topic:");
    Serial.println(topic);
    Serial.println("Error: Topic desconocido");
  }*/

/* ---------------------- CONFIG ---------------------- */

if(strcmp(topic,TOP_config)==0) //Comprobacion topic para led
  {
      StaticJsonDocument<128> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else
    {
      /* ---------------------- Actualiza ---------------------- */
       if(root.containsKey("actualiza"))  // comprobar si existe el campo/clave que estamos buscando
      {
       int fotaSampRate_mqtt = root["actualiza"];
       debugFunction("Mensaje OK, actualiza = ",0);
       debugFunction(String(fotaSampRate_mqtt),1);
       fotaSampRate = fotaSampRate_mqtt;
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"actualiza\" key not found in JSON",1);
      }
      
      /* ---------------------- Envia ---------------------- */
      if(root.containsKey("envia"))  // comprobar si existe el campo/clave que estamos buscando
      {
       int dataSampRate_mqtt = root["envia"];
       debugFunction("Mensaje OK, envia = ",0);
       debugFunction(String(dataSampRate_mqtt),1);
       dataSampRate = dataSampRate_mqtt;
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"envia\" key not found in JSON",1);
      }
      /* ---------------------- Velocidad ---------------------- */
      if(root.containsKey("velocidad"))  // comprobar si existe el campo/clave que estamos buscando
      {
       int ledspeed_mqtt = root["velocidad"];
       debugFunction("Mensaje OK, velocidad = ",0);
       debugFunction(String(ledspeed_mqtt),1);
       ledspeed = ledspeed_mqtt;
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"velocidad\" key not found in JSON",1);
      }
      
      /* ---------------------- LED_config ---------------------- */
       if(root.containsKey("LED"))  // comprobar si existe el campo/clave que estamos buscando
      {
       int valor_led_mqtt_config = root["LED"];
       debugFunction("Mensaje OK, LED (config) = ",0);
       debugFunction(String(valor_led_mqtt_config),1);
       
       if(valor_led_mqtt_config)
          led_actual = 100;
       else
          led_actual = 0;

       led_mqtt();   
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"LED\" key not found in JSON",1);
      }
      
       /* ---------------------- SWITCH_config ---------------------- */
       if(root.containsKey("LED"))  // comprobar si existe el campo/clave que estamos buscando
      {
       int valor_switch_mqtt_config = root["SWITCH"];
       debugFunction("Mensaje OK, SWITCH (config) = ",0);
       debugFunction(String(valor_switch_mqtt_config),1);
       
       if(valor_switch_mqtt_config)
          switch_valor = 0;
       else
          switch_valor = 1;
          
       ready_switch = true;       
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"SWITCH\" key not found in JSON",1);
      }
    }
    
  }

/* ---------------------- FOTA ---------------------- */  

  if(strcmp(topic,TOP_FOTA)==0)
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("actualiza"))  // comprobar si existe el campo/clave que estamos buscando
    {
     actualiza = root["actualiza"];
     debugFunction("Mensaje OK, actualiza = ",0);
     debugFunction(String(actualiza),1);
     
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"actualiza\" key not found in JSON",1);
    }
  }

/* ---------------------- MOVIMIENTO ---------------------- */ 
  
  if(strcmp(topic,TOP_Movimiento)==0)
  {
      StaticJsonDocument<24> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("orden"))  // comprobar si existe el campo/clave que estamos buscando
    {
     orden = root["orden"];
     /*debugFunction("Mensaje OK, orden = ",0);
     debugFunction(String(orden),1);*/
     velocidad();
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"orden\" key not found in JSON",1);
    }
  } 

/* ---------------------- MODO ---------------------- */  

  if(strcmp(topic,TOP_Modo)==0)
  {
      StaticJsonDocument<128> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",1);
      debugFunction(error.c_str(),0);
    }
    else if(root.containsKey("Modo"))  // comprobar si existe el campo/clave que estamos buscando
    {
     modo = root["Modo"];
     /*debugFunction("Mensaje OK, orden = ",0);
     debugFunction(String(orden),1);*/
     control_modo();
    
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"modo\" key not found in JSON",1);
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
    char JSon_Msg[64];
    datos.chipId= ESP.getChipId (); // Asegura que el chipId sea el correcto antes de utilizarlo en cada reconexion;
    clientId += String(datos.chipId) ; // establece el id del cliente mqtt
    debugFunction (clientId.c_str(),1);
    sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"false\",\"grupo\":\"%i\",\"placa\":\"%i\"}",datos.chipId.c_str(),grupo,placa);
       debugFunction("mqtt:set LWill to :",1);
      debugFunction(JSon_Msg,1);
    // Attempt to connect
    if (client.connect(clientId.c_str(),mqtt_user,mqtt_psw,TOP_conexion,0 ,true ,(const char*)JSon_Msg )) { //Establece la conexion al mqtt y configura LWT: "conexion:false"  //ej:  boolean rc = mqttClient.connect("myClientID", willTopic, willQoS, willRetain, willMessage); 
      
       sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"true\",\"grupo\":\"%i\",\"placa\":\"%i\"}",datos.chipId.c_str(),grupo,placa);
      debugFunction("mqtt:connected",1);
      debugFunction(JSon_Msg,1);
      // Once connected, publish an announcement...
   
     
      // ... and resubscribe
      client.setBufferSize(512); // Tamaño bufer 512bytes
      //client.subscribe("infind/GRUPO1/datos"); // Subscripcion al topic "datos"
      client.subscribe(TOP_ledCmd);  // Subscripcion al topic "led/cmd"
      client.subscribe(TOP_config);
      client.subscribe(TOP_switchCmd);
      client.subscribe(TOP_FOTA);
      client.subscribe("infind/GRUPO1/ESP0/broadcast"); // subscripcion a topic de broadcast
      client.subscribe(TOP_Movimiento);
      client.subscribe(TOP_Modo);
      client.publish("infind/GRUPO1/ESP0/ack",(const char*)JSon_Msg,true); //publica el estado de la conexion el topic "ack" del broadcast
      client.publish(TOP_conexion,(const char*)JSon_Msg,true); //publica el estado de la conexion=true en el topic "conexion"
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

void mqttTopics(){ // Funcion que establece los topics de conexion. Añade el numero de grupo y el numero de placa a cada topic
// Topic Raiz "infind/GRUPO%i/ESP%i/%s" en donde %i indican (numero de grupo y numero de placa resp.) y %s indica el topic en cuestion (pej: datos, conexion, etc.)

String aux; // almacenamiento temporal del topic

  aux=TOP_conexion;
  memset(TOP_conexion, 0, sizeof(TOP_conexion));// Resetea la variable que contiene el topic
  sprintf(TOP_conexion, TOP_generic ,grupo,placa,aux.c_str()); // Añade el topic raiz , el numero de grupo, numero de placa y el topic en cuestion
  Serial.println("Topic_Conexion:");
  Serial.println(TOP_conexion);

  aux=TOP_datos;
  memset(TOP_datos, 0, sizeof(TOP_datos));
  sprintf(TOP_datos,TOP_generic,grupo,placa,aux.c_str());
  Serial.println(TOP_datos);
  
  aux=TOP_config;
  memset(TOP_config, 0, sizeof(TOP_config));
  sprintf(TOP_config,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_ledCmd;
  memset(TOP_ledCmd, 0, sizeof(TOP_ledCmd));
  sprintf(TOP_ledCmd,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_ledStatus;
  memset(TOP_ledStatus, 0, sizeof(TOP_ledStatus));
  sprintf(TOP_ledStatus,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_switchCmd;
  memset(TOP_switchCmd, 0, sizeof(TOP_switchCmd));
  sprintf(TOP_switchCmd,TOP_generic,grupo,placa,aux.c_str());
  
  aux=TOP_switchStatus;
  memset(TOP_switchStatus, 0, sizeof(TOP_switchStatus));
  sprintf(TOP_switchStatus,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_FOTA;
  memset(TOP_FOTA, 0, sizeof(TOP_FOTA)); 
  sprintf(TOP_FOTA,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_FOTA_updt;
  memset(TOP_FOTA_updt, 0, sizeof(TOP_FOTA_updt)); 
  sprintf(TOP_FOTA_updt,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_sensores;
  memset(TOP_sensores, 0, sizeof(TOP_sensores)); 
  sprintf(TOP_sensores,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_Movimiento;
  memset(TOP_Movimiento, 0, sizeof(TOP_Movimiento)); 
  sprintf(TOP_Movimiento,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_Modo;
  memset(TOP_Modo, 0, sizeof(TOP_Modo)); 
  sprintf(TOP_Modo,TOP_generic,grupo,placa,aux.c_str());

  aux=TOP_Obstaculo;
  memset(TOP_Obstaculo, 0, sizeof(TOP_Obstaculo)); 
  sprintf(TOP_Obstaculo,TOP_generic,grupo,placa,aux.c_str());
  }

  
