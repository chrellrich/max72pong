#ifndef DisplayMatrix_h
#define DisplayMatrix_h
#include "Arduino.h" 
class DisplayMatrix {
public:
	DisplayMatrix(int pin);
	void myFunction(int blinkRate);
private:
	int _pin;
};
#endif