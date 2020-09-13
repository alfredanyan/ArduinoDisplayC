#include "SevSeg.h"
SevSeg sevseg;

const int buttonPin = 13
int buttonState = 0;
int lastButtonState = 0;

void setup(){
Serial.begin(9600);
pinMode(buttonPin, INPUT);
byte numDigits = 1;
byte digitPins[] = {};
byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
  // set true whenever current limiting resistor is connected in series
  bool resistorsOnSegment = true;
  byte hardwareConfig = COMMON_CATHODE;
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorOnSegment);
  sevseg.setBrightness(90);
  //set starting digit
  sevseg.setNumber(0);
  sevseg.refreshDisplay();
}

void loop(){
  //loop through whenever button is pressed
  buttonState = digitalRead(buttonPin);
  if(buttonState =! lastButtonState){
  if(buttonState == HIGH) {
    CycleNumbers();
    sevseg.setNumber(GenerateRandomNumber());
    sevseg.refreshDisplay();
  }
    //to prevent bounce switch
    delay(50)
  }
  lastButtonState = buttonState;

}
void CycleNumbers(){
  for(int i=0; i<10; i++){
    sevseg.setNumber(i);
    sevseg.refreshDisplay();
    delay(200);
  
  }
}

void GenerateRandomNumber(){
  //set seed to unknown value of analog read of unused pin
  randomSeed(analogRead(0));
  return random(0, 10);
}
