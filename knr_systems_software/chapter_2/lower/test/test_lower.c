#include "../inc/lower.h"
#include "/Unity/src/unity.h"

static void test_lower_for_char_A(void)
{
	TEST_ASSERT_EQUAL_INT('a', lower('A'));
}

static void test_lower_for_char_a(void)
{
	TEST_ASSERT_EQUAL_INT('a', lower('a'));
}

static void test_lower_for_char_B(void)
{
	TEST_ASSERT_EQUAL_INT('b', lower('B'));
}

static void test_lower_for_char_C(void)
{
	TEST_ASSERT_EQUAL_INT('c', lower('C'));
}

static void test_lower_for_char_d(void)
{
	TEST_ASSERT_EQUAL_INT('d', lower('d'));
}

static void test_lower_for_special_char_1(void)
{
	TEST_ASSERT_EQUAL_INT('$', lower('$'));
}

static void test_lower_for_special_char_2(void)
{
	TEST_ASSERT_EQUAL_INT('&', lower('&'));
}

static void test_lower_for_special_char_3(void)
{
	TEST_ASSERT_EQUAL_INT('@', lower('@'));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_lower_for_char_A);
	RUN_TEST(test_lower_for_char_a);
	RUN_TEST(test_lower_for_char_B);
	RUN_TEST(test_lower_for_char_C);
	RUN_TEST(test_lower_for_char_d);
	RUN_TEST(test_lower_for_special_char_1);
	RUN_TEST(test_lower_for_special_char_2);
	RUN_TEST(test_lower_for_special_char_3);

	UNITY_END();

	return 0;
}
