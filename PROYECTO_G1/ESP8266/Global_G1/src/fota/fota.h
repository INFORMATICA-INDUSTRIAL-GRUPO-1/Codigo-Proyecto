#ifndef fota_h

  #define fota_h

  #include <Arduino.h>
  #include <ESP8266httpUpdate.h>
  #include "../datos/datos.h"
  #include "../mqtt/mqtt.h"
  #include "../config/config.h"

  //-------------------------  FUNCIONES  -------------------------

  void progreso_OTA(int,int);
  void final_OTA();
  void inicio_OTA();
  void error_OTA(int);
  void FuncionActualizacion();

#endif
