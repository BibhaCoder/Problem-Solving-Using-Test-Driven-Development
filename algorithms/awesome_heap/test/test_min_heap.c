/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "/Unity/src/unity.h"
#include "../inc/min_heap.h"

static void insert_1st_item_in_min_heap(void)
{
	int status;

	status = insert(5);
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void insert_2nd_item_in_min_heap(void)
{
	int status;

	status = insert(4);
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_2_items(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(4, val);
}

static void insert_3rd_item_in_min_heap(void)
{
	int status;

	status = insert(3);
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void insert_4th_item_in_min_heap(void)
{
	int status;

	status = insert(2);
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void insert_5th_item_in_min_heap(void)
{
	int status;

	status = insert(1);
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_5_items(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(1, val);
}

static void delete_min_among_5_items(void)
{
	int status;

	status = delete();
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_4_items(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(2, val);
}

static void delete_min_among_4_items(void)
{
	int status;

	status = delete();
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_3_items(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(3, val);
}

static void delete_min_among_3_items(void)
{
	int status;

	status = delete();
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_2_items_1(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(4, val);
}

static void delete_min_among_2_items(void)
{
	int status;

	status = delete();
	TEST_ASSERT_EQUAL_INT(0, status);
	print_min_heap();
}

static void get_min_among_1_item(void)
{
	int status;
	uint32_t val = 0;

	status = get_min(&val);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_UINT32(5, val);
	print_min_heap_array();
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(insert_1st_item_in_min_heap);
	RUN_TEST(insert_2nd_item_in_min_heap);
	RUN_TEST(get_min_among_2_items);

	RUN_TEST(insert_3rd_item_in_min_heap);
	RUN_TEST(insert_4th_item_in_min_heap);
	RUN_TEST(insert_5th_item_in_min_heap);
	RUN_TEST(get_min_among_5_items);

	RUN_TEST(delete_min_among_5_items);
	RUN_TEST(get_min_among_4_items);

	RUN_TEST(delete_min_among_4_items);
	RUN_TEST(get_min_among_3_items);

	RUN_TEST(delete_min_among_3_items);
	RUN_TEST(get_min_among_2_items_1);

	RUN_TEST(delete_min_among_2_items);
	RUN_TEST(get_min_among_1_item);

	UNITY_END();

	return 0;
}
