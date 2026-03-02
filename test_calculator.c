#include "unity.h"
#include "calculator.h"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    return UNITY_END();
}