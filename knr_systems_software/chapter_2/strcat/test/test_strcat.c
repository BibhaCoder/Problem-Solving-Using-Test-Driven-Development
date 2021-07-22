/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include "../inc/strcat.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_1_null_pointer_my_strcat(void)
{
	int status;
	char *s = NULL;
	char *t = NULL;

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_null_pointer_my_strcat(void)
{
	int status;
	char *s = NULL;
	char t[] = "abc";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_3_null_pointer_my_strcat(void)
{
	int status;
	char s[] = "abc";
	char *t = NULL;

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_4_invalid_string_my_strcat(void)
{
	int status;
	char s[] = "";
	char t[] = "";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_5_invalid_string_my_strcat(void)
{
	int status;
	char s[] = "";
	char t[] = "a";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_small_dest_string_my_strcat(void)
{
	int status;
	char s[] = "a ";
	char t[] = "abc";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_char_string_my_strcat(void)
{
	int status;
	char s[] = "a  ";
	char t[] = "bc";
	char const *expected_output_string = "abc";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, s, 3);
}

static void test_5_char_string_my_strcat(void)
{
	int status;
	char s[] = "abc     ";
	char t[] = "defgh";
	char const *expected_output_string = "abcdefgh";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, s, 8);
}

static void test_8_char_string_my_strcat(void)
{
	int status;
	char s[] = "        ";
	char t[] = "01234567";
	char const *expected_output_string = "01234567";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, s, 8);
}

static void test_20_char_string_my_strcat(void)
{
	int status;
	char s[] = "0 1 2 3 4 5 6 7 8 9          ";
	char t[] = "0123456789";
	char const *expected_output_string = "0 1 2 3 4 5 6 7 8 90123456789";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, s, 30);
}

static void test_39_char_string_my_strcat(void)
{
	int status;
	char s[] = "                                       ";
	char t[] = "012345678901234567890123456789012345678";
	char const *expected_output_string = "012345678901234567890123456789012345678";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, s, 39);
}

static void test_40_char_string_my_strcat(void)
{
	int status;
	char s[] = "                                      ";
	char t[] = "0123456789012345678901234567890123456789";

	status = my_strcat(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_1_null_pointer_my_strcat);
	RUN_TEST(test_2_null_pointer_my_strcat);
	RUN_TEST(test_3_null_pointer_my_strcat);
	RUN_TEST(test_4_invalid_string_my_strcat);
	RUN_TEST(test_5_invalid_string_my_strcat);
	RUN_TEST(test_small_dest_string_my_strcat);
	RUN_TEST(test_2_char_string_my_strcat);
	RUN_TEST(test_5_char_string_my_strcat);
	RUN_TEST(test_8_char_string_my_strcat);
	RUN_TEST(test_20_char_string_my_strcat);
	RUN_TEST(test_39_char_string_my_strcat);
	RUN_TEST(test_40_char_string_my_strcat);

	return UNITY_END();
}
