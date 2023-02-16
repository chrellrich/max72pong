#include <Ball.h>

Ball::Ball() {
	position.set(0,0);
    
}

Ball::Ball(int x, int y) {
    position.set(x,y);   
}

void Ball::init() {
    // random direction here? 
    velocity.set(0,0);
}