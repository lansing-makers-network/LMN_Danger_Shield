#define TEMP     A4

void setup()
{
  Serial.begin(115200);

  //Initialize inputs and outputs
  pinMode(TEMP, INPUT);

  Serial.println("Danger Shield Temperature Test");  
}

void loop()
{
  //Read inputs
  long temperature = analogRead(TEMP);

  //Do conversion of temp from analog value to digital
	//5V is the same as 1023 from the ADC (12-bit) 
	//example, the ADC returns 153 * 5000 = 765,000
  temperature = temperature * 5000; 
	//It's now in mV - 765,000 / 1023 = 747
  temperature = temperature / 1023; 
   //The TMP36 reports 500mV at 0C 
	 //so let's subtract off the 500mV offset
  temperature -= 500; //747 - 500 = 247
  //Temp is now in C where 247 = 24.7

  //Display values
  char tempString[200];
  sprintf(tempString, " Temp: %03d.%01dC",
              (int)temperature/10, (int)temperature%10);
  Serial.print(tempString); 
}



