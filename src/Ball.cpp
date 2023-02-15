#include "Arduino.h"
#include "Ball.h"

Ball::Ball() {
	x = 0;
    y = 0;
}

Ball::Ball(int x, int y) {
    this->x = x;
    this->y = y;
}