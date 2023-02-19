#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
#include <Paddle.h>
#include <Vector.h>
#include <Physics.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 10;
long int FrameDuration = 0;//1000 / framerate;
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
  ball = new Ball(0, 5);
  leftPaddle = new Paddle();
  leftPaddle->setPosition(Vector(0, 0));
  rightPaddle = new Paddle();
  rightPaddle->setPosition(Vector(31, 0));
  physics = Physics();
  ball->setVelocity(Vector(1, 1));
}

void loop()
{
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration)
  {
     Serial.println(thisFrameTime - lastFrameTime);
    // Executes on every new frame

    // read inputs
    int joyValue1 = analogRead(joyStick1);
    int joyValue2 = analogRead(joyStick2);
    if (joyValue1 < 400)
    {
      leftPaddle->velocity.setY(-1);
    }
    else if (joyValue1 > 600)
    {
      leftPaddle->velocity.setY(1);
    }
    else
    {
      leftPaddle->velocity.setY(0);
    }
    if (joyValue2 < 400)
    {
      rightPaddle->velocity.setY(-1);
    }
    else if (joyValue2 > 600)
    {
      rightPaddle->velocity.setY(1);
    }
    else
    {
      rightPaddle->velocity.setY(0);
    }

    // calculate game state
    physics.update(ball, leftPaddle, rightPaddle, display);

    // // draw frame

    lastFrameTime = thisFrameTime;
  }
}
