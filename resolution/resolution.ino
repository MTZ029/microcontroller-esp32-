// checking for the resolution.

#define ADC_PIN 4
int ADC_value =0;
int ADC_value_mw=0;
adc_attenuation_t attenuation=ADC_0db;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ADC_PIN, INPUT);
analogSetPinAttenuation(ADC_PIN ,attenuation);
analogReadResolution(12);
}

void loop() {
  // put your main code here, to run repeatedly:
ADC_value =analogRead(ADC_PIN);
Serial.print("ADC value in milivolts is ");
Serial.println(ADC_value *3.3/4096);

Serial.print("The value of ADC is ");
Serial.println(ADC_value);
delay(200);
}
