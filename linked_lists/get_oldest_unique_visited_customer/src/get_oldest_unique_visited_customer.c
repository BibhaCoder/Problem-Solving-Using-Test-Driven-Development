/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/get_oldest_unique_visited_customer.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * design 1: best design using hash map and linked list:
 * =====================================================
 * runtime : O(1)
 * memory: O(size of hash map + size of unique cusotmers in doubly linked list)
 *
 * customer visit: O(1)
 * customer delete: O(1)
 * get and delete oldest unique visited customer: O(1)
 *
 * desing 2: Mean heap:
 * ===================
 * runtime: O(logN)
 * memory: O(size of min heap with unique customers)
 * customer visit: O(logN)
 * customer delete: O(logN)
 * get and delete oldest unique visited customer: O(logN)
 */

struct customer {
	struct customer *next;
	struct customer *prev;
	uint32_t customer_id;
};

struct customer_hash_map {
	uint32_t customer_id;
	bool is_visited;
	struct customer *node;
};

static struct customer *head;
static struct customer *tail;
static struct customer_hash_map user_hash_map[MAX_NUM_CUSTOMERS];

static bool has_customer_visited(uint32_t id)
{
	return user_hash_map[id].is_visited;
}

static void add_customer_in_hash_map(struct customer *c)
{
	uint32_t id = c->customer_id;

	user_hash_map[id].is_visited = true;
	user_hash_map[id].customer_id = id;
	user_hash_map[id].node = c;
}

static void delete_only_node_from_hash_map(uint32_t id)
{
	/* keep the customer as still visited to avoid adding
	 * already visited custmer in user hash map
	 */
	user_hash_map[id].node = NULL;
}

static void add_at_head(struct customer *c)
{
	c->prev = NULL;
	c->next = head;
	head = tail = c;
}

static void add_at_tail(struct customer *c)
{
	c->next = NULL;
	tail->next = c;
	c->prev = tail;
	tail = c;
}

static void delete_from_head(struct customer *c)
{
	struct customer *next = c->next;

	c->prev = NULL;
	if (!next)
		head = tail = NULL;
	else
		head = next;

	free(c);
}

static void delete_from_middle(struct customer *c)
{
	struct customer *prev = c->prev;
	struct customer *next = c->next;

	prev->next = next;
	if (next)
		next->prev = prev;
	else
		tail = prev;

	free(c);
}

static void delete_from_list(struct customer *c)
{
	if (!c)
		return;

	delete_only_node_from_hash_map(c->customer_id);

	if (head == c)
		delete_from_head(c);
	else
		delete_from_middle(c);
}

static int add_customer(uint32_t id)
{
	struct customer *c = malloc(sizeof(struct customer));
	if (!c) {
		printf("no memory\n");
		return -1;
	}

	c->customer_id = id;
	if (!head)
		add_at_head(c);
	else
		add_at_tail(c);

	add_customer_in_hash_map(c);

	return 0;
}

static int first_customer(void)
{
	if (!head)
		return -1;

	return head->customer_id;
}

static void delete_duplicate_customer(uint32_t id)
{
	delete_from_list(user_hash_map[id].node);
}

int visit_service(uint32_t id)
{
	if (id >= MAX_NUM_CUSTOMERS)
		return -1;

	if (!has_customer_visited(id)) {
		if (add_customer(id))
			return -1;
	} else {
		delete_duplicate_customer(id);
	}

	return 0;
}

int get_oldest_unique_visited_customer(void)
{
	if (!head)
		return -1;

	return first_customer();
}

static void reset_user_hash_map(void)
{
	size_t i;
	struct customer *c;

	for (i = 0; i < MAX_NUM_CUSTOMERS; i++) {
		if (user_hash_map[i].is_visited)
			user_hash_map[i].is_visited = false;
		c = user_hash_map[i].node;
		if (c) {
			user_hash_map[i].node = NULL;
			free(c);
		}
	}
}

int reset_customer_visits(void)
{
	printf("start reset customers visits\n");

	tail = head = NULL;

	reset_user_hash_map();

	printf("end reset customers visits\n");

	return 0;
}
