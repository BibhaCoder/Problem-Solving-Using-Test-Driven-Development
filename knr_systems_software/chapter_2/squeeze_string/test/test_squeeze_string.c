#include </Unity/src/unity.h>
#include "../inc/squeeze_string.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_pointer_squeeze(void)
{
	int status;
	char *input_string = NULL;
	char const *t = " ";

	status = squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_0_length_string_squeeze(void)
{
	int status;
	char *input_string = "";
	char const *t = "";

	status = squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_char_string_squeeze(void)
{
	char const *t = " ";
	char input_string[] = "a";
	char const *expected_output_string = "a";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_2_pre_char_string_squeeze(void)
{
	char const *t = " ";
	char input_string[] = " a";
	char const *expected_output_string = "a";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_2_post_char_string_squeeze(void)
{
	char const *t = " ";
	char input_string[] = "a ";
	char const *expected_output_string = "a";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 1);
}

static void test_5_char_string_squeeze(void)
{
	char const *t = " ";
	char input_string[] = "  a  a";
	char const *expected_output_string = "aa";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 2);
}

static void test_10_char_string_squeeze(void)
{
	char const *t = " ";
	char input_string[] = "    a    a ";
	char const *expected_output_string = "aa";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 2);
}

static void test_hellow_world_string_squeeze(void)
{
	char const *t = "$h";
	char input_string[] = "$$$$$$hello$$world$$$its$$$$squeeze$$$";
	char const *expected_output_string = "elloworlditssqueeze";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 20);
}

static void test_hellow_world_spaces_string_squeeze(void)
{
	char const *t = "$";
	char input_string[] = "$$$$$$hello $$world $$$its $$$$squeeze$$$";
	char const *expected_output_string = "hello world its squeeze";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 20);
}

static void test_test_driver_development_world_string_squeeze(void)
{
	char const *t = ".#$%&*";
	char input_string[] = ".....test...%..#._driven...&._development.$._is_best**";
	char const *expected_output_string = "test_driven_development_is_best";

	squeeze_string(input_string, t);

	TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string, 30);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_squeeze);
	RUN_TEST(test_0_length_string_squeeze);
	RUN_TEST(test_1_char_string_squeeze);
	RUN_TEST(test_2_pre_char_string_squeeze);
	RUN_TEST(test_2_post_char_string_squeeze);
	RUN_TEST(test_5_char_string_squeeze);
	RUN_TEST(test_10_char_string_squeeze);
	RUN_TEST(test_hellow_world_string_squeeze);
	RUN_TEST(test_hellow_world_spaces_string_squeeze);
	RUN_TEST(test_test_driver_development_world_string_squeeze);

	return UNITY_END();
}
