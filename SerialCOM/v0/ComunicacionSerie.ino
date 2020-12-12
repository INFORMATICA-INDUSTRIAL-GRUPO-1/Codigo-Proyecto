int velocidad[2];
byte buf_salida[2];
unsigned entrada=0;
unsigned long t1=0;
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
  entrada=Serial.read();
  Serial.println(entrada);
  delay(100);

}
