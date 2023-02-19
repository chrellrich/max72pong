#include <Arduino.h>
#include <unity.h>
#include <Vector.h>

Vector a;
Vector b;

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
    a = Vector();
    TEST_ASSERT_EQUAL(0, a.getX());
    TEST_ASSERT_EQUAL(0, a.getY());

    a = Vector(1, 2);
    TEST_ASSERT_EQUAL(1, a.getX());
    TEST_ASSERT_EQUAL(2, a.getY());
}

void test_vector_math(void)
{
    a = Vector(0, 1);
    TEST_ASSERT_TRUE(a == a);

    TEST_ASSERT_EQUAL(1, a.length());

    a = a.scal
    TEST_ASSERT_EQUAL(2, a.scale(2).length());

    TEST_ASSERT_EQUAL(1, a.scale(2).unitVector().length());

    // b = new Vector(1,0);
    // TEST_ASSERT_EQUAL(1, a->add(b).getX());
    // TEST_ASSERT_EQUAL(1, a->add(b)->getY());

    // Vector add(Vector vec);
    // Vector subtract(Vector b);
    // Vector scale(int n);
    // Vector unitVector();
    // int dotProduct(Vector b);
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_vector_constructor);
    RUN_TEST(test_vector_math);
}

void loop()
{
    UNITY_END();
}