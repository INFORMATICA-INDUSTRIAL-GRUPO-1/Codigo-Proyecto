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
// Pestaña: pulsos
//
// Descripcion del codigo
//
// contiene dos funciones relativas a la identificación de las pulsaciones del botón Flash
// (corta, larga o doble) y la respuesta de la placa ante estos estímulos.
//


#include <Arduino.h> 
#include "interrupciones.h"
#include "pulsos.h"


//-------------------------  PULSOS  ------------------------

// Interpreta el tipo de pulsacion que se realiza
unsigned long ultima_pulsacion = 0;
int pulsacion = 0;

void pulsos()                                 //Interpreta los pulsos del boton y la duración de la pulsacion.
{   
    unsigned long ahora = millis();
    unsigned long espera = ahora - ultima_pulsacion;
    
    if (duracion < 2000 && espera <= 300)     //"pulsacion doble"
      pulsacion = 2;  
      
    else if (duracion < 2000)                //pulsacion corta.
      pulsacion = 1;  
       
    if (duracion >= 2000)                     //pulsacion larga.
      pulsacion = 100;
}

//-------------------------  CONTROL LED Y SWITCH ------------------------

int led_actual = 0;                       //Valor de prueba
int led_almacenado = 100;                 //Variable que guarda el valor de luminosidad del primer led.

bool switch_valor = false;                //Variable que guarda el valor del estado del switch.
bool ready_switch = false;

String origen_led = "";
String origen_switch = "";

void funcion_flash()
{
  switch (pulsacion)
  {
    case 1:                       // Pulsación Corta
      if(!logica_negativa)        //Dependiendo del tipo de logica que se este usando en los actuaodes, escribe 1 o 0 dependiendo del valor anterior.
        switch_valor = digitalRead(SWITCH_PIN);   //Escribe el valor en el pin del switch.
      else
        switch_valor = !digitalRead(SWITCH_PIN);
        
      
      origen_switch = "pulsador";   //Procedencia de la señal de cambio.
      ready_switch = true;          //Datos preparados, puede enviar por MQTT los datos de switch.

      
        if (led_actual != 0)        // Led encendido: se guarda el valor de intensidad en nueva variable y luego se apaga.
        {
           led_almacenado = led_actual; // Variable de reserva
           led_actual = 0;          // Estado apagado del led
        }
        else                        // Led apagado: se enciende con el valor de intensidad guardado.
          led_actual = led_almacenado;
      
      origen_led = "pulsador";      //Procedencia de la señal de cambio.
    break;
    
    case 2:                       //Pulsación doble.
     switch_valor = LOW;          //Switch encendido.
     origen_switch = "pulsador";
     ready_switch = true;
     led_actual = 100;            //LED a 100%
     origen_led = "pulsador";
    break;

    case 100:                     // Pulsación larga
     FuncionActualizacion();      // Actualización mediante FOTA
    break;
  }
}
