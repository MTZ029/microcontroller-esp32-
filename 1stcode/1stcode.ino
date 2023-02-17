 #define LED_BUILTIN 2
#define led 4;
#include<HardwareSerial.h>
HardwareSerial Serialport(2);
void setup(){
Serial.begin(9600);
Serialport.begin(9600,SERIAL_8N1,16,17);
pinMode(2, OUTPUT);
pinMode(4, OUTPUT);


}
void loop(){
Serial.print('N');
delay(100);
Serial.print('F');
delay(100);
Serialport.print('A');
delay(100);
Serialport.print('B');
delay(100);

if(Serialport.available()){
  char number=Serialport.read();
  if(number=='N'){
    digitalWrite(2, HIGH);
    Serial.print(1);
  }
  if(number=='F'){
    digitalWrite(2,LOW);
    Serial.print(2);
  }
}
if(Serial.available()){
  char x=Serial.read();
  if(x=='A'){
    digitalWrite(4, HIGH);
  }
  if(x=='B'){
    digitalWrite(4, LOW);
  }
}



} 
