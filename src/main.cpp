#include <Arduino.h>
#include <Display.h>
// #include <Ball.h>
// #include <Paddle.h>

long int thisFrameTime = 0;
long int lastFrameTime = 0;
int framerate = 10;
long int FrameDuration = 1000/framerate;

Display* display;

bool state = true;

void setup() {
  display = new Display();
  Serial.begin(57600);
  Serial.println("Test");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  thisFrameTime = millis();
  if (thisFrameTime >= lastFrameTime + FrameDuration) {
    Serial.println(thisFrameTime - lastFrameTime);
    display->setPixel(0,0, state);
    digitalWrite(LED_BUILTIN, (state) ? HIGH : LOW);
    state = !state;
    lastFrameTime = thisFrameTime;
  }
  
}
