#ifndef Display_h
#define Display_h
#include "Arduino.h"
#include <MD_MAX72xx.h>
#include <Vector.h>

class Display
{
public:
	Display();
    bool getPixel(int x, int y);
    bool getPixel(Vector pixel);
    void setPixel(int x, int y, bool state);

    void setPixel(Vector pixel, bool state);

    void setUpdate(bool state);

    void resetMatrix();

private:
    void init();
    Vector convertToDisplayCoords(int x, int y);
    int convertXToDisplayCoords(int xGame, int yGame);
    int convertYToDisplayCoords(int xGame, int yGame);
};
#endif