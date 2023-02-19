#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
#include <Paddle.h>
#include <Vector.h>
#include <Physics.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 10;
long int FrameDuration = 1000/framerate;

Display display;
Ball ball;
Paddle leftPaddle;
Paddle rightPaddle;
Physics physics;

void setup() {
  Serial.begin(57600);
  // ball = Ball(31,31);
  // leftPaddle = Paddle();
  // leftPaddle.setPosition(Vector(0,31));
  // rightPaddle = Paddle();
  // leftPaddle.setPosition(Vector(0,0));
  // display = Display();
  // physics = Physics();
  // ball.setVelocity(Vector(1,1));
}



void loop() {
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration) {
    Serial.println(thisFrameTime - lastFrameTime);
    display.resetMatrix();
    display.setPixel(0,0, true);
    // Executes on every new frame
    // read inputs


    // calculate game state
    // physics.update(ball, leftPaddle, rightPaddle);

    // // draw frame
    // display.setPixel(ball.position, true);

    lastFrameTime = thisFrameTime;
  }
  
}
