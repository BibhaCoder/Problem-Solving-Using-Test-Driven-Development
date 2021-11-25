/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/conversion.h"
#include "/Unity/src/unity.h"

static void conversion_test_input_1(void)
{
	uint8_t out;
	uint32_t num1 = 0x0;
	uint32_t num2 = 0x0;
	uint32_t const expected_val = 0;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_2(void)
{
	uint8_t out;
	uint32_t num1 = 0x0;
	uint32_t num2 = 0x1;
	uint32_t const expected_val = 1;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_3(void)
{
	uint8_t out;
	uint32_t num1 = 29; /* 11101 */
	uint32_t num2 = 15; /* 01111 */
	uint32_t const expected_val = 2;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_4(void)
{
	uint8_t out;
	uint32_t num1 = 0x00000000;
	uint32_t num2 = 0xFFFFFFFF;
	uint32_t const expected_val = 32;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_5(void)
{
	uint8_t out;
	uint32_t num1 = 0x00000000;
	uint32_t num2 = 0x11111111;
	uint32_t const expected_val = 8;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_6(void)
{
	uint8_t out;
	uint32_t num1 = 0x55555555;
	uint32_t num2 = 0xaaaaaaaa;
	uint32_t const expected_val = 32;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_7(void)
{
	uint8_t out;
	uint32_t num1 = 0x3;
	uint32_t num2 = 0x2;
	uint32_t const expected_val = 1;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

static void conversion_test_input_8(void)
{
	uint8_t out;
	uint32_t num1 = 0xF;
	uint32_t num2 = 0x0;
	uint32_t const expected_val = 4;

	out = conversion(num1, num2);

	TEST_ASSERT_EQUAL_UINT32(expected_val, out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(conversion_test_input_1);
	RUN_TEST(conversion_test_input_2);
	RUN_TEST(conversion_test_input_3);
	RUN_TEST(conversion_test_input_4);
	RUN_TEST(conversion_test_input_5);
	RUN_TEST(conversion_test_input_6);
	RUN_TEST(conversion_test_input_7);
	RUN_TEST(conversion_test_input_8);

	UNITY_END();

	return 0;
}
