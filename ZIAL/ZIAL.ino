#define cs1 15
#define cs2 4
#define D0 16
#define D1 17
#define D2 5
#define D3 18 
#define D4 19 
#define D5 21
#define D6 22
#define D7 23
  
int alphabet[8];// 8 bit data being sent to the receiver
int alphabet1[8]; 

hw_timer_t *timer=NULL; // hardware timmer

void sender(){
  char q='Z';   // value to be sent
  int z=int(q); // binary conversion -> type casting
  for( int j=0; z>0; j++)   
  {   
    alphabet[j]=z%2;    // BINARY conversion
    z= z/2;  

  }
  
  digitalWrite(cs1, 1);
  digitalWrite(D0, alphabet[0]);
  digitalWrite(D1, alphabet[1]);
  digitalWrite(D2, alphabet[2]);
  digitalWrite(D3, alphabet[3]);
  digitalWrite(D4, alphabet[4]);
  digitalWrite(D5, alphabet[5]);
  digitalWrite(D6, alphabet[6]);
  digitalWrite(D7, alphabet[7]);

  pinMode(cs1,OUTPUT);
  pinMode(D0 , OUTPUT);
  pinMode(D1 , OUTPUT);
  pinMode(D2 , OUTPUT);  // declaring the pin modes 
  pinMode(D3 , OUTPUT);
  pinMode(D4 , OUTPUT);
  pinMode(D5 , OUTPUT);
  pinMode(D6 , OUTPUT);
  pinMode(D7 , OUTPUT);
}

void IRAM_ATTR Receivee(){ 
  
    pinMode(cs2,INPUT);
    pinMode(D0 , INPUT);
    pinMode(D1 , INPUT);
    pinMode(D2 , INPUT);
    pinMode(D3 , INPUT);
    pinMode(D4 , INPUT);
    pinMode(D5 , INPUT);
    pinMode(D6 , INPUT);
    pinMode(D7 , INPUT);
    
    int r=digitalRead(cs2);
    if(r==1){
          alphabet1[0]=digitalRead(D0);
          alphabet1[1]=digitalRead(D1);
          alphabet1[2]=digitalRead(D2);
          alphabet1[3]=digitalRead(D3);
          alphabet1[4]=digitalRead(D4);
          alphabet1[5]=digitalRead(D5);
          alphabet1[6]=digitalRead(D6);
          alphabet1[7]=digitalRead(D7);
    
          int result;
          for(int i=7 ; i>=0 ; i--)
          {   // opposite directrion so powers remain constant
            result *=2 ; // power
            result +=alphabet1[i]; // addition  64 +1
          }
          char A =char (result);
          Serial.print("        Value received on com5 is ->      " );
          Serial.println( A );

          for(int k =0 ; k<8 ;k++)
          {
            Serial.println(alphabet1[k]);

          }
          }
}
void setup() {
  Serial.begin(9600);
  digitalWrite(cs1,HIGH);
  timer=timerBegin(0 , 80 ,true);
  timerAttachInterrupt(timer , &Receivee , true);
  timerAlarmWrite(timer , 2000000 , true); // 2 seconds
  timerAlarmEnable(timer);
  }

// the loop function runs over and over again forever
void loop() {
  sender();   // function called 
  delay(2000); //delay of 2 seconds
  
  }
