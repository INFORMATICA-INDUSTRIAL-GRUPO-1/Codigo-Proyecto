/*
 
#include "robot_2sens.h"

int sensor1;
int sensor2;

int incomingByte=0;

bool dato_sensor; 

void sensores_arduino ()
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    dato_sensor = true;
    incomingByte = Serial.read();
    switch (incomingByte)
    {
        case 251:
       // if (Serial.available() > 0)
        
          sensor1=Serial.read();
          //Serial.printf("Hola: %d \n",sensor1);
        //}
        break;
        case 252:
        sensor2=Serial.read();
        //Serial.printf("%d %d \n", sensor1,sensor2);
        break;
    }//switch
  }//if

  else
  dato_sensor = false;
}//funcion
*/
