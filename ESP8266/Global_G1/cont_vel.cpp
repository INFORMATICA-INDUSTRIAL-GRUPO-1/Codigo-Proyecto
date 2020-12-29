#include "cont_vel.h"
uint8_t vel_envio[2];



void velocidad()
{
  switch (orden)
  {
    case 8:
    
      vel_envio[0]=88;
      vel_envio[1]=87;
    
    
    break;
    case 4:
    
      vel_envio[0]=88;
      vel_envio[1]=65;
      
    
    break;
    case 6:
    
      
      vel_envio[0]=88;
      vel_envio[1]=68;
   
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
}
