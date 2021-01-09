#include "cont_vel.h"
uint8_t vel_envio[2];

void control_modo()
{
  switch(modo)
  {
    case 0:
      vel_envio[0]=88;
      vel_envio[1]=82;
    break;
    case 1:
      vel_envio[0]=88;
      vel_envio[1]=77;
    break;
    case 2:
      vel_envio[0]=88;
      vel_envio[1]=69;
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
        vel_envio[1]=87;
       }

        
      break;
      case 4:
        if (!obs_izq)
        {
          vel_envio[0]=88;
          vel_envio[1]=65;
        }
        
      
      break;
      case 6:
      
        if (!obs_dcha)
        {
          vel_envio[0]=88;
          vel_envio[1]=68;
        }
        
     
      break;
      case 2:
      
        vel_envio[0]=88;
        vel_envio[1]=83;
     
      break;
      case 0:
        vel_envio[0]=88;
        vel_envio[1]=32;
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
