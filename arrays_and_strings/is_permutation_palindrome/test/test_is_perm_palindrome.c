/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/is_perm_palindrome.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_FALSE(is_perm_palindrome(s));
}

static void test_invalid_input_2(void)
{
	char const *s = "abcdefghijk";

	TEST_ASSERT_FALSE(is_perm_palindrome(s));
}

static void test_invalid_input_3(void)
{
	char const *s = "abc";

	TEST_ASSERT_FALSE(is_perm_palindrome(s));
}

static void test_valid_input_2_length_string(void)
{
	char const *s = "ta";

	TEST_ASSERT_FALSE(is_perm_palindrome(s));
}

static void test_valid_input_3_length_string(void)
{
	/* palindrome : aba */
	char const *s = "aab";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_5_length_string(void)
{
	/* palindrome : acbca */
	char const *s = "aaccb";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_7_length_string(void)
{
	/* palindrome : tcaoact */
	char const *s = "tacocat";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_8_length_string(void)
{
	/* palindrome : aabbbbaa */
	char const *s = "aaaabbbb";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_9_length_string(void)
{
	char const *s = "aaabbbccc";

	TEST_ASSERT_FALSE(is_perm_palindrome(s));
}

static void test_valid_input_10_length_string(void)
{
	char const *s = "aaaaaaaaaa";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_11_length_string(void)
{
	char const *s = "aaaaaaaaaaa";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

static void test_valid_input_13_length_string(void)
{
	char const *s = "aaaaaaaaaaaab";

	TEST_ASSERT_TRUE(is_perm_palindrome(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_1);
	RUN_TEST(test_invalid_input_2);
	RUN_TEST(test_invalid_input_3);
	RUN_TEST(test_valid_input_2_length_string);
	RUN_TEST(test_valid_input_3_length_string);
	RUN_TEST(test_valid_input_5_length_string);
	RUN_TEST(test_valid_input_7_length_string);
	RUN_TEST(test_valid_input_8_length_string);
	RUN_TEST(test_valid_input_9_length_string);
	RUN_TEST(test_valid_input_10_length_string);
	RUN_TEST(test_valid_input_11_length_string);
	RUN_TEST(test_valid_input_13_length_string);

	UNITY_END();

	return 0;
}
