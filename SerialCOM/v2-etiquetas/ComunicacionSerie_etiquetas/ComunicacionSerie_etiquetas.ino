int velocidad[2];
int sensor1;
int sensor2;
int sensor3;
int sensor4;
int sensor5;  
byte buf_salida[2];
unsigned entrada=0;
unsigned long t1=0;
int i=0;
int incomingByte=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
buf_salida[0]=0;
buf_salida[1]=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis()-t1>=100){
    t1=millis();
    if(buf_salida[0]<150){
      buf_salida[0]=buf_salida[0]+1;
      buf_salida[1]=buf_salida[1]+1;
      }
  }
  //Serial.write(buf_salida,2);
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
    }
    
    delay(100);
  }
 

}
