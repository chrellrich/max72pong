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

bool Display::getPixel(int x, int y)
{
    Vector displayCoords = convertToDisplayCoords(x, y);
    return mx->getPoint(displayCoords.getY(), displayCoords.getX());
}

bool Display::getPixel(Vector pixel)
{
    return this->getPixel(pixel.getX(), pixel.getY());
}

void Display::setPixel(int x, int y, bool state)
{

    if (x < 0 || x > 31 || y < 0 || y > 31)
    {
        return;
    }

    // if (x < 0)
    // {
    //     x = 0;
    // }
    // else if (x > 31)
    // {
    //     x = 31;
    // }

    // if (y < 0)
    // {
    //     y = 0;
    // }
    // else if (y > 31)
    // {
    //     y = 31;
    // }

    Vector displayCoords = convertToDisplayCoords(x, y);
    mx->setPoint(displayCoords.getY(), displayCoords.getX(), state);
}

void Display::setPixel(Vector pixel, bool state)
{
    this->setPixel(pixel.getX(), pixel.getY(), state);
}

void Display::setUpdate(bool state)
{
    mx->control(MD_MAX72XX::UPDATE, (state) ? MD_MAX72XX::ON : MD_MAX72XX::OFF);
}

void Display::resetMatrix()
{
    mx->control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 10);
    mx->control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
    mx->clear();
}

Vector Display::convertToDisplayCoords(int x, int y)
{
    // 32x32 pixel display is connected as 8x128
    int moduleRow = (y - y % 8) / 8;
    int xDisplay = -1;
    int yDisplay = -1;
    if (moduleRow % 2 == 0)
    {
        xDisplay = 31 - x + 32 * moduleRow;
        yDisplay = y % 8;
    }
    else
    {
        xDisplay = x + 32 * moduleRow;
        yDisplay = 7 - y % 8;
    }

    return Vector(xDisplay, yDisplay);
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
