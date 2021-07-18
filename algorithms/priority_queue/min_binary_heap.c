/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BINARY_HEAP_SIZE (1000000)

static uint32_t binary_heap[MAX_BINARY_HEAP_SIZE];
static size_t binary_heap_current_index = 0;

static void print_binary_heap(void)
{
	size_t i;

	for (i = 1; i <= binary_heap_current_index; i++)
		printf("[%u]->", binary_heap[i]);
	printf("\n");
}

static bool is_greater(uint32_t parent_node, uint32_t child_node)
{
	if (binary_heap[parent_node] > binary_heap[child_node])
		return true;
	else
		return false;
}

static void swap(uint32_t p, uint32_t q)
{
	uint32_t t;

	t = binary_heap[p];
	binary_heap[p] = binary_heap[q];
	binary_heap[q] = t;
}

static void swim(uint32_t child)
{
	uint32_t parent;

	while (child > 1) {
		parent = child >> 1;
		if (is_greater(parent, child))
			swap(parent, child);
		child = child >> 1;
	}
}

static void sink(uint32_t parent, size_t size)
{
	uint32_t child;

	child = parent << 1;

	while (child <= size) {
		if (child < size && is_greater(child, child + 1))
			child++;
		if (!is_greater(parent, child))
			break;
		else
			swap(parent, child);
		parent = child;
		child = parent << 1;
	}
}

static void insert(uint32_t val)
{
	if (binary_heap_current_index >= MAX_BINARY_HEAP_SIZE) {
		printf("binary heap is full\n");
		return;
	}

	binary_heap[++binary_heap_current_index] = val;
	swim(binary_heap_current_index);
}

static void build_min_binary_heap(size_t n)
{
	time_t t;
	size_t i;
	uint32_t val;

	srand(time(&t));

	for (i = 0; i < n; i++) {
		val = rand() % n;
		insert(val);
	}

	printf("min heap is:\n");
	print_binary_heap();
}

static uint32_t get_min(void)
{
	uint32_t root;

	root = binary_heap[1];
	swap(1, binary_heap_current_index);
	binary_heap_current_index--;
	sink(1, binary_heap_current_index);
	binary_heap[binary_heap_current_index + 1] = 0;

	return root;
}

static void sort_min_heap(size_t n)
{
	size_t i;

	printf("min heap soted output is:\n");
	for (i = 0; i < n; i++)
		printf("[%u]->", get_min());
	printf("\n");
}

int main(int argc, char *argv[])
{
	size_t n;

	if (argc < 2) {
		printf("invalid input\n");
		return -1;
	}

	n = atoi(argv[1]);
	build_min_binary_heap(n);
	sort_min_heap(n);

	return 0;
}
