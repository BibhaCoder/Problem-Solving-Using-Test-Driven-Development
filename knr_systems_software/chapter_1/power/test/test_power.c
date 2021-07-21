/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/power.h"
#include </Unity/src/unity.h>

static void test_power_zero(void)
{
	TEST_ASSERT_EQUAL_UINT64(1, power(2, 0));
}

static void test_power_one(void)
{
	TEST_ASSERT_EQUAL_UINT64(2, power(2, 1));
}

static void test_power_two(void)
{
	TEST_ASSERT_EQUAL_UINT64(4, power(2, 2));
}

static void test_power_three(void)
{
	TEST_ASSERT_EQUAL_UINT64(8, power(2, 3));
}

static void test_power_ten(void)
{
	TEST_ASSERT_EQUAL_UINT64(1024, power(2, 10));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_power_zero);
	RUN_TEST(test_power_one);
	RUN_TEST(test_power_two);
	RUN_TEST(test_power_three);
	RUN_TEST(test_power_ten);

	UNITY_END();

	return 0;
}
