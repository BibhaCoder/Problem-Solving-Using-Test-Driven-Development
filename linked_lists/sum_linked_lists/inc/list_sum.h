/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdint.h>

struct list {
	int val;
	struct list *next;
	struct list *prev;
};

struct list *list_sum(struct list *l1, struct list *l2);
int insert_number(int val, struct list **head);
int destroy_list(struct list *head);
