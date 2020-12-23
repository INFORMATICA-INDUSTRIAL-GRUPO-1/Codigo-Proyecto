/*

int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;  
int incomingByte=0;

void sensores_arduino ()
{
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    switch (incomingByte)
    {
        case 251:
        if (Serial.available() > 0) {
        sensor1=Serial.read();
        Serial.printf("Hola: %d \n",sensor1);}
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
        Serial.printf("%d %d %d %d %d \n", sensor1,sensor2,sensor3,sensor4,sensor5);
        break;
    }//switch
  }//if
}//funcion

*/
