#ifndef pulsos_h
#define pulsos_h
#include <Arduino.h> //libreria de arduino
#include "interrupciones.h"
#include "fota.h"

extern unsigned long ultima_pulsacion;
extern int pulsacion; 
extern volatile unsigned long duracion; //duda lo de volatile.

void pulsos(); //Interpreta los pulsos del boton y la duración de la pulsacion.


extern int led_valor1;
extern int led_valor2;

void funcion_flash(); 

#endif //se declara una unica vez
