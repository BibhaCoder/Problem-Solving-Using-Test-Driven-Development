#include "../inc/urlify.h"
#include "/Unity/src/unity.h"

static void test_3_len_urlify(void)
{
	int ret;
	char url[6] = {'a', ' ', 'c'};

	ret = urlify(url, 3);
	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_STRING("a%20c", url);
}

static void test_5_len_urlify(void)
{
	int ret;
	char url[9] = {'a', ' ', 'b', ' ', 'c'};

	ret = urlify(url, 5);
	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_STRING("a%20b%20c", url);
}

static void test_8_len_urlify(void)
{
	int ret;
	char url[15] = {'a', ' ', 'b', ' ', 'c', ' ', 'd', 'e'};

	ret = urlify(url, 8);
	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_STRING("a%20b%20c%20de", url);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_3_len_urlify);
	RUN_TEST(test_5_len_urlify);
	RUN_TEST(test_8_len_urlify);

	UNITY_END();

	return 0;
}
