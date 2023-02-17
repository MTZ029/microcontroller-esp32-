#define ADC_PIN 4
#define DAC_PIN 26
#define LED_BUILTIN 2 

int x;
void setup(){
  Serial.begin(115200);
  pinMode(4 , INPUT);
  pinMode(26 ,OUTPUT);

}

void loop(){
  dacWrite(26 , 255);  // give the values to print
  x =analogRead( 4 );
  Serial.println(x*(3.3/4096));
  delay(500);

  dacWrite(26 , 0);
  x1 =analogRead( 4 );
  Serial.println(x*(3.3/4096));
  delay(500);
}
