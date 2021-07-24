/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/list_reverse.h"
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

static bool is_input_valid(struct list *l)
{
	if (!l)
		return false;

	return true;
}

static struct list *__list_reverse(struct list *head)
{
	struct list *new_head = NULL;
	struct list *p1, *p2, *p3;

	p1 = head;
	p2 = head->next;

	while (p1 && p2) {
		p3 = p2->next;
		p2->next = p1;
		p1->next = new_head;
		new_head = p1;

		p1 = p2;
		p2 = p3;
	}

	if (p1)
		new_head = p1;

	return new_head;
}

struct list *list_reverse(struct list *l)
{
	if (!is_input_valid(l))
		return NULL;

	return __list_reverse(l);
}
