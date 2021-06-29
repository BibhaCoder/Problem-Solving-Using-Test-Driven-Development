#include "/Unity/src/unity.h"
#include "../inc/string_reverse.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_empty_string_reverse(void)
{
	char *input_string = "";
	char *expected_output_string = "";

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     string_reverse(input_string),
				     0
				    );
}

static void test_null_pointer_string_reverse(void)
{
	char *input_string = NULL;
	char *expected_output_string = NULL;

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     string_reverse(input_string),
				     0
				    );
}

static void test_1_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "a";
	char *expected_output_string = "a";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     1
				    );
	free(output_string);
}

static void test_2_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "ab";
	char *expected_output_string = "ba";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     2
				    );
	free(output_string);
}

static void test_3_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "abc";
	char *expected_output_string = "cba";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     3
				    );
	free(output_string);
}

static void test_4_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "abcd";
	char *expected_output_string = "dcba";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     4
				    );
	free(output_string);
}

static void test_5_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "abcde";
	char *expected_output_string = "edcba";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     5
				    );
	free(output_string);
}

static void test_arbitrary_char_string_reverse(void)
{
	char *output_string;
	char *input_string = "1234567890abcdefghijklmnopqrstuvwxyz";
	char *expected_output_string = "zyxwvutsrqponmlkjihgfedcba0987654321";

	output_string = string_reverse(input_string);
	TEST_ASSERT_NOT_NULL(output_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     36
				    );
	free(output_string);
}

int main(void)
{
        UNITY_BEGIN();

        RUN_TEST(test_null_pointer_string_reverse);
        RUN_TEST(test_empty_string_reverse);
        RUN_TEST(test_1_char_string_reverse);
        RUN_TEST(test_2_char_string_reverse);
        RUN_TEST(test_3_char_string_reverse);
        RUN_TEST(test_4_char_string_reverse);
        RUN_TEST(test_5_char_string_reverse);
        RUN_TEST(test_arbitrary_char_string_reverse);

        return UNITY_END();
}
