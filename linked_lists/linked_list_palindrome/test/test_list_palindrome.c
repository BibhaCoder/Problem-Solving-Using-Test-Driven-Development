/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/list_palindrome.h"
#include </Unity/src/unity.h>

static void is_list_palindrome_invalid_input_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_FALSE(is_list_palindrome(l));
}

static void is_list_palindrome_valid_input_1(void)
{
	struct list *l = NULL;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	TEST_ASSERT_TRUE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_2(void)
{
	struct list *l = NULL;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(2, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);

	TEST_ASSERT_TRUE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_3(void)
{
	struct list *l = NULL;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);

	TEST_ASSERT_FALSE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_4(void)
{
	struct list *l = NULL;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(3, &l);
	insert_number(2, &l);
	insert_number(1, &l);

	TEST_ASSERT_TRUE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_5(void)
{
	struct list *l = NULL;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(2, &l);
	insert_number(1, &l);

	TEST_ASSERT_FALSE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_6(void)
{
	struct list *l = NULL;
	int status;

	insert_number(1, &l);
	insert_number(1, &l);
	insert_number(1, &l);
	insert_number(1, &l);
	insert_number(1, &l);
	insert_number(1, &l);

	TEST_ASSERT_TRUE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void is_list_palindrome_valid_input_7(void)
{
	struct list *l = NULL;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);
	insert_number(6, &l);
	insert_number(7, &l);
	insert_number(6, &l);
	insert_number(5, &l);
	insert_number(4, &l);
	insert_number(3, &l);
	insert_number(2, &l);
	insert_number(1, &l);

	TEST_ASSERT_TRUE(is_list_palindrome(l));

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(is_list_palindrome_invalid_input_1);

	RUN_TEST(is_list_palindrome_valid_input_1);
	RUN_TEST(is_list_palindrome_valid_input_2);
	RUN_TEST(is_list_palindrome_valid_input_3);
	RUN_TEST(is_list_palindrome_valid_input_4);
	RUN_TEST(is_list_palindrome_valid_input_4);
	RUN_TEST(is_list_palindrome_valid_input_5);
	RUN_TEST(is_list_palindrome_valid_input_6);

	UNITY_END();

	return 0;
}
