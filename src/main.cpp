#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
#include <Paddle.h>
#include <Vector.h>
#include <Physics.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 60;
long int FrameDuration = 1000 / framerate;
int joyStick1 = A0;
int joyStick2 = A1;

Display *display;
Ball *ball;
Paddle *leftPaddle;
Paddle *rightPaddle;
Physics physics;

void setup()
{
  Serial.begin(57600);
  display = new Display();
  // ball = Ball(31,31);
  ball = new Ball(0, 0);
  leftPaddle = new Paddle();
  leftPaddle->setPosition(Vector(0, 31));
  rightPaddle = new Paddle();
  leftPaddle->setPosition(Vector(0, 0));
  physics = Physics();
  ball->setVelocity(Vector(1, 3));
}

void loop()
{
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration)
  {
    // Serial.println(thisFrameTime - lastFrameTime);
    // Executes on every new frame

    // read inputs
    if (analogRead(joyStick1) < 400)
    {
      ball->velocity.setX(1);
    }
    else if (analogRead(joyStick1) > 600)
    {
      ball->velocity.setX(-1);
    }
    else
    {
      ball->velocity.setX(0);
    }

    if (analogRead(joyStick2) < 400)
    {
      ball->velocity.setY(-1);
    }
    else if (analogRead(joyStick2) > 600)
    {
      ball->velocity.setY(1);
    }
    else
    {
      ball->velocity.setY(0);
    }

    // calculate game state
    physics.update(ball, leftPaddle, rightPaddle, display);

    // // draw frame

    lastFrameTime = thisFrameTime;
  }
}
