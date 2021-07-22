/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include "../inc/squeeze.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_squeeze(void)
{
	int status;
	char *input_string = NULL;
	char squeeze_char = ' ';

	status = squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_char_string_squeeze(void)
{
	char squeeze_char = ' ';
	char input_string[] = "a";
	char const *expected_output_string = "a";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_2_pre_char_string_squeeze(void)
{
	char squeeze_char = ' ';
	char input_string[] = " a";
	char const *expected_output_string = "a";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_2_post_char_string_squeeze(void)
{
	char squeeze_char = ' ';
	char input_string[] = "a ";
	char const *expected_output_string = "a";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_5_char_string_squeeze(void)
{
	char squeeze_char = ' ';
	char input_string[] = "  a  a";
	char const *expected_output_string = "aa";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 2);
}

static void test_10_char_string_squeeze(void)
{
	char squeeze_char = ' ';
	char input_string[] = "    a    a ";
	char const *expected_output_string = "aa";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 2);
}

static void test_hellow_world_string_squeeze(void)
{
	char squeeze_char = '$';
	char input_string[] = "$$$$$$hello$$world$$$its$$$$squeeze$$$";
	char const *expected_output_string = "helloworlditssqueeze";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 20);
}

static void test_hellow_world_spaces_string_squeeze(void)
{
	char squeeze_char = '$';
	char input_string[] = "$$$$$$hello $$world $$$its $$$$squeeze$$$";
	char const *expected_output_string = "hello world its squeeze";

	squeeze(input_string, squeeze_char);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 20);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_squeeze);
	RUN_TEST(test_1_char_string_squeeze);
	RUN_TEST(test_2_pre_char_string_squeeze);
	RUN_TEST(test_2_post_char_string_squeeze);
	RUN_TEST(test_5_char_string_squeeze);
	RUN_TEST(test_10_char_string_squeeze);
	RUN_TEST(test_hellow_world_string_squeeze);
	RUN_TEST(test_hellow_world_spaces_string_squeeze);

	return UNITY_END();
}
