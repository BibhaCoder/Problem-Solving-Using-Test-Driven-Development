/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/binary_search.h"
#include "/Unity/src/unity.h"

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void test_binary_search_invalid_input_1(void)
{
	int32_t index;
	int32_t *array = NULL;

	index = binary_search(array, MAX_INPUT_SIZE, 12);

	TEST_ASSERT_EQUAL_INT(-1, index);
}

static void test_binary_search_invalid_input_2(void)
{
	int32_t index;
	int32_t array[] =  {-2, 2, 4, 5};

	index = binary_search(array, MAX_INPUT_SIZE + 1, 12);

	TEST_ASSERT_EQUAL_INT(-1, index);
}

static void test_binary_search_invalid_input_3(void)
{
	int32_t index;
	int32_t array[] =  {5, 2, 4, 3};

	index = binary_search(array, ARRAY_SIZE(array), 12);

	TEST_ASSERT_EQUAL_INT(-1, index);
}

static void test_binary_search_valid_input_1(void)
{
	int32_t index;
	int32_t array[] =  {-2, 2, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 12);

	TEST_ASSERT_EQUAL_INT(-1, index);
}

static void test_binary_search_valid_input_2(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 3);

	TEST_ASSERT_EQUAL_INT(2, index);
}

static void test_binary_search_valid_input_3(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 1);

	TEST_ASSERT_EQUAL_INT(0, index);
}

static void test_binary_search_valid_input_4(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5, -1};

	index = binary_search(array, ARRAY_SIZE(array), 1);

	TEST_ASSERT_EQUAL_INT(-1, index);
}

static void test_binary_search_valid_input_5(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 5);

	TEST_ASSERT_EQUAL_INT(4, index);
}

static void test_binary_search_valid_input_6(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 2);

	TEST_ASSERT_EQUAL_INT(1, index);
}

static void test_binary_search_valid_input_7(void)
{
	int32_t index;
	int32_t array[] =  {1, 2, 3, 4, 5};

	index = binary_search(array, ARRAY_SIZE(array), 4);

	TEST_ASSERT_EQUAL_INT(3, index);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_binary_search_invalid_input_1);
	RUN_TEST(test_binary_search_invalid_input_2);
	RUN_TEST(test_binary_search_invalid_input_3);

	RUN_TEST(test_binary_search_valid_input_1);
	RUN_TEST(test_binary_search_valid_input_2);
	RUN_TEST(test_binary_search_valid_input_3);
	RUN_TEST(test_binary_search_valid_input_4);
	RUN_TEST(test_binary_search_valid_input_5);
	RUN_TEST(test_binary_search_valid_input_6);
	RUN_TEST(test_binary_search_valid_input_7);

	UNITY_END();

	return 0;
}
