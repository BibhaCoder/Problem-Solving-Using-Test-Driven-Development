#include "../inc/word_count.h"
#include "/Unity/src/unity.h"

static void test_word_count_invalid_input_1(void)
{
	char const *s = NULL;

	TEST_ASSERT_EQUAL_INT(0, word_count(s));
}

static void test_word_count_invalid_input_2(void)
{
	char const *s = "01234567788022144556u67689766897";

	TEST_ASSERT_EQUAL_INT(0, word_count(s));
}

static void test_word_count_invalid_input_3(void)
{
	char const *s = "";

	TEST_ASSERT_EQUAL_INT(0, word_count(s));
}

static void test_word_count_valid_1_word(void)
{
	char const *s = "hello";

	TEST_ASSERT_EQUAL_INT(1, word_count(s));
}

static void test_word_count_valid_2_words(void)
{
	char const *s = "hello world";

	TEST_ASSERT_EQUAL_INT(2, word_count(s));
}

static void test_word_count_valid_2_words_with_trailing_spaces(void)
{
	char const *s = "hello world      ";

	TEST_ASSERT_EQUAL_INT(2, word_count(s));
}

static void test_word_count_valid_5_words(void)
{
	char const *s = "    a b c d e  ";

	TEST_ASSERT_EQUAL_INT(5, word_count(s));
}

static void test_word_count_valid_9_words(void)
{
	char const *s = " 1 2 3 4 5 6 7 8 9";

	TEST_ASSERT_EQUAL_INT(9, word_count(s));
}


int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_word_count_invalid_input_1);
	RUN_TEST(test_word_count_invalid_input_2);
	RUN_TEST(test_word_count_invalid_input_3);

	RUN_TEST(test_word_count_valid_1_word);
	RUN_TEST(test_word_count_valid_2_words);
	RUN_TEST(test_word_count_valid_2_words_with_trailing_spaces);
	RUN_TEST(test_word_count_valid_5_words);
	RUN_TEST(test_word_count_valid_9_words);

	UNITY_END();

	return 0;
}
