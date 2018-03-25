// Pin definitions
#define LED6     6
#define SLIDER_A2  A2 //Matches button 1

void setup()
{
  //Initialize inputs and outputs
  pinMode(LED6, OUTPUT);
  
  Serial.begin(115200);
  Serial.println("Danger Shield Component: AnalogRead");  
}

void loop()
{

  //Read inputs
  int val1 = analogRead(SLIDER_A2); // outputs 0-1023
  Serial.print("Slider = "); 
  Serial.print(val1); 

  // using MAP command to ratio adjust values.
  //Map the slider level to a value we can set on the LED
  int ledLevel = map(val1, 0, 1023, 0, 255); 
  
  //analogWrite requires 0-255
  //Set the brightness on LED #2 (D6) based on slider 1
  analogWrite(LED6, ledLevel); //Set LED brightness
  Serial.print(",  Wrote LED = "); 
  Serial.println(ledLevel); 

  delay(250);
}



