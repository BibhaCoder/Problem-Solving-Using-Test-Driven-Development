#include "../inc/fib.h"
#include </Unity/src/unity.h>

static void test_fib_valid_input_0(void)
{
	uint64_t n = 0;
	uint64_t const expected_output = 0;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_1(void)
{
	uint64_t n = 1;
	uint64_t const expected_output = 1;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_2(void)
{
	uint64_t n = 2;
	uint64_t const expected_output = 1;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_3(void)
{
	uint64_t n = 3;
	uint64_t const expected_output = 2;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_4(void)
{
	uint64_t n = 4;
	uint64_t const expected_output = 3;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_5(void)
{
	uint64_t n = 5;
	uint64_t const expected_output = 5;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_6(void)
{
	uint64_t n = 6;
	uint64_t const expected_output = 8;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_7(void)
{
	uint64_t n = 7;
	uint64_t const expected_output = 13;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_8(void)
{
	uint64_t n = 8;
	uint64_t const expected_output = 21;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_15(void)
{
	uint64_t n = 15;
	uint64_t const expected_output = 610;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_17(void)
{
	uint64_t n = 17;
	uint64_t const expected_output = 1597;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_26(void)
{
	uint64_t n = 26;
	uint64_t const expected_output = 121393;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_53(void)
{
	uint64_t n = 53;
	uint64_t const expected_output = 53316291173;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

static void test_fib_valid_input_64(void)
{
	uint64_t n = 64;
	uint64_t const expected_output = 10610209857723;

	TEST_ASSERT_EQUAL_UINT64(expected_output, fib(n));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_fib_valid_input_0);
	RUN_TEST(test_fib_valid_input_1);
	RUN_TEST(test_fib_valid_input_2);
	RUN_TEST(test_fib_valid_input_3);
	RUN_TEST(test_fib_valid_input_4);
	RUN_TEST(test_fib_valid_input_5);
	RUN_TEST(test_fib_valid_input_6);
	RUN_TEST(test_fib_valid_input_7);
	RUN_TEST(test_fib_valid_input_8);
	RUN_TEST(test_fib_valid_input_15);
	RUN_TEST(test_fib_valid_input_17);
	RUN_TEST(test_fib_valid_input_26);
	RUN_TEST(test_fib_valid_input_53);
	RUN_TEST(test_fib_valid_input_64);

	UNITY_END();

	return 0;
}

