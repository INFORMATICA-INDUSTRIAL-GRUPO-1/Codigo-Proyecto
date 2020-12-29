int velocidad[2];
byte buf_salida[2];
unsigned entrada=0;
unsigned long t1=0;
int incomingByte;
int cont=1;
int sensor1, sensor2 , sensor3, sensor4, sensor5;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
buf_salida[0]=0;
buf_salida[1]=0;
pinMode(LED_BUILTIN, OUTPUT);
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
  //Serial.print("Dato enviado: ");
  Serial.write(buf_salida,2);
  //entrada=Serial.read();
  //Serial.print("Dato recibido: ");
  //Serial.println(entrada);

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
   // Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);
    
 switch (cont) {
    case 1:
      sensor1=incomingByte;
      cont++;
    break;
    case 2:
      sensor2=incomingByte;
      cont++;
    break;
    case 3:
      sensor3=incomingByte;
      cont++;
    break;
    case 4:
      sensor4=incomingByte;
      cont++;
    break;
    case 5:
      sensor5=incomingByte;
      cont = 1;
      //Serial.printf("%d %d %d %d %d \n", sensor1,sensor2,sensor3,sensor4,sensor5);
    break;
 
  }
  
  if (entrada <= 12){
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);  
  }
  delay(100);
  }

}
