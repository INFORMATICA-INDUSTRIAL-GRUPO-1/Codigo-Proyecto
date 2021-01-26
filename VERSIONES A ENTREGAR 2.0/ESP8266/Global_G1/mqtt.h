#ifndef mqtt_h

  #define mqtt_h
  
  #include <Arduino.h>
  #include <PubSubClient.h>
  #include <ESP8266WiFi.h>
  #include <ArduinoJson.h>
  #include "wifi.h"
  #include "datos.h"
  #include "cont_vel.h"
  
  //-------------------------  VARIABLES  ------------------------- 
   
  extern PubSubClient client;
  extern WiFiClient espClient;
  extern const char* mqtt_server;
  extern int mqtt_port; 
  extern const char* mqtt_user;
  extern const char* mqtt_psw;
  extern int actualiza;
  extern int orden;
  extern int modo;
  extern String id;
  
  //-------------------------  TOPICS MQTT  -------------------------  
  
  extern byte grupo;
  extern byte placa;
  extern char TOP_generic[48];
  extern char TOP_conexion[48];
  extern char TOP_datos[48];
  extern char TOP_config[48];
  extern char TOP_configPlaca[48];
  extern char TOP_ledCmd[48];
  extern char TOP_ledStatus[48];
  extern char TOP_switchCmd[48];
  extern char TOP_switchStatus[48];
  extern char TOP_FOTA[48];
  extern char TOP_FOTA_updt[48];
  extern char TOP_sensores[48];
  
  //-------------------------  FUNCIONES  -------------------------  
  
  void callback(char* topic, byte* payload, unsigned int length);
  void reconnect();
  void mqttSetup ();
  void mqttTopics();

#endif
