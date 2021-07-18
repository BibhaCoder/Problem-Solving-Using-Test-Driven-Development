/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include "../inc/kth_multiple.h"
#include "/Unity/src/unity.h"

static void test_k_0(void)
{
	TEST_ASSERT_EQUAL(1, kth_multiple(0));
	reset_all_queues();
}

static void test_k_1(void)
{
	TEST_ASSERT_EQUAL(3, kth_multiple(1));
	reset_all_queues();
}

static void test_k_2(void)
{
	TEST_ASSERT_EQUAL(5, kth_multiple(2));
	reset_all_queues();
}

static void test_k_17(void)
{
	TEST_ASSERT_EQUAL(135, kth_multiple(17));
	reset_all_queues();
}

static void test_k_20(void)
{
	TEST_ASSERT_EQUAL(189, kth_multiple(20));
	reset_all_queues();
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_k_0);
	RUN_TEST(test_k_1);
	RUN_TEST(test_k_2);
	RUN_TEST(test_k_17);
	RUN_TEST(test_k_20);

	kth_multiple(100);

	UNITY_END();

	return 0;
}
