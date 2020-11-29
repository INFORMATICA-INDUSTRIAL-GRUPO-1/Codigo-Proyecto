#include <Arduino.h>
#include "debug.h"


void debugFunction (String debugMsg){
  if (debug){
  Serial.println ();
  Serial.print ("DebugLine:");
  Serial.println(debugMsg);
  }
  
  }
