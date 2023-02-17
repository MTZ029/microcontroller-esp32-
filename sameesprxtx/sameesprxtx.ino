#include <HardwareSerial.h>  % simple heterofile 
#define LED_BUILTIN 2  % BUILTIN_LED
HardwareSerial Serialport(2); // use UART2
//Serial.begin(115200);    // another method to envoke the UART
//Serial1.begin(115200);
void setup() {
  // put your setup code here, to run once:
Serialport.begin(115200,SERIAL_8N2,16,17);
Serial.begin(115200);
pinMode(2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
Serialport.print('N');
delay(100);
Serialport.print('F');
delay(100);

if(Serial.available()){ 
char number=Serial.read(); // saved in number
//Serial.print(8);
//Serial.print(number);

if(number== 'F' )
{
  digitalWrite(2,LOW);
  Serial.println("LOW");
}
if(number=='N')
{
  digitalWrite(2,HIGH);
    Serial.println("HIGH");

}
}
}
