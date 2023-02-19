#include "Physics.h"

Physics::Physics()
{
}

void Physics::update(Ball *ball, Paddle *lp, Paddle *rp, Display *display)
{

    // left paddle
    if (!(lp->velocity.equals(Vector(0, 0))))
    {
        Vector oldPos = lp->position;
        Vector oldPosLast = oldPos.add(Vector(0,lp->length-1));
        
        Vector newPos = lp->position.add(lp->velocity);
        Vector newPosLast = newPos.add(Vector(0,lp->length-1));


        if (newPos.getY() < 0)
        {
            newPos.setY(0);
        }
        else if (newPosLast.getY() > 31)
        {
            newPos.setY(32 - lp->length);
        }
        if (lp->velocity.getY() > 0)
        {
            display->setPixel(oldPos, false);
            display->setPixel(newPosLast, true);
        }
        if (lp->velocity.getY() < 0)
        {
            display->setPixel(oldPosLast, false);
            display->setPixel(newPos, true);
        }
        lp->setPosition(newPos);
    }

    // right paddle
    if (!(rp->velocity.equals(Vector(0, 0))))
    {
        for (int i = rp->position.getY(); i < rp->position.getY() + rp->length; i++)
        {
            display->setPixel(rp->position.getX(), i, false);
        }

        rp->setPosition(rp->position.add(rp->velocity));
        if (rp->position.getY() < 0)
        {
            rp->position.setY(0);
        }
        else if (rp->position.getY() + rp->length > 32)
        {
            rp->position.setY(32 - rp->length);
        }

        for (int i = rp->position.getY(); i < rp->position.getY() + rp->length; i++)
        {
            display->setPixel(rp->position.getX(), i, true);
        }
    }

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