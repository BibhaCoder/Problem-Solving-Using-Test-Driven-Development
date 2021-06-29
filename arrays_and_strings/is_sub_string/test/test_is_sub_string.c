#include "../inc/is_sub_string.h"
#include "/Unity/src/unity.h"

static void test_is_sub_string_invalid_param_1(void)
{
	char const *s = NULL;
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_invalid_param_2(void)
{
	char const *s = NULL;
	char const *t = "ab";

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_invalid_param_3(void)
{
	char const *s = "ab";
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_invalid_param_4(void)
{
	char const *s = "0123456789012345678901234";
	char const *t = "2340";

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_invalid_param_5(void)
{
	char const *s = NULL;
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_valid_param_1(void)
{
	char const *s = "0123456789";
	char const *t = "8901";

	TEST_ASSERT_TRUE(is_sub_string(s, t));
}

static void test_is_sub_string_valid_param_2(void)
{
	char const *s = "waterbottle";
	char const *t = "ttlewaterbo";

	TEST_ASSERT_TRUE(is_sub_string(s, t));

	s = "waterbottle";
	t = "erbottlewat";

	TEST_ASSERT_TRUE(is_sub_string(s, t));
}

static void test_is_sub_string_valid_param_3(void)
{
	char const *s = "hello_world";
	char const *t = "ldge";

	TEST_ASSERT_FALSE(is_sub_string(s, t));
}

static void test_is_sub_string_valid_param_4(void)
{
	char const *s = "12345";
	char const *t = "45123";

	TEST_ASSERT_TRUE(is_sub_string(s, t));
}

static void test_is_sub_string_valid_param_5(void)
{
	char const *s = "12345";
	char const *t = "51234";

	TEST_ASSERT_TRUE(is_sub_string(s, t));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_is_sub_string_invalid_param_1);
	RUN_TEST(test_is_sub_string_invalid_param_2);
	RUN_TEST(test_is_sub_string_invalid_param_3);
	RUN_TEST(test_is_sub_string_invalid_param_4);
	RUN_TEST(test_is_sub_string_invalid_param_5);

	RUN_TEST(test_is_sub_string_valid_param_1);
	RUN_TEST(test_is_sub_string_valid_param_2);
	RUN_TEST(test_is_sub_string_valid_param_3);
	RUN_TEST(test_is_sub_string_valid_param_4);
	RUN_TEST(test_is_sub_string_valid_param_5);

	UNITY_END();

	return 0;
}
