#include "Physics.h"

Physics::Physics() {

}

void Physics::update(Ball ball, Paddle lp, Paddle rp) {
    // left paddle
    lp.setPosition(lp.position.add(lp.velocity));
    if (lp.position.getY() < 0) {
        lp.position.setY(0);
    } else if (lp.position.getY() + lp.length > 32)
    {
        lp.position.setY(32 - lp.length);
    }

    // right paddle
    rp.setPosition(rp.position.add(rp.velocity));
    if (rp.position.getY() < 0) {
        rp.position.setY(0);
    } else if (rp.position.getY() + rp.length > 32)
    {
        rp.position.setY(32 - rp.length);
    }

    // ball
    ball.setPosition(ball.position.add(ball.velocity));
    if (ball.position.getY() < 0 || ball.position.getY() > 31) {
        ball.velocity.setY(ball.velocity.getY()*-1);
    }
    if (ball.position.getX() < 0 || ball.position.getX() > 31)
    {
        ball.velocity.setX(ball.velocity.getX()*-1);
    }
}