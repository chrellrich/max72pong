#include <Arduino.h>
#include <unity.h>
#include <Vector.h>

Vector* a;

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_vector_constructor(void)
{
    a = new Vector();
    TEST_ASSERT_EQUAL(a->getX(), 0);
    // TEST_ASSERT_EQUAL(a->getY(), 0);
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_vector_constructor);
    
}

void loop() {
    UNITY_END();
}