#include "cont_vel.h"
uint8_t vel_envio[2];

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
  Serial.write(vel_envio[0]);
  delay(10);
  Serial.write(vel_envio[1]);
  delay(10);
  vel_envio[0] = 0;
  vel_envio[1] = 0;
}

void velocidad()
{
  if (modo==1)
  {
    switch (orden)
    {
      case 8:
       if (!obs_izq && !obs_dcha && !obs_cent)
       {
        vel_envio[0]=88;
        vel_envio[1]=87; //W (ADELANTE)
       }

        
      break;
      case 4:
        if (!obs_izq)
        {
          vel_envio[0]=88;
          vel_envio[1]=65; //A (ATRÁS)
        }
        
      
      break;
      case 6:
      
        if (!obs_dcha)
        {
          vel_envio[0]=88;
          vel_envio[1]=68; //D (DERECHA)
        }
        
     
      break;
      case 2:
      
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
    vel_envio[0] = 0;
    vel_envio[1] = 0;
    orden = -1;
  }
  
  
}
