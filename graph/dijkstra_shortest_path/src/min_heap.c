/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <limits.h>
#include "../inc/min_heap.h"
#include "../inc/dijkstra_shortest_path.h"

#define MAX_MIN_HEAP_ITEMS (MAX_VERTICES_IN_GRAPH)

static struct min_heap min_heap_array[MAX_MIN_HEAP_ITEMS + 1];
static int min_heap_current_size;

static void swap(int parent, int child)
{
	struct min_heap temp;

	temp = min_heap_array[parent];
	min_heap_array[parent] = min_heap_array[child];
	min_heap_array[child] = temp;
}

static int get_min_child_index(int left_child, int right_child)
{
	if (right_child > min_heap_current_size)
		return left_child;

	else if (min_heap_array[left_child].weight < min_heap_array[right_child].weight)
		return left_child;
	else
		return right_child;
}

static void sink(int parent)
{
	int min_index;
	int left_child;
	int right_child;

	left_child = parent << 1;
	right_child = left_child + 1;

	while (left_child <= min_heap_current_size) {
		min_index = get_min_child_index(left_child, right_child);
		if (min_heap_array[min_index].weight < min_heap_array[parent].weight)
			swap(parent, min_index);

		parent = min_index;
		left_child = parent << 1;
		right_child = left_child + 1;
	}
}

static void swim(int child)
{
	int parent;

	parent = child >> 1;

	while (parent) {
		if (min_heap_array[parent].weight > min_heap_array[child].weight)
			swap(parent, child);

		child = parent;
		parent = child >> 1;
	}
}

int insert_in_min_heap(int index, int weight)
{
	struct min_heap item;

	if (min_heap_current_size >= MAX_MIN_HEAP_ITEMS)
		return -1;

	item.index = index;
	item.weight = weight;

	min_heap_array[++min_heap_current_size] = item;
	swim(min_heap_current_size);

	return 0;
}

void update_min_heap(int index, int weight)
{
	min_heap_array[index].weight = weight;

	sink(1);
}

int get_min(struct min_heap *val)
{
	if (!min_heap_current_size)
		return -1;

	*val = min_heap_array[1];

	return 0;
}

int delete_min(void)
{
	if (min_heap_current_size < 1)
		return -1;

	min_heap_array[1].weight = INT_MAX;
	swap(1, min_heap_current_size);
	min_heap_current_size--;

	sink(1);

	return 0;
}

void print_min_heap(void)
{
	int i;

	printf("min heap is:\n");
	for (i = 1; i <= min_heap_current_size; i++)
		printf("[%d](%d : %d)\n", i, min_heap_array[i].index,
		       min_heap_array[i].weight);
	printf("\n");
}

void reset_min_heap(void)
{
	int i;

	for (i = 0; i < MAX_MIN_HEAP_ITEMS + 1; i++) {
		min_heap_array[i].index = 0;
		min_heap_array[i].weight = 0;
	}

	min_heap_current_size = 0;
}
