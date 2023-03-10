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

String Physics::update(Ball *ball, Paddle *lp, Paddle *rp, Display *display)
{
    display->setUpdate(true);

    // ball
    String gameState = updateBall(ball, display, lp, rp);

    // left paddle
    updatePaddle(lp, display);

    // right paddle
    updatePaddle(rp, display);

    display->setUpdate(false);
    return gameState;
}

String Physics::updateBall(Ball *ball, Display *display, Paddle *lp, Paddle *rp)
{
    String gameState = "";
    if (!(ball->velocity.equals(Vector(0, 0))))
    {
        if (!((ball->position.getX() >= 8 && ball->position.getX() <= 10 && ball->position.getY() >= 1 && ball->position.getY() <= 5) || (ball->position.getX() >= 21 && ball->position.getX() <= 24 && ball->position.getY() >= 1 && ball->position.getY() <= 5)))
        {
            display->setPixel(ball->position, false);
        }

        ball->setPosition(ball->position.add(ball->velocity));

        if (ball->position.getX() < 0)
        {
            Vector PaddleStart = lp->position;
            Vector PaddleEnd = PaddleStart.add(Vector(0, lp->length - 1));

            if (ball->position.getY() >= PaddleStart.getY() && ball->position.getY() <= PaddleEnd.getY())
            {
                // paddle was hit
                ball->velocity.setX(ball->velocity.getX() * -1);

                if (ball->position.getY() <= PaddleStart.getY() + 2)
                {
                    // upper 2 pixels were hit
                    ball->setVelocity(ball->velocity.rotate(-10));
                    
                }
                else if (ball->position.getY() >= PaddleEnd.getY() - 2)
                {
                    // lower 2 pixels were hit
                    ball->setVelocity(ball->velocity.rotate(10));
                }

                // increase ball speed by 10 percent
                ball->setVelocity(ball->velocity.scale(1.1));

                // cap ball speed at 3
                if (ball->velocity.length() > 3)
                {
                    ball->setVelocity(ball->velocity.scale(1 / ball->velocity.length() * 3));
                }
            }
            else
            {
                ball->setVelocity(Vector(0, 0));
                ball->setPosition(Vector(15, 15));
                gameState = "leftHit";
            }
        }
        else if (ball->position.getX() > 31)
        {
            Vector PaddleStart = rp->position;
            Vector PaddleEnd = PaddleStart.add(Vector(0, rp->length - 1));

            if (ball->position.getY() >= PaddleStart.getY() && ball->position.getY() <= PaddleEnd.getY())
            {
                // paddle was hit
                ball->velocity.setX(ball->velocity.getX() * -1);

                if (ball->position.getY() <= PaddleStart.getY() + 2)
                {
                    // upper 2 pixels were hit
                    ball->setVelocity(ball->velocity.rotate(10));
                }
                else if (ball->position.getY() >= PaddleEnd.getY() - 2)
                {
                    // lower 2 pixels were hit
                    ball->setVelocity(ball->velocity.rotate(-10));
                }

                ball->setVelocity(ball->velocity.scale(1.1));
                if (ball->velocity.length() > 3)
                {
                    ball->setVelocity(ball->velocity.scale(1 / ball->velocity.length() * 3));
                }
            }
            else
            {
                ball->setVelocity(Vector(0, 0));
                ball->setPosition(Vector(15, 15));
                gameState = "rightHit";
            }
        }

        if (ball->position.getY() < 0 || ball->position.getY() > 31)
        {
            ball->velocity.setY(ball->velocity.getY() * -1);
        }
        // only draw ball if not in score area
        if (!((ball->position.getX() >= 8 && ball->position.getX() <= 10 && ball->position.getY() >= 1 && ball->position.getY() <= 5) || (ball->position.getX() >= 21 && ball->position.getX() <= 24 && ball->position.getY() >= 1 && ball->position.getY() <= 5)))
        {
            display->setPixel(ball->position, true);
        }
    }
    return gameState;
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