// Programa Asignatura INFORMATICA INDUSTRIAL Grupo1
// Codigo ESP8266
// Version V.1
//
// Autores
//
//  ANTONIO JESUS PEREZ BAZUELO
//  MANUEL VALLE DELGADO
//  MATHIAS LOFEUDO CLINCKSPOOR
//  PABLO ROLDAN PEREZ
//  PABLO VERA SOTO
//
// Pestaña: debug
//
// Descripcion del codigo
//
// Funcion que muestra mensajes por puerto serie cuando se desee.
//

#include <Arduino.h>
#include "debug.h"


void debugFunction (String debugMsg, bool line) // Funcion que permite activar/desactivar el debug por serie del programa
{
  if (debug)    //Muestra por pantalla los mesajes siempre y cuando en config.cpp se haya declarado debug como verdadero.
  {
    if (debugMsg == "/d")
       Serial.print ("DebugLine:");
    else
    {   
      if(line)
      {
         Serial.print ("DebugLine:");
         Serial.println(debugMsg);
      }
      else
        Serial.print (debugMsg);
    } 
  }
}
