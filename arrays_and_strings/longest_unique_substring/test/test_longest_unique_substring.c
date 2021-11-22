/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/longest_unique_substring.h"
#include "/Unity/src/unity.h"

static void invalid_test_longest_unique_sub_string_1(void)
{
	TEST_ASSERT_EQUAL_INT(-1, longest_unique_substring(NULL));
}

static void valid_test_longest_unique_sub_string_1(void)
{
	TEST_ASSERT_EQUAL_INT(3, longest_unique_substring("abcabcbb"));
}

static void valid_test_longest_unique_sub_string_2(void)
{
	TEST_ASSERT_EQUAL_INT(1, longest_unique_substring("bbbbb"));
}

static void valid_test_longest_unique_sub_string_3(void)
{
	TEST_ASSERT_EQUAL_INT(3, longest_unique_substring("pwwkew"));
	TEST_ASSERT_EQUAL_INT(6, longest_unique_substring("ABDEFGABEF"));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(invalid_test_longest_unique_sub_string_1);

	RUN_TEST(valid_test_longest_unique_sub_string_1);
	RUN_TEST(valid_test_longest_unique_sub_string_2);
	RUN_TEST(valid_test_longest_unique_sub_string_3);

	UNITY_END();

	return 0;
}
