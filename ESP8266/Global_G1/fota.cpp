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
// Pestaña: fota
//
// Descripcion del codigo
//
// Se encarga de ejecutar la actualización FOTA.
//

//-------------------------  Seccion librerias y pestañas  -------------------------  

#include <Arduino.h>

#include <ESP8266httpUpdate.h>
#include "datos.h"
#include "mqtt.h"
#include "debug.h"
#include "fota.h"
#include "config.h"

//-------------------------  Funciones  -------------------------  

void FuncionActualizacion()
{
  debugFunction ("--------------------",1);
  debugFunction ("Comprobando actualización:",1);
  debugFunction ("--------------------",1);
  debugFunction ("--------------------",1);
  debugFunction ("/d",0);
  debugFunction (OTA_URL,0);
  debugFunction (":",0);
  debugFunction ("",1);
  debugFunction ("--------------------",1);  
  ESPhttpUpdate.setLedPin(16,LOW);
  ESPhttpUpdate.onStart(inicio_OTA);
  ESPhttpUpdate.onError(error_OTA);
  ESPhttpUpdate.onProgress(progreso_OTA);
  ESPhttpUpdate.onEnd(final_OTA);
  
  switch(ESPhttpUpdate.update(OTA_URL, HTTP_OTA_VERSION, OTAfingerprint))  //Para poder conectarse al servidor.
  {
    case HTTP_UPDATE_FAILED:
      Serial.printf(" HTTP update failed: Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;
    case HTTP_UPDATE_NO_UPDATES:
      Serial.println(F(" El dispositivo ya está actualizado"));
      break;
    case HTTP_UPDATE_OK:
      Serial.println(F(" OK"));
      break;
    }
}

void final_OTA()
{
  Serial.println("Fin OTA. Reiniciando...");
}

void inicio_OTA()   
{
  actualiza_mqtt();   //Se manda un mensaje por MQTT para que quede registro de la actualizacion.
  Serial.println("Nuevo Firmware encontrado. Actualizando...");
}

void error_OTA(int e)
{
  char cadena[64];
  snprintf(cadena,64,"ERROR: %d",e);
  Serial.println(cadena);
}

void progreso_OTA(int x, int todo)
{
  char cadena[256];
  int progress=(int)((x*100)/todo);
  if(progress%10==0)
  {
    snprintf(cadena,256,"Progreso: %d%% - %dK de %dK",progress,x/1024,todo/1024);
    Serial.println(cadena);
  }
}
