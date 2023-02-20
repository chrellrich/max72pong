#ifndef Vector_h
#define Vector_h
#include "Arduino.h"

class Vector
{
public:
    Vector();
    Vector(float x, float y);
    Vector add(Vector vec);
    Vector subtract(Vector b);
    Vector scale(float n);
    float length();
    Vector rotate(float angle);
    Vector unitVector();
    float dotProduct(Vector b);
    bool equals(Vector b);
    bool operator==(Vector b);
    void set(float x, float y);
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();

private:
    float x;
    float y;
};
#endif