#include "Physics.h"

Physics::Physics()
{
}

void Physics::update(Ball *ball, Paddle *lp, Paddle *rp, Display *display)
{

    // left paddle
    updatePaddle(lp, display);

    // right paddle
    updatePaddle(rp, display);

    // ball
    if (!(ball->velocity.equals(Vector(0, 0))))
    {
        display->setPixel(ball->position, false);

        ball->setPosition(ball->position.add(ball->velocity));
        if (ball->position.getY() < 0 || ball->position.getY() > 31)
        {
            ball->velocity.setY(ball->velocity.getY() * -1);
        }
        if (ball->position.getX() < 0 || ball->position.getX() > 31)
        {
            ball->velocity.setX(ball->velocity.getX() * -1);
        }

        display->setPixel(ball->position, true);
    }
}

void Physics::updatePaddle(Paddle* paddle, Display* display) {
    if (!(paddle->velocity.equals(Vector(0, 0))))
    {
        Vector oldPos = paddle->position;
        Vector oldPosLast = oldPos.add(Vector(0,paddle->length-1));
        
        Vector newPos = paddle->position.add(paddle->velocity);
        Vector newPosLast = newPos.add(Vector(0,paddle->length-1));


        if (newPos.getY() < 0)
        {
            newPos.setY(0);
        }
        else if (newPosLast.getY() > 31)
        {
            newPos.setY(32 - paddle->length);
        }
        if (paddle->velocity.getY() > 0)
        {
            display->setPixel(oldPos, false);
            display->setPixel(newPosLast, true);
        }
        if (paddle->velocity.getY() < 0)
        {
            display->setPixel(oldPosLast, false);
            display->setPixel(newPos, true);
        }
        paddle->setPosition(newPos);
    }
}