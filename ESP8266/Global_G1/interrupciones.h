#ifndef interrupciones_h
#define interrupciones_h
#include <Arduino.h> //libreria de arduino
#include "config.h"
#include "pulsos.h"

extern volatile unsigned long duracion;
extern volatile bool ready_led;
extern byte BUTTON_PIN;


ICACHE_RAM_ATTR void RTI();

#endif
