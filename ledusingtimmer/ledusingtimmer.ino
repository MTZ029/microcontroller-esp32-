#define LED_BUILTIN 2
// the loop function runs over and over again forever
hw_timer_t *timmer =NULL;

void IRAM_ATTR ontimer(){
digitalWrite(LED_BUILTIN ,!digitalRead(LED_BUILTIN));
}
void setup() {
  // put your setup code here, to run once:
pinMode(LED_BUILTIN , OUTPUT);
timmer =timerBegin( 0 , 80 , true);
timerAttachInterrupt(timmer , &ontimer , true);
timerAlarmWrite(timmer , 1000000 ,true);
timerAlarmEnable(timmer);
}

void loop() {
  // put your main code here, to run repeatedly:

}
