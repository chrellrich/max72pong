#include "Display.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 16
#define CLK_PIN 13  // or SCK
#define DATA_PIN 11 // or MOSI
#define CS_PIN 10   // or SS

MD_MAX72XX* mx = new MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

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
    mx->setPoint(convertYToDisplayCoords(x, y), convertXToDisplayCoords(x, y), state);
}

void Display::resetMatrix()
{
    mx->control(MD_MAX72XX::INTENSITY, MAX_INTENSITY / 10);
    mx->control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
    mx->clear();
}

int Display::convertXToDisplayCoords(int xGame, int yGame)
{
    return 0;
}

int Display::convertYToDisplayCoords(int xGame, int yGame)
{
    return 0;
}
