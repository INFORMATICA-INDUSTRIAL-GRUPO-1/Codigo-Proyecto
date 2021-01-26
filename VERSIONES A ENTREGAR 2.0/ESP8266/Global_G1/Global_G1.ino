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
// Pestaña: Global
// Descripcion del codigo
//
// Este programa se encarga de administrar las diferentes partes del proyecto y servir de nexo entre ellas, logrando así una mejor organización.
//
// Este programa se encarga de administrar el estado de los leds incorporados en la placa,
// de realizar actualizaciones de firmware cuando corresponda y de enviar datos de la placa 
// y sensores al servidor MQTT. 

//-------------------------  PESTAÑAS Y LIBRERIAS  ------------------------

// Incluir aqui las librerias//
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
#include <ESP8266httpUpdate.h>
#include <ArduinoJson.h>


//-------------------------  VARIABLES GLOBALES  ------------------------ 

// Declarar aqui las variables globales

// Envio de datos
unsigned long lastMsg = 0;
unsigned long lastSensores = 0;

// FOTA
unsigned long lastFOTA = 0;
unsigned long primerFOTA = 0;
bool primera_FOTA=true;
bool prim_F=false;

//Regulacion Led:
unsigned long lastLed = 0;
int inten_Led = 0;        //Valor de escritura en el Led.
int valor_maped = 0;      //[0 1023] (primera inicializacion)

//-------------------------  PESTAÑAS  ------------------------ 

// Incluir aqui las pestañas ".h"//
#include "config.h"
#include "wifi.h"
#include "mqtt.h"
#include "fota.h"
#include "datos.h"
#include "debug.h"
#include "pulsos.h"
#include "interrupciones.h"
#include "robot_5sens.h"
#include "cont_vel.h"


//-------------------------  SETUP  ------------------------
void setup() {
 // Configuracion Inicial del ESP8266
  pinMode(BUILTIN_LED, OUTPUT);       // Inicializa BUILTIN_LED com pin de salida.
  pinMode(SWITCH_PIN, OUTPUT);        // Inicializa el pin 2 (GPIO 16) como pin de salida.
  digitalWrite(SWITCH_PIN, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  //Se declara el boton como entrada.
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), RTI, CHANGE); //Activacion de la interrupcion.
  Serial.begin(115200);               // Puerto serie Establecimiento.
  setup_wifi();                       // Llamada a la funcion de config del WiFi.
  mqttSetup ();                       // Llamada a la funcion de setup de MQTT.
  mqttTopics();                       // Carga los topics.
  dht.setup(DHT_PIN, DHTesp::DHT11);  // Se establece el pin 2 como pin para hacer lectutra del sensor DHT.
  
}        // END SETUP


//-------------------------  LOOP  ------------------------

void loop() {
  
  if (!client.connected())                          // Comprobacion y reconexion (en caso de fallo) del cliente mqtt.
  { 
    reconnect();
    tomaDatos(datos);
    serializa_datos_JSON ().toCharArray (msg,512);  // Serializacion de los datos del archivo json para su publicacion.
    client.publish(TOP_datos, msg, true);           // Publicacion del mensaje "datos" como retenido al Inicializar la placa.
  }
  client.loop();   // Comprueba si se reciben nuevos mensajes por MQTT.
  
  unsigned long now = millis();                     // Toma del tiempo actual en ms

  
//Primera actualización
if(primera_FOTA && placa!=0)
{
  prim_F=true;
  primerFOTA=now;
  primera_FOTA=false;
}

if (((primerFOTA-now)>30000) && prim_F)
{
  FuncionActualizacion();             //Llamamos a la funcion para que actualice el programa.
  prim_F=false;
}
  
// END comprobacion y reconexion


//-------------------------  CONTROL LED Y SWITCH  ------------------------

  if (ready_led)                    // Se llama la interrupcion para asegurar que no se captan rebotes en la pulsacion.
  {
      pulsos();                     // Interpreta los pulsos de la interrupcion.
      ultima_pulsacion = millis();  // Guarda en ultima_pulsación el tiempo de la ultima pulsacion.
      funcion_flash();              // Interpreta, con el "codigo pulso", que hacer en la placa (ON/OFF, FOTA...).
      led_mqtt();                   // Publica el valor del led actualizado. (Función en DATOS).
      ready_led = false;            // Variable para no volver a entrar en el IF.
  }

  if (ready_switch)                 // Se llama la interrupcion para asegurar que no se captan rebotes en la pulsacion.
  {
    if(!logica_negativa){           //Dependiendo de la lógica con la que se trabaje, se escrbie el valor recibido o su contrario.
      switch_valor=!switch_valor;
    }
    digitalWrite(SWITCH_PIN,switch_valor);
    switch_mqtt();                  //Publica el valor del swtich (Funcón en DATOS).
    ready_switch = false;           // Variable para no volver a entrar en el IF.
  }
  
  if (led_actual > 100)               // Restringe valor entre 0 y 100.
        led_actual = 100;
  else if (led_actual < 0)
      led_actual = 0;
      
  if(ledspeed <= 0)
    ledspeed = 1;                       //Acota la velocidad de encendido/apagado del LED.  
    
  if (now >= lastLed + ledspeed)        //ledspeed recibido por mqtt(por defecto 10).
  {    
    if (inten_Led != led_actual)     
    {
      if (inten_Led < led_actual)       //aumenta 1 cuando es menor.
          inten_Led++;
      else if (inten_Led > led_actual) //disminuye 1 cuando es mayor.
          inten_Led--;
        
      valor_maped = 1023-(inten_Led*10.23);     // Remapeo de valor [0-1023] e inversion para que el 100% se corresponda a led encendido y 0% =>> led apagado.
      if(!logica_negativa){                     // Cambio para pasar el valor de iluminación a lógica positiva.
        valor_maped = abs(1023-valor_maped);
      }
      analogWrite (BUILTIN_LED,valor_maped);    // Escribe en el pin BUILTIN_LED el valor remapeado.
      lastLed = now;
      }
    }

//-------------------------  FOTA  ------------------------
    
if((now-lastFOTA > fotaSampRate*60000) && (fotaSampRate != 0)||(actualiza==1))    //Entra cuando transcurre el periodo indicado, siempre y cuadno no sea 0. Puede entrar si se ha solicitado por MQTT.
{
  FuncionActualizacion();   //Llamada a la funcion de actualizacion.
  lastFOTA=now;             //Se guarda la ultima vez que se actualizo.
  actualiza=0;              //Para que no vuelva a entrar en el if.
}

//-------------------------  ENVIO DATOS  ------------------------
if(dataSampRate <= 0)
  dataSampRate = 1;                    //Se acota a 1 segundo el envio de datos en caso de recibir un dato no deseado.
  
if (now - lastMsg > dataSampRate*1000) //DATOS =>> ejecucion cada 5 min (por defecto) =>> Asigna los valores y Publica el topic datos
{
  lastMsg = now;

  tomaDatos(datos); //actualiza los valores de "datos".
  
  serializa_datos_JSON ().toCharArray (msg,512);  // Serializacion de los datos del archivo json para su publicacion.
  client.publish(TOP_datos, msg, true);           // Publicacion del mensaje "datos" como retenido.
  
}//END DATOS 

//-------------------------  ENVIO SENSORES ROBOT  ------------------------

  sensores_arduino(); //Lee los datos de los sensores constantemente para que no se acumulen en el buffer.
  
  if(dato_sensor)
     sensores_mqtt(); // Envio mediante mqtt la lectura de los sensores.
  
}// END LOOP
