#define LED_BUILTIN 2
HardwareSerial Serialport(2); // use UART2

void setup() {
  // put your setup code here, to run once:
Serialport.begin(115200, SERIAL_8N1 ,16 ,17);
Serial.begin(115200);
pinMode(LED_BUILTIN , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serialport.print('N');
Serial.print('N');
delay(1000);
Serialport.print('F');
Serial.print('F');
delay(1000);

char number;
if(Serial.available()){
  number=Serial.read();
  if(number=='A'){
    digitalWrite(2, HIGH);
    Serial.println("SOHAIB HIGH");
  }
  else if(number=='B'){
    digitalWrite(2 ,LOW);
    Serial.println("SOHAIB LOW");
  }
}
}
