#include <Vector.h>

Vector::Vector() {
    x = 0;
    y = 0;
}

Vector::Vector(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector Vector::add(Vector b) {
    return Vector(this->x + b.x, this->y + b.y);
}

Vector Vector::subtract(Vector b) {
    return Vector(this->x - b.x, this->y - b.y);
}

Vector Vector::scale(int n) {
    return Vector(this->x*n, this->y*n);
}

int Vector::length() {
    return sqrt(this->x^2 + this->y^2);
}

Vector Vector::unitVector() {
    return this->scale(this->length());
}

int Vector::dotProduct(Vector b) {
    return this->x * b.x + this->y * b.y;
}

// Getter and Setter
void Vector::set(int x, int y) {
    this->x = x;
    this->y = y;
}

void Vector::setX(int x) {
    this->x = x;
}

void Vector::setY(int y) {
    this->y = y;
}

int Vector::getX() {
    return x;
}

int Vector::getY() {
    return y;
}