/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/pairwise_swap.h"
#include "/Unity/src/unity.h"

static void test_pairwise_swap_input_1(void)
{
	uint32_t out;
	uint32_t val = 0;
	uint32_t const expected_val = 0;

	out = pairwise_swap(val);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void test_pairwise_swap_input_2(void)
{
	uint32_t out;
	uint32_t val = 0x1;
	uint32_t const expected_val = 0x2;

	out = pairwise_swap(val);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void test_pairwise_swap_input_3(void)
{
	uint32_t out;
	uint32_t val = 0x2;
	uint32_t const expected_val = 0x1;

	out = pairwise_swap(val);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void test_pairwise_swap_input_4(void)
{
	uint32_t out;
	uint32_t val = 0x55555555;
	uint32_t const expected_val = 0xAAAAAAAA;

	out = pairwise_swap(val);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void test_pairwise_swap_input_5(void)
{
	uint32_t out;
	uint32_t val = 0xAAAAAAAA;
	uint32_t const expected_val = 0x55555555;

	out = pairwise_swap(val);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_pairwise_swap_input_1);
	RUN_TEST(test_pairwise_swap_input_2);
	RUN_TEST(test_pairwise_swap_input_3);
	RUN_TEST(test_pairwise_swap_input_4);
	RUN_TEST(test_pairwise_swap_input_5);

	UNITY_END();

	return 0;
}
