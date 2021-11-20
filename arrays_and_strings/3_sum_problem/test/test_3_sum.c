/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/3_sum.h"
#include "/Unity/src/unity.h"
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void invalid_test_3_sum(void)
{
	TEST_ASSERT_EQUAL_INT(-1, three_sum(NULL, 0, 0));
}

static void invalid_test_3_sum_1(void)
{
	uint32_t array[] =  {1};

	TEST_ASSERT_EQUAL_INT(-1, three_sum(array, ARRAY_SIZE(array), 0));
}

static void invalid_test_3_sum_2(void)
{
	uint32_t array[] =  {5, 2, 3, 1, 21};

	/* sizeof(array) = 5 * 4 = 20 bytes > MAX_INPUT_ARRAY_SIZE */
	TEST_ASSERT_EQUAL_INT(-1, three_sum(array, sizeof(array), 0));
}

static void valid_test_3_sum_1(void)
{
	/* 1st sort the input array */
	uint32_t array[] =  {1, 2, 3, 4, 5};

	TEST_ASSERT_EQUAL_INT(1, three_sum(array, ARRAY_SIZE(array), 6));
}

static void valid_test_3_sum_2(void)
{
	/* 1st sort the input array */
	uint32_t array[] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	TEST_ASSERT_EQUAL_INT(3, three_sum(array, ARRAY_SIZE(array), 12));
}

static void valid_test_3_sum_3(void)
{
	/* 1st sort the input array */
	uint32_t array[] =  {-1, -2, -3, -4, 0, 1, 2, 3, 4, 5};

	TEST_ASSERT_EQUAL_INT(4, three_sum(array, ARRAY_SIZE(array), 0));
}

static void valid_test_3_sum_4(void)
{
	/* 1st sort the input array */
	uint32_t array[] =  {-121, -51, -37, -40, -20, 20, 40, 37, 51, 121};

	TEST_ASSERT_EQUAL_INT(3, three_sum(array, ARRAY_SIZE(array), 40));
}

static void valid_test_3_sum_5(void)
{
	/* 1st sort the input array */
	uint32_t array[] =  {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

	TEST_ASSERT_EQUAL_INT(5, three_sum(array, ARRAY_SIZE(array), 40));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(invalid_test_3_sum);
	RUN_TEST(invalid_test_3_sum_1);
	RUN_TEST(invalid_test_3_sum_2);

	RUN_TEST(valid_test_3_sum_1);
	RUN_TEST(valid_test_3_sum_2);
	RUN_TEST(valid_test_3_sum_3);
	RUN_TEST(valid_test_3_sum_4);
	RUN_TEST(valid_test_3_sum_5);

	UNITY_END();

	return 0;
}
