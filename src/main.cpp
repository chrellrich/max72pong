#include <MD_MAX72xx.h>
#include <SPI.h>
#include <DisplayMatrix.h>
#include <Ball.h>
#include <Paddle.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 16
#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS


MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES); // Arbitrary pins

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 60;
long int FrameDuration = 1000/framerate;

void resetMatrix(void) {
  mx.control(MD_MAX72XX::INTENSITY, MAX_INTENSITY/10);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  mx.clear();
}

int convertXToDisplayCoords(int xGame,int yGame) {
  // 32x32 pixel display is connect as 8x128 
  int moduleRow = (yGame - yGame % 8) / 8;
  int xDisplay = -1;
  if (moduleRow % 2 == 0) {
    xDisplay = 31 - xGame + 32 * moduleRow;
  } else {
    xDisplay = xGame + 32 * moduleRow;
  }
  return xDisplay;
}

int convertYToDisplayCoords(int xGame,int yGame) {
  // 32x32 pixel display is connect as 8x128 
  int moduleRow = (yGame - yGame % 8) / 8;
  int yDisplay = -1;
  if (moduleRow % 2 == 0) {
    yDisplay = yGame % 8;
  } else {
    yDisplay = 7 - yGame % 8;
  }
  return yDisplay; 
}

void setup() {
  mx.begin();
  resetMatrix();
  Serial.begin(57600);
}

void loop() {
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration) {
    Serial.println(thisFrameTime - lastFrameTime);
    
    lastFrameTime = thisFrameTime;
  }
  
}
