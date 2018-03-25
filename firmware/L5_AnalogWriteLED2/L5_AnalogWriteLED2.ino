// Pin definitions
#define LED5     5
#define LED6     6
#define SLIDER_A2  A2 //Matches button 1
#define SLIDER_A0  A0 //Matches button 3
#define BUZZER   3

void setup()
{
  //Initialize inputs and outputs
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("Danger Shield Component: AnalogWriteLED6");  
}

void loop()
{

  //Read inputs
  int val1 = analogRead(SLIDER_A2);
  int val3 = analogRead(SLIDER_A0);
  Serial.print("Sliders = "); 
  Serial.print(val1); 
  Serial.print(", "); 
  Serial.print(val3); 

  // using MAP command to ratio adjust values.
  int ledLevel = map(val1, 0, 1023, 0, 255); //Map the slider level to a value we can set on the LED

  //Set the brightness on LED #2 (D6) based on slider 1
  analogWrite(LED6, ledLevel); //Set LED brightness
  Serial.print(",  Wrote LED = "); 
  Serial.print(ledLevel); 

  //Set the sound based on the 3rd slider
  long buzSound = map(val3, 0, 1023, 1000, 10000); //Map the slider value to an audible frequency
  if(buzSound > 1100)
    tone(BUZZER, buzSound); //Set sound value
  else
    noTone(BUZZER);
  Serial.print(",  Wrote Tone = "); 
  Serial.print(buzSound); 
  Serial.println(); // Note this
    
  delay(25); // This speed up, Pro is finer sound changes, Con is spam Serial Prints.
}



