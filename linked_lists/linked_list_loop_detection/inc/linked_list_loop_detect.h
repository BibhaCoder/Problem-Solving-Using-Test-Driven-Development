/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdbool.h>
#include <stddef.h>

struct list {
	int val;
	struct list *next;
};

struct list *loop_detect(struct list *head);
int insert_number(int val, struct list **head);
int destroy_list(struct list *head);
struct list *get_tail(struct list *head);
struct list *get_nth_item(struct list *head, size_t n);
