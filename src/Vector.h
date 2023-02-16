#ifndef Vector_h
#define Vector_h
#include "Arduino.h"

class Vector
{
public:
    Vector();
    Vector(int x, int y);
    Vector add(Vector vec);
    Vector subtract(Vector b);
    Vector scale(int n);
    int length();
    Vector unitVector();
    int dotProduct(Vector b);
    void set(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

private:
    int x;
    int y;
};
#endif