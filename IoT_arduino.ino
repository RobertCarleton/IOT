// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

double sensorValue = 0;        // value read from the pot
double outputValue = 0;        // value output to the PWM (analog out)

// LCD
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

void setup() {
  pinMode(4, OUTPUT);
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

// LCD
  lcd.begin(16, 2);

    lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 50 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(50);


  if(sensorValue >= 300)
   {
    lcd.setCursor(0, 0);
    lcd.print("humidity high  "); // spaces are needed to keep text spaced properly
    lcd.setRGB(colorR, 0, 0); // Red
   }
  else
   {
    lcd.setCursor(0, 0);
    lcd.print("humidity normal");
    lcd.setRGB(0, colorG, 0); // Green
   }
    
  lcd.setCursor(0, 1);
    // Prints the value of the moisture sensor
    lcd.print(sensorValue);
}
