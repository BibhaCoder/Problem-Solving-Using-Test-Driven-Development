/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include <stdint.h>
#include "../inc/getbit.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_invalid_input_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 4;

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_invalid_input_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 5;

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_invalid_input_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 0;

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_3_invalid_input_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 0;
	size_t n = 3;

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 0;
	size_t n = 1;
	size_t expected_output = 0x1; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_2_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 2;
	size_t expected_output = 0x3; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_3_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 3;
	size_t expected_output = 0x7; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_4_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 3;
	size_t n = 4;
	size_t expected_output = 0xf; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_5_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 7;
	size_t n = 5;
	size_t expected_output = 0xf; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_8_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 15;
	size_t n = 8;
	size_t expected_output = 0x7e; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_16_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 15;
	size_t n = 16;
	size_t expected_output = 0x7e7e; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_24_bits_getbit(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 23;
	size_t n = 24;
	size_t expected_output = 0x7e7e7e; 

	status = getbit(x, p, n);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_invalid_input_getbit);
	RUN_TEST(test_1_invalid_input_getbit);
	RUN_TEST(test_2_invalid_input_getbit);
	RUN_TEST(test_3_invalid_input_getbit);

	RUN_TEST(test_1_bits_getbit);
	RUN_TEST(test_2_bits_getbit);
	RUN_TEST(test_3_bits_getbit);
	RUN_TEST(test_4_bits_getbit);
	RUN_TEST(test_5_bits_getbit);
	RUN_TEST(test_8_bits_getbit);
	RUN_TEST(test_16_bits_getbit);
	RUN_TEST(test_24_bits_getbit);

	return UNITY_END();
}
