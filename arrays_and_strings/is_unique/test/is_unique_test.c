/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/is_unique.h"
#include "/Unity/src/unity.h"

static void test_is_unique_empty_invalid_string_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_FALSE(is_unique(s));
}

static void test_is_unique_empty_invalid_string_2(void)
{
	char const *s = "0123456789a";

	TEST_ASSERT_FALSE(is_unique(s));
}

static void test_is_unique_empty_invalid_ascii_string_2(void)
{
	char const *s = "'aAÂ";

	TEST_ASSERT_FALSE(is_unique(s));
}

static void test_is_unique_valid_string_len_3(void)
{
	char const *s = "abc";

	TEST_ASSERT_TRUE(is_unique(s));
}

static void test_is_unique_valid_string_len_5(void)
{
	char const *s = "abcde";

	TEST_ASSERT_TRUE(is_unique(s));
}

static void test_is_unique_valid_string_len_6(void)
{
	char const *s = "111111";

	TEST_ASSERT_FALSE(is_unique(s));
}

static void test_is_unique_valid_string_len_7(void)
{
	char const *s = "h8-q;'@";

	TEST_ASSERT_TRUE(is_unique(s));
}

static void test_is_unique_valid_string_len_8(void)
{
	char const *s = "12345671";

	TEST_ASSERT_FALSE(is_unique(s));
}

static void test_is_unique_valid_string_len_10(void)
{
	char const *s = "012345678";

	TEST_ASSERT_TRUE(is_unique(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_is_unique_empty_invalid_string_1);
	RUN_TEST(test_is_unique_empty_invalid_string_2);
	RUN_TEST(test_is_unique_empty_invalid_ascii_string_2);
	RUN_TEST(test_is_unique_valid_string_len_3);
	RUN_TEST(test_is_unique_valid_string_len_5);
	RUN_TEST(test_is_unique_valid_string_len_6);
	RUN_TEST(test_is_unique_valid_string_len_7);
	RUN_TEST(test_is_unique_valid_string_len_8);
	RUN_TEST(test_is_unique_valid_string_len_10);

	UNITY_END();

	return 0;
}
