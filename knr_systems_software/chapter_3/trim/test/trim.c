#include </Unity/src/unity.h>
#include "../inc/trim.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_invalid_1_input_trim(void)
{
	int status;
	char *s =  NULL;

	status = trim(s);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_2_input_trim(void)
{
	int status;
	char *s =  "";

	status = trim(s);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_3_input_trim(void)
{
	int status;
	char *s =  "0123456789012345678912345";

	status = trim(s);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_invalid_4_input_trim(void)
{
	int status;
	char *s =  "01234567890123456789";

	status = trim(s);

	TEST_ASSERT_EQUAL(-1, status);
}

static void test_1_char_trim(void)
{
	int status;
	char s[] =  "a     ";
	char *expected_output = "a";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_3_char_trim(void)
{
	int status;
	char s[] =  "a b c   ";
	char *expected_output = "a b c";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_5_char_trim(void)
{
	int status;
	char s[] =  "a b c d e\n\t  \t  \n";
	char *expected_output = "a b c d e";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_8_char_trim(void)
{
	int status;
	char s[] =  "012345678          ";
	char *expected_output = "012345678";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_all_white_spaces_char_trim(void)
{
	int status;
	char s[] =  "0          ";
	char *expected_output = "0";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_all_spaces_1_char_trim(void)
{
	int status;
	char s[] =  "          a   ";
	char *expected_output = "          a";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_all_blanks_trim(void)
{
	int status;
	char s[] =  "             ";
	char *expected_output = "";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_all_tabs_new_lines_blanks_trim(void)
{
	int status;
	char s[] =  "     \n\n\n\n\n\t\t\t\t\t";
	char *expected_output = "";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

static void test_max_input_no_blanks_trim(void)
{
	int status;
	char s[] =  "0123456789012345678";
	char *expected_output = "0123456789012345678";

	status = trim(s);

	TEST_ASSERT_EQUAL(0, status);
	TEST_ASSERT_EQUAL_STRING(expected_output, s);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_1_input_trim);
	RUN_TEST(test_invalid_2_input_trim);
	RUN_TEST(test_invalid_3_input_trim);
	RUN_TEST(test_invalid_4_input_trim);

	RUN_TEST(test_1_char_trim);
	RUN_TEST(test_3_char_trim);
	RUN_TEST(test_5_char_trim);
	RUN_TEST(test_8_char_trim);

	RUN_TEST(test_all_white_spaces_char_trim);
	RUN_TEST(test_all_spaces_1_char_trim);
	RUN_TEST(test_all_blanks_trim);
	RUN_TEST(test_all_tabs_new_lines_blanks_trim);
	RUN_TEST(test_max_input_no_blanks_trim);

	return UNITY_END();
}
