// Shift register bit values to display
// 0-9 on the seven-segment display
const byte ledCharSet[10] = {
 //dGFEDCBA
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};


// Pin definitions
#define SLIDER_A1  A1
#define DATA     4
#define LATCH    7
#define CLOCK    8

void setup()
{
  Serial.begin(115200);
  //Initialize inputs and outputs
  pinMode(SLIDER_A1, INPUT);

  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(DATA, OUTPUT);

  Serial.println("Danger Shield Component 7 Segment");
}

void loop()
{
  //Read inputs
  int val2 = analogRead(SLIDER_A1); // 0-1023

  //Display values
  Serial.print("val2 = ");
  Serial.print(val2); // Note the HEX.
  Serial.print(" (0x");
  Serial.print(val2, HEX); // Note the HEX.
  Serial.println(")");

  //Set 7 segment display based on the 2nd slider
  //Map the slider value to a displayable value
  int numToDisplay = map(val2, 0, 1023, 0, 9); 
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLOCK, MSBFIRST, ~(ledCharSet[numToDisplay]));
  digitalWrite(LATCH, HIGH);

  delay(25);
}



