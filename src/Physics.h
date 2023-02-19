#ifndef Physics_h
#define Physics_h
#include "Arduino.h"
#include <Ball.h>
#include <Paddle.h>
#include <Display.h>

class Physics
{
public:
    Physics();
    void init(Ball *ball, Paddle *lp, Paddle *rp, Display *display);
    void update(Ball *ball, Paddle *lp, Paddle *rp, Display *display);

    void updateBall(Ball *ball, Display *display);

private:
    void updatePaddle(Paddle* paddle, Display* display);
    
};
#endif