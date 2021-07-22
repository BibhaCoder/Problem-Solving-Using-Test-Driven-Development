/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include "../inc/scientific_atof.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = NULL;

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_empty_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "";

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "g";

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_long_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "123456789.12345678912345";

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_1_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "12345.5bc";

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_2_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "12 x345.5bc";

	status = scientific_atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_1_char_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = " 0.1";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, output_number);
}

static void test_2_char_negative_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "   \n\n\n\t\t\t  -3.14";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(-3.14, output_number);
}

static void test_3_char_negative_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "   \n\n\n\t\t\t  -31.678";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(-31.678, output_number);
}

static void test_5_char_positive_string_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "  +55555.55555   ";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(55555.55555, output_number);
}

static void test_5_char_string_scientific_expo_neg_2_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "123.45e-2";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(1.2345, output_number);
}

static void test_5_char_string_scientific_expo_neg_5_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "123.45e-5";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(0.0012345, output_number);
}

static void test_8_char_string_scientific_expo_pos_3_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "123.45e+3";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(123450, output_number);
}

static void test_8_char_string_scientific_expo_pos_5_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "    123.45e+5    ";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(12345000, output_number);
}

static void test_15_char_string_scientific_expo_pos_3_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "\n123456789.12345e+5";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(12345678912345, output_number);
}

static void test_17_char_string_scientific_expo_pos_2_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "1234.34e+2";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(123434, output_number);
}

static void test_17_char_string_scientific_expo_pos_3_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "0.12345e+3";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(123.45, output_number);
}

static void test_2_char_string_decimal_start_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = ".12345";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(.12345, output_number);
}

static void test_3_char_string_decimal_start_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "0.123";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(0.123, output_number);
}

static void test_5_char_string_decimal_start_scientific_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = ".1E-14";

	status = scientific_atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(0.000000000000001, output_number);
	TEST_ASSERT_EQUAL_DOUBLE(1e-15, output_number);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_scientific_atof);
	RUN_TEST(test_empty_string_scientific_atof);
	RUN_TEST(test_invalid_string_scientific_atof);
	RUN_TEST(test_invalid_long_string_scientific_atof);
	RUN_TEST(test_invalid_1_string_scientific_atof);
	RUN_TEST(test_invalid_2_string_scientific_atof);

	RUN_TEST(test_1_char_string_scientific_atof);
	RUN_TEST(test_2_char_negative_string_scientific_atof);
	RUN_TEST(test_3_char_negative_string_scientific_atof);
	RUN_TEST(test_5_char_positive_string_scientific_atof);

	RUN_TEST(test_5_char_string_scientific_expo_neg_2_atof);
	RUN_TEST(test_5_char_string_scientific_expo_neg_5_atof);

	RUN_TEST(test_8_char_string_scientific_expo_pos_3_atof);
	RUN_TEST(test_8_char_string_scientific_expo_pos_5_atof);
	RUN_TEST(test_15_char_string_scientific_expo_pos_3_atof);
	RUN_TEST(test_17_char_string_scientific_expo_pos_2_atof);
	RUN_TEST(test_17_char_string_scientific_expo_pos_3_atof);

	RUN_TEST(test_2_char_string_decimal_start_atof);
	RUN_TEST(test_3_char_string_decimal_start_atof);
	RUN_TEST(test_5_char_string_decimal_start_scientific_atof);

	return UNITY_END();
}
