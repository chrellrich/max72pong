#ifndef DisplayMatrix_h
#define DisplayMatrix_h
#include "Arduino.h"
class DisplayMatrix
{
public:
	DisplayMatrix();
	void setPixel(int x, int y, bool state);

private:
	void resetMatrix();
	int convertXToDisplayCoords(int xGame, int yGame);
	int convertYToDisplayCoords(int xGame, int yGame);
};
#endif