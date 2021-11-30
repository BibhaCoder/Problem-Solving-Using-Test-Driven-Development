/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/return_kth_to_last.h"
#include "/Unity/src/unity.h"

static void test_return_kth_to_last_invalid_input_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 101));
	TEST_ASSERT_NOT_NULL(l);
	TEST_ASSERT_EQUAL(-1, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_invalid_input_2(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 0));
	TEST_ASSERT_NOT_NULL(l);
	TEST_ASSERT_EQUAL(-1, return_kth_to_last(l, 2));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_NOT_NULL(l);
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_2(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(2, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_3(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(2, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(3, return_kth_to_last(l, 2));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_4(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(2, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(3, return_kth_to_last(l, 2));
	TEST_ASSERT_EQUAL(4, return_kth_to_last(l, 3));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_5(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(0, add_item(&l, 5));
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(2, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(3, return_kth_to_last(l, 2));
	TEST_ASSERT_EQUAL(4, return_kth_to_last(l, 3));
	TEST_ASSERT_EQUAL(5, return_kth_to_last(l, 4));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

static void test_return_kth_to_last_valid_input_5_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_EQUAL(0, add_item(&l, 5));
	TEST_ASSERT_EQUAL(0, add_item(&l, 4));
	TEST_ASSERT_EQUAL(0, add_item(&l, 3));
	TEST_ASSERT_EQUAL(0, add_item(&l, 2));
	TEST_ASSERT_EQUAL(0, add_item(&l, 1));
	TEST_ASSERT_EQUAL(5, return_kth_to_last(l, 0));
	TEST_ASSERT_EQUAL(4, return_kth_to_last(l, 1));
	TEST_ASSERT_EQUAL(3, return_kth_to_last(l, 2));
	TEST_ASSERT_EQUAL(2, return_kth_to_last(l, 3));
	TEST_ASSERT_EQUAL(1, return_kth_to_last(l, 4));
	TEST_ASSERT_EQUAL(0, destroy_items(l));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_return_kth_to_last_invalid_input_1);
	RUN_TEST(test_return_kth_to_last_invalid_input_2);

	RUN_TEST(test_return_kth_to_last_valid_input_1);
	RUN_TEST(test_return_kth_to_last_valid_input_2);
	RUN_TEST(test_return_kth_to_last_valid_input_3);
	RUN_TEST(test_return_kth_to_last_valid_input_4);
	RUN_TEST(test_return_kth_to_last_valid_input_5);
	RUN_TEST(test_return_kth_to_last_valid_input_5_1);

	UNITY_END();

	return 0;
}
