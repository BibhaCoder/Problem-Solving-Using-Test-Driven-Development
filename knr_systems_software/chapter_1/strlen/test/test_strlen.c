#include </Unity/src/unity.h>
#include "../inc/string_length.h"
#include "stdlib.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_string_length(void)
{
	size_t output_string_length;
	char const *input_line = NULL;

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 0);
}

static void test_empty_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 0);
}

static void test_1_char_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "a";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 1);
}

static void test_2_char_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "ab";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 2);
}

static void test_3_char_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "abc";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 3);
}

static void test_5_char_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "abcde";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 5);
}

static void test_25_char_string_string_length(void)
{
	size_t output_string_length;
	char const *input_line = "0123456789012345678901234";

	output_string_length = string_length(input_line);

	TEST_ASSERT_EQUAL(output_string_length, 25);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_string_length);
	RUN_TEST(test_empty_string_string_length);
	RUN_TEST(test_1_char_string_string_length);
	RUN_TEST(test_2_char_string_string_length);
	RUN_TEST(test_3_char_string_string_length);
	RUN_TEST(test_5_char_string_string_length);
	RUN_TEST(test_25_char_string_string_length);

	return UNITY_END();
}
