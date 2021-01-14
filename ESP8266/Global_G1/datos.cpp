// Programa Asignatura INFORMATICA INDUSTRIAL Grupo1
// Codigo ESP8266
// Version V.0.0.02
// Autores
//
//
//
//
//
// Fecha de creacion: 28/11/2020
// Ultima modificacion: 16/12/2020 (Manuel Valle Delgado)
// 
// Pestaña:datos.cpp
// Descripcion del codigo
//    Aqui se recogen las distintas variables que requieren configuracion
//

////////////////////Seccion librerias y pestañas//////////////////////////////
//Librerias//
#include <Arduino.h>
#include "DHTesp.h"
#include <ArduinoJson.h>
//#include <Arduino_JSON.h>
#include <PubSubClient.h>


#include "datos.h"
#include "debug.h"
#include "config.h"
#include "mqtt.h"
#include "pulsos.h"
#include "wifi.h"


////////////////////Declaraciones//////////////////////////////



ADC_MODE (ADC_VCC);//Conecta el pin Analogico A0 a la alimentacion
char msg[512];

DHTesp dht;       //instancia el objeto DHTesp como dht
registro_datos datos ;  // instancia el struct "datos"

///////FUNCIONES//////////////////////////////////////////
   String serializa_datos_JSON () // Funcion de formateo a json y luego Serializacion
{
  StaticJsonDocument <512> jsonRoot; // crea obj json para "datos"
  
  
  String jsonString = "";
  
    //FORMATEO DE "DATOS" A json

  jsonRoot["CHIPID"]= datos.chipId; 
  jsonRoot["Uptime"]= datos.tiempo; 
  jsonRoot["Vcc"]= datos.Vcc;
  JsonObject DHT_11=jsonRoot.createNestedObject("DHT11"); // crea un subobjeto json para "DHT11"
  DHT_11["temp"] = datos.temperatura;
  DHT_11["hum"] = datos.humedad;
  jsonRoot["LED"]=datos.led;
  jsonRoot["SWITCH"]=datos.Switch;
  JsonObject _WIFI=jsonRoot.createNestedObject("Wifi"); // crea un subobjeto json para "WiFi"
  _WIFI["SSid"]=datos.SSID_wifi;  
  //String IP_str = IpAddress2String(datos.IP_wifi); 
  _WIFI["IP"]= datos.IP_wifi;  
  _WIFI["RSSI"]=datos.RSSI_wifi;

 // jsonRoot["DHT11"]= DHT11; // añade el subobjeto "DHT11" json al json "root"
 // jsonRoot["Wifi"]= WIFI; // añade el subobjeto "WiFi" json al json "root"

  //Serial.print (jsonRoot); // Debug Serial
  serializeJson(jsonRoot,jsonString);

  debugFunction (jsonString,1);
  return jsonString; // Devuelve la Serializacion del json "root" creado
}


float voltageSense () {
  float voltage = 0;
  voltage =round (ESP.getVcc()); // obtiene el valor en milivoltios de la tension de alimentacion se redondea para asi al convertirlo a voltios se obtienen 2 decimales
  //Serial.println(voltage);
  voltage = (voltage/1000.0); // transforma el valor a voltios
  //Serial.println(voltage);
  //Serial.print("Vcc: "); // debug voltaje
  //Serial.println (voltage);  //debug voltaje
  return voltage;
  }

void tomaDatos (struct registro_datos &datos) // funcion que toma los datos de los distintos sensores y los guarda en el struct "datos"
{
  datos.chipId = ESP.getChipId();
  datos.tiempo = millis(); //tiempo de ejecucion desde el último reinicio
  datos.Vcc=voltageSense (); // toma de voltaje de entrada 
  datos.temperatura=dht.getTemperature(); // Toma de la tempreatura en el sensor DHT11
  datos.humedad=dht.getHumidity(); // Toma de la humedad en el sensor DHT11
  datos.SSID_wifi= ssid; //Toma del SSid del WiFi
  datos.IP_wifi  = ip ; // Toma de la IP del ESP 8266 
  datos.RSSI_wifi= ssidReq (); // Toma del RSSI del WiFi
  debugFunction (ip,1);
  }

void led_mqtt()                       // Funcion que tiene como entrada un valor entero [0-100], lo Remapea entre [0-1023] y publicacion del estado actual del led
{
  StaticJsonDocument<128> jsonRoot;
 
  datos.led = led_actual;             // Guarda el ultimo valor recibido
  jsonRoot["CHIPID"] = ESP.getChipId();
  jsonRoot["led"] = led_actual;       //Convierte el estado del led a json para ACK al broker mqtt
  jsonRoot["origen"] = origen_led;
  
  if(origen_switch=="mqtt")
  {
    jsonRoot["id"]=id;
  }
  origen_led = " ";
  
  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_ledStatus, msg); //publicacion del estado del led

}

void switch_mqtt()
{
   StaticJsonDocument<128> jsonRoot;
   if(switch_valor)
      datos.Switch = false;
   else
      datos.Switch = true;
      
  jsonRoot["CHIPID"] = ESP.getChipId();
  jsonRoot["Switch"] = datos.Switch;      //Convierte el estado del led a json para ACK al broker mqtt
  jsonRoot["origen"] = origen_switch;
  
  if(origen_switch=="mqtt")
  {
    jsonRoot["id"]=id;
  }
  
  origen_switch = " ";
  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_switchStatus, msg);  //publicacion del estado del led
}

  void actualiza_mqtt()
{
  StaticJsonDocument<100> jsonRoot;
 
   
  jsonRoot["ultimaFOTA"] = 1;//Envía una señal para indicar que se va a actualizar

  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_FOTA_updt, msg);
}

void sensores2_mqtt ()
{
  StaticJsonDocument<100> jsonRoot;

  JsonObject Sensores=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
  Sensores["1"] = sensor1;
  Sensores["2"] = sensor2;

  serializeJson(jsonRoot,msg);

  //debugFunction (msg,1);
  client.publish(TOP_sensores, msg);
 
}

void sensores2_mqtt ()
{
  StaticJsonDocument<128> jsonRoot;

  JsonObject Sensores=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
  Sensores["1"] = sensor1;
  Sensores["2"] = sensor2;
//  Sensores["3"] = sensor3;
//  Sensores["4"] = sensor4;
//  Sensores["5"] = sensor5;
    
  serializeJson(jsonRoot,msg);

  //debugFunction (msg,1);
  client.publish(TOP_sensores, msg);
 
}

void sensores2_mqtt ()
{
  StaticJsonDocument<128> jsonRoot;

  JsonObject Sensores=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
  Sensores["1"] = sensor1;
  Sensores["2"] = sensor2;
//  Sensores["3"] = sensor3;
//  Sensores["4"] = sensor4;
//  Sensores["5"] = sensor5;
    
  serializeJson(jsonRoot,msg);

  //debugFunction (msg,1);
  client.publish(TOP_sensores, msg);
 
}
