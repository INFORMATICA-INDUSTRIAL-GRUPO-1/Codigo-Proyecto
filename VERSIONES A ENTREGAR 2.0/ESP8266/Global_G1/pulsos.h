#ifndef pulsos_h

  #define pulsos_h
  
  #include <Arduino.h> //libreria de arduino
  #include "interrupciones.h"
  #include "fota.h"

  //-------------------------  VARIABLES  -------------------------  
  
  extern unsigned long ultima_pulsacion;
  extern int pulsacion; 
  extern volatile unsigned long duracion;
  extern int led_actual;
  extern int led_almacenado;
  
  extern bool switch_valor;
  extern bool ready_switch;
  
  extern String origen_led;
  extern String origen_switch;

  //-------------------------  FUNCIONES  -------------------------  
  
  void pulsos();
  void funcion_flash(); 

#endif
