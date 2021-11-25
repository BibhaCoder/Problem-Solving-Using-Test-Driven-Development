/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/unique_chars_in_string.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_unique_chars_in_string_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_EQUAL(false, is_string_made_of_unique_char(s));
}

static void test_invalid_input_unique_chars_in_string_2(void)
{
	char const *s = "";

	TEST_ASSERT_EQUAL(false, is_string_made_of_unique_char(s));
}

static void test_invalid_input_unique_chars_in_string_3(void)
{
	char const *s = "0000000000000000000000000011111111111111111111000000000";

	TEST_ASSERT_EQUAL(false, is_string_made_of_unique_char(s));
}

static void test_unique_chars_in_3_length_string(void)
{
	char const *s = "abc";

	TEST_ASSERT_EQUAL(true, is_string_made_of_unique_char(s));
}

static void test_non_unique_chars_in_3_length_string(void)
{
	char const *s = "abb";

	TEST_ASSERT_EQUAL(false, is_string_made_of_unique_char(s));
}

static void test_unique_chars_in_15_length_string(void)
{
	char const *s = "0123456789abcde";

	TEST_ASSERT_EQUAL(true, is_string_made_of_unique_char(s));
}

static void test_non_unique_chars_in_15_length_string(void)
{
	char const *s = "0123456789abcd0";

	TEST_ASSERT_EQUAL(false, is_string_made_of_unique_char(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_unique_chars_in_string_1);
	RUN_TEST(test_invalid_input_unique_chars_in_string_2);
	RUN_TEST(test_invalid_input_unique_chars_in_string_3);

	RUN_TEST(test_unique_chars_in_3_length_string);
	RUN_TEST(test_non_unique_chars_in_3_length_string);
	RUN_TEST(test_unique_chars_in_15_length_string);
	RUN_TEST(test_non_unique_chars_in_15_length_string);

	UNITY_END();

	return 0;
}

