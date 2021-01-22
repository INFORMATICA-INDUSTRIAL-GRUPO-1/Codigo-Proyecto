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
// Ultima modificacion: 7/12/2020 (Manuel Valle Delgado)
// 
// Pestaña:pulsos
// Descripcion del codigo:
// Dependiendo de la duración de la pulsación, realizará disintas tareas.
// Aquí se encuentran las 2 funciones encargadas de darles sentido a las pulsaciones.


#include <Arduino.h> //libreria de arduino
#include "interrupciones.h"
#include "pulsos.h"


/*-------------------------  PULSOS  ------------------------*/
// Interpreta el tipo de pulsacion que se realiza
unsigned long ultima_pulsacion = 0;
int pulsacion = 0;

void pulsos()                                 //Interpreta los pulsos del boton y la duración de la pulsacion.
{   
    unsigned long ahora = millis();
    unsigned long espera = ahora - ultima_pulsacion;
    if (duracion < 1500 && espera <= 300)     //"pulsacion doble"
    {
        pulsacion = 2;
    }//if
     else if (duracion < 2000)                //pulsacion corta
    {
        pulsacion = 1;
    }//else if
       
    if (duracion >= 2000)                     //pulsacion larga.
    {
        pulsacion = 100;
    }
}                 //Fin pulsos

/*-------------------------  CONTROL LED Y SWITCH ------------------------*/
int led_actual = 0;            //valor de prueba
int led_almacenado = 100;                 //variable que guarda el valor de luminosidad del primer led.

bool switch_valor = false;               //variable que guarda el valor del estado del segundo led.
bool ready_switch = false;

String origen_led = " ";
String origen_switch = " ";

void funcion_flash()
{
  switch (pulsacion)
  {
    case 1:                       // Pulsación Corta
      if(!logica_negativa)
        switch_valor = digitalRead(SWITCH_PIN);
      else
        switch_valor = !digitalRead(SWITCH_PIN);
        
      origen_led = "pulsador";
      origen_switch = "pulsador";
      ready_switch = true; 

      
        if (led_actual != 0)        // Led encendido: se guarda el valor de intensidad en nueva variable y luego se apaga.
        {
           led_almacenado = led_actual; // Variable de reserva
           led_actual = 0;          // Estado apagado del led
        }
        else                        // Led apagado: se enciende con el valor de intensidad guardado.
          led_actual = led_almacenado;
      
      
    break;
    
    case 2:                       // Pulsación doble
     switch_valor = LOW;
     origen_led = "pulsador";
     origen_switch = "pulsador";
     ready_switch = true;
     led_actual = 100;
    break;

    case 100:                     // Pulsación larga
     FuncionActualizacion();      // Actualización mediante FOTA
    break;
  }//switch
}//funcion
