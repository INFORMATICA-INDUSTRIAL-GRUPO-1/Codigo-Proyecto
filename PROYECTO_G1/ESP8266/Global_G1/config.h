#ifndef config_h

  #define config_h
  
  #include <Arduino.h>
  
  extern bool debug;
  
  //--------------------  CONFIGURACION DE LOS PARÁMETROS DEL SERVIDOR DE ACTUALIZACIONES FOTA  --------------------  
  
  #define OTA_URL "https://iot.ac.uma.es:1880/esp8266-ota/update"       //Direccion del servidor OTA para la actualizacion.
  #define HTTP_OTA_VERSION   String(__FILE__).substring(String(__FILE__).lastIndexOf('\\')+1)+".nodemcu"
  extern String OTAfingerprint;
  
  //-------------------------  GPIO's  -------------------------  
  
  extern byte DHT_PIN;
  extern byte SWITCH_PIN;
  extern byte LED_PIN;
  extern byte SWITCH_PIN; 
  
  extern const char* ssid ;
  extern const char* password;
  extern const char* mqtt_server;
  extern int mqtt_port;
  extern const char* mqtt_user;
  extern const char* mqtt_psw;
  extern const char* AP_ssid;
  extern const char* AP_password;
  extern byte max_reconnect;
  
  //-------------------------  TOPICS MQTT  -------------------------  
  
  extern String s_TOP_generic;
  extern String s_TOP_conexion;
  extern String s_TOP_datos;
  extern String s_TOP_config;
  extern String s_TOP_configPlaca;
  extern String s_TOP_ledCmd;
  extern String s_TOP_ledStatus;
  extern String s_TOP_switchCmd;
  extern String s_TOP_switchStatus;
  extern String s_TOP_FOTA;
  extern String s_TOP_FOTA_updt;
  extern String s_TOP_sensores;
  extern String s_TOP_Movimiento;
  extern String s_TOP_Modo;
  extern String s_TOP_Obstaculo;
  
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
  extern char TOP_Movimiento[48];
  extern char TOP_Modo[48];
  extern char TOP_Obstaculo[48];
  
  //-------------------------  PARAMETROS  -------------------------  
  
  extern bool logica_negativa;
  extern byte grupo;
  extern byte placa;
  extern byte num_sensores;
  extern int dataSampRate ; //En Segundos
  extern int fotaSampRate ;//En minutos
  extern int ledspeed;

#endif
