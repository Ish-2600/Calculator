#include "unity.h"
#include "calculator.h"
#include <limits.h>


// runs BEFORE each test
void setUp(void) {
    // nothing needed
}

// runs AFTER each test
void tearDown(void) {
    // nothing needed
}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); // 2 + 3 = 5
}

void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4)); // 5 + -4 = 1
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); // -3 + -4 = -7
}

// multiple checks in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0));  // 10 + 0 = 10
    TEST_ASSERT_EQUAL(0, add(0, 0));    // 0 + 0 = 0
}

void test_add_overflow(void) {
    int result = add(INT_MAX, 1);   // overflow scenario
    TEST_ASSERT_TRUE(result < 0);   // expects wrap to negative
}

void test_add_underflow(void) {
    int result = add(INT_MIN, -1);  // underflow scenario
    TEST_ASSERT_TRUE(result > 0);   // expects wrap to positive
}

//Subtract functions
void test_subtract_positive_numbers(void) {
    TEST_ASSERT_EQUAL(2, subtract(5, 3)); // 5 - 3 = 2
}

void test_subtract_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(9, subtract(5, -4)); // 5 - (-4) = 9
}

void test_subtract_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, subtract(-3, -4)); // -3 - (-4) = 1
}

void test_subtract_zero(void) {
    TEST_ASSERT_EQUAL(10, subtract(10, 0));
    TEST_ASSERT_EQUAL(-10, subtract(0, 10));
}

int main(void) {
    UNITY_BEGIN();
    //Addition
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    //Subtraction
    RUN_TEST(test_subtract_positive_numbers);
    RUN_TEST(test_subtract_positive_and_negative_numbers);
    RUN_TEST(test_subtract_negative_numbers);
    RUN_TEST(test_subtract_zero);

    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);

    return UNITY_END();
}