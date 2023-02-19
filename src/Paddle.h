#ifndef Paddle_h
#define Paddle_h
#include "Arduino.h"
#include <Display.h>

class Paddle
{
public:
    Paddle();
    Paddle(int length);
    void setPosition(Vector position);

    void setVelocity(Vector velocity);

	int length;
    Vector position;
    Vector velocity;
private:
};
#endif