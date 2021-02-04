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
// Pestaña: datos
// Descripcion del codigo
//
// Contiene las funciones para gestionar los datos que se manejan en el programa
// y las funciones necesarias para publicar por MQTT.
//


//-------------------------  Seccion librerias y pestañas  -------------------------

#include <Arduino.h>
#include "DHTesp.h"
#include <ArduinoJson.h>
//#include <Arduino_JSON.h>
#include <PubSubClient.h>


#include "datos.h"
#include "../debug/debug.h"
#include "../config/config.h"
#include "../mqtt/mqtt.h"
#include "../pulsos/pulsos.h"
#include "../wifi/wifi.h"

//-------------------------  DECLARACIONES  -------------------------

ADC_MODE (ADC_VCC);     //Conecta el pin Analogico A0 a la alimentacion.
char msg[512];          //Se crea msg para poder enviarlo por MQTT mas adelante.

DHTesp dht;             //Instancia el objeto DHTesp como dht.
registro_datos datos ;  //Instancia el struct "datos".

//-------------------------  FUNCIONES  -------------------------

   String serializa_datos_JSON () // Funcion de formateo a JSON y luego serializacion.
{
  StaticJsonDocument <512> jsonRoot;  // Crea obj JSON para "datos".

  String jsonString = "";             //Se inicializa vacio.

    //FORMATEO DE "DATOS" A JSON.

  jsonRoot["CHIPID"]= datos.chipId; //Guarda en un objeto JSON (en este caso CHIPID) el valor de datos.chipId. El resto de campos se rellenan de identica forma.
  jsonRoot["MAC"] = datos.MAC;
  jsonRoot["Uptime"]= datos.tiempo;

  JsonObject ESP_=jsonRoot.createNestedObject("ESP_"); // Crea un subobjeto JSON para "ESP_".
    ESP_["placa"] = placa;
    ESP_["grupo"] = grupo;

  jsonRoot["Vcc"]= datos.Vcc;

  JsonObject DHT_11=jsonRoot.createNestedObject("DHT11"); // Crea un subobjeto JSON para "DHT_11".
  DHT_11["temp"] = datos.temperatura;
  DHT_11["hum"] = datos.humedad;

  jsonRoot["LED"]=datos.led;
  jsonRoot["SWITCH"]=datos.Switch;

  JsonObject _WIFI=jsonRoot.createNestedObject("Wifi"); // Crea un subobjeto json para "_WiFi".
  _WIFI["SSid"]=datos.SSID_wifi;
  _WIFI["IP"]= datos.IP_wifi;
  _WIFI["RSSI"]=datos.RSSI_wifi;

  serializeJson(jsonRoot,jsonString);   //Funcion que serializa el mensajge en formato JSON.

  debugFunction (jsonString,1);
  return jsonString; // Devuelve la Serializacion del json "root" creado.
}


float voltageSense ()
{
  float voltage = 0;
  voltage =round (ESP.getVcc());  //Obtiene el valor en milivoltios de la tension de alimentacion.
                                  //Se redondea para asi al convertirlo a voltios se obtienen menos decimales.

  voltage = (voltage/1000.0); // Transforma el valor a voltios.
  return voltage;
}

void tomaDatos (struct registro_datos &datos) //Funcion que toma los datos de los distintos sensores y los guarda en el struct "datos".
{
  datos.chipId = ESP.getChipId();
  datos.MAC = String(WiFi.macAddress());
  datos.tiempo = millis();                //Tiempo de ejecucion desde el ultimo reinicio.
  datos.Vcc=voltageSense ();              //Toma de voltaje de entrada.
  datos.temperatura=dht.getTemperature(); //Toma de la temperatura en el sensor DHT11.
  datos.humedad=dht.getHumidity();        //Toma de la humedad en el sensor DHT11.
  datos.SSID_wifi= ssid;                  //Toma del SSid del WiFi.
  datos.IP_wifi  = ip ;                   //Toma de la IP del ESP 8266
  datos.RSSI_wifi= ssidReq();             //Toma del RSSI del WiFi. (Llamada a funcion ssidReq() en wifi.cpp).
  }

void led_mqtt()                       // Funcion que publica por MQTT el valor de LED.
{
  StaticJsonDocument<512> jsonRoot;

  datos.led = led_actual;             // Guarda el ultimo valor recibido.
  jsonRoot["CHIPID"] = ESP.getChipId();
  jsonRoot["led"] = led_actual;       //Convierte el estado del LED a JSON para ACK al broker mqtt.
  jsonRoot["origen"] = origen_led;

  if(origen_led=="mqtt")
  {
    jsonRoot["id"]=id;              //Id solo se rellena cuando se ha modificado por Telegram (id necesaria para comunicarse con el usuario de forma correcta).
  }                                 //Si se hace mediante el dashboard, el campo id estara vacio.
  origen_led = "";

  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_ledStatus, msg); //Publicacion del estado del LED

}

void switch_mqtt()                       // Funcion que publica por MQTT el valor de switch.
{
   StaticJsonDocument<512> jsonRoot;
   if(switch_valor)
      datos.Switch = false;
   else
      datos.Switch = true;

  jsonRoot["CHIPID"] = ESP.getChipId();
  jsonRoot["Switch"] = datos.Switch;      //Convierte el estado del switch a JSON para ACK al broker MQTT.
  jsonRoot["origen"] = origen_switch;

  if(origen_switch=="mqtt")
  {
    jsonRoot["id"]=id;              //Id solo se rellena cuando se ha modificado por Telegram (id necesaria para comunicarse con el usuario de forma correcta).
  }                                 //Si se hace mediante el dashboard, el campo id estara vacio.
  origen_switch = "";

  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_switchStatus, msg);  //Publicacion del estado del switch.
}

  void actualiza_mqtt()
{
  StaticJsonDocument<100> jsonRoot;


  jsonRoot["ultimaFOTA"] = 1;                           //Envia una señal para indicar que se va a actualizar.
  JsonObject ESP_=jsonRoot.createNestedObject("ESP_");  //Crea un subobjeto json para "ESP_"
    ESP_["placa"] = placa;
    ESP_["grupo"] = grupo;
  serializeJson(jsonRoot,msg);

  debugFunction (msg,1);
  client.publish(TOP_FOTA_updt, msg);
}

void sensores_mqtt()                       // Funcion que publica por MQTT el valor de los sensores del robot.
{
  StaticJsonDocument<128> jsonRoot;

  JsonObject Sensores=jsonRoot.createNestedObject("Sensores"); // Crea un subobjeto json para "Sensores"


  jsonRoot["Num_Sensores"] = num_sensores;
  Sensores["1"] = sensor1;
  Sensores["2"] = sensor2;
  if(num_sensores == 5){            //Para no crear conflictos, en caso de tener 2 sensores, estos valores no se envian
    Sensores["3"] = sensor3;
    Sensores["4"] = sensor4;
    Sensores["5"] = sensor5;
  }

  serializeJson(jsonRoot,msg);

  client.publish(TOP_sensores, msg);

}
