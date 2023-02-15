#ifndef Ball_h
#define Ball_h
#include "Arduino.h"
class Ball
{
public:
	Ball();
    Ball(int x, int y);

private:
	int x;
    int y;
    int dx;
    int dy;
};
#endif