#include "../inc/are_all_sub_array_unique.h"
#include </Unity/src/unity.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void test_unique_sub_array_invalid_input_0(void)
{
	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(NULL, 10));
}

static void test_unique_sub_array_invalid_input_1(void)
{
	int array[] = {1, 2, 3, 4, 1, 2, 5};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, 0));
}

static void test_unique_sub_array_invalid_input_2(void)
{
	int array[] = {1, 2, 3, 4, 1, 2, 5};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, 101));
}

static void test_unique_sub_array_valid_input_0(void)
{
	int array[] = {1, 2, 3, 4, 4, 2, 5};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, 0));
}

static void test_unique_sub_array_valid_input_1(void)
{
	int array[] = {1, 2, 3, 4, 1, 2, 5};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_2(void)
{
	int array[] = {1, 2, 3, 4, -1, 2, 3, 4, -10};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_3(void)
{
	int array[] = {1, 2, 3, 4, -1, 19, 35, 3, 4, -1, 19};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_4(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, 3, 4, 5, 6, 7, 8};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_5(void)
{
	int array[] = {1, 2, 3, 4, 5};

	TEST_ASSERT_TRUE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_6(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

	TEST_ASSERT_TRUE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_7(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4, 5, 8};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_8(void)
{
	int array[] = {1, 2, 3, 4, 5, 6, -1, -2, -200, 2, 3, 4};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_9(void)
{
	int array[] = {1, 2, 3, 2, 3};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

static void test_unique_sub_array_valid_input_10(void)
{
	int array[] = {1, 2, 3, 4, 4};

	TEST_ASSERT_FALSE(are_all_sub_arrays_unique(array, ARRAY_SIZE(array)));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_unique_sub_array_invalid_input_0);
	RUN_TEST(test_unique_sub_array_invalid_input_1);
	RUN_TEST(test_unique_sub_array_invalid_input_2);

	RUN_TEST(test_unique_sub_array_valid_input_0);
	RUN_TEST(test_unique_sub_array_valid_input_1);
	RUN_TEST(test_unique_sub_array_valid_input_2);
	RUN_TEST(test_unique_sub_array_valid_input_3);
	RUN_TEST(test_unique_sub_array_valid_input_4);
	RUN_TEST(test_unique_sub_array_valid_input_5);
	RUN_TEST(test_unique_sub_array_valid_input_6);
	RUN_TEST(test_unique_sub_array_valid_input_7);
	RUN_TEST(test_unique_sub_array_valid_input_8);
	RUN_TEST(test_unique_sub_array_valid_input_9);
	RUN_TEST(test_unique_sub_array_valid_input_10);

	UNITY_END();

	return 0;
}
