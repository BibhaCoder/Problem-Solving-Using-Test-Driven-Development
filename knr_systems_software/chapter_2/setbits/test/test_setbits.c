/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include </Unity/src/unity.h>
#include <stdint.h>
#include "../inc/setbits.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_invalid_input_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 4;
	size_t y = 0xff;

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_invalid_input_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 5;
	size_t y = 0xff;

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_invalid_input_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 0;
	size_t y = 0xff;

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_3_invalid_input_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 0;
	size_t n = 3;
	size_t y = 0xff;

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 0;
	size_t n = 1;
	size_t y = 0x0;
	size_t expected_output = 0x3e; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_2_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x3f;
	size_t p = 2;
	size_t n = 2;
	size_t y = 0x0;
	size_t expected_output = 0x39; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_3_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x30;
	size_t p = 2;
	size_t n = 3;
	size_t y = 0xf;
	size_t expected_output = 0x37; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_4_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x20;
	size_t p = 3;
	size_t n = 4;
	size_t y = 0xff;
	size_t expected_output = 0x2f; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_5_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 7;
	size_t n = 5;
	size_t y = 0x0;
	size_t expected_output = 0x7e7e7e06; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_8_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 15;
	size_t n = 8;
	size_t y = 0x0;
	size_t expected_output = 0x7e7e007e; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_16_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 15;
	size_t n = 16;
	size_t y = 0xffff;
	size_t expected_output = 0x7e7effff; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

static void test_24_bits_setbits(void)
{
	ssize_t status;
	size_t x = 0x7e7e7e7e;
	size_t p = 23;
	size_t n = 24;
	size_t y = 0x333333;
	size_t expected_output = 0x7e333333; 

	status = setbits(x, p, n, y);

	TEST_ASSERT_EQUAL_HEX(expected_output, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_invalid_input_setbits);
	RUN_TEST(test_1_invalid_input_setbits);
	RUN_TEST(test_2_invalid_input_setbits);
	RUN_TEST(test_3_invalid_input_setbits);

	RUN_TEST(test_1_bits_setbits);
	RUN_TEST(test_2_bits_setbits);
	RUN_TEST(test_3_bits_setbits);
	RUN_TEST(test_4_bits_setbits);
	RUN_TEST(test_5_bits_setbits);
	RUN_TEST(test_8_bits_setbits);
	RUN_TEST(test_16_bits_setbits);
	RUN_TEST(test_24_bits_setbits);

	return UNITY_END();
}
