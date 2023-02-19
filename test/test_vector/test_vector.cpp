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

void test_equals(void)
{
    a = Vector(0, 12);
    b = Vector(0, 12);

    TEST_ASSERT_TRUE(a == b);
}

void test_length(void)
{
    a = Vector(0, 1);
    TEST_ASSERT_EQUAL(1, a.length());
    a = Vector(0, 2);
    TEST_ASSERT_EQUAL(2, a.length());
}

void test_scale(void)
{
    a = Vector(1, 1);
    TEST_ASSERT_TRUE(a.scale(2) == Vector(2, 2));
}

void test_add(void)
{
    a = Vector(0, 1);
    b = Vector(1, 0);
    TEST_ASSERT_TRUE(Vector(1,1) == a.add(b));
}

void test_subtract(void)
{
    a = Vector(3, 3);
    b = Vector(2, 2);
    TEST_ASSERT_TRUE(Vector(1,1) == a.subtract(b));
}

void test_dotproduct(void)
{
    a = Vector(2, 2);
    b = Vector(5, 10);
    TEST_ASSERT_EQUAL(30, a.dotProduct(b));    
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!
    RUN_TEST(test_vector_constructor);
    RUN_TEST(test_equals);
    RUN_TEST(test_length);
    RUN_TEST(test_scale);
    RUN_TEST(test_unit);
    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    RUN_TEST(test_dotproduct);
}

void loop()
{
    UNITY_END();
}