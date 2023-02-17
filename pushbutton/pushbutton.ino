#define BUILTIN_LED 2
#define signal_pin 4;
#define intrpt_pin 35;
void IRAM_ATTR ontimer(){
  int x=digitalRead(2);
  digitalWrite(2,!x);
}
void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(35,INPUT);
  attachInterrupt(35,&ontimer,FALLING);

}

void loop() {
  digitalWrite(4,HIGH);
  delay(1000);
    digitalWrite(4,LOW);
  
}
