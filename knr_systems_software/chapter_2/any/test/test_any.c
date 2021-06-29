#include </Unity/src/unity.h>
#include <stdint.h>
#include "../inc/any.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_invalid_input_any(void)
{
	ssize_t status;
	char const *s = NULL;
	char const *t = NULL;

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_invalid_input_any(void)
{
	ssize_t status;
	char const *s = "";
	char const *t = NULL;

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_invalid_input_any(void)
{
	ssize_t status;
	char const *s = NULL;
	char const *t = "";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_3_invalid_input_any(void)
{
	ssize_t status;
	char const *s = "";
	char const *t = "";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_4_invalid_input_any(void)
{
	ssize_t status;
	char const *s = "0123456789";
	char const *t = "abc";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_5_invalid_input_any(void)
{
	ssize_t status;
	char const *s = "3456789";
	char const *t = "0123456789";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_char_not_found_string_any(void)
{
	ssize_t status;
	char const *s = "0";
	char const *t = "1";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "012";
	char const *t = "1";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(1, status);
}

static void test_3_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "01745632";
	char const *t = "2";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(7, status);
}

static void test_3_char_not_found_string_any(void)
{
	ssize_t status;
	char const *s = "333";
	char const *t = "aaa";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_8_char_dup_not_found_string_any(void)
{
	ssize_t status;
	char const *s = "@@@###%%%";
	char const *t = "aaa";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_5_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "85476901";
	char const *t = "3333335";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(1, status);
}

static void test_8_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "123456789";
	char const *t = "9";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(8, status);
}

static void test_9_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "#1$%4)6(8";
	char const *t = "aaaaaaaa8";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(8, status);
}

static void test_9_dup_char_found_string_any(void)
{
	ssize_t status;
	char const *s = "~!@#$%^@@";
	char const *t = "aaaaaaaa@";

	status = any(s, t);

	TEST_ASSERT_EQUAL_INT(2, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_invalid_input_any);
	RUN_TEST(test_1_invalid_input_any);
	RUN_TEST(test_2_invalid_input_any);
	RUN_TEST(test_3_invalid_input_any);
	RUN_TEST(test_4_invalid_input_any);
	RUN_TEST(test_5_invalid_input_any);

	RUN_TEST(test_1_char_not_found_string_any);
	RUN_TEST(test_1_char_found_string_any);
	RUN_TEST(test_3_char_found_string_any);
	RUN_TEST(test_5_char_found_string_any);
	RUN_TEST(test_8_char_found_string_any);
	RUN_TEST(test_9_char_found_string_any);
	RUN_TEST(test_9_dup_char_found_string_any);

	RUN_TEST(test_3_char_not_found_string_any);
	RUN_TEST(test_8_char_dup_not_found_string_any);

	return UNITY_END();
}
