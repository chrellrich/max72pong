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
    String update(Ball *ball, Paddle *lp, Paddle *rp, Display *display);

    String updateBall(Ball *ball, Display *display, Paddle *lp, Paddle *rp);

private:
    void updatePaddle(Paddle* paddle, Display* display);
    
};
#endif