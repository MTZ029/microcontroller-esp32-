#define pushButton_pin   15
#define LED_BUILTIN  2
 
void IRAM_ATTR toggleLED()
{
  //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  Serial.print("Called");
}
 
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushButton_pin, INPUT_PULLUP);
  attachInterrupt(pushButton_pin, toggleLED, FALLING);
}
 
void loop()
{
}
