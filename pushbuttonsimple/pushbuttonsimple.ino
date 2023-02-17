#define button_pin 21
#define LED_BUILTIN 2

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button_pin , INPUT_PULLUP);   // the input is defined at pullup.
pinMode(LED_BUILTIN , OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int buttonstate =digitalRead(button_pin);

Serial.println(buttonstate);
if(buttonstate==1){
  digitalWrite(LED_BUILTIN ,HIGH);
}
if(buttonstate==0){
  digitalWrite(LED_BUILTIN ,LOW);
  }
}
