/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include <stdint.h>
#include "../inc/rightrot.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_invalid_input_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3f;
	uint8_t n = 0;

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_1_invalid_input_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3f;
	uint8_t n = 65;

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_invalid_input_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3f;
	uint8_t n = 100;

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_2_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3;
	uint8_t n = 2;
	size_t expected_output = 0xc000000000000000; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_4_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3f;
	uint8_t n = 4;
	size_t expected_output = 0xf000000000000003; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_8_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x3355;
	uint8_t n = 8;
	size_t expected_output = 0x5500000000000033; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_16_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x33335555;
	uint8_t n = 16;
	size_t expected_output = 0x5555000000003333; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_1_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x1;
	uint8_t n = 1;
	size_t expected_output = 0x8000000000000000; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_3_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x7;
	uint8_t n = 3;
	size_t expected_output = 0xe000000000000000; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_5_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x1f;
	uint8_t n = 5;
	size_t expected_output = 0xf800000000000000; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_7_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x7f;
	uint8_t n = 7;
	size_t expected_output = 0xfe00000000000000; 

	status = rightrot(x, n);

	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

static void test_generic_bits_rightrot(void)
{
	ssize_t status;
	size_t x = 0x1f;
	uint8_t n;
	size_t expected_output; 

	n = 1;
	expected_output = 0x800000000000000f;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 2;
	expected_output = 0xc000000000000007;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 3;
	expected_output = 0xe000000000000003;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 4;
	expected_output = 0xf000000000000001;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 5;
	expected_output = 0xf800000000000000;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 32;
	x = 0xaaaaaaaabbbbbbbb;
	expected_output = 0xbbbbbbbbaaaaaaaa;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);

	n = 32;
	x = 0xaaaaaaabbbbbbbbb;
	expected_output = 0xbbbbbbbbaaaaaaab;
	status = rightrot(x, n);
	TEST_ASSERT_EQUAL_HEX64(expected_output, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_invalid_input_rightrot);
	RUN_TEST(test_1_invalid_input_rightrot);
	RUN_TEST(test_2_invalid_input_rightrot);

	RUN_TEST(test_2_bits_rightrot);
	RUN_TEST(test_4_bits_rightrot);
	RUN_TEST(test_8_bits_rightrot);
	RUN_TEST(test_16_bits_rightrot);

	RUN_TEST(test_1_bits_rightrot);
	RUN_TEST(test_3_bits_rightrot);
	RUN_TEST(test_5_bits_rightrot);
	RUN_TEST(test_7_bits_rightrot);
	RUN_TEST(test_generic_bits_rightrot);

	return UNITY_END();
}
