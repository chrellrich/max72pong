#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
#include <Paddle.h>
#include <Vector.h>
#include <Physics.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 30;
long int FrameDuration = 1000 / framerate;
int joyStick1 = A0;
int joyStick2 = A1;

Display *display;
Ball *ball;
Paddle *leftPaddle;
Paddle *rightPaddle;
Physics physics;

int scoreLeft = 0;
int scoreRight = 0;

void setup()
{
  Serial.begin(57600);
  display = new Display();
  // ball = Ball(31,31);
  ball = new Ball(15, 15);
  leftPaddle = new Paddle();
  leftPaddle->setPosition(Vector(0, 0));
  rightPaddle = new Paddle();
  rightPaddle->setPosition(Vector(31, 0));
  physics = Physics();
  ball->setVelocity(Vector(1, 2));
  physics.init(ball, leftPaddle, rightPaddle, display);
}

void drawScore() {
  // todo draw either numbers or maybe points to indicate the current scores
}

void resetField() {
  ball->setPosition(Vector(15.5,15.5));
  int startDir = 0;
  if (scoreLeft > scoreRight) {
    startDir = 1;
  } else if (scoreLeft < scoreRight)
  {
    startDir = -1;
  } else {
    startDir = random(-1, 1);
  }
  
  ball->setVelocity(Vector(startDir, 0));
  leftPaddle->setPosition(Vector(0,0));
  rightPaddle->setPosition(Vector(0,31));
  leftPaddle->setVelocity(Vector(0,0));
  rightPaddle->setVelocity(Vector(0,0));
  display->resetMatrix();
  drawScore();
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
    String gameState = physics.update(ball, leftPaddle, rightPaddle, display);
    if (gameState == "leftHit")
    { 
      scoreRight += 1,
      resetField();
      Serial.println("right scored");
    }
    else if (gameState == "righttHit")
    {
      scoreLeft += 1,
      resetField();
      Serial.println("left scored");
    }
    lastFrameTime = thisFrameTime;
  }
}
