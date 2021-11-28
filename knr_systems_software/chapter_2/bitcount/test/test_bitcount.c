/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include </Unity/src/unity.h>
#include <stdint.h>
#include "../inc/bitcount.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0;
	uint32_t expected_output = 0; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_1_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x1;
	uint32_t expected_output = 1; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_2_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x3;
	uint32_t expected_output = 2; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_3_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x7;
	uint32_t expected_output = 3; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_4_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0xf;
	uint32_t expected_output = 4; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_5_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x1f;
	uint32_t expected_output = 5; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_6_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x3f;
	uint32_t expected_output = 6; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_7_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x7f;
	uint32_t expected_output = 7; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_8_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0xff;
	uint32_t expected_output = 8; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_9_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x1ff;
	uint32_t expected_output = 9; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_10_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x3ff;
	uint32_t expected_output = 10; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_11_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x7ff;
	uint32_t expected_output = 11; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_12_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0xfff;
	uint32_t expected_output = 12; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_13_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x1fff;
	uint32_t expected_output = 13; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_14_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x3fff;
	uint32_t expected_output = 14; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_15_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0x7fff;
	uint32_t expected_output = 15; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

static void test_32_bits_bitcount(void)
{
	uint8_t out;
	uint32_t x = 0xffffffff;
	uint32_t expected_output = 32; 

	out = bitcount(x);

	TEST_ASSERT_EQUAL_UINT32(expected_output, out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_bits_bitcount);
	RUN_TEST(test_1_bits_bitcount);
	RUN_TEST(test_2_bits_bitcount);
	RUN_TEST(test_3_bits_bitcount);
	RUN_TEST(test_4_bits_bitcount);
	RUN_TEST(test_5_bits_bitcount);
	RUN_TEST(test_6_bits_bitcount);
	RUN_TEST(test_7_bits_bitcount);
	RUN_TEST(test_8_bits_bitcount);
	RUN_TEST(test_9_bits_bitcount);
	RUN_TEST(test_10_bits_bitcount);
	RUN_TEST(test_11_bits_bitcount);
	RUN_TEST(test_12_bits_bitcount);
	RUN_TEST(test_13_bits_bitcount);
	RUN_TEST(test_14_bits_bitcount);
	RUN_TEST(test_15_bits_bitcount);
	RUN_TEST(test_32_bits_bitcount);

	return UNITY_END();
}
