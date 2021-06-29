#include </Unity/src/unity.h>
#include "../inc/my_atoi.h"
#include "stdlib.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = NULL;

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_empty_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_invalid_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "12g345abc";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_1_char_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 1;
	char const *input_string_number = "1";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_2_char_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 12;
	char const *input_string_number = "12";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_3_char_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 123;
	char const *input_string_number = "123";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_1_char_negative_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "-1";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_19_char_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 1234567890123456789;
	char const *input_string_number = "1234567890123456789";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_19_char_invalid_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 0;
	char const *input_string_number = "1234567890a23456789";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

static void test_19_char_all_5_string_atoi(void)
{
	uint64_t output_number;
	uint64_t expected_output_number = 555555555555555555;
	char const *input_string_number = "555555555555555555";

	output_number = my_atoi(input_string_number);

	TEST_ASSERT_EQUAL_UINT64(expected_output_number, output_number);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_atoi);
	RUN_TEST(test_empty_string_atoi);
	RUN_TEST(test_invalid_string_atoi);
	RUN_TEST(test_1_char_string_atoi);
	RUN_TEST(test_2_char_string_atoi);
	RUN_TEST(test_3_char_string_atoi);
	RUN_TEST(test_1_char_negative_string_atoi);
	RUN_TEST(test_19_char_string_atoi);
	RUN_TEST(test_19_char_invalid_string_atoi);
	RUN_TEST(test_19_char_all_5_string_atoi);

	return UNITY_END();
}
