#define L 15ss
#define L1 4 
#define L2 5 
#define L3 18 
#define L4 19 
#define L5 21 
#define L6 22
#define L7 23
#define L8 16
int b[10];
 
void IRAM_ATTR my(){
  // MSB from left to right
  b[0]=digitalRead(15);
  b[1]=digitalRead(4);
  b[2]=digitalRead(5);
  b[3]=digitalRead(18);
  b[4]=digitalRead(19);
  b[5]=digitalRead(21);
  b[6]=digitalRead(22);
  b[7]=digitalRead(23);
  Serial.print("Inturrutp called ");
  delay(2000); // delay 
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  pinMode(15, INPUT);
  pinMode(4 , INPUT);
  pinMode(5 , INPUT);
  pinMode(18, INPUT);
  pinMode(19 ,INPUT);
  pinMode(21 , INPUT);
  pinMode(22 , INPUT);
  pinMode(23 , INPUT);
  pinMode(L8 , INPUT_PULLUP);   // data transmit only on falling edge.

  attachInterrupt(L8 , &my , FALLING);
  //delay(8000);

}

void loop(){
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
