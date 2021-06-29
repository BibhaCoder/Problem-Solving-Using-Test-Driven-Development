#include <stdbool.h>
#include "../inc/strend.h"
#include </Unity/src/unity.h>

static void test_invalid_input_0(void)
{
	char const *s = NULL;
	char const *t = NULL;

	TEST_ASSERT_EQUAL(false, strend(s, t));
}

static void test_invalid_input_1(void)
{
	char const *s = "";
	char const *t = "";

	TEST_ASSERT_EQUAL(false, strend(s, t));
}

static void test_invalid_input_2(void)
{
	char const *s = "01234567788901234567788";
	char const *t = "abc";

	TEST_ASSERT_EQUAL(false, strend(s, t));
}

static void test_valid_strend_3_chars_found(void)
{
	char const *s = "123abc";
	char const *t = "abc";

	TEST_ASSERT_EQUAL(true, strend(s, t));
}

static void test_valid_strend_3_chars_not_found(void)
{
	char const *s = "123abc";
	char const *t = "def";

	TEST_ASSERT_EQUAL(false, strend(s, t));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_0);
	RUN_TEST(test_invalid_input_1);
	RUN_TEST(test_invalid_input_2);

	RUN_TEST(test_valid_strend_3_chars_found);
	RUN_TEST(test_valid_strend_3_chars_not_found);

	UNITY_END();

	return 0;
}
