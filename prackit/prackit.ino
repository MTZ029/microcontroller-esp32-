#define LED 2 
char number;
#include <HardwareSerial.h>

HardwareSerial Serialport(2); // UART 3

void setup(){
  pinMode(2 , OUTPUT);
  Serial.begin(9600);
  Serialport.begin(9600 , SERIAL_8N2 , 16 ,17 );

}

void loop(){
  Serial.print('N');
  delay(1000);
  Serial.print('F');


  // uart 2;
  if(Serialport.available()){
    number=Serialport.read();
  }

  if (number=='N'){
    digitalWrite(2, HIGH);
  }
  if(number=='F'){
    digitalWrite(2 , LOW);
  }
}
