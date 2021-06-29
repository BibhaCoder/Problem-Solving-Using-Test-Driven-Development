#include </Unity/src/unity.h>
#include "../inc/atof.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = NULL;

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_empty_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "";

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "g";

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_long_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "123456789.12345678912345";

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_1_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "12345.5bc";

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_2_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "12 x345.5bc";

	status = atof(input_string_number, &output_number);
	TEST_ASSERT_EQUAL(-1, status);
}

static void test_1_char_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = " 0.1";

	status = atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(0.1, output_number);
}

static void test_2_char_negative_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "   \n\n\n\t\t\t  -3.14";

	status = atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(-3.14, output_number);
}

static void test_3_char_negative_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "   \n\n\n\t\t\t  -31.678";

	status = atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(-31.678, output_number);
}

static void test_5_char_positive_string_atof(void)
{
	int status;
	double output_number;
	char const *input_string_number = "  +55555.55555   ";

	status = atof(input_string_number, &output_number);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_DOUBLE(55555.55555, output_number);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_atof);
	RUN_TEST(test_empty_string_atof);
	RUN_TEST(test_invalid_string_atof);
	RUN_TEST(test_invalid_long_string_atof);
	RUN_TEST(test_invalid_1_string_atof);
	RUN_TEST(test_invalid_2_string_atof);

	RUN_TEST(test_1_char_string_atof);
	RUN_TEST(test_2_char_negative_string_atof);
	RUN_TEST(test_3_char_negative_string_atof);
	RUN_TEST(test_5_char_positive_string_atof);

	return UNITY_END();
}
