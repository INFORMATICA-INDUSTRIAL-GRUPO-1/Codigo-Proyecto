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
// Ultima modificacion: 21/12/2020 a 21:09 (Manuel Valle Delgado)
// 
// Pestaña:Global
// Descripcion del codigo
//
//




/*-------------------------  PESTAÑAS Y LIBRERIAS  ------------------------*/ 
 

// Incluir aqui las librerias//
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHTesp.h"
#include <ESP8266httpUpdate.h>
#include <ArduinoJson.h>


/*-------------------------  VARIABLES GLOBALES  ------------------------*/ 
// Declarar aqui las variables globales//
// Envio de datos
unsigned long lastMsg = 0;

// FOTA
unsigned long lastFOTA = 0;

//Regulacion Led:
unsigned long lastLed = 0;
int inten_Led = 0;        //Valor de escritura en el Led.
int valor_maped = 0;      //[0 1023] (primera inicializacion)
bool ledState = false;
byte times = 0;

unsigned long lastSensores = 0;

bool primera_FOTA=true;
/*-------------------------  PESTAÑAS  ------------------------*/ 

// Incluir aqui las pestañas ".h"//
#include "config.h"
#include "wifi.h"
#include "mqtt.h"
#include "fota.h"
#include "datos.h"
#include "debug.h"
#include "pulsos.h"
#include "interrupciones.h"
#include "robot_2sens.h"
#include "robot_5sens.h"
#include "cont_vel.h"


/*-------------------------  SETUP  ------------------------*/
void setup() {
 // Configuracion Inicial del ESP8266
  pinMode(BUILTIN_LED, OUTPUT);       // Initialize the BUILTIN_LED pin as an output
  pinMode(SWITCH_PIN, OUTPUT);        // Inicializa el pin 2 (GPIO 16) como pin de salida.
  digitalWrite(SWITCH_PIN, LOW);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  //Se declara el boton como entrada
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), RTI, CHANGE); //Activacion de la interrupcion 
  Serial.begin(115200);               // Puerto serie Establecimiento
  setup_wifi();                       // Llamada a la funcion de config. del WiFi

  

  //Configuracion Server MQTT y topics
  debugFunction ("Establecimiento de MQTT",1);
  mqttSetup ();                       // Llamada a la funcion de setup de mqtt
  mqttTopics();                       // Carga los topics 
  dht.setup(DHT_PIN, DHTesp::DHT11);  // Connect DHT sensor to GPIO 17

  //Indicador de la activación del modo debug (Se activa en config)
  if(debug){                          //establecer manualmente debug en true para activarlo      
    debugFunction ("Datos para debug",0); //texto enviado para el debug
    }
  
}        // END SETUP


/*-------------------------  LOOP  ------------------------*/
void loop() {
  
  if (!client.connected())                          // Comprobacion y reconexion (en caso de fallo) del cliente mqtt
  { 
    reconnect();
    tomaDatos(datos);
    serializa_datos_JSON ().toCharArray (msg,512);  // Serializacion de los datos del archivo json para su publicacion
    client.publish(TOP_datos, msg, true);           //publicacion del mensaje "datos" como retenido al Inicializar la placa
  }
  client.loop();   // look for new message in MQTTprotocol
  
//Primera actualización
if(primera_FOTA)
{
  FuncionActualizacion();             //LLamamos a la funcion para que actualice el programa
  primera_FOTA=false;
}
  
  unsigned long now = millis();                     // Toma del tiempo actual en ms
  
// END comprobacion y reconexion


/*-------------------------  CONTROL LED Y SWITCH  ------------------------*/
  if (ready_led)                    // Se llama la interrupcion para asegurar que no se captan rebotes en la pulsacion
  {
      pulsos();                     // Interpreta los pulsos de la interrupcion.
      ultima_pulsacion = millis();  // Guarda en ultima_pulsación el tiempo de la ultima pulsacion.
      funcion_flash();              // Interpreta, con el "codigo pulso", que hacer en la placa (ON/OFF, FOTA...)
      led_mqtt();                   // Publica el valor del led actualizado. (Función en DATOS)
      ready_led = false;            // Variable para no volver a entrar en el IF.
  }

  if (ready_switch)
  {
    digitalWrite(SWITCH_PIN,switch_valor);
    switch_mqtt();
    ready_switch = false;
  }
  
  if (led_actual > 100)               // Restringe valor entre 0 y 100
        led_actual = 100;
  else if (led_actual < 0)
      led_actual = 0;
      
  if(ledspeed <= 0)
    ledspeed = 1;                     //Acota la velocidad de encendido/apagado del led  
    
  if (now >= lastLed + ledspeed)      //if_1  ledspeed recibido por mqtt(por defecto 10)
  {    
    if (inten_Led != led_actual)      //if_2
    {
      if (inten_Led < led_actual)     //aumenta 1 cuando es menor
          inten_Led++;
      else if (inten_Led > led_actual) //disminuye 1 cuando es mayor
          inten_Led--;
        
      valor_maped = 1023-(inten_Led*10.23);     // Remapeo de valor [0-1023] e inversion para que el 100% se corresponda a led encendido y 0% =>> led apagado
      analogWrite (BUILTIN_LED,valor_maped);    // Escribe en el puerto BUILTIN_LED el valor remapeado
      lastLed = now;
      }//if_2
    }//if_1

/*-------------------------  FOTA  ------------------------*/
    
if((now-lastFOTA > fotaSampRate*60000) && (fotaSampRate != 0)||(actualiza==1))
{
  FuncionActualizacion();
  lastFOTA=now;
  actualiza=0;
}

/*-------------------------  ENVIO DATOS  ------------------------*/
if(dataSampRate <= 0)
  dataSampRate = 1;                    //Se acota a 1 segundo el envio de datos en caso de recibir un dato no deseado.
  
if (now - lastMsg > dataSampRate*1000) //DATOS =>> ejecucion cada 5 min (por defecto) =>> Asigna los valores y Publica el topic datos
{
  lastMsg = now;

  
  tomaDatos(datos); //actualiza los valores de "datos"
  
  serializa_datos_JSON ().toCharArray (msg,512); // Serializacion de los datos del archivo json para su publicacion
  client.publish(TOP_datos, msg, true); //publicacion del mensaje "datos" como retenido
  Serial.print("Temp:");
  Serial.println(datos.temperatura);

}//END DATOS 

/*-------------------------  ENVIO SENSORES ROBOT  ------------------------*/

  sensores_arduino(); //lee los datos de los sensores constantemente para que no se acumulen en el buffer.
  
  if(dato_sensor && now - lastSensores > 1000)
   { 
     sensores2_mqtt();// envio a mqtt lectura sensores
     lastSensores = now;//variable para actualizacion
   }

  
}// END LOOP
