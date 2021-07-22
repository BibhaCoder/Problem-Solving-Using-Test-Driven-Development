/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/escape.h"
#include "/Unity/src/unity.h"
#include <stdlib.h>

static void test_escape_invalid_input_1(void)
{
	char const *s = NULL;
	char const *t = escape(s);

	TEST_ASSERT_NULL(t);
}

static void test_escape_valid_input_1(void)
{
	char const *s = "\n";
	char const *expected = "\\n";
	char const *t = escape(s);

	TEST_ASSERT_NOT_NULL(t);
	TEST_ASSERT_EQUAL_STRING(expected, t);
	free(t);
}

static void test_escape_valid_input_2(void)
{
	char const *s = "abc\n\t";
	char const *expected = "abc\\n\\t";
	char const *t = escape(s);

	TEST_ASSERT_NOT_NULL(t);
	TEST_ASSERT_EQUAL_STRING(expected, t);
	free(t);
}

static void test_escape_valid_input_3(void)
{
	char const *s = "\n\n\n\n\n";
	char const *expected = "\\n\\n\\n\\n\\n";
	char const *t = escape(s);

	TEST_ASSERT_NOT_NULL(t);
	TEST_ASSERT_EQUAL_STRING(expected, t);
	free(t);
}

static void test_escape_valid_input_4(void)
{
	char const *s = "abcdefgh";
	char const *expected = "abcdefgh";
	char const *t = escape(s);

	TEST_ASSERT_NOT_NULL(t);
	TEST_ASSERT_EQUAL_STRING(expected, t);
	free(t);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_escape_invalid_input_1);

	RUN_TEST(test_escape_valid_input_1);
	RUN_TEST(test_escape_valid_input_2);
	RUN_TEST(test_escape_valid_input_3);
	RUN_TEST(test_escape_valid_input_4);

	UNITY_END();

	return 0;
}
