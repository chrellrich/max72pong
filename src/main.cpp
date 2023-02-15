#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
// #include <Paddle.h>
#include <Vector.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 10;
long int FrameDuration = 1000/framerate;

Display* display = new Display();
Ball* ball = new Ball();

void setup() {
  Serial.begin(57600);
}

void loop() {
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration) {
    Serial.println(thisFrameTime - lastFrameTime);
    
    // Executes on every new frame



    lastFrameTime = thisFrameTime;
  }
  
}
