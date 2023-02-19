#ifndef Ball_h
#define Ball_h
#include <Arduino.h>
#include <Vector.h>
#include <Display.h>


class Ball
{
public:
	Ball();
    Ball(int x, int y);

    void init();

    void setPosition(Vector position);

    void setVelocity(Vector velocity);

	Vector position;
    Vector velocity;
private:
};
#endif