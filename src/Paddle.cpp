#include "Arduino.h"
#include "Paddle.h"

Paddle::Paddle() {
    this->length = 6;
}

Paddle::Paddle(int length) {
    this->length = length;
}

void Paddle::setPosition(Vector position) {
    this->position = position;
}

void Paddle::setVelocity(Vector velocity) {
    this->velocity = velocity;
}