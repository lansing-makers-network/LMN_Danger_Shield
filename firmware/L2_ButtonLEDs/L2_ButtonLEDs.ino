// Pin definitions
#define LED5     5
#define LED6     6
#define BUTTON10  10
#define BUTTON11  11
#define BUTTON12  12

void setup()
{
  Serial.begin(115200);

  //Initialize inputs and outputs
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  //Enable internal pullups
  pinMode(BUTTON10, INPUT_PULLUP);
  pinMode(BUTTON11, INPUT_PULLUP);
  pinMode(BUTTON12, INPUT_PULLUP);

  Serial.println("Danger Shield Component: ButtonLEDs");  
}

void loop()
{
 //If user is hitting button 1, turn on LED 1
  if(digitalRead(BUTTON10) == LOW)
  {
    Serial.print(" Button 1!");
    digitalWrite(LED5, HIGH);
  }
  else
    digitalWrite(LED5, LOW);
  Serial.println();

 //If user is hitting button 2, turn on LED 2
  if(digitalRead(BUTTON11) == LOW)
  {
    Serial.println(" Button 2!");
    digitalWrite(LED6, HIGH);
  }
  else
    digitalWrite(LED6, LOW);

}



