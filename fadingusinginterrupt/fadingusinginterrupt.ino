/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-led-fade
 */

#define LED_PIN  18 // ESP32 pin GIOP18 connected to LED

int brightness = 10;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
hw_timer_t *timer= NULL ;

void IRAM_ATTR my(){

  digitalWrite(18 , brightness);
  brightness =brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
}
  

// the setup routine runs once when you press reset:
void setup() {
  // declare pin GIOP18 to be an output:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  timer =timerBegin(0 , 80 ,true );
timerAttachInterrupt(timer , &my , true);
timerAlarmWrite(timer ,1000000 ,true);
timerAlarmEnable(timer);
}

// the loop routine runs over and over again forever:
void loop() {
 

  // wait for 30 milliseconds to see the dimming effect
  delay(20);
}
