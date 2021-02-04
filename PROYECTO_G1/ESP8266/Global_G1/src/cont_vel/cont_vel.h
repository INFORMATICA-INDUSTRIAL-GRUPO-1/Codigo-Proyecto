#ifndef cont_vel_h

  #define cont_vel_h

  #include <Arduino.h>
  #include <ArduinoJson.h>

  #include "../wifi/wifi.h"
  #include "../datos/datos.h"
  #include "../config/config.h"
  #include "../mqtt/mqtt.h"
  #include "../robot_5sens/robot_5sens.h"

  //-------------------------  VARIABLES  -------------------------

  extern uint8_t vel_envio[2];

  //-------------------------  FUNCIONES  -------------------------

  void control_modo();
  void velocidad();

#endif
