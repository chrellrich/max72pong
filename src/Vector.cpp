#include <Vector.h>

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector Vector::add(Vector b) {
    return Vector(this->x + b.x, this->y + b.y);
}

Vector Vector::subtract(Vector b) {
    return Vector(this->x - b.x, this->y - b.y);
}

Vector Vector::scale(float n) {
    return Vector(this->x*n, this->y*n);
}

float Vector::length() {
    return sqrt((this->x * this->x) + (this->y * this->y));
}

Vector Vector::rotate(float angle) {
    // x' = x cos θ − y sin θ
    // y' = x sin θ + y cos θ
    angle = 2 * PI / 360 * angle;

    float xn = this->x * cos(angle) - this->y * sin(angle);
    float yn = this->x * sin(angle) + this->y * cos(angle); 

    return Vector(xn, yn);
}

Vector Vector::unitVector() {
    return this->scale(1/this->length());
}

float Vector::dotProduct(Vector b) {
    return this->x * b.x + this->y * b.y;
}

bool Vector::equals(Vector b) {
    return this->getX() == b.getX() && this->getY() == b.getY();
}

bool Vector::operator==(Vector b) {
    return this->equals(b);
}
// Getter and Setter
void Vector::set(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vector::setX(float x) {
    this->x = x;
}

void Vector::setY(float y) {
    this->y = y;
}

float Vector::getX() {
    return x;
}

float Vector::getY() {
    return y;
}