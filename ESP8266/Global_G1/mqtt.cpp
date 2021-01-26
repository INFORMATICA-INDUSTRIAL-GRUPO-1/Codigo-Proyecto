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
// Pestaña: mqtt
//
// Descripcion del codigo
//
// Se encuentran las funciones correspondientes a la configuración de la conexión de la ESP al servidor MQTT,
// configuración de los topics que van a utilizarse en todo el programa y recepción de información mediante suscripción a distintos topics. 
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
String id = ""; //Inicializamos la id a "vacio".

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
    StaticJsonDocument<512> root;   // El tamaño tiene que ser adecuado para el mensaje.
    DeserializationError error = deserializeJson(root, mensaje); //Deserializa el mensaje.

    //Se comprueba si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("level"))        //Comprueba si existe el campo/clave.
    {
       int valor_led_mqtt = root["level"];      //Guarda en valor_led_mqtt el valor recibido desde MQTT.
       String id_mqtt=root["id"];               //Guarda en id el valor recibido desde MQTT.
       id=id_mqtt;                              //El valor de id_mqtt se pasa a una variable global.
       debugFunction("Mensaje OK, level = ",0);
       debugFunction(String(valor_led_mqtt),1);
       led_actual = valor_led_mqtt;             //valor_led_mqtt se guarda en una variable global.
       origen_led = "mqtt";
       led_mqtt();                              //Funcion que publica por MQTT el nuevo valor de LED.
    }
    
    else                                      //Mensaje recibido por el topic correcto pero con la palabra clave erronea.
    {
      debugFunction("Error : ",0);
      debugFunction("\"level\" palabra clave no encontrada en JSON",1);
    }
  }

//-------------------------  SWITCH_CMD  -------------------------

  if(strcmp(topic,TOP_switchCmd)==0) //Comprobacion topic para switch.
  {
    StaticJsonDocument<512> root;  
    DeserializationError error = deserializeJson(root, mensaje); //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("level"))            //Comprueba si existe el campo/clave.
    {
       int valor_switch_mqtt = root["level"];       //Guarda en valor_switch_mqtt el valor recibido desde MQTT.
       String id_mqtt=root["id"];                   //Guarda en id el valor recibido desde MQTT.
       id=id_mqtt;                                  //El valor de id_mqtt se pasa a una variable global.
       debugFunction("Mensaje OK, level = ",0);
       debugFunction(String(valor_switch_mqtt),1);
     
       if(valor_switch_mqtt)                        //Interpreta el valor recibido para escribirlo en el switch.
          switch_valor = 0;
       else
          switch_valor = 1;
          
       origen_switch = "mqtt";
       ready_switch = true;                         //Datos preparados, puede escribirlo y enviar el mensaje por MQTT.
    }
 
  else                                          //Mensaje recibido por el topic correcto pero con la palabra clave erronea.
  {
    debugFunction("Error : ",0);
    debugFunction("\"level\" palabra clave no encontrada en JSON",1);
  }
   
}

//-------------------------  CONFIG  -------------------------

  if(strcmp(topic,TOP_config)==0) //Comprobacion topic para config.
  {
    StaticJsonDocument<128> root; 
    DeserializationError error = deserializeJson(root, mensaje); //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else
    {
      // ---------------------- Actualiza ---------------------- 
      
       if(root.containsKey("actualiza"))  //Comprueba si existe el campo/clave.
        {
          if(root["actualiza"] == -1)       //En caso de enviar un dato no deseado, en Node-Red se envia "-1". 
                                            //Esto hace que no se modifique el valor de ese campo. En el resto de campos se hace de forma identica.
            debugFunction("actualiza = null. No se han hecho modificaciones",1);
          else
          {
             int fotaSampRate_mqtt = root["actualiza"];     //Obtiene el valor recibido.
             debugFunction("Mensaje OK, actualiza = ",0);
             debugFunction(String(fotaSampRate_mqtt),1);
             fotaSampRate = fotaSampRate_mqtt;              //Se guarda el valor recibido en una variable global.
          }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"actualiza\" palabra clave no encontrada en JSON",1);
      }
      
      // ---------------------- Envia ---------------------- 
      
      if(root.containsKey("envia"))  //Comprueba si existe el campo/clave.
       {
        if(root["envia"] == -1)
          debugFunction("envia = null. No se han hecho modificaciones",1);
        else
        {
           int dataSampRate_mqtt = root["envia"];     //Obtiene el valor recibido.
           debugFunction("Mensaje OK, envia = ",0);
           debugFunction(String(dataSampRate_mqtt),1);
           dataSampRate = dataSampRate_mqtt;          //Se guarda el valor recibido en una variable global.
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"envia\" palabra clave no encontrada en JSON",1);
      }
      
      // ---------------------- Velocidad ---------------------- 
      
      if(root.containsKey("velocidad"))               //Comprueba si existe el campo/clave.
      {
        if(root["velocidad"] == -1)
          debugFunction("velocidad = null. No se han hecho modificaciones",1);
        else
        { 
         int ledspeed_mqtt = root["velocidad"];       //Obtiene el valor recibido.
         debugFunction("Mensaje OK, velocidad = ",0);
         debugFunction(String(ledspeed_mqtt),1);
         ledspeed = ledspeed_mqtt;                    //Se guarda el valor recibido en una variable global.
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"velocidad\" palabra clave no encontrada en JSON",1);
      }
      
      // ---------------------- LED_config ---------------------- 
      
       if(root.containsKey("LED"))                //Comprueba si existe el campo/clave.
       {
        if(root["LED"] == -1)
          debugFunction("LED = null. No se han hecho modificaciones",1);
        else
        { 
           int valor_led_mqtt_config = root["LED"];         //Obtiene el valor recibido.
           debugFunction("Mensaje OK, LED (config) = ",0);
           debugFunction(String(valor_led_mqtt_config),1);
           
           if(valor_led_mqtt_config)         //Interpreta el valor recibido.
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
        debugFunction("\"LED\" palabra clave no encontrada en JSON",1);
      }
      
       // ---------------------- SWITCH_config ---------------------- 
       
       if(root.containsKey("SWITCH"))                //Comprueba si existe el campo/clave.
       {
        if(root["SWITCH"] == -1)
          debugFunction("SWITCH = null. No se han hecho modificaciones",1);
        else
        {        
           int valor_switch_mqtt_config = root["SWITCH"];  //Obtiene el valor recibido.
           debugFunction("Mensaje OK, SWITCH (config) = ",0);
           debugFunction(String(valor_switch_mqtt_config),1);
           
           if(valor_switch_mqtt_config)       //Interpreta el valor recibido.
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
        debugFunction("\"SWITCH\" palabra clave no encontrada en JSON",1);
      }
      
      // ---------------------- Logica Negativa ----------------------
       
      if(root.containsKey("Logica_negativa"))     //Comprueba si existe el campo/clave.
      {
        if(root["Logica_negativa"] == -1)
          debugFunction("Logica negativa = null. No se han hecho modificaciones",1);
        else
        {        
           bool valor_Logica_negativa_mqtt_config = root["Logica_negativa"];  //Obtiene el valor recibido.
           debugFunction("Mensaje OK, Logica Negativa = ",0);
           debugFunction(String(valor_Logica_negativa_mqtt_config),1); 
           logica_negativa=valor_Logica_negativa_mqtt_config;                 //Se guarda el valor recibido en una variable global.
        }
      }
      else
      {
        debugFunction("Error : ",0);
        debugFunction("\"Logica Negativa\" palabra clave no encontrada en JSON",1);
      }
    }
    
  }
//-------------------------  FOTA  -------------------------  

  if(strcmp(topic,TOP_FOTA)==0)
  {
    StaticJsonDocument<24> root;          
    DeserializationError error = deserializeJson(root, mensaje);    //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("actualiza"))          //Comprueba si existe el campo/clave.
    {
       actualiza = root["actualiza"];                 //Obtiene el valor recibido.
       debugFunction("Mensaje OK, actualiza = ",0);
       debugFunction(String(actualiza),1);            //Se guarda el valor recibido en una variable global.
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"actualiza\" palabra clave no encontrada en JSON",1);
    }
  }

//-------------------------  MOVIMIENTO  -------------------------  
  
  if(strcmp(topic,TOP_Movimiento)==0)
  {
    StaticJsonDocument<24> root; 
    DeserializationError error = deserializeJson(root, mensaje);  //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",0);
      debugFunction(error.c_str(),1);
    }
    else if(root.containsKey("orden"))  //Comprueba si existe el campo/clave.
    {
       orden = root["orden"];             //Se guarda el valor recibido en una variable global.
       velocidad();                       //Se llama a la funcion que interpreta el dato recibido.
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"orden\" palabra clave no encontrada en JSON",1);
    }
  } 

//-------------------------  MODO  -------------------------  

  if(strcmp(topic,TOP_Modo)==0)
  {
    StaticJsonDocument<128> root; 
    DeserializationError error = deserializeJson(root, mensaje);  //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",1);
      debugFunction(error.c_str(),0);
    }
    else if(root.containsKey("Modo"))   //Comprueba si existe el campo/clave.
    {
       modo = root["Modo"];               //Se guarda el valor recibido en una variable global.
       control_modo();                    //Se llama a la funcion que interpreta el dato recibido.
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"modo\" palabra clave no encontrada en JSON",1);
    }
  }
  
//-------------------------  CONFIG_PLACA  ------------------------- 

  if(strcmp(topic,TOP_configPlaca)==0)
  {
    StaticJsonDocument<128> root; 
    DeserializationError error = deserializeJson(root, mensaje);    //Deserializa el mensaje.

    // Compruebo si hubo error.
    if (error) 
    {
      debugFunction("Error deserializeJson() failed: ",1);
      debugFunction(error.c_str(),0);
    }
    else if(root.containsKey("placa"))  //Comprueba si existe el campo/clave.
      {
        if(root.containsKey("CHIPID"))  //Comprueba si existe el campo/clave.
        { 
            String ID = root["CHIPID"];
            int aux;                    //Variable auxiliar.
            debugFunction("CHIPID recibida:",1);
            debugFunction(ID,1);
            
            if (ID == datos.chipId)    // Compruebo que es el chipid correcto, es un topic de BROADCAST.
            {
              debugFunction("CHIPID coincide:",1);
              aux = root["placa"];
              
              if (aux != placa)        //Solo actualizo la placa cuando ha cambiado.
              {
                placa = root["placa"];
                debugFunction("Actualizado el numero de placa:",1);
                debugFunction(String(placa),1);
                
                if (client.connected())   //Se desconecta del servidor MQTT
                {
                  debugFunction("cliente desconectado:",1);
                  client.disconnect();
                  delay (500);
                }
                mqttSetup (); //Funcion para conectarse al broker MQTT con el nuevo numero de placa.
                mqttTopics(); //Reescribe los topics
              }  
            }
            else
              debugFunction("numero de placa coincide, no se actualiza",1); 
       }
    }
    else
    {
      debugFunction("Error : ",0);
      debugFunction("\"placa\" palabra clave no encontrada en JSON",1);
    } 
  }
   
  free(mensaje); //Se libera memoria.

}// END CALLBACK

void reconnect()  // Funcion de reconexion en caso de fallo (además de la primera conexion) del CLIENTE MQTT.
  {
    while (!client.connected())  // Intenta reconectar el MQTT (hasta exito).
    {
      Serial.print("Estableciendo conexión MQTT........");
      String clientId = "ESP8266Client-";         // Crea un  cliente ID basado en el ChipId.
      char JSon_Msg[64];                          // Crea un char de 64 bits.
      datos.chipId= ESP.getChipId ();             // Asegura que el chipId sea el correcto antes de utilizarlo en cada reconexion.
      clientId += String(datos.chipId) ;          // Establece el id del cliente MQTT.
      debugFunction (clientId.c_str(),1);
      
      sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"false\",\"grupo\":\"%i\",\"placa\":\"%i\"}",datos.chipId.c_str(),grupo,placa);   //Serializa en formato JSON el mensaje de ultima voluntad.
         //debugFunction("mqtt:set LWill to :",1);
         //debugFunction(JSon_Msg,1);
        
      if (client.connect(clientId.c_str(),mqtt_user,mqtt_psw,TOP_conexion,0 ,true ,(const char*)JSon_Msg ))  //Establece la conexion al mqtt y configura LWT: "conexion:false"  //ej:  boolean rc = mqttClient.connect("myClientID", willTopic, willQoS, willRetain, willMessage); 
        {
          sprintf (JSon_Msg,"{\"CHIPID\":\"%s\",\"online\":\"true\",\"grupo\":\"%i\",\"placa\":\"%i\"}",datos.chipId.c_str(),grupo,placa);  //Serializa en formato JSON el mensaje de conexion.
          //debugFunction("mqtt:conectado",1);
          //debugFunction(JSon_Msg,1);
  
          //Subscripciones a los diferentes topics:
          
          client.setBufferSize(512); // Tamaño bufer 512bytes
          client.subscribe(TOP_ledCmd);
          client.subscribe(TOP_config);
          client.subscribe(TOP_configPlaca);
          client.subscribe(TOP_switchCmd);
          client.subscribe(TOP_FOTA);
          client.subscribe(TOP_Movimiento);
          client.subscribe(TOP_Modo);
          client.publish(TOP_conexion,(const char*)JSon_Msg,true); //Publica el estado de la conexion=true en el topic "conexion"
        } 
      else  // fallo en la conexion mqtt
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        delay(5000);        //Espera 5 segndos para volever a intentar la conexion.
      }
    }
}// END RECONECT

void mqttSetup ()                 //Funcion para conectarse al broker MQTT.
  {
    debugFunction ("Servidor MQTT:",0);
    debugFunction (mqtt_server,1);    
    client.setServer(mqtt_server, mqtt_port); // Establecimiento de la conexion al broker MQTT (Nombre y puerto declarados en config.cpp).
    client.setCallback(callback); 
  }

void mqttTopics() // Funcion que establece los topics de conexion. Añade el numero de grupo y el numero de placa a cada topic.
                  // Topic Raiz "infind/GRUPO%i/ESP%i/%s" en donde %i indican (numero de grupo y numero de placa resp.) y %s indica el topic en cuestion (pej: datos, conexion, etc.)
{
  String aux;       // Almacenamiento temporal del topic.

  aux=s_TOP_conexion;
  memset(TOP_conexion, 0, sizeof(TOP_conexion));                // Resetea la variable que contiene el topic
  sprintf(TOP_conexion, TOP_generic ,grupo,placa,aux.c_str());  // Añade el topic raiz , el numero de grupo, numero de placa y el topic en cuestion. Se hace de forma identeica en el resto de topics.

  aux=s_TOP_datos;
  memset(TOP_datos, 0, sizeof(TOP_datos));
  sprintf(TOP_datos,TOP_generic,grupo,placa,aux.c_str());
  
  aux=s_TOP_config;
  memset(TOP_config, 0, sizeof(TOP_config));
  sprintf(TOP_config,TOP_generic,grupo,placa,aux.c_str());

  aux=s_TOP_configPlaca;
  memset(TOP_configPlaca, 0, sizeof(TOP_configPlaca));
  sprintf(TOP_configPlaca,TOP_generic,grupo,0,aux.c_str());

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

  
