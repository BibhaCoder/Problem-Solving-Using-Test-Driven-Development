/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/linked_list_loop_detect.h"
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

static bool is_input_valid(struct list *head)
{
	if (!head)
		return false;

	return true;
}

static struct list *__loop_detect(struct list *head)
{
	struct list *fast, *slow;

	slow  = fast = head;
	while (fast) {
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;

		if (slow == fast)
			break;
	}

	if (!fast)
		return NULL;

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

struct list *loop_detect(struct list *head)
{
	if (!is_input_valid(head))
		return NULL;

	return __loop_detect(head);
}

struct list *get_tail(struct list *head)
{
	struct list *tail = NULL;

	if (!head)
		return NULL;

	while (head) {
		tail = head;
		head = head->next;
	}

	return tail;
}

struct list *get_nth_item(struct list *head, size_t n)
{
	if (!head)
		return NULL;
	if (!n)
		return head;

	while (n && head) {
		head = head->next;
		n--;
	}

	if (!head)
		return NULL;
	else
		return head;
}
