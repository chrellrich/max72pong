#ifndef Display_h
#define Display_h
#include "Arduino.h"
#include <MD_MAX72xx.h>
#include <Vector.h>

class Display
{
public:
	Display();
	void setPixel(int x, int y, bool state);

    void setPixel(Vector *pixel, bool state);


private:
    void init();
	void resetMatrix();
    Vector convertToDisplayCoords(Vector coord);
    int convertXToDisplayCoords(int xGame, int yGame);
    int convertYToDisplayCoords(int xGame, int yGame);
};
#endif