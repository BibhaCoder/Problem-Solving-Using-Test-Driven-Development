/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/linked_list_loop_detect.h"
#include </Unity/src/unity.h>

static void list_loop_detect_invalid_input_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_NULL(loop_detect(l));
}

static void list_loop_detect_valid_input_1_without_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	int status;

	insert_number(1, &l);

	c = loop_detect(l);
	TEST_ASSERT_NULL(c);

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_1_with_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	int status;

	insert_number(1, &l);
	/* build loop */
	l->next = l;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(l, c);

	/* remove loop */
	l->next = NULL;
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_2_without_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);

	c = loop_detect(l);
	TEST_ASSERT_NULL(c);

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_2_with_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	struct list *tail;
	struct list *collision_node;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 2);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 3);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_3_with_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	struct list *tail;
	struct list *collision_node;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);
	insert_number(6, &l);
	insert_number(7, &l);
	insert_number(8, &l);
	insert_number(9, &l);
	insert_number(10, &l);
	insert_number(11, &l);
	insert_number(12, &l);

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 5);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 9);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 2);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_3_without_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);

	c = loop_detect(l);
	TEST_ASSERT_NULL(c);

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_loop_detect_valid_input_4_with_loop(void)
{
	struct list *l = NULL;
	struct list *c;
	struct list *tail;
	struct list *collision_node;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);
	insert_number(6, &l);
	insert_number(7, &l);
	insert_number(8, &l);
	insert_number(9, &l);
	insert_number(10, &l);

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 5);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 7);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	/* build loop */
	tail = get_tail(l);
	collision_node = get_nth_item(l, 9);
	tail->next = collision_node;

	c = loop_detect(l);
	TEST_ASSERT_EQUAL_PTR(collision_node, c);

	/* remove the loop */
	tail->next = NULL;

	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(list_loop_detect_invalid_input_1);

	RUN_TEST(list_loop_detect_valid_input_1_without_loop);
	RUN_TEST(list_loop_detect_valid_input_1_with_loop);
	RUN_TEST(list_loop_detect_valid_input_2_without_loop);
	RUN_TEST(list_loop_detect_valid_input_2_with_loop);
	RUN_TEST(list_loop_detect_valid_input_3_with_loop);
	RUN_TEST(list_loop_detect_valid_input_3_without_loop);
	RUN_TEST(list_loop_detect_valid_input_4_with_loop);

	UNITY_END();

	return 0;
}
