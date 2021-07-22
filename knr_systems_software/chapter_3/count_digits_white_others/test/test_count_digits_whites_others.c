/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include </Unity/src/unity.h>
#include "../inc/count_digits_whites_others.h"

void setUp(void)
{

}

void tearDown(void)
{

}

static void test_null_string_pointer_count(void)
{
	ssize_t ret;
	struct digits_whites_others s = {.digits = 0,
					 .whites = 0,
					 .others = 0};
	char const *input_string = NULL;

	ret = count_digits_whites_others(input_string, &s);

	TEST_ASSERT_EQUAL_INT(-1, ret);
}

static void test_null_struct_pointer_count(void)
{
	ssize_t ret;
	char const *input_string = "012abc";

	ret = count_digits_whites_others(input_string, NULL);

	TEST_ASSERT_EQUAL_INT(-1, ret);
}

static void test_1_digit_8_others_count(void)
{
	ssize_t ret;
	struct digits_whites_others s = {0, 0, 0};
	char const *input_string = "abcdefgh0";
	struct digits_whites_others e = {.digits = 1,
					 .whites = 0,
					 .others = 8};

	ret = count_digits_whites_others(input_string, &s);

	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_MEMORY(&e, &s, sizeof(s));
}

static void test_5_digit_5_whites_5_others_count(void)
{
	ssize_t ret;
	struct digits_whites_others s = {0, 0, 0};
	char const *input_string = "a0 b1 c2 d3 e5 ";
	struct digits_whites_others e = {.digits = 5,
					 .whites = 5,
					 .others = 5};

	ret = count_digits_whites_others(input_string, &s);

	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_MEMORY(&e, &s, sizeof(s));
}

static void test_10_digit_5_whites(void)
{
	ssize_t ret;
	struct digits_whites_others s = {0, 0, 0};
	char const *input_string = "0123456789     ";
	struct digits_whites_others e = {.digits = 10,
					 .whites = 5,
					 .others = 0};

	ret = count_digits_whites_others(input_string, &s);

	TEST_ASSERT_EQUAL_INT(0, ret);
	TEST_ASSERT_EQUAL_MEMORY(&e, &s, sizeof(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_string_pointer_count);
	RUN_TEST(test_null_struct_pointer_count);

	RUN_TEST(test_1_digit_8_others_count);
	RUN_TEST(test_5_digit_5_whites_5_others_count);
	RUN_TEST(test_10_digit_5_whites);

	return UNITY_END();
}
