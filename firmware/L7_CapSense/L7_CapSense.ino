
// Pin definitions
#define CAP_PAD   9
#define CAP_GND   2

#include <CapacitiveSensor.h>

CapacitiveSensor capPadOn92 = CapacitiveSensor(CAP_PAD, CAP_GND);   

void setup()
{
  Serial.begin(115200);

  //Initialize the capsense
  capPadOn92.set_CS_AutocaL_Millis(0xFFFFFFFF); 
  // Turn off autocalibrate

  Serial.println("Danger Shield Component CapSense");
}

void loop()
{
  //Read the cap sense pad
  long capLevel = capPadOn92.capacitiveSensor(30);

  //Display values
  Serial.print("capLevel = ");
  Serial.print(capLevel); // Note the HEX.
  Serial.print(" (0x");
  Serial.print(capLevel, HEX); // Note the HEX.
  Serial.println(")");

  delay(250);
}



