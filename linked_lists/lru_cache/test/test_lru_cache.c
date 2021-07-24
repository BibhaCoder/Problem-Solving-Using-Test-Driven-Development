/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/lru_cache.h"
#include "/Unity/src/unity.h"
#include <stdlib.h>

static void test_invalid_lru_cache_find_0(void)
{
	TEST_ASSERT_NULL(find_item(0));
}

static void test_invalid_lru_cache_find_1(void)
{
	TEST_ASSERT_NULL(find_item(MAX_ITEM_KEY));
}

static void test_invalid_lru_cache_find_2(void)
{
	TEST_ASSERT_NULL(find_item(MAX_ITEM_KEY + 1));
}

static void test_invalid_lru_cache_remove_0(void)
{
	TEST_ASSERT_EQUAL_INT(-1, remove_item(MAX_ITEM_KEY));
}

static void test_invalid_lru_cache_remove_1(void)
{
	TEST_ASSERT_EQUAL_INT(-1, remove_item(MAX_ITEM_KEY + 1));
}

static void test_invalid_lru_cache_remove_2(void)
{
	TEST_ASSERT_EQUAL_INT(-1, remove_item(0));
}

static void test_invalid_lru_cache_add_0(void)
{
	TEST_ASSERT_EQUAL_INT(-1, add_item(MAX_ITEM_KEY, 0));
}

static void test_invalid_lru_cache_add_1(void)
{
	TEST_ASSERT_EQUAL_INT(-1, add_item(MAX_ITEM_KEY + 1, 0));
}

static void test_invalid_lru_cache_add_2(void)
{
	TEST_ASSERT_EQUAL_INT(-1, add_item(-1, 0));
}

static void test_valid_lru_cache_add_cache_full(void)
{
	TEST_ASSERT_EQUAL_INT(0, add_item(0, 0));
	TEST_ASSERT_EQUAL_INT(0, add_item(0, 0));
	TEST_ASSERT_EQUAL_INT(0, add_item(1, 1));
	TEST_ASSERT_EQUAL_INT(0, add_item(2, 2));
	TEST_ASSERT_EQUAL_INT(0, add_item(3, 3));
	TEST_ASSERT_EQUAL_INT(0, add_item(4, 4));
	TEST_ASSERT_EQUAL_INT(0, add_item(5, 5));
	TEST_ASSERT_EQUAL_INT(0, add_item(6, 6));
	TEST_ASSERT_EQUAL_INT(0, add_item(7, 7));
	TEST_ASSERT_EQUAL_INT(0, add_item(8, 8));
	TEST_ASSERT_EQUAL_INT(0, add_item(8, 8));
	TEST_ASSERT_EQUAL_INT(0, add_item(9, 9));

	print_lru_cache();
}

static void test_valid_lru_cache_add_cache_full_and_evict(void)
{
	struct lru_cache *item;

	TEST_ASSERT_EQUAL_INT(0, add_item(10, 10));
	print_lru_cache();

	TEST_ASSERT_NOT_NULL(item = find_item(10));
	TEST_ASSERT_EQUAL_INT(10, item->value);
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(10, item->value);

	TEST_ASSERT_EQUAL_INT(0, add_item(11, 11));
	TEST_ASSERT_EQUAL_INT(0, add_item(11, 11));
	print_lru_cache();

	TEST_ASSERT_NOT_NULL(item = find_item(11));
	TEST_ASSERT_EQUAL_INT(11, item->value);
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(11, item->value);

	print_lru_cache();
}

static void test_valid_lru_update_when_cache_is_full(void)
{
	struct lru_cache *item;

	TEST_ASSERT_EQUAL_INT(0, add_item(11, 121));
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(121, item->value);

	TEST_ASSERT_EQUAL_INT(0, add_item(5, 25));
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(25, item->value);

	TEST_ASSERT_NOT_NULL(item = find_item(11));
	TEST_ASSERT_EQUAL_INT(121, item->value);
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(121, item->value);

	print_lru_cache();
}

static void test_valid_lru_cache_remove(void)
{
	struct lru_cache *item;

	TEST_ASSERT_EQUAL_INT(0, remove_item(10));
	TEST_ASSERT_EQUAL_INT(0, remove_item(9));
	TEST_ASSERT_EQUAL_INT(0, remove_item(8));
	TEST_ASSERT_EQUAL_INT(0, remove_item(7));
	TEST_ASSERT_EQUAL_INT(0, remove_item(6));
	TEST_ASSERT_EQUAL_INT(0, remove_item(5));
	TEST_ASSERT_EQUAL_INT(0, remove_item(4));
	TEST_ASSERT_EQUAL_INT(0, remove_item(3));

	print_lru_cache();

	TEST_ASSERT_EQUAL_INT(0, remove_item(2));
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(121, item->value);

	TEST_ASSERT_EQUAL_INT(0, remove_item(11));
	TEST_ASSERT_NULL(item = get_lru_cache_most_recent_hit());

	print_lru_cache();
}

static void test_valid_destroy_lru_cache(void)
{
	TEST_ASSERT_EQUAL_INT(0, destroy_lru_cache());

	print_lru_cache();
}

static void test_valid_lru_cache_add_cache_full_1(void)
{
	struct lru_cache *item;

	TEST_ASSERT_EQUAL_INT(0, add_item(0, 10));
	TEST_ASSERT_EQUAL_INT(0, add_item(0, 20));
	TEST_ASSERT_EQUAL_INT(0, add_item(1, 11));
	TEST_ASSERT_EQUAL_INT(0, add_item(2, 22));
	TEST_ASSERT_EQUAL_INT(0, add_item(3, 33));
	TEST_ASSERT_EQUAL_INT(0, add_item(4, 44));
	TEST_ASSERT_EQUAL_INT(0, add_item(5, 55));
	TEST_ASSERT_EQUAL_INT(0, add_item(6, 66));
	TEST_ASSERT_EQUAL_INT(0, add_item(7, 77));
	TEST_ASSERT_EQUAL_INT(0, add_item(8, 88));
	TEST_ASSERT_EQUAL_INT(0, add_item(8, -888));
	TEST_ASSERT_EQUAL_INT(0, add_item(9, -999));

	print_lru_cache();

	TEST_ASSERT_EQUAL_INT(0, add_item(10, 1234567));
	TEST_ASSERT_EQUAL_INT(0, add_item(11, 398467322));
	TEST_ASSERT_EQUAL_INT(0, add_item(12, -923465289));

	TEST_ASSERT_EQUAL_INT(0, add_item(5, -55555));
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(-55555, item->value);

	TEST_ASSERT_EQUAL_INT(0, add_item(1, 125125));
	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(125125, item->value);

	print_lru_cache();
}

static void test_valid_lru_cache_random_add(void)
{
	size_t i;
	size_t recent_key = 0;
	int32_t recent_val = 0;
	struct lru_cache *item;

	for (i = 0; i < 100000; i++) {
		recent_key = rand() % MAX_ITEM_KEY;
		recent_val = rand();
		TEST_ASSERT_EQUAL_INT(0, add_item(recent_key, recent_val));
	}

	print_lru_cache();

	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(recent_val, item->value);

	print_lru_cache();
}

static void test_valid_lru_cache_add_and_find_100_billion_nodes(void)
{
	size_t i;
	size_t recent_key = 0;
	int32_t recent_val = 0;
	struct lru_cache *item;

	for (i = 0; i < 100000000000; i++) {
		recent_key = i % MAX_ITEM_KEY;
		recent_val = rand();
		TEST_ASSERT_EQUAL_INT(0, add_item(recent_key, recent_val));
	}

	for (i = 0; i < 100000000000; i++) {
		recent_key = i % MAX_ITEM_KEY;
		find_item(recent_key);
	}

	print_lru_cache();

	TEST_ASSERT_NOT_NULL(item = get_lru_cache_most_recent_hit());
	TEST_ASSERT_EQUAL_INT(recent_val, item->value);

	print_lru_cache();
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_lru_cache_find_0);
	RUN_TEST(test_invalid_lru_cache_find_1);
	RUN_TEST(test_invalid_lru_cache_find_2);

	RUN_TEST(test_invalid_lru_cache_remove_0);
	RUN_TEST(test_invalid_lru_cache_remove_1);
	RUN_TEST(test_invalid_lru_cache_remove_2);

	RUN_TEST(test_invalid_lru_cache_add_0);
	RUN_TEST(test_invalid_lru_cache_add_1);
	RUN_TEST(test_invalid_lru_cache_add_2);

	RUN_TEST(test_valid_lru_cache_add_cache_full);
	RUN_TEST(test_valid_lru_cache_add_cache_full_and_evict);
	RUN_TEST(test_valid_lru_update_when_cache_is_full);
	RUN_TEST(test_valid_lru_cache_remove);

	RUN_TEST(test_valid_lru_cache_add_cache_full_1);

	RUN_TEST(test_valid_destroy_lru_cache);

	RUN_TEST(test_valid_lru_cache_random_add);

	RUN_TEST(test_valid_destroy_lru_cache);

	RUN_TEST(test_valid_lru_cache_add_and_find_100_billion_nodes);

	RUN_TEST(test_valid_destroy_lru_cache);

	UNITY_END();

	return 0;
}
