/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include </Unity/src/unity.h>
#include "../inc/strindex.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_invalid_1_input_strindex(void)
{
	ssize_t status;
	char const *s =  NULL;
	char const *t =  NULL;

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_2_input_strindex(void)
{
	ssize_t status;
	char const *s =  "";
	char const *t =  "";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_3_input_strindex(void)
{
	ssize_t status;
	char const *s = "0123456789012345678912345";
	char const *t = "abc";


	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_4_input_strindex(void)
{
	int status;
	char const *s =  "01234";
	char const *t =  "01234567890123456789";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_5_input_strindex(void)
{
	int status;
	char const *s =  "01234";
	char const *t =  "012345";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_1_char_found_strindex(void)
{
	int status;
	char const *s =  "0";
	char const *t =  "0";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(0, status);
}

static void test_1_char_not_found_strindex(void)
{
	int status;
	char const *s =  "0";
	char const *t =  "1";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_3_char_found_strindex(void)
{
	int status;
	char const *s =  "0123456789";
	char const *t =  "567";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(5, status);
}

static void test_8_char_found_strindex(void)
{
	int status;
	char const *s =  "0123456789";
	char const *t =  "12345678";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(1, status);
}

static void test_8_char_not_found_strindex(void)
{
	int status;
	char const *s =  "0123456789";
	char const *t =  "12345578";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_10_char_found_strindex(void)
{
	int status;
	char const *s =  "0123456789";
	char const *t =  "0123456789";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(0, status);
}

static void test_19_char_found_strindex(void)
{
	int status;
	char const *s =  "0123456789012345678";
	char const *t =  "89";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(8, status);
}

static void test_19_char_not_found_strindex(void)
{
	int status;
	char const *s =  "0123456789012345678";
	char const *t =  "abcdefghijklmnopqrs";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_20_char_found_strindex(void)
{
	int status;
	char const *s =  "0123456789abcdefghi";
	char const *t =  "i";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(18, status);
}

static void test_20_special_char_not_found_strindex(void)
{
	int status;
	char const *s =  "aaaaaaaaaaaaaaaaa";
	char const *t =  "aaa00aaa000aaa000";

	status = strindex(s, t);

	TEST_ASSERT_EQUAL(-1, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_1_input_strindex);
	RUN_TEST(test_invalid_2_input_strindex);
	RUN_TEST(test_invalid_3_input_strindex);
	RUN_TEST(test_invalid_4_input_strindex);
	RUN_TEST(test_invalid_5_input_strindex);

	RUN_TEST(test_1_char_found_strindex);
	RUN_TEST(test_1_char_not_found_strindex);
	RUN_TEST(test_3_char_found_strindex);
	RUN_TEST(test_8_char_found_strindex);
	RUN_TEST(test_8_char_not_found_strindex);

	RUN_TEST(test_10_char_found_strindex);
	RUN_TEST(test_19_char_found_strindex);

	RUN_TEST(test_19_char_not_found_strindex);
	RUN_TEST(test_20_char_found_strindex);
	RUN_TEST(test_20_special_char_not_found_strindex);

	return UNITY_END();
}
