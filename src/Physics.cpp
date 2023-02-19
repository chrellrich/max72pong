#include "Physics.h"

Physics::Physics()
{
}

void Physics::init(Ball *ball, Paddle *lp, Paddle *rp, Display *display)
{
    display->setUpdate(true);
    // paddles
    Vector lpLast = lp->position.add(Vector(0, lp->length - 1));
    Vector rpLast = rp->position.add(Vector(0, lp->length - 1));
    for (int i = lp->position.getY(); i < lpLast.getY(); i++)
    {
        display->setPixel(lp->position.getX(), i, true);
    }
    for (int i = rp->position.getY(); i < rpLast.getY(); i++)
    {
        display->setPixel(rp->position.getX(), i, true);
    }

    // ball
    display->setPixel(ball->position, true);
    display->setUpdate(false);
}

void Physics::update(Ball *ball, Paddle *lp, Paddle *rp, Display *display)
{
    display->setUpdate(true);

    // ball
    updateBall(ball, display);

    // left paddle
    updatePaddle(lp, display);

    // right paddle
    updatePaddle(rp, display);

    display->setUpdate(false);
}

void Physics::updateBall(Ball *ball, Display *display)
{
    if (!(ball->velocity.equals(Vector(0, 0))))
    {
        display->setPixel(ball->position, false);

        ball->setPosition(ball->position.add(ball->velocity));
        if (ball->position.getY() < 0 || ball->position.getY() > 31)
        {
            ball->velocity.setY(ball->velocity.getY() * -1);
        }
        if (ball->position.getX() < 1 || ball->position.getX() > 31)
        {
            ball->velocity.setX(ball->velocity.getX() * -1);
        }

        display->setPixel(ball->position, true);
    }
}

void Physics::updatePaddle(Paddle *paddle, Display *display)
{
    if (!(paddle->velocity.equals(Vector(0, 0))))
    {
        Vector oldPos = paddle->position;
        Vector oldPosLast = oldPos.add(Vector(0, paddle->length - 1));

        Vector newPos = paddle->position.add(paddle->velocity);
        Vector newPosLast = newPos.add(Vector(0, paddle->length - 1));

        if (newPos.getY() < 0)
        {
            newPos.setY(0);
        }
        else if (newPosLast.getY() > 31)
        {
            newPos.setY(32 - paddle->length);
        }
        if (!oldPos.equals(newPos))
        {
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

    Vector posLast = paddle->position.add(Vector(0, paddle->length - 1));
    for (int i = paddle->position.getY(); i <= posLast.getY(); i++)
    {
        if (display->getPixel(paddle->position.getX(), i) == false)
        {
            display->setPixel(paddle->position.getX(), i, true);
        }
    }
}