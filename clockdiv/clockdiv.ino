// checking for the resolution.
#define ADC_PIN 4
int ADC_value =0;
int ADC_value_mw=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ADC_PIN, INPUT);
analogSetClockDiv(1); //cloc divided by 255
}

void loop() {
  // put your main code here, to run repeatedly:
// calling 2 micros in a row takes 50 microseconds.
// this code bascally checks for the time difference between time1 & time 2, microseconds.
int time1=micros();
ADC_value=analogRead(ADC_PIN);
int time2=micros();
Serial.println(time2-time1);    
delay(100);
}
