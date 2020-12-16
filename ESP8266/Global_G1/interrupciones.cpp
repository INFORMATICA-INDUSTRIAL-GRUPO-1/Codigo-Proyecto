#include <Arduino.h>
#include "config.h"

// Rutina de Tratamiento de la Interrupcion (RTI)

volatile unsigned long duracion = 0;
volatile bool ready_led = false;

  ICACHE_RAM_ATTR void RTI() 
  {    
    int lectura=digitalRead(0);
    volatile unsigned long inicio = 0;
    volatile unsigned long ultima_int = 0;
    int estado_int=HIGH; // por defecto HIGH (PULLUP). Cuando se pulsa se pone a LOW
    unsigned long hora = millis(); //Iniciar 1 vez millis(), para no volver a preguntar otras 3 veces más dentro de la función. Se trata de una interrupción, no debe de demandar tanto.
    
    if(lectura == estado_int || hora - ultima_int<50) return; // filtro rebotes 50ms. Cuidado con la segunda condicion que puede dar 0 y no entrar.
    //
      if(lectura == LOW) //Boton pulsado.
      {
        estado_int = LOW;
        inicio = hora;
      }
      else  //Se suelta el boton
      {
        estado_int=HIGH;
        duracion = hora - inicio; //Tiempo actual - tiempo cuando se pulsó.
        ready_led = true;//Datos listos. Puedo entrar en el loop y mostrar.
      }
      ultima_int = hora; //Necesario para el filtro de ruido.
}
