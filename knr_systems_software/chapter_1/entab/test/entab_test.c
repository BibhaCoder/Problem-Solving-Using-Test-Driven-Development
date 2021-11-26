/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "/Unity/src/unity.h"
#include "../inc/string_entab.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_null_pointer_string_entab(void)
{
	char const *input_string = NULL;
	char *expected_output_string = NULL;

	expected_output_string = string_entab(input_string);

	TEST_ASSERT_NULL(expected_output_string);
}

static void test_empty_string_entab(void)
{
	char const *input_string = "";
	char const *expected_output_string = "";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     0
				    );
}

static void test_1_char_string_entab(void)
{
	char const *input_string = "a";
	char const *expected_output_string = "a";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     1
				    );
	free(output_string);
}

static void test_8_blanks_string_entab(void)
{
	char const *input_string = "        ";
	char const *expected_output_string = "\t";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     1
				    );
	free(output_string);
}

static void test_5_blanks_string_entab(void)
{
	char const *input_string = "     ";
	char const *expected_output_string = "     ";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     5
				    );
	free(output_string);
}

static void test_5_blanks_3_char_string_entab(void)
{
	char const *input_string = "     aaa";
	char const *expected_output_string = "     aaa";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     8
				    );
	free(output_string);
}

static void test_8_blanks_5_char_string_entab(void)
{
	char const *input_string = "a b c d e    ";
	char const *expected_output_string = "a b c d e    ";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     13
				    );
	free(output_string);
}

static void test_19_blanks_5_char_string_entab(void)
{
	char const *input_string = "a b c d        e        ";
	char const *expected_output_string = "a b c d\te\t";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     10
				    );
	free(output_string);
}

static void test_16_blanks_string_entab(void)
{
	char const *input_string = "                ";
	char const *expected_output_string = "\t\t";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     2
				    );
	free(output_string);
}

static void test_24_blanks_string_entab(void)
{
	char const *input_string = "                        ";
	char const *expected_output_string = "\t\t\t";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     3
				    );
	free(output_string);
}

static void test_40_blanks_string_entab(void)
{
	char const *input_string = "                                        ";
	char const *expected_output_string = "\t\t\t\t\t";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     5
				    );
	free(output_string);
}

static void test_45_blanks_string_entab(void)
{
	char const *input_string = "                                        01234";
	char const *expected_output_string = "\t\t\t\t\t01234";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     10
				    );
	free(output_string);
}

static void test_45_blanks_5_chars_string_entab(void)
{
	char const *input_string = "0        1        2        3        4             ";
	char const *expected_output_string = "0\t1\t2\t3\t4\t     ";
	char *output_string;

	output_string = string_entab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     10
				    );
	free(output_string);
}

int main(void)
{
        UNITY_BEGIN();

        RUN_TEST(test_null_pointer_string_entab);
        RUN_TEST(test_empty_string_entab);
        RUN_TEST(test_1_char_string_entab);
        RUN_TEST(test_8_blanks_string_entab);
        RUN_TEST(test_5_blanks_string_entab);
        RUN_TEST(test_5_blanks_3_char_string_entab);
        RUN_TEST(test_8_blanks_5_char_string_entab);
        RUN_TEST(test_19_blanks_5_char_string_entab);
        RUN_TEST(test_16_blanks_string_entab);
        RUN_TEST(test_24_blanks_string_entab);
        RUN_TEST(test_40_blanks_string_entab);
        RUN_TEST(test_45_blanks_string_entab);
        RUN_TEST(test_45_blanks_5_chars_string_entab);

        return UNITY_END();
}
