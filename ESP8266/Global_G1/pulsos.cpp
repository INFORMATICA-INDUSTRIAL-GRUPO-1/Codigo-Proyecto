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

unsigned long ultima_pulsacion;
int pulsacion = 0;

void pulsos() //Interpreta los pulsos del boton y la duración de la pulsacion.
{   
    unsigned long ahora = millis();
    unsigned long espera = ahora - ultima_pulsacion;
    if (duracion < 1500 && espera <= 300)//"pulsacion doble"
    {
        pulsacion = 2;
    }//if
     else if (duracion < 1500)//pulsacion corta
    {
        pulsacion = 1;
    }//else if
       
    if (duracion >= 1500)//pulsacion larga.
    {
        pulsacion = 100;
    }
    
}//funcion


int led_valor1 = 10; //valor de prueba
int led_valor2; //variable que guarda el valor de luminosidad.

void funcion_flash()
{
  switch (pulsacion)
  {
    case 1:
      if (led_valor1 != 0)//Led encendido: se guarda el valor de intensidad en nueva variable y luego se apaga.
      {
         led_valor2 = led_valor1;
         led_valor1 = 0;
      }//if
      else//Led apagado: se enciende con el valor de intensidad guardado.
      {
        led_valor1 = led_valor2;
      }//else
    break;
    
    case 2:
      led_valor1 = 100;
    break;

    case 100:
      //FOTA
    break;
  }//switch
}//funcion
