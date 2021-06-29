#include "../inc/double_to_binary.h"
#include "/Unity/src/unity.h"
#include <stdlib.h>

static void invalid_double_to_binary_input_1(void)
{
	double val = 3.14;

	TEST_ASSERT_NULL(double_to_binary(val));
}

static void invalid_double_to_binary_input_2(void)
{
	double val = 1.0;

	TEST_ASSERT_NULL(double_to_binary(val));
}

static void valid_double_to_binary_input_1(void)
{
	double val = 0.5;
	char const *expected = "1";
	char *out;

	out = double_to_binary(val);
	TEST_ASSERT_EQUAL_STRING(expected, out);
	free(out);
}

static void valid_double_to_binary_input_2(void)
{
	double val = 0.125;
	char const *expected = "001";
	char *out;

	out = double_to_binary(val);
	TEST_ASSERT_EQUAL_STRING(expected, out);
	free(out);
}

static void valid_double_to_binary_input_3(void)
{
	double val = 0.0625;
	char const *expected = "0001";
	char *out;

	out = double_to_binary(val);
	TEST_ASSERT_EQUAL_STRING(expected, out);
	free(out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(invalid_double_to_binary_input_1);
	RUN_TEST(invalid_double_to_binary_input_2);

	RUN_TEST(valid_double_to_binary_input_1);
	RUN_TEST(valid_double_to_binary_input_2);
	RUN_TEST(valid_double_to_binary_input_3);

	UNITY_END();

	return 0;
}
