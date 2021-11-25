/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/string_compress.h"
#include "/Unity/src/unity.h"
#include <stdlib.h> 

static void test_string_compress_invalid_input_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_NULL(compress(s));
}

static void test_string_compress_invalid_input_2(void)
{
	char const *s = "aaaaabbbbbccccc";

	TEST_ASSERT_NULL(compress(s));
}

static void test_string_compress_valid_string_length_3(void)
{
	char *out;
	char const *s = "aaa";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a3", compress(s));
	free(out);
}

static void test_string_compress_valid_string_length_5(void)
{
	char *out;
	char const *s = "bbbbb";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("b5", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_1(void)
{
	char *out;
	char const *s = "abc";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a1b1c1", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_2(void)
{
	char *out;
	char const *s = "abcddddd";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a1b1c1d5", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_3(void)
{
	char *out;
	char const *s = "a";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a1", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_4(void)
{
	char *out;
	char const *s = "aaaaabbb";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a5b3", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_5(void)
{
	char *out;
	char const *s = "abcdefghi";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a1b1c1d1e1f1g1h1i1", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_6(void)
{
	char *out;
	char const *s = "aaaaabbbb";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a5b4", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_7(void)
{
	char *out;
	char const *s = "aaaaaaaaa";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a9", compress(s));
	free(out);
}

static void test_string_compress_valid_string_input_8(void)
{
	char *out;
	char const *s = "aaaaaaaab";

	out = compress(s);
	TEST_ASSERT_EQUAL_STRING ("a8b1", compress(s));
	free(out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_string_compress_invalid_input_1);
	RUN_TEST(test_string_compress_invalid_input_2);

	RUN_TEST(test_string_compress_valid_string_length_3);
	RUN_TEST(test_string_compress_valid_string_length_5);
	RUN_TEST(test_string_compress_valid_string_input_1);
	RUN_TEST(test_string_compress_valid_string_input_2);
	RUN_TEST(test_string_compress_valid_string_input_3);
	RUN_TEST(test_string_compress_valid_string_input_4);
	RUN_TEST(test_string_compress_valid_string_input_5);
	RUN_TEST(test_string_compress_valid_string_input_6);
	RUN_TEST(test_string_compress_valid_string_input_7);
	RUN_TEST(test_string_compress_valid_string_input_8);

	UNITY_END();

	return 0;
}
