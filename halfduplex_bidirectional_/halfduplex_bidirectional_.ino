#define L 15
#define L1 4 
#define L2 5 
#define L3 18 
#define L4 19 
#define L5 21 
#define L6 22
#define L7 23
#define L8 34
//#define L9 13 
int b[10];
int a[10];

hw_timer_t *timer =NULL; 
 void IRAM_ATTR my(){
  // MSB from left to right
  pinMode(15, INPUT);
  pinMode(4 , INPUT);
  pinMode(5 , INPUT);
  pinMode(18, INPUT);
  pinMode(19 ,INPUT);
  pinMode(21 , INPUT);
  pinMode(22 , INPUT);
  pinMode(23 , INPUT);
  b[0]=digitalRead(15);
  b[1]=digitalRead(4);
  b[2]=digitalRead(5);
  b[3]=digitalRead(18);
  b[4]=digitalRead(19);
  b[5]=digitalRead(21);
  b[6]=digitalRead(22);
  b[7]=digitalRead(23);
  Serial.print("Inturrutp called ");
  int result;
  for(int i=7 ; i>=0 ; i--){   // opposite directrion so powers remain constant
  result *=2 ; // power
  result +=b[i]; // addition  64 +1
  }
  char A =char (result);
  Serial.println("        The value is      " );
  Serial.print( A );

  for(int k =0 ; k<8 ;k++){
  Serial.print(b[k]);
}
}

void IRAM_ATTR my1(){

  pinMode(15, OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19 ,OUTPUT);
  pinMode(21 , OUTPUT);
  pinMode(22 , OUTPUT);
  pinMode(23 , OUTPUT);
char b='E';
int y=int(b);
  for( int i=0; y>0; i++)   
{   

a[i]=y%2;    
y= y/2;  

}
Serial.print('A') ;   
  digitalWrite(13 , LOW);
  digitalWrite(15,a[0]);
  digitalWrite(4,a[1]);
  digitalWrite(5,a[2]);
  digitalWrite(18,a[3]);
  digitalWrite(19,a[4]);
  digitalWrite(21,a[5]);
  digitalWrite(22,a[6]);
  digitalWrite(23,a[7]);
  
  //digitalWrite(13 , HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");

  pinMode(34 , INPUT);   // data transmit only on falling edge.
  //pinMode(13 , OUTPUT);

  attachInterrupt(34 , &my , FALLING);
  timer=timerBegin(0 , 80 , true);
  timerAttachInterrupt(timer , &my1 , true);
  timerAlarmWrite(timer ,8000000 ,true  );
  timerAlarmEnable(timer);
  //delay(8000);

}
void loop(){
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
