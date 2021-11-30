/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/list_sum.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int insert_number(int val, struct list **head)
{
	struct list *node;

	node = malloc(sizeof(struct list));
	if (!node)
		return -1;

	node->val = val;
	node->next = *head;
	node->prev = NULL;
	if (*head)
		(*head)->prev = node;
	*head = node;

	return 0;
}

int destroy_list(struct list *head)
{
	struct list *prev;

	while (head) {
		prev = head;
		head = head->next;	
		free(prev);
	}

	return 0;
}

static bool is_input_valid(struct list *l1, struct list *l2)
{
	if ((!l1) || (!l2))
		return false;

	return true;
}

static struct list *get_tail(struct list *head)
{
	struct list *tail = NULL;

	while (head) {
		tail = head;
		head = head->next;
	}

	return tail;
}

static void insert_last_remaining_sum(int carry, struct list *l,
				      struct list **out_list)
{
	int sum;

	sum = l->val + carry;
	if (sum == 10) {
		insert_number(0, out_list);
		insert_number(1, out_list);
	} else {
		insert_number(sum, out_list);
	}

	l = l->prev;
	while(l) {
		insert_number(l->val, out_list);
		l = l->prev;
	}
}

static struct list *add_input_lists(struct list *l1, struct list *l2)
{
	int sum;
	int carry = 0;
	struct list *l1_tail = get_tail(l1);
	struct list *l2_tail = get_tail(l2);
	struct list *l3 = NULL;

	while (l1_tail && l2_tail) {
		sum = carry + l1_tail->val + l2_tail->val;
		if (sum > 9) {
			sum = sum % 10;
			carry = 1;
		} else {
			carry = 0;
		}
		insert_number(sum, &l3);
		l1_tail = l1_tail->prev;
		l2_tail = l2_tail->prev;
	}

	if (l1_tail) {
		insert_last_remaining_sum(carry, l1_tail, &l3);
	} else if (l2_tail) {
		insert_last_remaining_sum(carry, l2_tail, &l3);
	} else {
		if (carry)
			insert_number(1, &l3);
	}

	return l3;
}

struct list *list_sum(struct list *l1, struct list *l2)
{
	if (!is_input_valid(l1, l2))
		return NULL;

	return add_input_lists(l1, l2);
}
