#include "../inc/one_away.h"
#include "/Unity/src/unity.h"

static void test_one_away_invalid_input_1(void)
{
	char const *s = NULL;
	char const *t = NULL;

	TEST_ASSERT_FALSE(is_one_edit_away(s, t));
}

static void test_one_away_invalid_input_2(void)
{
	char const *s = "abc";
	char const *t = "abcde";

	TEST_ASSERT_FALSE(is_one_edit_away(s, t));
}

static void test_one_away_invalid_input_3(void)
{
	char const *s = "abc";
	char const *t = "abcdefghi";

	TEST_ASSERT_FALSE(is_one_edit_away(s, t));
}

static void test_one_away_valid_equal_len_4(void)
{
	char const *s = "abcd";
	char const *t = "abcd";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_len_4(void)
{
	char const *s = "abcd";
	char const *t = "xbcd";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_1(void)
{
	char const *s = "pales";
	char const *t = "pale";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_2(void)
{
	char const *s = "pales";
	char const *t = "kales";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_3(void)
{
	char const *s = "pales";
	char const *t = "bales";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_4(void)
{
	char const *s = "pale";
	char const *t = "bae";

	TEST_ASSERT_FALSE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_5(void)
{
	char const *s = "pale";
	char const *t = "ple";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_6(void)
{
	char const *s = "apple";
	char const *t = "aple";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_7(void)
{
	char const *s = "qualcomm";
	char const *t = "qualcom";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_8(void)
{
	char const *s = "qualcomm";
	char const *t = "qualcomn";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_9(void)
{
	char const *s = "google";
	char const *t = "poogle";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_10(void)
{
	char const *s = "amazon";
	char const *t = "tamzon";

	TEST_ASSERT_FALSE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_11(void)
{
	char const *s = "netflix";
	char const *t = "tetflix";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

static void test_one_away_valid_non_equal_input_set_12(void)
{
	char const *s = "uber";
	char const *t = "ubera";

	TEST_ASSERT_TRUE(is_one_edit_away(s, t));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_one_away_invalid_input_1);
	RUN_TEST(test_one_away_invalid_input_2);
	RUN_TEST(test_one_away_invalid_input_3);

	RUN_TEST(test_one_away_valid_equal_len_4);
	RUN_TEST(test_one_away_valid_non_equal_len_4);
	RUN_TEST(test_one_away_valid_non_equal_input_set_1);
	RUN_TEST(test_one_away_valid_non_equal_input_set_2);
	RUN_TEST(test_one_away_valid_non_equal_input_set_3);
	RUN_TEST(test_one_away_valid_non_equal_input_set_4);
	RUN_TEST(test_one_away_valid_non_equal_input_set_5);
	RUN_TEST(test_one_away_valid_non_equal_input_set_6);
	RUN_TEST(test_one_away_valid_non_equal_input_set_7);
	RUN_TEST(test_one_away_valid_non_equal_input_set_8);
	RUN_TEST(test_one_away_valid_non_equal_input_set_9);
	RUN_TEST(test_one_away_valid_non_equal_input_set_10);
	RUN_TEST(test_one_away_valid_non_equal_input_set_11);
	RUN_TEST(test_one_away_valid_non_equal_input_set_12);

	UNITY_END();

	return 0;
}
