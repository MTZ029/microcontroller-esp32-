#define D0 4 
#define D1 2

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(D0 , OUTPUT);
pinMode(D1 , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=digitalRead(D0);
int x1=digitalRead(D1);
digitalWrite(D0 , !x);
Serial.println("LED 4");
delay(1000);
digitalWrite(D1 , !x1);
Serial.println("LED 2");
delay(1000);

}
