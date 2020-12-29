/*
#include "robot_5sens.h"

int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;  
int incomingByte=0;
bool dato_sensor; 

void sensores_arduino ()
{
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    dato_sensor = true;
    incomingByte = Serial.read();
    switch (incomingByte)
    {
        case 251:
          sensor1=Serial.read();
        break;
        
        case 252:
          sensor2=Serial.read();
        break;
        
        case 253:
          sensor3=Serial.read();
        break;
        
        case 254:
          sensor4=Serial.read();
        break;
        
        case 255:
          sensor5=Serial.read();
        break;
    }//switch
  }//if
  else
    dato_sensor = false;
}//funcion*/
