#ifndef interrupciones_h

  #define interrupciones_h
  
  #include <Arduino.h>
  #include "config.h"
  #include "pulsos.h"

  //-------------------------  VARIABLES  -------------------------  
  
  extern volatile unsigned long duracion;
  extern volatile bool ready_led;
  extern byte BUTTON_PIN;

  //-------------------------  FUNCIONES  -------------------------  
  
  ICACHE_RAM_ATTR void RTI();

#endif
