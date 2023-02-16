#ifndef Ball_h
#define Ball_h
#include <Arduino.h>
#include <Vector.h>

class Ball
{
public:
	Ball();
    Ball(int x, int y);

    void init();

private:
	Vector position;
    Vector velocity;
};
#endif