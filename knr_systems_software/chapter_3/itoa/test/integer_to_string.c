/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include </Unity/src/unity.h>
#include "../inc/integer_to_string.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_0_number_to_string(void)
{
	int64_t n = 0;
	char const *expected = "0";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_negative_1_number_to_string(void)
{
	int64_t n = -1;
	char const *expected = "-1";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_negative_123_number_to_string(void)
{
	int64_t n = -123;
	char const *expected = "-123";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_negative_9876543210_number_to_string(void)
{
	int64_t n = -9876543210;
	char const *expected = "-9876543210";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_1_number_to_string(void)
{
	int64_t n = 1;
	char const *expected = "1";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_8_number_to_string(void)
{
	int64_t n = 8;
	char const *expected = "8";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_23_number_to_string(void)
{
	int64_t n = 23;
	char const *expected = "23";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_123_number_to_string(void)
{
	int64_t n = 123;
	char const *expected = "123";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_12345_number_to_string(void)
{
	int64_t n = 12345;
	char const *expected = "12345";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_123456_number_to_string(void)
{
	int64_t n = 123456;
	char const *expected = "123456";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_12345678_number_to_string(void)
{
	int64_t n = 12345678;
	char const *expected = "12345678";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_12345678901234_number_to_string(void)
{
	int64_t n = 12345678901234;
	char const *expected = "12345678901234";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_123456789012345_number_to_string(void)
{
	int64_t n = 123456789012345;
	char const *expected = "123456789012345";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_9485625895968937_number_to_string(void)
{
	int64_t n = 9485625895968937;
	char const *expected = "9485625895968937";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

static void test_9485625795568935_number_to_string(void)
{
	int64_t n = 9485625795568935;
	char const *expected = "9485625795568935";
	char out[MAX_SIZE] = {0,};

	integer_to_string(n, out);

	TEST_ASSERT_EQUAL_STRING(expected, out);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_0_number_to_string);
	RUN_TEST(test_1_number_to_string);
	RUN_TEST(test_8_number_to_string);

	RUN_TEST(test_23_number_to_string);
	RUN_TEST(test_123_number_to_string);
	RUN_TEST(test_12345_number_to_string);
	RUN_TEST(test_123456_number_to_string);
	RUN_TEST(test_12345678_number_to_string);

	RUN_TEST(test_12345678901234_number_to_string);
	RUN_TEST(test_123456789012345_number_to_string);
	RUN_TEST(test_9485625895968937_number_to_string);
	RUN_TEST(test_9485625795568935_number_to_string);

	RUN_TEST(test_negative_1_number_to_string);
	RUN_TEST(test_negative_123_number_to_string);
	RUN_TEST(test_negative_9876543210_number_to_string);

	return UNITY_END();
}
