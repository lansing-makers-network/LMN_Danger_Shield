#define SLIDER_A0  A0 //Matches button 3
#define BUZZER   3

void setup()
{
  Serial.begin(115200);

  //Initialize inputs and outputs
  pinMode(SLIDER_A0, INPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Danger Shield Component: Slider/Tone");  
}

void loop()
{
  //Read inputs
  int val3 = analogRead(SLIDER_A0);

  //Set the sound based on the 3rd slider
  long buzSound = map(val3, 0, 1023, 1000, 10000); 
	//Map the slider value to an audible frequency
  if(buzSound > 1100)
    tone(BUZZER, buzSound); //Set sound value
  else
    noTone(BUZZER);
}



