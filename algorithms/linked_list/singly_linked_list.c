/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct list {
	uint32_t val;
	struct list *next;
};
static struct list *head;

static struct list *build_list(uint32_t val)
{
	struct list *node;

	node = malloc(sizeof(struct list));
	if (!node)
		return NULL;

	node->val = val;
	node->next = head;
	head = node;

	return head;
}

static void print_list(void)
{
	struct list *node = head;

	while (node) {
		printf("[%u]-->", node->val);
		node = node->next;
	}
	printf("NULL\n");
}

static void delete_node(uint32_t val)
{
	struct list *deleted_node;
	struct list **double_pointer;

	printf("%s : %u\n", __func__, val);
	double_pointer = &head;

	while ((*double_pointer) && ((**double_pointer).val != val))
		double_pointer = &(*double_pointer)->next;

	if (*double_pointer == NULL) {
		printf("node %u did not found in list\n", val);
		return;
	}

	deleted_node = *double_pointer;
	*double_pointer = deleted_node->next;

	deleted_node->next = NULL;
	free(deleted_node);
}

static void test_list(void)
{
	uint32_t i;

	for (i = 0; i < 10; i++) {
		build_list(i);
		print_list();
	}

	delete_node(11);
	print_list();
	delete_node(12);
	print_list();

	delete_node(5);
	print_list();
	delete_node(7);
	print_list();

	for (i = 9; i >  0; i--) {
		delete_node(i);
		print_list();
	}
	delete_node(0);
	print_list();
}

int main()
{
	test_list();

	return 0;
}
