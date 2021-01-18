#ifndef pulsos_h
#define pulsos_h
#include <Arduino.h> //libreria de arduino
#include "interrupciones.h"
#include "fota.h"

extern unsigned long ultima_pulsacion;
extern int pulsacion; 
extern volatile unsigned long duracion; //duda lo de volatile.

void pulsos(); //Interpreta los pulsos del boton y la duración de la pulsacion.


extern int led_actual;
extern int led_almacenado;

extern bool switch_valor;
extern bool ready_switch;

extern String origen_led;
extern String origen_switch;

void funcion_flash(); 

#endif //se declara una unica vez
