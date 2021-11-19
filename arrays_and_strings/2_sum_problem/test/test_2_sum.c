/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/2_sum.h"
#include "/Unity/src/unity.h"
#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static void invalid_test_2_sum(void)
{
	TEST_ASSERT_EQUAL_INT(-1, two_sum(NULL, 0, 0));
}

static void invalid_test_2_sum_1(void)
{
	uint32_t array[] =  {1};

	TEST_ASSERT_EQUAL_INT(-1, two_sum(array, ARRAY_SIZE(array), 0));
}

static void invalid_test_2_sum_2(void)
{
	uint32_t array[] =  {10, 2, 3, 5, 11};

	TEST_ASSERT_EQUAL_INT(-1, two_sum(array, ARRAY_SIZE(array), 0));
}

static void invalid_test_2_sum_3(void)
{
	uint32_t array[] =  {5, 2, 3, 1, 21};

	/* sizeof(array) = 5 * 4 = 20 bytes */
	TEST_ASSERT_EQUAL_INT(-1, two_sum(array, sizeof(array), 0));
}

static void valid_test_2_sum_1(void)
{
	uint32_t array[] =  {4, 2, 3, 1, 5};

	TEST_ASSERT_EQUAL_INT(2, two_sum(array, ARRAY_SIZE(array), 5));
}

static void valid_test_2_sum_2(void)
{
	uint32_t array[] =  {10, 4, 6, 2, 3, 1, 5, 9, 8, 7};

	TEST_ASSERT_EQUAL_INT(4, two_sum(array, ARRAY_SIZE(array), 10));
}

static void valid_test_2_sum_3(void)
{
	uint32_t array[] =  {10, 4, 6, 2, 3, 1, 5, 9, 8, 7};

	TEST_ASSERT_EQUAL_INT(4, two_sum(array, ARRAY_SIZE(array), 12));
}

static void valid_test_2_sum_4(void)
{
	uint32_t array[] =  {3, 4, 4, 2, 3, 1, 5, 9, 8, 9};

	TEST_ASSERT_EQUAL_INT(2, two_sum(array, ARRAY_SIZE(array), 5));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(invalid_test_2_sum);
	RUN_TEST(invalid_test_2_sum_1);
	RUN_TEST(invalid_test_2_sum_2);
	RUN_TEST(invalid_test_2_sum_3);

	RUN_TEST(valid_test_2_sum_1);
	RUN_TEST(valid_test_2_sum_2);
	RUN_TEST(valid_test_2_sum_3);
	RUN_TEST(valid_test_2_sum_4);

	UNITY_END();

	return 0;
}
