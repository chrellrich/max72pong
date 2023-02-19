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
    return sqrt((this->x * this->x) + (this->y * this->y));
}

// Vector Vector::unitVector() {
//     return this->scale(1/this->length());
// }

int Vector::dotProduct(Vector b) {
    return this->x * b.x + this->y * b.y;
}

bool Vector::equals(Vector b) {
    return this->getX() == b.getX() && this->getY() == b.getY();
}

bool Vector::operator==(Vector b) {
    return this->equals(b);
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