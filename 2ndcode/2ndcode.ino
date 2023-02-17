#define ADC_pin 34
int ADC_value=0;
int ADC_Value_mw=0;
adc_attenuation_t attenudation =ADC_0db;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ADC_pin ,INPUT);
analogSetPinAttenuation(ADC_pin ,attenudation );
}

void loop() {
  // put your main code here, to run repeatedly:
ADC_Value_mw=analogReadMilliVolts(ADC_pin);
Serial.print("ADC value is : ");
Serial.println(ADC_Value_mw);
Serial.println("      millivolts   "); 
delay(200);
}
