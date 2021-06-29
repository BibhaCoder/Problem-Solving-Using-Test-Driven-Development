#include "../inc/return_kth_to_last.h"
#include <stdlib.h>
#include <stdbool.h>

int add_item(struct list **head, uint8_t n)
{
	struct list *l;

	l = malloc(sizeof(struct list));
	if (!l)
		return -1;
	l->val = n;
	l->next = *head;
	*head = l;

	return 0; 
}

static size_t get_num_of_total_items(struct list *head)
{
	size_t num = 0;

	while (head) {
		num++;
		head = head->next;
	}

	return num;
}

static int __return_kth_to_last(struct list *head, uint32_t k)
{
	uint32_t i;
	struct list *ahead, *behind;

	ahead = behind = head;

	for (i = 0; i <= k; i++)
		ahead = ahead->next;

	while (ahead) {
		ahead = ahead->next;
		behind = behind->next;
	}

	return behind->val;
}

int return_kth_to_last(struct list *head, uint32_t k)
{
	size_t list_size;

	if (!head)
		return -1;

	list_size = get_num_of_total_items(head);
	if (k >= list_size)
		return -1;

	return __return_kth_to_last(head, k);
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
