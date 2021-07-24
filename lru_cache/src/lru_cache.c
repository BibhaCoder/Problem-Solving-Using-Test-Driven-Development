/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/lru_cache.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct lru_cache_hit_list {
	struct lru_cache_hit_list *next;
	struct lru_cache_hit_list *prev;
	struct lru_cache *val;
};

static size_t lru_cached_count;
static struct lru_cache *cache[MAX_ITEM_KEY];
static struct lru_cache_hit_list *head;
static struct lru_cache_hit_list *tail;

static void increment_total_lru_cached_item(void)
{
	lru_cached_count++;
}

static void decrement_total_lru_cached_item(void)
{
	lru_cached_count--;
}

static void reset_total_lru_cached_item(void)
{
	lru_cached_count = 0;
}

static size_t get_total_lru_cached_item(void)
{
	return lru_cached_count;
}

static void delete_from_middle(struct lru_cache_hit_list *node)
{
	struct lru_cache_hit_list *prev, *next;

	prev = node->prev;
	next = node->next;

	prev->next = next;
	next->prev = prev;
}

static void delete_from_head(void)
{
	head = head->next;
	if (head)
		head->prev = NULL;
	else
		tail = NULL;
}

static void delete_from_tail(void)
{
	tail = tail->prev;
	if (tail)
		tail->next = NULL;
	else
		head = NULL;
}

static void delete_from_hit_list(struct lru_cache_hit_list *node)
{
	if (head == node)
		delete_from_head();
	else if (tail == node)
		delete_from_tail();
	else
		delete_from_middle(node);
}

static void add_at_tail(struct lru_cache_hit_list *node)
{
	node->next = NULL;

	tail->next = node;
	node->prev = tail;
	tail = node;
}

static void move_to_cache_hit_list_tail(struct lru_cache_hit_list *node)
{
	if (tail == node)
		return;

	printf("migrate [%zu : %d] to tail of hit list\n",
	       node->val->key, node->val->value);
	delete_from_hit_list(node);

	add_at_tail(node);
}

static struct lru_cache_hit_list *add_to_list_tail(struct lru_cache *item)
{
	struct lru_cache_hit_list *node;

	node = malloc(sizeof(*node));
	if (!node)
		return NULL;

	node->val = item;
	node->next = NULL;
	node->prev = NULL;

	if (tail) {
		node->prev = tail;
		tail->next = node;
		tail = node;
	} else {
		head = tail = node;
	}

	return node;
}

static bool is_cache_full(void)
{
	if (get_total_lru_cached_item() > MAX_ITEMS_IN_LRU_CACHE)
		return true;
	else
		return false;
}

static void evict_oldest_from_head(void)
{
	struct lru_cache_hit_list *temp = head;

	cache[temp->val->key] = NULL;
	printf("evict least recently used item [%zu : %d]\n",
		temp->val->key, temp->val->value);
	delete_from_head();
	decrement_total_lru_cached_item();
	free(temp);
}

static int add_in_lru_cache(size_t index, int32_t val)
{
	struct lru_cache *item;

	if (cache[index]) {
		cache[index]->value = val;
		move_to_cache_hit_list_tail(cache[index]->node);
		return 0;
	}

	item = malloc(sizeof(*item));
	if (!item)
		return -1;

	item->key = index;
	item->value = val;
	item->node = add_to_list_tail(item);
	if (!(item->node))
		return -1;
	cache[index] = item;
	increment_total_lru_cached_item();

	if (is_cache_full())
		evict_oldest_from_head();

	return 0;
}

int add_item(size_t index, int32_t val)
{
	if (index >= MAX_ITEM_KEY)
		return -1;

	return add_in_lru_cache(index, val);
}

static void print_lru_cache_hash_map(void)
{
	size_t i;

	printf("lru cache hash map is:\n");
	for (i = 0; i < MAX_ITEM_KEY; i++) {
		if (cache[i])
			printf("[%zu: %d]\n", cache[i]->key, cache[i]->value);
		else
			printf("NULL\n");
	}
	printf("\n");


}

static void print_lru_cache_hit_list(void)
{
	struct lru_cache *item;
	struct lru_cache_hit_list *node = head;

	printf("lru cache hit list is:\n");
	if (!node) {
		printf("(empty)\n");
		return;
	}

	while (node) {
		item = node->val;
		printf("[%zu: %d]-->", item->key, item->value);
		node = node->next;
	}
	printf("\n");
}

void print_lru_cache(void)
{
	print_lru_cache_hash_map();

	print_lru_cache_hit_list();
}

struct lru_cache *find_item(size_t key)
{
	struct lru_cache *item;

	if (!head)
		return NULL;

	if (key > MAX_ITEM_KEY)
		return NULL;

	item = cache[key];
	if (item)
		move_to_cache_hit_list_tail(item->node);

	return cache[key];
}

int remove_item(size_t key)
{
	struct lru_cache *item;

	if (!head)
		return -1;

	if (key > MAX_ITEM_KEY)
		return -1;

	item = cache[key];
	if (!item)
		return -1;

	cache[key] = NULL;
	delete_from_hit_list(item->node);
	decrement_total_lru_cached_item();
	free(item->node);
	free(item);

	return 0;
}

static void destroy_lru_cache_hash_map(void)
{
	size_t i;

	for (i = 0; i < MAX_ITEM_KEY; i++) {
		if (cache[i])
			free(cache[i]);

		cache[i] = NULL;
	}
}

static void destroy_lru_cache_hit_list(void)
{
	struct lru_cache_hit_list *prev;
	struct lru_cache_hit_list *node = head;

	prev = node;
	while (node) {
		node = node->next;
		free(prev);
		prev = node;
	}

	head = tail = NULL;
}

int destroy_lru_cache(void)
{
	destroy_lru_cache_hash_map();

	destroy_lru_cache_hit_list();

	reset_total_lru_cached_item();

	return 0;
}

struct lru_cache *get_lru_cache_most_recent_hit(void)
{
	if (!tail)
		return NULL;

	return tail->val;
}
