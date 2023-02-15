#ifndef Paddle_h
#define Paddle_h
#include "Arduino.h"
class Paddle
{
public:
	Paddle(int length);
	void setPosition(int position);

private:
	int length;
    int position;
};
#endif