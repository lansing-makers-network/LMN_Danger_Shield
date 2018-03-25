// Pin definitions
#define SLIDER_A2  A2 //Matches button 1
#define SLIDER_A1  A1 
#define SLIDER_A0  A0 //Matches button 3

void setup()
{
  Serial.begin(115200);

  //Enable internal pullups
  // The default is INPUT!!!!
  pinMode(SLIDER_A2, INPUT);
  pinMode(SLIDER_A1, INPUT);
  pinMode(SLIDER_A0, INPUT);

  Serial.println("Danger Shield Component: AnalogRead");  
}

void loop()
{
  //Read inputs
  int val1 = analogRead(SLIDER_A2);
  int val2 = analogRead(SLIDER_A1);
  int val3 = analogRead(SLIDER_A0);

  //sprintf is a great way to combine a bunch of 
  // variables and strings together into one 
  // print statement
  char tempString[200];
  sprintf(tempString, "Sliders: %04d %04d %04d ", 
                                  val1, val2, val3);
  Serial.println(tempString); 

  delay(250);
}



