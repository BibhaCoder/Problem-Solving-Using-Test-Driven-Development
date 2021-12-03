/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/integer_palindrome.h"
#include "/Unity/src/unity.h"

static void is_integer_palindrome_input_0(void)
{
	TEST_ASSERT_TRUE(is_integer_palindrome(0));
}

static void is_integer_palindrome_input_1(void)
{
	TEST_ASSERT_TRUE(is_integer_palindrome(3));
	TEST_ASSERT_TRUE(is_integer_palindrome(-3));
	TEST_ASSERT_TRUE(is_integer_palindrome(9));
	TEST_ASSERT_TRUE(is_integer_palindrome(-9));
}

static void is_integer_palindrome_input_2(void)
{
	TEST_ASSERT_TRUE(is_integer_palindrome(121));
	TEST_ASSERT_FALSE(is_integer_palindrome(24));
	TEST_ASSERT_TRUE(is_integer_palindrome(123454321));
	TEST_ASSERT_TRUE(is_integer_palindrome(3333));
	TEST_ASSERT_TRUE(is_integer_palindrome(33333));
	TEST_ASSERT_TRUE(is_integer_palindrome(55555));
}

static void is_integer_palindrome_input_3(void)
{
	TEST_ASSERT_FALSE(is_integer_palindrome(12));
	TEST_ASSERT_TRUE(is_integer_palindrome(-121));
	TEST_ASSERT_TRUE(is_integer_palindrome(-456787654));
	TEST_ASSERT_FALSE(is_integer_palindrome(10));
	TEST_ASSERT_FALSE(is_integer_palindrome(2147483647));
	TEST_ASSERT_FALSE(is_integer_palindrome(-2147483648));
	
	TEST_ASSERT_FALSE(is_integer_palindrome(1000000003));
	TEST_ASSERT_FALSE(is_integer_palindrome(-1000000003));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(is_integer_palindrome_input_0);
	RUN_TEST(is_integer_palindrome_input_1);

	RUN_TEST(is_integer_palindrome_input_2);
	RUN_TEST(is_integer_palindrome_input_3);

	UNITY_END();

	return 0;
}
