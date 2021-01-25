#include "cont_vel.h"
uint8_t vel_envio[2];

//-------------------------  SELECCION MODO  -------------------------  

void control_modo() 
{
  switch(modo)
  {
    case 0:
      vel_envio[0]=88; //X
      vel_envio[1]=82; //R (STOP)
    break;
    case 1:
      vel_envio[0]=88; //X
      vel_envio[1]=77; //M (MANUAL)
    break;
    case 2:
      vel_envio[0]=88; //X
      vel_envio[1]=69; //E (AUTOMÁTICO)
    break;
  }
  Serial.write(vel_envio[0]);  //Envia la etiqueta (X).
  delay(10);
  Serial.write(vel_envio[1]);  //Tras 10 ms envia el modo seleccionado.
  delay(10);
  vel_envio[0] = 0;           //Se reseta para no enviar datos no deseados.
  vel_envio[1] = 0;
}

//-------------------------  CONTROL VELOCIDAD ANGULAR, LINEAL Y STOP  -------------------------  

void velocidad()
{
  if (modo==1)    //Se asegura de que estamos trabajando en modo manual.
  {
    switch (orden)  
    {
      case 8:
       if (!obs_izq && !obs_dcha && !obs_cent) //Si no detecta obstaculos, puede aumentar velocidad hacia adelante.
       {
        vel_envio[0]=88;
        vel_envio[1]=87; //W (ADELANTE)
       }

        
      break;
      case 4:
        if (!obs_izq)   //Si no detecta obstaculos en la izquierda, puede aumentar velocidad angular hacia izquierda.
        {
          vel_envio[0]=88;
          vel_envio[1]=65; //A (IZQUIERDA)
        }
        
      
      break;
      case 6:
      
        if (!obs_dcha)    //Si no detecta obstaculos en la derecha, puede aumentar velocidad angular hacia derecha.
        {
          vel_envio[0]=88;
          vel_envio[1]=68; //D (DERECHA)
        }
        
     
      break;
      case 2:           //Independientemente de los objetos detectados, siempre podrá ir hacia atras.
      
        vel_envio[0]=88;
        vel_envio[1]=83; // S (RETROCESO)
     
      break;
      case 0:
        vel_envio[0]=88;
        vel_envio[1]=32;// espacio (STOP O SALIR)
      break;
      
    }
    Serial.write(vel_envio[0]);
    delay(10);
    Serial.write(vel_envio[1]);
    vel_envio[0] = 0;   //Se reseta para no enviar datos no deseados.
    vel_envio[1] = 0;
    orden = -1;         //Se reseta para no enviar datos no deseados.
  }
  
  
}
