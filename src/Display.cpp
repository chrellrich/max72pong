#include "Display.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 16
#define CLK_PIN 13  // or SCK
#define DATA_PIN 11 // or MOSI
#define CS_PIN 10   // or SS

MD_MAX72XX *mx = new MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

Display::Display()
{
    init();
}

void Display::init()
{
    mx->begin();
    resetMatrix();
}

void Display::setPixel(int x, int y, bool state)
{
    mx->control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
    mx->setPoint(convertYToDisplayCoords(x, y), convertXToDisplayCoords(x, y), state);
    mx->control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
}

void Display::setPixel(Vector* pixel, bool state)
{
    this->setPixel(pixel->getX(), pixel->getY(), state);
}

void Display::resetMatrix()
{
    mx->control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 10);
    mx->control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
    mx->clear();
}

Vector Display::convertToDisplayCoords(Vector coord) {
    Vector displayCoords = Vector();
    
    // 32x32 pixel display is connect as 8x128
    int moduleRow = (coord.getY() - coord.getY() % 8) / 8;
    int xDisplay = -1;
    int yDisplay = -1;
    if (moduleRow % 2 == 0)
    {
        xDisplay = 31 - coord.getX() + 32 * moduleRow;
        yDisplay = coord.getY() % 8;
    }
    else
    {
        xDisplay = coord.getX() + 32 * moduleRow;
        yDisplay = 7 - coord.getY() % 8;
    }
    displayCoords.setX(xDisplay);
    displayCoords.setY(yDisplay);

    return displayCoords;
}

int Display::convertXToDisplayCoords(int xGame, int yGame)
{
    // 32x32 pixel display is connect as 8x128
    int moduleRow = (yGame - yGame % 8) / 8;
    int xDisplay = -1;
    if (moduleRow % 2 == 0)
    {
        xDisplay = 31 - xGame + 32 * moduleRow;
    }
    else
    {
        xDisplay = xGame + 32 * moduleRow;
    }
    return xDisplay;
}

int Display::convertYToDisplayCoords(int xGame, int yGame)
{
    // 32x32 pixel display is connect as 8x128
    int moduleRow = (yGame - yGame % 8) / 8;
    int yDisplay = -1;
    if (moduleRow % 2 == 0)
    {
        yDisplay = yGame % 8;
    }
    else
    {
        yDisplay = 7 - yGame % 8;
    }
    return yDisplay;
}
