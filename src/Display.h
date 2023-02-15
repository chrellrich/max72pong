#ifndef Display_h
#define Display_h
#include "Arduino.h"
#include <MD_MAX72xx.h>

class Display
{
public:
	Display();
	void setPixel(int x, int y, bool state);

private:
    void init();
	void resetMatrix();
	int convertXToDisplayCoords(int xGame, int yGame);
	int convertYToDisplayCoords(int xGame, int yGame);
};
#endif