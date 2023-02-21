#include <Arduino.h>
#include <Display.h>
#include <Ball.h>
#include <Paddle.h>
#include <Vector.h>
#include <Physics.h>
#include <font.h>

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

int state = 0;

void setup()
{
  Serial.begin(57600);
  display = new Display();
  ball = new Ball(15, 15);
  leftPaddle = new Paddle();
  leftPaddle->setPosition(Vector(0, 0));
  rightPaddle = new Paddle();
  rightPaddle->setPosition(Vector(31, 0));
  physics = Physics();
  ball->setVelocity(Vector(1, 2));
  physics.init(ball, leftPaddle, rightPaddle, display);
}

void drawByteArray(bool zeichen[5][3], int position)
{
  display->setUpdate(true);
  for (int i = 0; i < 5; i++)
  {
    // Serial.print("i = ");
    // Serial.print(i);
    for (int j = 0; j < 3; j++)
    {
      // Serial.print(" j(");
      // Serial.print(j);
      // Serial.print(") ");
      // Serial.print((zero[i][j]));
      display->setPixel(position + j, 1 + i, zeichen[i][j]);
    }
    // Serial.println();
  }
  display->setUpdate(false);
}

void drawNumber(int score, int position)
{

  switch (score)
  {
  case 0:
    drawByteArray(zero, position);
    break;
  case 1:
    drawByteArray(one, position);
    break;
  case 2:
    drawByteArray(two, position);
    break;
  case 3:
    drawByteArray(three, position);
    break;
  case 4:
    drawByteArray(four, position);
    break;
  case 5:
    drawByteArray(five, position);
    break;
  case 6:
    drawByteArray(six, position);
    break;
  case 7:
    drawByteArray(seven, position);
    break;
  case 8:
    drawByteArray(eight, position);
    break;
  case 9:
    drawByteArray(nine, position);
    break;

  default:
    break;
  }
}

void drawScore()
{
  drawNumber(scoreLeft, 8);
  drawNumber(scoreRight, 21);
}

void resetField()
{
  if (scoreLeft == 10)
  {
    state = 1;
    scoreLeft = 0;
  }
  else if (scoreRight == 10)
  {
    state = 1;
    scoreRight = 0;
  }
  int startDir = 0;
  if (scoreLeft > scoreRight)
  {
    startDir = -1;
  }
  else if (scoreLeft < scoreRight)
  {
    startDir = 1;
  }
  else
  {
    startDir = (rand() % 2 == 0) ? 1 : -1;
  }
  ball->setPosition(Vector(15, 15));
  ball->setVelocity(Vector(0.5 * startDir, 0));
  leftPaddle->setVelocity(Vector(0, 0));
  rightPaddle->setVelocity(Vector(0, 0));
  // display->resetMatrix();
  display->setPixel(ball->position, false);
  drawScore();
}

void readInputs()
{
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
}

void loop()
{
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration)
  {
    // Serial.println(thisFrameTime - lastFrameTime);
    // Executes on every new frame
    switch (state)
    {
    case 0:
      // game in progress
      // read inputs
      readInputs();

      // calculate game state
      String gameState = physics.update(ball, leftPaddle, rightPaddle, display);
      if (gameState == "leftHit")
      {
        scoreRight += 1,
            resetField();
        Serial.println("right scored");
      }
      else if (gameState == "rightHit")
      {
        scoreLeft += 1,
            resetField();
        Serial.println("left scored");
      }
      break;
    case 1:
      break;
    default:
      break;
    }

    lastFrameTime = thisFrameTime;
  }
}
