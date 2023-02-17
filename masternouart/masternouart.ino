#define pin_1 15
#define pin_2 4
#define pin_3 5
#define pin_4 18
#define pin_5 19
#define pin_6 21
#define pin_7 22
#define pin_8 23;
#define pin 13
int b[8];
int i;
int n;

hw_timer_t *timer=NULL;

void IRAM_ATTR my(){
  digitalWrite(13 , HIGH);
    char a='A';
  int y=int(a);
  for(i=0;y>0;i++){
    b[i]=y%2;   // modulous divisions
    y=y/2;
  }
  digitalWrite(13,LOW);
  digitalWrite(15,b[0]);
  digitalWrite(4,b[1]);
  digitalWrite(5,b[2]);
  digitalWrite(18,b[3]);
  digitalWrite(19,b[4]);
  digitalWrite(21,b[5]);
  digitalWrite(22,b[6]);
  digitalWrite(23,b[7]); 

  digitalWrite(13 ,LOW);
  }
void setup(){
pinMode(15, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(18, OUTPUT);
pinMode(21, OUTPUT);
pinMode(22, OUTPUT);
pinMode(23, OUTPUT);
pinMode(13,OUTPUT);

timer=timerEnable(0 , 80 ,true );
timerAttachInterrupt(timer , &my , true);
timerAlarmWrite(timer , 8000000 , true );
timerAlarmE
}
void loop(){

}
