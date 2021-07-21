/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdint.h>

struct min_heap {
        int index;
        int weight;
};

int insert_in_min_heap(int index, int weight);
int get_min(struct min_heap *item);
int delete_min(void);
void update_min_heap(int index, int weight);
void print_min_heap(void);
void print_min_heap_array(void);
void reset_min_heap(void);
