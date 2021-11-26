/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include </Unity/src/unity.h>
#include "../inc/line_fold.h"
#include "stdlib.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_line_fold(void)
{
	char const *input_line = NULL;
	char *output_line;

	output_line = line_fold(input_line);

	TEST_ASSERT_NULL(output_line);
}

static void test_invalid_input_line_fold(void)
{
	char const *input_line = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *output_line;

	output_line = line_fold(input_line);

	TEST_ASSERT_NULL(output_line);
}

static void test_1_char_line_fold(void)
{
	char *output_line;
	char const *input_line = "a";
	char const *expected_output = "a";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 1);

	free(output_line);
}

static void test_6_char_line_fold(void)
{
	char *output_line;
	char const *input_line = "abcd e";
	char const *expected_output = "abcd\ne";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 6);

	free(output_line);
}

static void test_6_char_line_with_word_in_middle_fold(void)
{
	char *output_line;
	char const *input_line = "ab cde";
	char const *expected_output = "ab\ncde";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 6);

	free(output_line);
}

static void test_7_char_line_no_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "abcdefg";
	char const *expected_output = "abcdefg";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 7);

	free(output_line);
}

static void test_12_char_line_no_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "abcdefghijk";
	char const *expected_output = "abcdefghijk";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 12);

	free(output_line);
}

static void test_12_char_line_with_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "abcd efgh ijk";
	char const *expected_output = "abcd\nefgh\nijk";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 12);

	free(output_line);
}

static void test_17_char_line_with_mixed_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "aaa aaa aaaaaaaaa";
	char const *expected_output = "aaa\naaa\naaaaaaaaa";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 19);

	free(output_line);
}

static void test_30_char_line_with_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "aaaa bbbb cccc dddd eeee ffff";
	char const *expected_output = "aaaa\nbbbb\ncccc\ndddd\neeee\nffff";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 30);

	free(output_line);
}

static void test_32_char_line_with_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "aaaa bbbb ccccc ddddd eeee ffff";
	char const *expected_output = "aaaa\nbbbb\nccccc\nddddd\neeee\nffff";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 32);

	free(output_line);
}

static void test_40_char_line_no_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "aaaaabbbbbcccccdddddeeeeefffffggggghhhhh";
	char const *expected_output = "aaaaabbbbbcccccdddddeeeeefffffggggghhhhh";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 40);

	free(output_line);
}

static void test_readble_string_line_with_white_space_fold(void)
{
	char *output_line;
	char const *input_line = "hello world its me your friend";
	char const *expected_output = "hello\nworld\nits me\nyour\nfriend";

	output_line = line_fold(input_line);

	TEST_ASSERT_NOT_NULL(output_line);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output, output_line, 32);

	free(output_line);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_line_fold);
	RUN_TEST(test_invalid_input_line_fold);
	RUN_TEST(test_1_char_line_fold);
	RUN_TEST(test_6_char_line_fold);
	RUN_TEST(test_6_char_line_with_word_in_middle_fold);
	RUN_TEST(test_7_char_line_no_white_space_fold);
	RUN_TEST(test_12_char_line_no_white_space_fold);
	RUN_TEST(test_12_char_line_with_white_space_fold);
	RUN_TEST(test_17_char_line_with_mixed_white_space_fold);
	RUN_TEST(test_30_char_line_with_white_space_fold);
	RUN_TEST(test_32_char_line_with_white_space_fold);
	RUN_TEST(test_40_char_line_no_white_space_fold);
	RUN_TEST(test_readble_string_line_with_white_space_fold);

	return UNITY_END();
}
