#include <Arduino.h>
#include "debug.h"


void debugFunction (String debugMsg, bool line){ // Funcion que permite activar/desactivar el debug por serie del programa
  if (debug){
    if (debugMsg == "/d")
       Serial.print ("DebugLine:");
    else{   
    if(line){
        
         Serial.print ("DebugLine:");
         Serial.println(debugMsg);
      }
      else{
      Serial.print (debugMsg);
      }
    }//END ELSE debugMsg  
  }//END if debug
}//END DEBUG 
