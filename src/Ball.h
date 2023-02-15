#ifndef Ball_h
#define Ball_h
#include "Arduino.h"
class Ball
{
public:
	Ball();

private:
	int x;
    int y;
    int dx;
    int dy;
};
#endif