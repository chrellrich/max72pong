#include "Arduino.h"
#include "DisplayMatrix.h"
DisplayMatrix::DisplayMatrix(int pin) {
	pinMode(pin, OUTPUT);
	_pin = pin;
}
void DisplayMatrix::myFunction(int blinkRate){
digitalWrite(_pin, HIGH);
delay(blinkRate);
digitalWrite(_pin, LOW);
delay(blinkRate);
}