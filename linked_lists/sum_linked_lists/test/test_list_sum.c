/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/list_sum.h"
#include </Unity/src/unity.h>

static void list_sum_invalid_input_1(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;

	TEST_ASSERT_NULL(list_sum(l1, l2));
}

static void list_sum_invalid_input_2(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	int status;

	status = insert_number(1, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	TEST_ASSERT_NULL(list_sum(l1, l2));

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_invalid_input_3(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	int status;

	status = insert_number(1, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	TEST_ASSERT_NULL(list_sum(l1, l2));

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_1(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(1, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(1, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	while (l3) {
		TEST_ASSERT_EQUAL_INT(2, l3->val);
		l3 = l3->next;
	}

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_2(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(4, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(5, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	while (l3) {
		TEST_ASSERT_EQUAL_INT(9, l3->val);
		l3 = l3->next;
	}

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_3(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(8, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(1, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(7, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_4(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(5, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(5, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(1, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(0, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_5(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(3, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(5, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(1, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(2, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(7, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(4, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_6(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(3, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(5, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(7, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(2, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(8, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(0, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_7(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(3, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(5, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(8, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(8, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(3, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(4, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(1, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_8(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(8, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(4, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(8, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(7, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(1, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(2, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(7, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(8, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_9(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(9, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(1, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(0, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(9, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(9, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(9, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(8, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_10(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(7, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(1, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(6, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(5, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(9, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(2, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(9, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(1, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(2, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_11(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);
	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(3, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(2, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(2, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(5, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_12(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(2, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(3, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(3, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(3, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(3, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(3, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(5, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_sum_valid_input_13(void)
{
	struct list *l1 = NULL;
	struct list *l2 = NULL;
	struct list *l3 = NULL;
	int status;

	status = insert_number(0, &l1);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l1);

	status = insert_number(0, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(0, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);
	status = insert_number(8, &l2);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l2);

	l3 = list_sum(l1, l2);
	TEST_ASSERT_NOT_NULL(l3);
	TEST_ASSERT_EQUAL_INT(8, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(0, l3->val);
	l3 = l3->next;
	TEST_ASSERT_EQUAL_INT(0, l3->val);

	status = destroy_list(l1);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l2);
	TEST_ASSERT_EQUAL_INT(0, status);

	status = destroy_list(l3);
	TEST_ASSERT_EQUAL_INT(0, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(list_sum_invalid_input_1);
	RUN_TEST(list_sum_invalid_input_2);
	RUN_TEST(list_sum_invalid_input_3);

	RUN_TEST(list_sum_valid_input_1);
	RUN_TEST(list_sum_valid_input_2);
	RUN_TEST(list_sum_valid_input_3);
	RUN_TEST(list_sum_valid_input_4);
	RUN_TEST(list_sum_valid_input_4);
	RUN_TEST(list_sum_valid_input_5);
	RUN_TEST(list_sum_valid_input_6);
	RUN_TEST(list_sum_valid_input_7);
	RUN_TEST(list_sum_valid_input_8);
	RUN_TEST(list_sum_valid_input_9);
	RUN_TEST(list_sum_valid_input_10);
	RUN_TEST(list_sum_valid_input_11);
	RUN_TEST(list_sum_valid_input_12);
	RUN_TEST(list_sum_valid_input_13);

	UNITY_END();

	return 0;
}
