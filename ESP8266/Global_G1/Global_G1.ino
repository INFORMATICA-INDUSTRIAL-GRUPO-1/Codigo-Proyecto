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
// Pestaña:Global
// Descripcion del codigo
//
//




////////////////////Seccion librerias y pestañas//////////////////////////////
//Librerias//
// Incluir aqui las librerias//

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
#include <ESP8266httpUpdate.h>
#include <ArduinoJson.h>


////////////////////Seccion variables globales//////////////////////////////
// Declarar aqui las variables globales//
unsigned long lastMsg = 0;

// FOTA
unsigned long lastFOTA = 0;

//Regulacion Led:

unsigned long lastLed = 0;
int inten_Led = 0; //Valor de escritura en el Led.
int valor_maped = 0; //[0 1023] (primera inicializacion)



bool ledState = false;
byte times = 0;






//Pestañas//
// Incluir aqui las pestañas//
#include "config.h"
#include "wifi.h"
#include "mqtt.h"
#include "fota.h"
#include "datos.h"
#include "debug.h"
#include "pulsos.h"
#include "interrupciones.h"



void setup() {
 // Configuracion Inicial del ESP8266
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  pinMode(16, OUTPUT); //Inicializa el pin 2 (GPIO 16) como pin de salida.
  digitalWrite(16, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);//se declara el boton como entrada
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), RTI, CHANGE); //activacion de la interrupcion 
  Serial.begin(115200); // Puerto serie Establecimiento
  setup_wifi(); //llamada a la funcion de config. del WiFi

  FuncionActualizacion(); //LLamamos a la funcion para que actualice el programa

  debugFunction ("Establecimiento de MQTT",1);
  mqttSetup (); //Llamada a la funcion de setup de mqtt
  
  dht.setup(DHT_PIN, DHTesp::DHT11); // Connect DHT sensor to GPIO 17

  if(debug){
    debugFunction ("Datos para debug",0);
    tomaDatos(datos);
    serializa_datos_JSON ().toCharArray (msg,512); // Serializacion de los datos del archivo json para su publicacion
    }
  

}// END SETUP

/*-------------------------  LOOP  ------------------------*/
void loop() {
  
  if (!client.connected()) // Comprobacion y reconexion (en caso de fallo) del cliente mqtt
  { 
    reconnect();
  }
  client.loop(); // look for new message in MQTTprotocol

  unsigned long now = millis(); // Toma del tiempo actual en ms
  
// END comprobacion y reconexion

/*-------------------------  LedCmd  ------------------------*/

  if (ready_led)
  {
      pulsos(); //Interpreta los pulsos de la interrupcion.
      ultima_pulsacion = millis(); //Guarda en p1 el tiempo de la ultima pulsacion.
      funcion_flash(); //Interpreta, con el "codigo pulso", que hacer en la placa (ON/OFF, FOTA...)
      led_mqtt(); // Publica el valor del led actualizado.
      ready_led = false; //Variable para no volver a entrar en el IF.
  }
  
  if (led_valor1 > 100)   //restringe valor entre 0 upto 100
        led_valor1 = 100;
  else if (led_valor1 < 0)
      led_valor1 = 0;

  if (now >= lastLed + ledspeed) //if_1 (entra cada 10 ms)
  {    
    if (inten_Led != led_valor1) //if_2
    {
      if (inten_Led < led_valor1) //aumenta 1 cuando es menor
          inten_Led++;
      else if (inten_Led > led_valor1) //disminuye 1 cuando es mayor
          inten_Led--;
        
      valor_maped = 1023-(inten_Led*10.23);// Remapeo de valor [0-1023] e inversion para que el 100% se corresponda a led encendido y 0% =>> led apagado
      analogWrite (BUILTIN_LED,valor_maped); // Escribe en el puerto BUILTIN_LED el valor remapeado
      lastLed = now;
    /*-------------------------  Debug  ------------------------
      Serial.print("Valor_actual: "); //Debug Serial
      Serial.println(inten_Led);
      Serial.println();*/
      }//if_2
    }//if_1
if((now-lastFOTA > fotaSampRate*60000) && (fotaSampRate != 0)||(actualiza==1))
{
  FuncionActualizacion();
  lastFOTA=now;
  actualiza=0;
}
if (now - lastMsg > dataSampRate*1000) //DATOS =>> ejecucion cada 5 min (por defecto) =>> Asigna los valores y Publica el topic datos
{
  lastMsg = now;

  
  tomaDatos(datos); //actualiza los valores de "datos"
  
 serializa_datos_JSON ().toCharArray (msg,512); // Serializacion de los datos del archivo json para su publicacion
 client.publish("infind/GRUPO1/datos", msg, true); //publicacion del mensaje "datos" como retenido
 Serial.print("Temp:");
 Serial.println(datos.temperatura);
  
  
}//END DATOS 
   


  
}// END LOOP
