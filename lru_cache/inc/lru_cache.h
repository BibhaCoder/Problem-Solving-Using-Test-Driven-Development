/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdint.h>
#include <stddef.h>

struct lru_cache {
	size_t key;
	int32_t value;
	struct lru_cache_hit_list *node;
};

#define MAX_ITEM_KEY (20)

#define MAX_ITEMS_IN_LRU_CACHE  (10)

int add_item(size_t key, int32_t value);
struct lru_cache *find_item(size_t key);
struct lru_cache *get_lru_cache_most_recent_hit(void);
int remove_item(size_t key);
void print_lru_cache(void);
int destroy_lru_cache(void);
