#define DAC1 25
#define ADC_PIN 4
float adcRead=0;
int dacValue=0;
int deg=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ADC_PIN ,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
dacValue=int(128 +127*(sin(deg*PI/180)));    // 128 is your offset
dacWrite(25,dacValue);
deg =deg+1; //deg = deg++ ;
if(deg>=360)
deg=0;
delay(12);
adcRead=analogRead(ADC_PIN);
Serial.println(adcRead*3.3/4096);
}
