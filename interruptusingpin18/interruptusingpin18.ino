#define GPIOINTRPT_PIN 18
# define GPIOINT_SIGNAL 15
void IRAM_ATTR myisr(){
  int pin_stat =digitalRead(2);
  digitalWrite( 2 , !pin_stat);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(50);
pinMode(GPIOINT_SIGNAL ,OUTPUT);
pinMode(2 ,OUTPUT);

pinMode(GPIOINTRPT_PIN , INPUT_PULLUP);
delay(50);

attachInterrupt(GPIOINTRPT_PIN ,&myisr ,FALLING);
delay(10);

//attachInterrupt(GPIOINTRPT_PIN ,&myisr ,RISING);
//delay(10);

Serial.print("Setup complete");
}

void loop() {
  // put your main code here, to run repeatedly:

int pin_stat =digitalRead(GPIOINT_SIGNAL);
digitalWrite(GPIOINT_SIGNAL , !pin_stat);
Serial.print("LED TOGLGLE");
delay(250);
}
