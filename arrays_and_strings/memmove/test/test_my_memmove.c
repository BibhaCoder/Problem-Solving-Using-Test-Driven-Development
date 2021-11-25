/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/my_memmove.h"
#include "/Unity/src/unity.h"
#include <stdio.h> 

#define MAX_SIZE (10)

static void test_my_move_invalid_input_1(void)
{
	uint8_t *s = NULL;
	uint8_t *d = NULL;
	size_t size = 3;

	TEST_ASSERT_NULL(my_memmove(d, s, size));
}

static void test_my_move_invalid_input_2(void)
{
	uint8_t s[MAX_SIZE] = {0, 1, 2, 3, 4};
	uint8_t d[] = {5, 6, 7, 8, 9};
	size_t size = 50;

	TEST_ASSERT_NULL(my_memmove(d, s, size));
}

static void test_my_move_valid_non_overlap_input_1(void)
{
	uint8_t s[MAX_SIZE] = {0, 1, 2, 3, 4};
	uint8_t d[] = {5, 6, 7, 8, 9};
	uint8_t const e[] = {0, 1, 2, 3, 4};
	size_t size = sizeof(d);

	TEST_ASSERT_NOT_NULL(my_memmove(d, s, size));
	TEST_ASSERT_EQUAL_MEMORY(e, d, size);
}

static void test_my_move_valid_non_overlap_input_2(void)
{
	uint8_t s[MAX_SIZE] = {0, 1, 2, 3, 4, 5};
	uint8_t const e[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(s, &s[1], size));
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_non_overlap_input_3(void)
{
	uint8_t s[MAX_SIZE] = {2, 2, 2, 2, 2};
	uint8_t d[] = {1, 1, 1, 1, 1};
	uint8_t const e[] = {2, 2, 2, 2, 2};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(d, s, size));
	TEST_ASSERT_EQUAL_MEMORY(e, d, size);
}

static void print(uint8_t *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

static void test_my_move_valid_overlap_input_1(void)
{
	uint8_t s[MAX_SIZE] = {0, 1, 2, 3, 4, 5};
	uint8_t const e[] = {0, 0, 1, 2, 3};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[1], &s[0], size));
	print(&s[1], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_2(void)
{
	uint8_t s[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint8_t e[] = {1, 2, 3, 1, 2};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[3], &s[0], size));
	print(&s[3], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_3(void)
{
	uint8_t s[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint8_t const e[] = {1, 2, 1, 2, 3};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[2], &s[0], size));
	print(&s[2], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_4(void)
{
	uint8_t s[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint8_t const e[] = {1, 1, 2, 3, 4};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[1], &s[0], size));
	print(&s[1], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_5(void)
{
	uint8_t s[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint8_t const e[] = {1, 2, 3, 4, 5};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[0], &s[0], size));
	print(&s[0], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_6(void)
{
	uint8_t s[MAX_SIZE] = {5, 3, 5, 3, 5, 3, 5, 3};
	uint8_t const e[] = {5, 5, 3, 5, 3};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[1], &s[0], size));
	print(&s[0], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

static void test_my_move_valid_overlap_input_7(void)
{
	uint8_t s[MAX_SIZE] = {5, 3, 5, 3, 5, 3, 5, 3};
	uint8_t const e[] = {5, 3, 5, 3, 5};
	size_t size = sizeof(e);

	TEST_ASSERT_NOT_NULL(my_memmove(&s[2], &s[0], size));
	print(&s[0], size);
	print(&s[0], size);
	TEST_ASSERT_EQUAL_MEMORY(e, s, size);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_my_move_invalid_input_1);
	RUN_TEST(test_my_move_invalid_input_2);

	RUN_TEST(test_my_move_valid_non_overlap_input_1);
	RUN_TEST(test_my_move_valid_non_overlap_input_2);
	RUN_TEST(test_my_move_valid_non_overlap_input_3);
	RUN_TEST(test_my_move_valid_overlap_input_1);
	RUN_TEST(test_my_move_valid_overlap_input_2);
	RUN_TEST(test_my_move_valid_overlap_input_3);
	RUN_TEST(test_my_move_valid_overlap_input_4);
	RUN_TEST(test_my_move_valid_overlap_input_5);
	RUN_TEST(test_my_move_valid_overlap_input_6);
	RUN_TEST(test_my_move_valid_overlap_input_7);

	UNITY_END();

	return 0;
}
