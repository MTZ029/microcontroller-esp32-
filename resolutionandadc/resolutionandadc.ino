/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-led-fade
 */

#define LED_PIN  4 // ESP32 pin GIOP18 connected to LED

float x=0;
float y=0;


adc_attenuation_t attenuation =ADC_6db;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin GIOP18 to be an output:
  pinMode(4, INPUT);
  Serial.begin(9600);
  analogSetPinAttenuation( 4 , attenuation );
  analogReadResolution(9); // quantization bits are set i  the comment 
  //analogSetAttenuation(attenuation); // same as above
}

// the loop routine runs over and over again forever:
void loop() {
 x =analogReadMilliVolts(4);
 Serial.print("The value is ");
 Serial.println(x);
 
 delay(1000);
 y =x*(3.3/512);    // conversion to the original value valeu in millivolts
 Serial.print("The Resolution is ");
 Serial.println(y);

  // wait for 30 milliseconds to see the dimming effect
  delay(1000);
}
