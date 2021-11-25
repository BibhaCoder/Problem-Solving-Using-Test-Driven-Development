/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include "../inc/min_heap.h"

#define MAX_MIN_HEAP_ITEMS (10)

static uint32_t min_heap_array[MAX_MIN_HEAP_ITEMS + 1];
static size_t min_heap_current_size;

int insert(uint32_t val);

static void sink(size_t index);

static void swap(size_t parent, size_t child)
{
	uint32_t temp;

	temp = min_heap_array[parent];
	min_heap_array[parent] = min_heap_array[child];
	min_heap_array[child] = temp;
}

static size_t get_min_child_index(size_t left_child, size_t right_child)
{
	if (right_child > min_heap_current_size)
		return left_child;

	else if (min_heap_array[left_child] < min_heap_array[right_child])
		return left_child;
	else
		return right_child;
}

static void sink(size_t parent)
{
	size_t min_index;
	size_t left_child;
	size_t right_child;

	left_child = parent << 1;
	right_child = left_child + 1;

	while (left_child <= min_heap_current_size) {
		min_index = get_min_child_index(left_child, right_child);
		if (min_heap_array[min_index] < min_heap_array[parent])
			swap(parent, min_index);
		else
			break;

		parent = min_index;
		left_child = parent << 1;
		right_child = left_child + 1;
	}
}

static void swim(size_t child)
{
	size_t parent;

	parent = child >> 1;

	while (parent) {
		if (min_heap_array[parent] > min_heap_array[child])
			swap(parent, child);

		child = parent;
		parent = child >> 1;
	}
}

int insert(uint32_t val)
{
	if (min_heap_current_size >= MAX_MIN_HEAP_ITEMS)
		return -1;

	min_heap_array[++min_heap_current_size] = val;
	swim(min_heap_current_size);

	return 0;
}

int get_min(uint32_t *val)
{
	if (!min_heap_current_size)
		return -1;

	*val = min_heap_array[1];

	return 0;
}

int delete(void)
{
	if (min_heap_current_size < 1)
		return -1;

	swap(1, min_heap_current_size);
	min_heap_current_size--;

	sink(1);

	return 0;
}

void print_min_heap(void)
{
	size_t i;

	printf("min heap is:\n");
	for (i = 1; i <= min_heap_current_size; i++)
		printf("[%u] ", min_heap_array[i]);
	printf("\n");
}

void print_min_heap_array(void)
{
	size_t i;

	printf("min heap sorted array is:\n");
	for (i = 1; i < MAX_MIN_HEAP_ITEMS + 1; i++)
		printf("[%u] ", min_heap_array[i]);
	printf("\n");
}
