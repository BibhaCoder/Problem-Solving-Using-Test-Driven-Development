/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/longest_palindromic_substring.h"
#include </Unity/src/unity.h>
#include <stdlib.h>

static void test_longest_palindromic_substring_invalid_input_0(void)
{
	TEST_ASSERT_NULL(longest_palindromic_substring(NULL));
}

static void test_longest_palindromic_substring_valid_input_0(void)
{
	char *out;

	out = longest_palindromic_substring("babad");
	TEST_ASSERT_EQUAL_STRING("bab", out);
	free(out);
}

static void test_longest_palindromic_substring_valid_input_1(void)
{
	char *out;

	out = longest_palindromic_substring("cbbd");
	TEST_ASSERT_EQUAL_STRING("bb", out);
	free(out);
}

static void test_longest_palindromic_substring_valid_input_2(void)
{
	char *out;

	out = longest_palindromic_substring("ac");
	TEST_ASSERT_EQUAL_STRING("a", out);
	free(out);
}

static void test_longest_palindromic_substring_valid_input_3(void)
{
	char *out;

	out = longest_palindromic_substring("a");
	TEST_ASSERT_EQUAL_STRING("a", out);
	free(out);

	out = longest_palindromic_substring("abcdbababcd");
	TEST_ASSERT_EQUAL_STRING("babab", out);
	free(out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_longest_palindromic_substring_invalid_input_0);

	RUN_TEST(test_longest_palindromic_substring_valid_input_0);
	RUN_TEST(test_longest_palindromic_substring_valid_input_1);
	RUN_TEST(test_longest_palindromic_substring_valid_input_2);
	RUN_TEST(test_longest_palindromic_substring_valid_input_3);

	UNITY_END();

	return 0;
}
