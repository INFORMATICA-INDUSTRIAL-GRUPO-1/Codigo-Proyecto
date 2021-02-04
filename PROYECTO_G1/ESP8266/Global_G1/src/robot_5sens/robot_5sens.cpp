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
// Pestaña: pulsos
// Descripcion del codigo
//
// Se encarga de leer los valores de todos los sensores recibidos desde Arduino por el puerto serie. 
// Debido a que existen dos modelos diferentes de robot (uno equipado con 2 sensores y otro con 5 sensores)
// se debe de introducir previamente de que modelo se trata para no hacer lecturas falsas en un robot de 2 sensores. 
//

#include "robot_5sens.h"

//Se declaran los sensores y resto de variables.
int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5; 
 
int incomingByte=0; //Variable que lee el dato recibido desde el puerto serie.
bool dato_sensor; 

bool obs_izq = false;
bool obs_dcha = false;
bool obs_cent = false;

bool stop_izq = false;
bool stop_dcha = false;
bool stop_cent = false;

void sensores_arduino ()
{
  if (Serial.available() > 0) //Se estan recibiendo datos del puerto serie.
  {
    dato_sensor = true;       //Se esta recibiendo informacion. Esta variable booleana habilita el envio de datos por MQTT.
    incomingByte = Serial.read();   //Se guarda en la variable los datos recibidos.
    switch (incomingByte)       //Dependiendo de la etiqueta recibida, el dato se corresponde a un sensor o a otro.
    {
        case 251:
          sensor1=Serial.read();    //Tras identificar la etiqueta, se lee el valor del sensor. Se hace de forma identica en el resto de sensores.
          if(sensor1 < 40 && sensor1 > 0) //Se ha detectado un objeto a la izquierda.
            obs_izq = true;
          else
            obs_izq = false;
            
        break;
        
        case 252:
          sensor2=Serial.read();    
          if(sensor2 < 40 && sensor2 > 0)   //Se ha detectado un objeto a la derecha.
              obs_dcha = true;
          else
              obs_dcha = false;
        break;

        
        case 253:
          if(num_sensores == 5)     //En caso de tener 5 sensores, lee el valor de los sensores restantes: 
          {    
            sensor3=Serial.read();    //Lectura del sensor laser izquierdo.
            if(sensor3 < 50 && sensor3 > 0)   //Se ha detectado un objeto a la izquierda.
                obs_izq = true;
            else
                obs_izq = false;
          }
        break;
        
        case 254:
        if(num_sensores == 5)
        {
          sensor4=Serial.read();    //Lectura del sensor laser central.
          if(sensor4 < 50 && sensor4 > 0)   //Se ha detectado un objeto en el centro.
              obs_cent = true;
          else
              obs_cent = false;
        }
        break;
        
        case 255:
        if(num_sensores == 5)
        {
          sensor5=Serial.read();      //Lectura del sensor laser derecho.
          if(sensor5 < 50 && sensor5 > 0)
              obs_dcha = true;
          else
              obs_dcha = false;
        }  

        //Tras la lectura de todos los sensores, se interpreta esa informacion:
        
        //--------------------------- OBJ_IZQ ---------------------------

            if (obs_izq && !stop_izq)     //Entra cuando ha detectado un objeto en la izquierda y no se ha enviado aun la orden de stop.
            {
              stop_izq=true;      //Orden de stop. Bloquea los controles recibidos por MQTT para avanzar hacia la izquierda.
              if(modo==1) //Modo manual.
              {
                // Mando que el robot se pare
                Serial.write(88); // etiqueta (X)
                delay(10);
                Serial.write(32); //stop
                
                // Mando por mqtt que hay obstáculo por la izquierda.
                StaticJsonDocument<100> jsonRoot;
    
                JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
                Obstaculo["1"] = "izquierda";
                
                serializeJson(jsonRoot,msg); //Guarda en msg el campo de jsonRoot.
                client.publish(TOP_Obstaculo, msg); //Se publica por el topic adecuado.
              }
          }

          else if (!obs_izq)
            stop_izq=false;
            
        //--------------------------- OBJ_DCHA --------------------------- 
           
          if (obs_dcha && !stop_dcha)     //Entra cuando ha detectado un objeto en la derecha y no se ha enviado aun la orden de stop.
          {
            stop_dcha=true;     //Orden de stop. Bloquea los controles recibidos por MQTT para avanzar hacia la derecha.
            if (modo==1)        //Modo manual.
            {
              // Mando que el robot se pare
              Serial.write(88); // etiqueta (X)
              delay(10);
              Serial.write(32); //stop
              
              // Mando por mqtt que hay obstáculo por la derecha.
              StaticJsonDocument<100> jsonRoot;
  
              JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores"
              Obstaculo["1"] = "derecha";
              
              serializeJson(jsonRoot,msg);
              client.publish(TOP_Obstaculo, msg);
            } 
          }
          else if (!obs_dcha)
            stop_dcha=false;
            
        //--------------------------- OBJ_CENT ---------------------------      
      
          if (obs_cent && !stop_cent && num_sensores == 5) //Entra cuando ha detectado un objeto por el centro, no se ha enviado aun la orden de stop y el robot dispone de 5 sensores.
          {
            stop_cent=true;     //Orden de stop. Bloquea los controles recibidos por MQTT para avanzar hacia adelante.
            if (modo==1)        //Modo manual.
            {
              // Mando que el robot se pare
              Serial.write(88); //etiqueta (X)
              delay(10);
              Serial.write(32); //stop
              
              // Mando por mqtt que hay obstáculo por el centro.
              StaticJsonDocument<100> jsonRoot;
  
              JsonObject Obstaculo=jsonRoot.createNestedObject("Sensores"); // crea un subobjeto json para "Sensores".
              Obstaculo["1"] = "centro";
              
              serializeJson(jsonRoot,msg);
              client.publish(TOP_Obstaculo, msg);
            }
          }
          else if (!obs_cent)
            stop_cent=false;
            
        break;
    }
  }
  else
    dato_sensor = false;
}
