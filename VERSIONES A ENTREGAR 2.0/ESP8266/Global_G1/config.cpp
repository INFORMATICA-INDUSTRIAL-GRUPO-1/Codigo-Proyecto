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
// Pestaña: config
// Descripcion del codigo
//
// Se encarga de declarar y gestionar todas las variables que tienen
// que ver con la configuración del programa. 
// Con respecto a los topics, se han preparado para ser flexibles


#include <Arduino.h>
#include "config.h"

//-------------------------  GPIO's  -------------------------  

byte DHT_PIN=5; ///Pin de conexion de datos del DHT11
byte SWITCH_PIN = 16; //Pin de conexion del swich
byte LED_PIN=BUILTIN_LED; // Led de la placa
byte BUTTON_PIN = 0; // Boton de Flash de la placa ESP8266

//-------------------------  Debug Por Puerto Serie  -------------------------  

bool debug = true;

//-------------------------  FOTA  -------------------------  

String OTAfingerprint("5d56095c5f7ba43f01b72231d3a7daa36e102e60"); // sustituir valor

//-------------------------  CONFIGURACION WiFi & MQTT  -------------------------  

//const char* ssid = "MOVISTAR_1F74"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "vK3yLb5r6i7W5zM3nYNE"; // CLAVE DE LA RED WIFI

//const char* ssid = "MOVISTAR_1F74"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "vK3yLb5r6i7W5zM3nYNE"; // CLAVE DE LA RED WIFI

//const char* ssid = "TOTOLINK_N300RH_Pri"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "AlHaMbRa_2.718"; // CLAVE DE LA RED WIFI

const char* ssid = "Manu_2s"; // PONER EL NOMBRE DE LA RED WIFI
const char* password = "Srmonline";// CLAVE DE LA RED WIFI

//const char* ssid = "Pabloski587"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "pablovera"; // CLAVE DE LA RED WIFI

//const char* ssid = "prueba"; // PONER EL NOMBRE DE LA RED WIFI
//const char* password = "12345678"; // CLAVE DE LA RED WIFI

const char* mqtt_server = "iot.ac.uma.es" ;//  IP DEL BROKER MQTT (IP de la maquina Fisica (PC,RPI,iot.uma...,etc) (NO de la maquina virtual)) 
int mqtt_port = 1883;
const char* mqtt_user = "infind";
const char* mqtt_psw = "zancudo";

const char* AP_ssid = "ESP8266"; //"ESP8266" SSid del AccesPoint para wificonfig
const char* AP_password = "ESP8266_12"; //psw del AccesPoint para wificonfig

byte max_reconnect = 5; // intentos de reconexion antes de configurar el "AccesPoint"

//-------------------------  TOPICS MQTT  -------------------------  

String s_TOP_conexion = "conexion";          
String s_TOP_datos = "datos"; 
String s_TOP_config = "config"; 
String s_TOP_configPlaca = "config/placa"; 
String s_TOP_ledCmd = "led/cmd";  
String s_TOP_ledStatus = "led/status"; 
String s_TOP_switchCmd = "switch/cmd"; 
String s_TOP_switchStatus = "switch/status"; 
String s_TOP_FOTA = "FOTA";
String s_TOP_FOTA_updt = "FOTA/actualizado"; 
String s_TOP_sensores = "PIERO/Sensores"; 
String s_TOP_Movimiento = "PIERO/Movimiento";
String s_TOP_Modo = "PIERO/Modo";
String s_TOP_Obstaculo = "PIERO/Obstaculo";


char TOP_generic[48] ="infind/GRUPO%i/ESP%i/%s";

char TOP_conexion[48] = "conexion"; 
            
char TOP_datos[48] = "datos"; 

char TOP_config[48] = "config"; 

char TOP_configPlaca[48] = "config/placa"; 

char TOP_ledCmd[48] = "led/cmd";  

char TOP_ledStatus[48] = "led/status"; 

char TOP_switchCmd[48] = "switch/cmd"; 

char TOP_switchStatus[48] = "switch/status"; 

char TOP_FOTA[48] = "FOTA";

char TOP_FOTA_updt[48] = "FOTA/actualizado"; 

char TOP_sensores[48] = "PIERO/Sensores"; 

char TOP_Movimiento[48] = "PIERO/Movimiento";

char TOP_Modo[48] = "PIERO/Modo";

char TOP_Obstaculo[48] = "PIERO/Obstaculo";


//-------------------------  Parametros  -------------------------  

int dataSampRate = 5*60;  // Tiempo entre publicaciones de los datos en SEGUNDOS.
int fotaSampRate = 0;     // Tiempo entre busqueda de nuevas actualizaciones en MINUTOS (0 para deshabilitar la comprobacion por tiempo).
int ledspeed = 10 ;       // Velocidad a la que se modifica los cambios en la intensidad del LED, en MILISEGUNDOS.


bool logica_negativa=true;

int actualiza = 0; 
int orden = -1;
int modo = 0;

byte grupo = 1;
byte placa = 0;
byte num_sensores = 5;
