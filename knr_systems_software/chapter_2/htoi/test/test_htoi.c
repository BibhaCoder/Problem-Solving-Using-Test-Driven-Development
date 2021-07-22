/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include "../inc/htoi.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = NULL;

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_empty_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_invalid_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "g";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_1_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 10;
	char const *input_string_number = "a";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_1_with_0x_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 10;
	char const *input_string_number = " 0xa";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_2_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 255;
	char const *input_string_number = "FF";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_3_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 2730;
	char const *input_string_number = "aaa";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_5_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 699050;
	char const *input_string_number = "AAAAA";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_8_hex_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 2863311530;
	char const *input_string_number = "AaAaAaAa";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_2_hex_woth_0X_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 255;
	char const *input_string_number = "     \t\t\t\n\n\n    0XFF";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_3_hex_woth_0X_char_string_htoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "\t\t\t\n\n\n0X\n\t\t FF";

	output_number = htoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_htoi);
	RUN_TEST(test_empty_string_htoi);
	RUN_TEST(test_invalid_string_htoi);
	RUN_TEST(test_1_hex_char_string_htoi);
	RUN_TEST(test_1_with_0x_hex_char_string_htoi);
	RUN_TEST(test_2_hex_char_string_htoi);
	RUN_TEST(test_3_hex_char_string_htoi);
	RUN_TEST(test_5_hex_char_string_htoi);
	RUN_TEST(test_8_hex_char_string_htoi);
	RUN_TEST(test_2_hex_woth_0X_char_string_htoi);
	RUN_TEST(test_3_hex_woth_0X_char_string_htoi);

	return UNITY_END();
}
