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

int state = 1;

bool leftReady;
bool rightReady;

void drawBoolArray(bool zeichen[5][3], int x, int y)
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
      display->setPixel(x + j, y + i, zeichen[i][j]);
    }
    // Serial.println();
  }
  display->setUpdate(false);
}

void drawNumber(int score, int x, int y)
{

  switch (score)
  {
  case 0:
    drawBoolArray(zero, x, y);
    break;
  case 1:
    drawBoolArray(one, x, y);
    break;
  case 2:
    drawBoolArray(two, x, y);
    break;
  case 3:
    drawBoolArray(three, x, y);
    break;
  case 4:
    drawBoolArray(four, x, y);
    break;
  case 5:
    drawBoolArray(five, x, y);
    break;
  case 6:
    drawBoolArray(six, x, y);
    break;
  case 7:
    drawBoolArray(seven, x, y);
    break;
  case 8:
    drawBoolArray(eight, x, y);
    break;
  case 9:
    drawBoolArray(nine, x, y);
    break;

  default:
    break;
  }
}

void drawScore()
{
  drawNumber(scoreLeft, 8, 1);
  drawNumber(scoreRight, 21, 1);
}

void resetField()
{
  if (scoreLeft == 10)
  {
    state = 1;
  }
  else if (scoreRight == 10)
  {
    state = 1;
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
  delay(500);
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
  physics.init(ball, leftPaddle, rightPaddle, display);
  resetField();
}

void loop()
{
  // Controll execution speed so the target framerate is reached
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration)
  {
    // Serial.println(thisFrameTime - lastFrameTime);
    // Executes on every new frame
    if (state == 0)
    {
      // game in progress
      // read inputs
      readInputs();

      // calculate game state
      String gameState = physics.update(ball, leftPaddle, rightPaddle, display);
      if (gameState == "leftHit")
      {
        scoreRight += 1;
        resetField();
        Serial.println("right scored");
      }
      else if (gameState == "rightHit")
      {
        scoreLeft += 1;
        resetField();
        Serial.println("left scored");
      }
    }
    else if (state == 1)
    {
      // ready for next game
      int joyValue1 = analogRead(joyStick1);
      int joyValue2 = analogRead(joyStick2);

      if (joyValue1 > 700 && !leftReady)
      {
        leftReady = true;
        drawBoolArray(ready, 8, 16);
      }
      if (leftReady == NULL)
      {
        drawBoolArray(arrowDown, 8, 16);
        leftReady = false;
      }
      if (joyValue2 > 700 && !rightReady)
      {
        rightReady = true;
        drawBoolArray(ready, 21, 16);
      }
      if (rightReady == NULL)
      {
        drawBoolArray(arrowDown, 21, 16);
        rightReady = false;
      }
      if (leftReady && rightReady)
      {
        resetField();
        scoreLeft = 0;
        scoreRight = 0;
        leftReady = NULL;
        rightReady = NULL;
        delay(200);
        display->resetMatrix();
        state = 0;
        resetField();
      }
    }

    lastFrameTime = thisFrameTime;
  }
}
