#include "../inc/stair.h"
#include "/Unity/src/unity.h"

static void test_valid_basic_inputs(void)
{
	TEST_ASSERT_EQUAL_UINT64(1, stair(0));
	TEST_ASSERT_EQUAL_UINT64(1, stair(1));
	TEST_ASSERT_EQUAL_UINT64(2, stair(2));
}

static void test_valid_input_3(void)
{
	TEST_ASSERT_EQUAL_UINT64(4, stair(3));
}

static void test_valid_input_4(void)
{
	TEST_ASSERT_EQUAL_UINT64(7, stair(4));
}

static void test_valid_input_12(void)
{
	TEST_ASSERT_EQUAL_UINT64(927, stair(12));
}

static void test_valid_input_25(void)
{
	TEST_ASSERT_EQUAL_UINT64(2555757, stair(25));
}

static void test_valid_input_50(void)
{
	TEST_ASSERT_EQUAL_UINT64(10562230626642, stair(50));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_valid_basic_inputs);
	RUN_TEST(test_valid_input_3);
	RUN_TEST(test_valid_input_4);
	RUN_TEST(test_valid_input_12);
	RUN_TEST(test_valid_input_25);
	RUN_TEST(test_valid_input_50);

	UNITY_END();

	return 0;
}
