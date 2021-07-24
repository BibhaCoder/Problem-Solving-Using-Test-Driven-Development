/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdbool.h>

struct list {
	int val;
	struct list *next;
	struct list *prev;
};

bool is_list_palindrome(struct list *l);
int insert_number(int val, struct list **head);
int destroy_list(struct list *head);
