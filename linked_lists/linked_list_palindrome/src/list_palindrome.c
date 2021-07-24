/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/list_palindrome.h"
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

static bool is_input_valid(struct list *l)
{
	if (!l)
		return false;

	return true;
}

static struct list *get_tail(struct list *head, size_t *out_num_node)
{
	struct list *tail = NULL;
	*out_num_node = 0;

	while (head) {
		tail = head;
		head = head->next;
		(*out_num_node)++;
	}

	return tail;
}

static bool __is_list_palindrome(struct list *head)
{
	size_t i;
	struct list *tail;
	size_t num_items;
	size_t check_items;

	tail = get_tail(head, &num_items);
	check_items = num_items >> 1;

	for (i = 0; i < check_items; i++) {
		if (head->val != tail->val)
			return false;
		head = head->next;
		tail = tail->prev;
	}

	return true;
}

bool is_list_palindrome(struct list *l)
{
	if (!is_input_valid(l))
		return NULL;

	return __is_list_palindrome(l);
}
