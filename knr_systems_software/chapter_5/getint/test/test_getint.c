/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/getint.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_0(void)
{
	char const *s = NULL;
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_input_1(void)
{
	char const *s = "";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_input_2(void)
{
	char const *s = "abc123";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_input_3(void)
{
	char const *s = "12345678901234";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_input_4(void)
{
	char const *s = "abcdefgh";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_valid_string_no_1(void)
{
	char const *s = "1";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(1, output);
}

static void test_valid_string_no_123(void)
{
	char const *s = "123";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(123, output);
}

static void test_valid_string_no_123_with_trailing_spaces(void)
{
	char const *s = "  \n\n\t\t123";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(123, output);
}

static void test_valid_string_negative_no_3(void)
{
	char const *s = "-3";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(-3, output);
}

static void test_valid_string_negative_no_355(void)
{
	char const *s = "-355";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(-355, output);
}

static void test_valid_string_positive_no_5(void)
{
	char const *s = "+5";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(5, output);
}

static void test_valid_string_positive_no_555(void)
{
	char const *s = "+55555";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(55555, output);
}

static void test_invalid_string_only_positive_char(void)
{
	char const *s = "+ ";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_string_only_negative_char(void)
{
	char const *s = "   - ";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

static void test_invalid_string_only_signs_char(void)
{
	char const *s = "++--";
	int output;

	output = getint(s);
	TEST_ASSERT_EQUAL(ERROR, output);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_0);
	RUN_TEST(test_invalid_input_1);
	RUN_TEST(test_invalid_input_2);
	RUN_TEST(test_invalid_input_3);
	RUN_TEST(test_invalid_input_4);

	RUN_TEST(test_valid_string_no_1);
	RUN_TEST(test_valid_string_no_123);

	RUN_TEST(test_valid_string_no_123_with_trailing_spaces);

	RUN_TEST(test_valid_string_negative_no_3);
	RUN_TEST(test_valid_string_negative_no_355);

	RUN_TEST(test_valid_string_positive_no_5);
	RUN_TEST(test_valid_string_positive_no_555);

	RUN_TEST(test_invalid_string_only_positive_char);
	RUN_TEST(test_invalid_string_only_negative_char);
	RUN_TEST(test_invalid_string_only_signs_char);

	UNITY_END();

	return 0;
}
