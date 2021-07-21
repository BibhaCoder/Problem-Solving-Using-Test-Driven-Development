/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "/Unity/src/unity.h"
#include "../inc/string_detab.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_null_pointer_string_detab(void)
{
	char const *input_string = NULL;
	char const *expected_output_string = NULL;

	expected_output_string = string_detab(input_string);

	TEST_ASSERT_NULL(expected_output_string);
}

static void test_empty_string_detab(void)
{
	char const *input_string = "";
	char const *expected_output_string = "";

	expected_output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     input_string,
				     0
				    );
}

static void test_1_char_string_detab(void)
{
	char const *input_string = "a";
	char const *expected_output_string = "a";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     1
				    );
	free(output_string);
}

static void test_1_tab_char_string_detab(void)
{
	char const *input_string = "	";
	char const *expected_output_string = "        ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     8
				    );
	free(output_string);
}

static void test_2_tabs_char_string_detab(void)
{
	char const *input_string = "		";
	char const *expected_output_string = "                ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     16
				    );
	free(output_string);
}

static void test_2_tabs_1_char_string_detab(void)
{
	char const *input_string = "	a	";
	char const *expected_output_string = "        a        ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     17
				    );
	free(output_string);
}

static void test_2_tabs_2_char_string_detab(void)
{
	char const *input_string = "a	b	";
	char const *expected_output_string = "a        b        ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     18
				    );
	free(output_string);
}

static void test_3_tabs_3_char_string_detab(void)
{
	char const *input_string = "a		b";
	char const *expected_output_string = "a                b";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     18
				    );
	free(output_string);
}

static void test_3_tabs_5_char_string_detab(void)
{
	char const *input_string = "ab	c	d	e";
	char const *expected_output_string = "ab        c        d        e";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     29
				    );
	free(output_string);
}

static void test_8_tabs_9_char_string_detab(void)
{
	char const *input_string = "abc			def			g	h	i";
	char const *expected_output_string = "abc                        def                        g        h        i";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     73
				    );
	free(output_string);
}

static void test_10_tabs_10_char_string_detab(void)
{
	char const *input_string = "a	b	c	d	e	f	g	h	i		";
	char const *expected_output_string = "a        b        c        d        e        f        g        h        i                ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     90
				    );
	free(output_string);
}

static void test_5_tabs_0_char_string_detab(void)
{
	char const *input_string = "					";
	char const *expected_output_string = "                                        ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     40
				    );
	free(output_string);
}

static void test_12_tabs_3_char_string_detab(void)
{
	char const *input_string = "												abc";
	char const *expected_output_string = "                                                                                                abc";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     99
				    );
	free(output_string);
}

static void test_input_bigger_than_max_size(void)
{
	char const *input_string = "aaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccdddddddddddddddddddddddddddeeeeeeeeeeeeeeeeeeeeeeeeeeeeeffffffffffffffffffffffffffffffffgggggggggggggggggggggghhhhhhhhhhhh";
	char const *expected_output_string = NULL;

	expected_output_string = string_detab(input_string);

	TEST_ASSERT_NULL(expected_output_string);
}

static void test_largest_string_no_tabs(void)
{
	char *input_string = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char *expected_output_string = "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     99
				    );
	free(output_string);
}

static void test_largest_string_all_tabs(void)
{
	char const *input_string = "												";
	char const *expected_output_string = "                                                                                                ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     96
				    );
	free(output_string);
}

static void test_5_tabs_5_char_string_detab(void)
{
	char const *input_string = "abcde					";
	char const *expected_output_string = "abcde                                        ";
	char *output_string;

	output_string = string_detab(input_string);

	TEST_ASSERT_EQUAL_STRING_LEN(
				     expected_output_string,
				     output_string,
				     45
				    );
	free(output_string);
}

int main(void)
{
        UNITY_BEGIN();

        RUN_TEST(test_null_pointer_string_detab);
        RUN_TEST(test_empty_string_detab);
        RUN_TEST(test_1_char_string_detab);
        RUN_TEST(test_1_tab_char_string_detab);
        RUN_TEST(test_2_tabs_char_string_detab);
        RUN_TEST(test_2_tabs_1_char_string_detab);
        RUN_TEST(test_2_tabs_2_char_string_detab);
        RUN_TEST(test_3_tabs_3_char_string_detab);
        RUN_TEST(test_3_tabs_5_char_string_detab);
        RUN_TEST(test_8_tabs_9_char_string_detab);
        RUN_TEST(test_10_tabs_10_char_string_detab);
        RUN_TEST(test_5_tabs_0_char_string_detab);
        RUN_TEST(test_12_tabs_3_char_string_detab);
        RUN_TEST(test_input_bigger_than_max_size);
        RUN_TEST(test_largest_string_no_tabs);
        RUN_TEST(test_largest_string_all_tabs);
        RUN_TEST(test_5_tabs_5_char_string_detab);

        return UNITY_END();
}
