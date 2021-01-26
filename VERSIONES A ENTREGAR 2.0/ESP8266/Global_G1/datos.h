#ifndef datos_h

  #define datos_h
  
  #include <Arduino.h>
  #include "DHTesp.h"
  #include <ArduinoJson.h>
  #include <PubSubClient.h>
  
  #include "config.h"
  #include "wifi.h"
  #include "mqtt.h"
  #include "robot_5sens.h"
  
  //-------------------------  VARIABLES  -------------------------  

  extern DHTesp dht;
  extern PubSubClient client;
  extern char msg[512];
  extern String ip;
  
  struct registro_datos  //Struct "datos" contiene los parámetros recogidos por los sensores
  {
    String chipId;
    String MAC;
    unsigned long tiempo;
    float Vcc;
    float temperatura;
    float humedad;
    byte led;
    bool switchState;
    String SSID_wifi;
    String IP_wifi;
    int RSSI_wifi;
    bool Switch;
  };
  
  extern struct registro_datos datos ;
  
  //-------------------------  FUNCIONES  ------------------------- 
  
  String serializa_datos_JSON ();//struct registro_datos datos
  float voltageSense ();
  void tomaDatos (struct registro_datos &datos);
  void led_mqtt();
  void switch_mqtt();
  void actualiza_mqtt();
  void sensores_mqtt();
  
#endif
