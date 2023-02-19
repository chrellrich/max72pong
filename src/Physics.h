#ifndef Physics_h
#define Physics_h
#include "Arduino.h"
#include <Ball.h>
#include <Paddle.h>

class Physics
{
public:
    Physics();
    void update(Ball ball, Paddle lp, Paddle rp);
private:
    
};
#endif