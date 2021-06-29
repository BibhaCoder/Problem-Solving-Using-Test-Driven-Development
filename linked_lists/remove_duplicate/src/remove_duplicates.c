#include "../inc/remove_duplicates.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int assert_no_duplicates(struct list *l)
{
	bool hash_map[MAX_INPUT_VAL] = {false, };

	if (!l)
		return -1;

	while (l) {
		if (hash_map[l->val])
			return -1;
		else
			hash_map[l->val] = true;
		l = l->next;
	}

	return 0;
}

int add_item(struct list **head, uint8_t n)
{
	struct list *l;

	if (n > MAX_INPUT_VAL)
		return -1;

	l = malloc(sizeof(struct list));
	if (!l)
		return -1;
	l->val = n;
	l->next = *head;
	*head = l;

	return 0; 
}

static void remove_item(struct list *prev)
{
	struct list *current = prev->next;

	if (!current) {
		prev->next = NULL;
		return;
	}

	prev->next = current->next;
	free(current);
}

int remove_duplicates(struct list *current)
{
	struct list *prev = current;
	bool hash_map[MAX_INPUT_VAL] = {false, };

	if (!current)
		return -1;

	while (current) {
		if (hash_map[current->val]) {
			remove_item(prev);
			current = prev->next;
		} else {
			hash_map[current->val] = true;
			prev = current;
			current = current->next;
		}
	}

	return 0;
}

int destroy_items(struct list *head)
{
	struct list *cur;

	if (!head)
		return -1;

	while (head) {
		cur = head;
		head = head->next;
		free(cur);
	}

	return 0;
}
