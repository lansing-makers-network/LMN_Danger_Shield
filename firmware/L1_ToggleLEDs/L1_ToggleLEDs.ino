// Pin definitions
#define LED5     5
#define LED6     6

void setup()
{
  Serial.begin(115200);

  //Initialize inputs and outputs
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  Serial.println("Danger Shield Component: ToggleLEDs");  
}

void loop()
{
    //Blink the status LEDs back and forth
    if(digitalRead(LED5) == LOW)
    {
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
    }
    else {
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
    }

    delay(250);
}



