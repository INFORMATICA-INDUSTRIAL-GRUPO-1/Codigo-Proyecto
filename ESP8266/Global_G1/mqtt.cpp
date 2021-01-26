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

//-------------------------  Seccion librerias y pestañas  -------------------------  

#include <Arduino.h>

#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "debug.h"
#include "datos.h"
#include "mqtt.h"
#include "pulsos.h"
#include "wifi.h"
String id; //inicializamos la id a 0

//-------------------------   DECLARACIONES  -------------------------  

PubSubClient client(espClient);


//-------------------------  FUNCIONES  -------------------------  

void callback(char* topic, byte* payload, unsigned int length) { // Funcion de callback (comprueba nuevas publicaciones en los topics suscritos)
  char *mensaje=(char *)malloc(length+1); // reservo memoria para copia del mensaje
  strncpy(mensaje,(char*)payload,length); // copio el mensaje en cadena de caracteres
  /*
  Serial.print("Message arrived ["); //DEBUG por puerto Serie
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
Bucle necesario para determinar que mensaje esta entrando y por que topic.*/


//-------------------------  LED_CMD  -------------------------  

  if(strcmp(topic,TOP_ledCmd)==0)     //Comprobacion topic para LED.
  {
      StaticJsonDocument<500> root;   // El tamaño tiene que ser adecuado para el mensaje.

    DeserializationError error = deserializeJson(root, mensaje); //Deserializa el mensaje.

    //Se omprueb si no hubo error.
    if (error) {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("level"))        //Comprueba si existe el campo/clave que estamos buscando.
    {
     int valor_led_mqtt = root["level"];      //Guarda en valor_led_mqtt el valor recibido desde MQTT.
     String id_mqtt=root["id"];               //Guarda en id el valor recibido desde MQTT.
     id=id_mqtt;                              //El valor de id_mqtt se pasa a una variable global.
     debugFunction("Mensaje OK, level = ",0);
     debugFunction(String(valor_led_mqtt),1);
     led_actual = valor_led_mqtt;             //El valor_led_mqtt se pasa a una variable global.
     origen_led = "mqtt";
     led_mqtt();                              //Funcion que publica por MQTT el nuevo valor de LED.
    }
    
    else                                      //Mensaje recibido por el topic correcto pero con la palabra clave erronea.
    {
      debugFunction("Error : ",0);
      debugFunction("\"level\" palbra clave no encontrada en JSON",1);
    }
  }

//-------------------------  SWITCH_CMD  ---------------------- 

    if(strcmp(topic,TOP_switchCmd)==0) //Comprobacion topic para led
  {
      StaticJsonDocument<500> root; // el tamaño tiene que ser adecuado para el mensaje
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
     String id_mqtt=root["id"];
     id=id_mqtt;
     debugFunction("Mensaje OK, level = ",0);
     debugFunction(String(valor_switch_mqtt),1);
     
     if(valor_switch_mqtt)
        switch_valor = 0;
     else
        switch_valor = 1;
        
     origen_switch = "mqtt";
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
        if(root["actualiza"] == -1)
          debugFunction("actualiza = null. No se han hecho modificaciones",1);
        else
        {
         int fotaSampRate_mqtt = root["actualiza"];
         debugFunction("Mensaje OK, actualiza = ",0);
         debugFunction(String(fotaSampRate_mqtt),1);
         fotaSampRate = fotaSampRate_mqtt;
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"actualiza\" key not found in JSON",1);
      }
      
      /* ---------------------- Envia ---------------------- */
      if(root.containsKey("envia"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root["envia"] == -1)
          debugFunction("envia = null. No se han hecho modificaciones",1);
        else
        {
         int dataSampRate_mqtt = root["envia"];
         debugFunction("Mensaje OK, envia = ",0);
         debugFunction(String(dataSampRate_mqtt),1);
         dataSampRate = dataSampRate_mqtt;
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"envia\" key not found in JSON",1);
      }
      /* ---------------------- Velocidad ---------------------- */
      if(root.containsKey("velocidad"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root["velocidad"] == -1)
          debugFunction("velocidad = null. No se han hecho modificaciones",1);
        else
        { 
         int ledspeed_mqtt = root["velocidad"];
         debugFunction("Mensaje OK, velocidad = ",0);
         debugFunction(String(ledspeed_mqtt),1);
         ledspeed = ledspeed_mqtt;
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"velocidad\" key not found in JSON",1);
      }
      
      /* ---------------------- LED_config ---------------------- */
       if(root.containsKey("LED"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root["LED"] == -1)
          debugFunction("LED = null. No se han hecho modificaciones",1);
        else
        { 
         int valor_led_mqtt_config = root["LED"];
         debugFunction("Mensaje OK, LED (config) = ",0);
         debugFunction(String(valor_led_mqtt_config),1);
         
         if(valor_led_mqtt_config)
            led_actual = 100;
         else
           led_actual = 0;
  
         origen_led = "mqtt_config";
         led_mqtt();   
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"LED\" key not found in JSON",1);
      }
      
       /* ---------------------- SWITCH_config ---------------------- */
       if(root.containsKey("SWITCH"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root["SWITCH"] == -1)
          debugFunction("SWITCH = null. No se han hecho modificaciones",1);
        else
        {        
         int valor_switch_mqtt_config = root["SWITCH"];
         debugFunction("Mensaje OK, SWITCH (config) = ",0);
         debugFunction(String(valor_switch_mqtt_config),1);
         
         if(valor_switch_mqtt_config)
            switch_valor = false;
         else
            switch_valor = true;
            
         origen_switch = "mqtt_config";
         ready_switch = true;       
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"SWITCH\" key not found in JSON",1);
      }
      
      // ---------------------- Logica Negativa ---------------------- 
      if(root.containsKey("Logica_negativa"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root["Logica_negativa"] == -1)
          debugFunction("Logica negativa = null. No se han hecho modificaciones",1);
        else
        {        
         bool valor_Logica_negativa_mqtt_config = root["Logica_negativa"];
         debugFunction("Mensaje OK, Logica Negativa = ",0);
         debugFunction(String(valor_Logica_negativa_mqtt_config),1); 
         logica_negativa=valor_Logica_negativa_mqtt_config;     
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"Logica Negativa\" key not found in JSON",1);
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
   /* ---------------------- ConfigPlaca ---------------------- */  

  if(strcmp(topic,TOP_configPlaca)==0)
  {
      StaticJsonDocument<128> root; // el tamaño tiene que ser adecuado para el mensaje
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(root, mensaje);

    // Compruebo si no hubo error
    if (error) {
      debugFunction("Error deserializeJson() failed: ",1);
      debugFunction(error.c_str(),0);
      }
    else if(root.containsKey("placa"))  // comprobar si existe el campo/clave que estamos buscando
      {
        if(root.containsKey("CHIPID"))  // comprobar si existe el campo/clave que estamos buscando
        { 
            String ID = root["CHIPID"];
            int aux;
            debugFunction("CHIPID recibida:",1);
            debugFunction(ID,1);
            if (ID == datos.chipId){ // Compruebo que es el chipid correcto, es un topic de BROADCAST
              debugFunction("CHIPID coincide:",1);
              aux = root["placa"];
              if (aux != placa){ // solo actualizo la placa cuando ha cambiado
                placa = root["placa"];
                debugFunction("Actualizado el numero de placa:",1);
                debugFunction(String(placa),1);
                if (client.connected()){
                  debugFunction("cliente desconectado:",1);
                  client.disconnect();
                  delay (500);
                }
                mqttSetup ();
                mqttTopics(); // reescribe los topics
              }  
            }
            else
              debugFunction("numero de placa coincide, no se actualiza",1); 
 
        }
      }
    else
      {
        debugFunction("Error : ",0);
        debugFunction("\"placa\" key not found in JSON",1);
      } 
  } 
  free(mensaje); // libero memoria

}// END CALLBACK



void reconnect() { // Funcion de reconexion en caso de fallo (además de la primera conexion) del cliente mqtt
  // Loop until we're reconnected
  while (!client.connected()) { // intenta reconectar el mqtt (hasta exito)
    Serial.print("Estableciendo conexión MQTT........");
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
      debugFunction("mqtt:conectado",1);
      debugFunction(JSon_Msg,1);
      // Once connected, publish an announcement...
   
     
      // ... and resubscribe
      client.setBufferSize(512); // Tamaño bufer 512bytes
      //client.subscribe("infind/GRUPO1/datos"); // Subscripcion al topic "datos"
      client.subscribe(TOP_ledCmd);  // Subscripcion al topic "led/cmd"
      client.subscribe(TOP_config);
      client.subscribe(TOP_configPlaca);
      client.subscribe(TOP_switchCmd);
      client.subscribe(TOP_FOTA);
      //client.subscribe("infind/GRUPO1/ESP0/broadcast"); // subscripcion a topic de broadcast
      client.subscribe(TOP_Movimiento);
      client.subscribe(TOP_Modo);
      //client.publish("infind/GRUPO1/ESP0/ack",(const char*)JSon_Msg,true); //publica el estado de la conexion el topic "ack" del broadcast
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
  debugFunction ("Servidor MQTT:",0);
  debugFunction (mqtt_server,1);
  client.setServer(mqtt_server, mqtt_port); // Establecimiento de la conexion al mqtt
  client.setCallback(callback); 
  
  }

void mqttTopics(){ // Funcion que establece los topics de conexion. Añade el numero de grupo y el numero de placa a cada topic
// Topic Raiz "infind/GRUPO%i/ESP%i/%s" en donde %i indican (numero de grupo y numero de placa resp.) y %s indica el topic en cuestion (pej: datos, conexion, etc.)

String aux; // almacenamiento temporal del topic

  aux=s_TOP_conexion;
  memset(TOP_conexion, 0, sizeof(TOP_conexion));// Resetea la variable que contiene el topic
  sprintf(TOP_conexion, TOP_generic ,grupo,placa,aux.c_str()); // Añade el topic raiz , el numero de grupo, numero de placa y el topic en cuestion
  Serial.println("Topic_Conexion:");
  Serial.println(TOP_conexion);

  aux=s_TOP_datos;
  memset(TOP_datos, 0, sizeof(TOP_datos));
  sprintf(TOP_datos,TOP_generic,grupo,placa,aux.c_str());
  Serial.println(TOP_datos);
  
  aux=s_TOP_config;
  memset(TOP_config, 0, sizeof(TOP_config));
  sprintf(TOP_config,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_configPlaca;
  memset(TOP_configPlaca, 0, sizeof(TOP_configPlaca));
  sprintf(TOP_configPlaca,TOP_generic,grupo,0,aux.c_str());
  Serial.println(TOP_configPlaca);

  aux=s_TOP_ledCmd;
  memset(TOP_ledCmd, 0, sizeof(TOP_ledCmd));
  sprintf(TOP_ledCmd,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_ledStatus;
  memset(TOP_ledStatus, 0, sizeof(TOP_ledStatus));
  sprintf(TOP_ledStatus,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_switchCmd;
  memset(TOP_switchCmd, 0, sizeof(TOP_switchCmd));
  sprintf(TOP_switchCmd,TOP_generic,grupo,placa,aux.c_str());
  
  aux=s_TOP_switchStatus;
  memset(TOP_switchStatus, 0, sizeof(TOP_switchStatus));
  sprintf(TOP_switchStatus,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_FOTA;
  memset(TOP_FOTA, 0, sizeof(TOP_FOTA)); 
  sprintf(TOP_FOTA,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_FOTA_updt;
  memset(TOP_FOTA_updt, 0, sizeof(TOP_FOTA_updt)); 
  sprintf(TOP_FOTA_updt,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_sensores;
  memset(TOP_sensores, 0, sizeof(TOP_sensores)); 
  sprintf(TOP_sensores,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_Movimiento;
  memset(TOP_Movimiento, 0, sizeof(TOP_Movimiento)); 
  sprintf(TOP_Movimiento,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_Modo;
  memset(TOP_Modo, 0, sizeof(TOP_Modo)); 
  sprintf(TOP_Modo,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_Obstaculo;
  memset(TOP_Obstaculo, 0, sizeof(TOP_Obstaculo)); 
  sprintf(TOP_Obstaculo,TOP_generic,grupo,placa,aux.c_str());
  }

  
