/*
 
#include "robot_2sens.h"

int sensor1;
int sensor2;

int incomingByte=0;
bool obs_izq = false;
bool obs_dcha = false;
// Detección obstáculos
bool stop_izq = false;
bool stop_dcha = false;

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
          if (sensor1<50 && sensor1>0)
          {
            obs_izq=true;
          }
          else
          {
            obs_izq=false;
          }
          //Serial.printf("Hola: %d \n",sensor1);
        //}
        break;
        case 252:
          sensor2=Serial.read();
          if (sensor2<50 && sensor2>0)
          {
            obs_dcha=true;
          }
          else
          {
            obs_dcha=false;
          }
          if (obs_izq && !stop_izq)
          {
            stop_izq=true;
            if(modo==1)
            {
              // Mando que el robot se pare
              Serial.write(88);
              delay(10);
              Serial.write(32);
              // Mando por mqtt que hay obstáculo por la izquierda
              StaticJsonDocument<100> jsonRoot;
  
              JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
              Obstaculo["1"] = "izquierda";
              
            
              serializeJson(jsonRoot,msg);
            
              //debugFunction (msg,1);
              client.publish("infind/GRUPO1/PIERO/Obstaculo", msg);
            }
              
          }
          else if (!obs_izq)
          {
            stop_izq=false;
          }
          if (obs_dcha && !stop_dcha)
          {
            stop_dcha=true;
            if (modo==1)
            {
              // Mando que el robot se pare
              Serial.write(88);
              delay(10);
              Serial.write(32);
              // Mando por mqtt que hay obstáculo por la izquierda
              StaticJsonDocument<100> jsonRoot;
  
              JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
              Obstaculo["1"] = "derecha";
              
            
              serializeJson(jsonRoot,msg);
            
              //debugFunction (msg,1);
              client.publish("infind/GRUPO1/PIERO/Obstaculo", msg);
            }
              
          }
          else if (!obs_dcha)
          {
            stop_dcha=false;
          }
        //Serial.printf("%d %d \n", sensor1,sensor2);
        break;
    }//switch
  }//if

  else
  dato_sensor = false;
}//funcion
*/
