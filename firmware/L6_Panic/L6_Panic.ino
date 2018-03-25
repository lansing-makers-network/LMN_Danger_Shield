// Pin definitions
#define LIGHT    A3
#define LED5     5
#define LED6     6

int avgLightLevel;

void setup()
{
  Serial.begin(115200);

  //Initialize inputs and outputs
  pinMode(LIGHT, INPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  Serial.println("Danger Shield Component Panic");  

  //Take 16 readings from the light sensor and 
  //average them together
  avgLightLevel = 0;
  for(int x = 0 ; x < 16 ; x++)
    avgLightLevel += analogRead(LIGHT);
  avgLightLevel /= 16;
  Serial.print("Avg: ");
  Serial.println(avgLightLevel);

}

void loop()
{
  //Read inputs
  int lightLevel = analogRead(LIGHT);

  //Display values
  //sprintf is a great way to combine a bunch of 
  //variables and strings together into one print statement
  char tempString[200];
  sprintf(tempString, "Light: %04d", lightLevel);
  Serial.print(tempString); 
  Serial.println();

  //If light sensor is less than 3/4 of the average 
  //(covered up) then freak out
  while(lightLevel < (avgLightLevel * 3 / 4))
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
    // Notice that everything else stopped
    // And that when released one of the LEDs is still on

    delay(25);

    lightLevel = analogRead(LIGHT); 
    //We need to take another reading 
    //to be able to exit the while loop
  }
}



