/*
#include "robot_5sens.h"

int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;  
int incomingByte=0;
bool dato_sensor; 

bool obs_izq = false;
bool obs_dcha = false;
bool obs_cent = false;

bool stop_izq = false;
bool stop_dcha = false;
bool stop_cent = false;

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
          if(sensor1 < 50 && sensor1 > 0)
              obs_izq = true;
          else
            obs_izq = false;
            
        break;
        
        case 252:
          sensor2=Serial.read();
          if(sensor2 < 50 && sensor2 > 0)
              obs_izq = true;
          else
              obs_izq = false;
        break;
        
        case 253:
          sensor3=Serial.read();
          if(sensor3 < 50 && sensor3 > 0)
            {
              obs_cent = true;
            }
          else
            obs_cent = false;
        break;
        
        case 254:
          sensor4=Serial.read();
          if(sensor4 < 50 && sensor4 > 0)
            {
              obs_dcha = true;
            }
          else
            obs_dcha = false;
        break;
        
        case 255:
          sensor5=Serial.read();
          if(sensor4 < 50 && sensor4 > 0)
            {
              obs_dcha = true;
            }
          else
            obs_dcha = false;
           */
/*--------------------------- OBJ_IZQ ---------------------------*/
 /*           if (obs_izq && !stop_izq)
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
              client.publish(TOP_Obstaculo, msg);
            }
              
          }

          else if (!obs_izq)
            stop_izq=false;
            */
/*--------------------------- OBJ_DCHA ---------------------------*/            
     /*     if (obs_dcha && !stop_dcha)
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
              client.publish(TOP_Obstaculo, msg);
            }
              
          }
          else if (!obs_dcha)
            stop_dcha=false;
   */         
/*--------------------------- OBJ_CENT ---------------------------*/            
   /*       if (obs_cent && !stop_cent)
          {
            stop_cent=true;
            if (modo==1)
            {
              // Mando que el robot se pare
              Serial.write(88);
              delay(10);
              Serial.write(32);
              // Mando por mqtt que hay obstáculo por la izquierda
              StaticJsonDocument<100> jsonRoot;
  
              JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
              Obstaculo["1"] = "centro";
              
            
              serializeJson(jsonRoot,msg);
            
              //debugFunction (msg,1);
              client.publish(TOP_Obstaculo, msg);
            }
              
          }
          else if (!obs_cent)
            stop_cent=false;
          
        break;
    }//switch
  }//if
  else
    dato_sensor = false;
}//funcion
*/
