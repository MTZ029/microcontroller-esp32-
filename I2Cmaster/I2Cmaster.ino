#include<Wire.h>
int X=0;
//String alpha="How are you ?";  // 
String R;
void setup() {
  // put your setup code here, to run once:
//Wire.begin();    //initializing the function
Wire.begin(9);
if(wire.available){
Wire.onReceive(REVENT);
}
Serial.begin(9600);
}

void REVENT(int bytes){
  while(Wire.available()){
    R=(char)Wire.read();
    Serial.println(R);
  }
} 

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(9);
Wire.write(X);
Wire.write("How are you ?");
Wire.endTransmission();

X++;
if(X>5){
  X=0;
}
delay(1000);
}
