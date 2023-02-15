#include "Arduino.h"
#include "Paddle.h"

Paddle::Paddle(int length) {
    this->length = length;
}

void Paddle::setPosition(int position) {
    this->position = position;
}