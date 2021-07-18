/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/is_anagram.h"
#include "/Unity/src/unity.h"

static void test_is_anagram_empty_invalid_string_1(void)
{
	char const *s = NULL;
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

static void test_is_anagram_empty_invalid_string_2(void)
{
	char const *s = "0123456789a";
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

static void test_is_anagram_empty_invalid_string_3(void)
{
	char const *s = "'aAÃ";
	char const *t = "a'AÃ";

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

static void test_is_anagram_valid_string_len_3(void)
{
	char const *s = "abc";
	char const *t = "cba";

	TEST_ASSERT_TRUE(is_anagram(s, t));
}

static void test_is_anagram_fail_valid_string_len_5(void)
{
	char const *s = "hello";
	char const *t = "lehoh";

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

static void test_is_anagram_pass_valid_string_len_5(void)
{
	char const *s = "hello";
	char const *t = "lehol";

	TEST_ASSERT_TRUE(is_anagram(s, t));
}

static void test_is_anagram_fail_valid_string_len_8(void)
{
	char const *s = "12345678";
	char const *t = "21436789";

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

static void test_is_anagram_pass_valid_string_len_8(void)
{
	char const *s = "12345678";
	char const *t = "87654321";

	TEST_ASSERT_TRUE(is_anagram(s, t));
}

static void test_is_anagram_pass_valid_string_len_10(void)
{
	char const *s = "0123456789";
	char const *t = "9876543210";

	TEST_ASSERT_TRUE(is_anagram(s, t));
}

static void test_is_anagram_pass_valid_string_len_11(void)
{
	char const *s = "aaabbb";
	char const *t = "caabbb";

	TEST_ASSERT_FALSE(is_anagram(s, t));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_is_anagram_empty_invalid_string_1);
	RUN_TEST(test_is_anagram_empty_invalid_string_2);
	RUN_TEST(test_is_anagram_empty_invalid_string_3);

	RUN_TEST(test_is_anagram_valid_string_len_3);
	RUN_TEST(test_is_anagram_fail_valid_string_len_5);
	RUN_TEST(test_is_anagram_pass_valid_string_len_5);
	RUN_TEST(test_is_anagram_fail_valid_string_len_8);
	RUN_TEST(test_is_anagram_pass_valid_string_len_8);
	RUN_TEST(test_is_anagram_pass_valid_string_len_10);
	RUN_TEST(test_is_anagram_pass_valid_string_len_11);

	UNITY_END();

	return 0;
}
