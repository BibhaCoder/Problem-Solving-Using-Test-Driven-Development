#include <stdio.h>
#include "../inc/string_find.h"
#include </Unity/src/unity.h>

static void test_invalid_input_1(void)
{
	char const *s = NULL;
	char const *t = NULL;
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_2(void)
{
	char const *s = NULL;
	char const *t = "abc";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_3(void)
{
	char const *s = "abc";
	char const *t = NULL;
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_4(void)
{
	char const *s = "";
	char const *t = "";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_5(void)
{
	char const *s = "abc";
	char const *t = "";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_6(void)
{
	char const *s = "";
	char const *t = "abc";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_7(void)
{
	char const *s = "0123456789012345";
	char const *t = "";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_invalid_input_8(void)
{
	char const *s = "";
	char const *t = "0123456789012345";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_string_find_1_char(void)
{
	char const *s = "a";
	char const *t = "a";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NOT_NULL(out);
	TEST_ASSERT_EQUAL_STRING("a", out);
}

static void test_string_find_2_chars(void)
{
	char const *s = "012345678";
	char const *t = "56";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NOT_NULL(out);
	TEST_ASSERT_EQUAL_STRING("5678", out);
}

static void test_string_find_3_chars(void)
{
	char const *s = "012345678";
	char const *t = "abc";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NULL(out);
}

static void test_string_find_5_chars(void)
{
	char const *s = "012345678";
	char const *t = "12345";
	char const *out;

	out = string_find(s, t);

	TEST_ASSERT_NOT_NULL(out);
	TEST_ASSERT_EQUAL_STRING("12345678", out);
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

	RUN_TEST(test_string_find_1_char);
	RUN_TEST(test_string_find_2_chars);
	RUN_TEST(test_string_find_3_chars);
	RUN_TEST(test_string_find_5_chars);

	UNITY_END();

	return 0;
}
