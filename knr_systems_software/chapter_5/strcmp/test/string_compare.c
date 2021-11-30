/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include "../inc/string_compare.h"
#include </Unity/src/unity.h>

static void test_invalid_input_1(void)
{
	char const *s = NULL;
	char const *t = NULL;
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_2(void)
{
	char const *s = NULL;
	char const *t = "abc";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_3(void)
{
	char const *s = "abc";
	char const *t = NULL;
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_4(void)
{
	char const *s = "";
	char const *t = "";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_5(void)
{
	char const *s = "abc";
	char const *t = "";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_6(void)
{
	char const *s = "";
	char const *t = "abc";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_7(void)
{
	char const *s = "0123456789012345";
	char const *t = "";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_8(void)
{
	char const *s = "";
	char const *t = "0123456789012345";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_invalid_input_9(void)
{
	char const *s = "12345";
	char const *t = "1234";
	ssize_t diff = 0; 

	TEST_ASSERT_EQUAL(-1, string_compare(s, t, &diff));
}

static void test_string_compare_1_char(void)
{
	char const *s = "a";
	char const *t = "a";
	ssize_t diff;

	TEST_ASSERT_EQUAL(0, string_compare(s, t, &diff));
	TEST_ASSERT_EQUAL(0, diff);
}

static void test_string_compare_3_char(void)
{
	char const *s = "123";
	char const *t = "1235";
	ssize_t diff;

	TEST_ASSERT_EQUAL(0, string_compare(s, t, &diff));
	TEST_ASSERT_EQUAL(0, diff);
}

static void test_string_compare_5_char(void)
{
	char const *s = "12367";
	char const *t = "12357";
	ssize_t diff;

	TEST_ASSERT_EQUAL(0, string_compare(s, t, &diff));
	TEST_ASSERT_EQUAL(1, diff);
}

static void test_string_compare_8_char(void)
{
	char const *s = "11111110";
	char const *t = "111111131";
	ssize_t diff;

	TEST_ASSERT_EQUAL(0, string_compare(s, t, &diff));
	TEST_ASSERT_EQUAL(-3, diff);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_1);
	RUN_TEST(test_invalid_input_2);
	RUN_TEST(test_invalid_input_3);
	RUN_TEST(test_invalid_input_4);
	RUN_TEST(test_invalid_input_5);
	RUN_TEST(test_invalid_input_6);
	RUN_TEST(test_invalid_input_7);
	RUN_TEST(test_invalid_input_8);
	RUN_TEST(test_invalid_input_9);

	RUN_TEST(test_string_compare_1_char);
	RUN_TEST(test_string_compare_3_char);
	RUN_TEST(test_string_compare_5_char);
	RUN_TEST(test_string_compare_8_char);

	UNITY_END();

	return 0;
}
