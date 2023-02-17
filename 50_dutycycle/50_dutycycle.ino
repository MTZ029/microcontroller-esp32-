#define LED_BUILTIN 2 

hw_timer_t *timer =NULL;
int x =0;

void IRAM_ATTR my(){
x=digitalRead(2);
digitalWrite(2 ,!x);
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(2 , OUTPUT);
timer=timerBegin(0 , 80 , true); // upcounting 
timerAttachInterrupt(timer , &my , true); // edge triggered 
timerAlarmWrite(timer ,500000 , true );
timerAlarmEnable(timer);

}

void loop() {
  // put your main code here, to run repeatedly:

}
