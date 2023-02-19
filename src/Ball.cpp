#include <Ball.h>

Ball::Ball() {
	position.set(0,0);
    init();
}

Ball::Ball(int x, int y) {
    position.set(x,y);
    init();
}

void Ball::init() {
    // random direction here? 
    velocity.set(0,0);
}

void Ball::setPosition(Vector position) {
    this->position = position;
}

void Ball::setVelocity(Vector velocity) {
    this->velocity = velocity;
}