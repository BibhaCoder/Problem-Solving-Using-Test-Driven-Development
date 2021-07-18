/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/string_permutation_palindrome.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_string_perm_palindrome_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_EQUAL(false, is_string_permutation_palindrome(s));
}

static void test_invalid_input_string_perm_palindrome_2(void)
{
	char const *s = "";

	TEST_ASSERT_EQUAL(false, is_string_permutation_palindrome(s));
}

static void test_invalid_input_string_perm_palindrome_3(void)
{
	char const *s = "0000000000000000000000000011111111111111111111000000000";

	TEST_ASSERT_EQUAL(false, is_string_permutation_palindrome(s));
}

static void test_invalid_input_string_perm_palindrome_4(void)
{
	char const *s = "123";

	TEST_ASSERT_EQUAL(false, is_string_permutation_palindrome(s));
}

static void test_string_palindrome_in_4_length_string(void)
{
	char const *s = "aabb";

	TEST_ASSERT_EQUAL(true, is_string_permutation_palindrome(s));
}

static void test_string_palindrome_in_3_length_string(void)
{
	char const *s = "abc";

	TEST_ASSERT_EQUAL(false, is_string_permutation_palindrome(s));
}

static void test_string_palindrome_in_7_length_string(void)
{
	char const *s = "tactcoa";

	TEST_ASSERT_EQUAL(true, is_string_permutation_palindrome(s));
}

static void test_string_palindrome_in_11_length_string(void)
{
	char const *s = "tactcoapapa";

	TEST_ASSERT_EQUAL(true, is_string_permutation_palindrome(s));
}

static void test_string_palindrome_in_18_length_string(void)
{
	char const *s = "aaaaaaaaaaaaaaaaaa";

	TEST_ASSERT_EQUAL(true, is_string_permutation_palindrome(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_string_perm_palindrome_1);
	RUN_TEST(test_invalid_input_string_perm_palindrome_2);
	RUN_TEST(test_invalid_input_string_perm_palindrome_3);
	RUN_TEST(test_invalid_input_string_perm_palindrome_4);

	RUN_TEST(test_string_palindrome_in_4_length_string);
	RUN_TEST(test_string_palindrome_in_3_length_string);
	RUN_TEST(test_string_palindrome_in_7_length_string);
	RUN_TEST(test_string_palindrome_in_11_length_string);
	RUN_TEST(test_string_palindrome_in_18_length_string);

	UNITY_END();

	return 0;
}

