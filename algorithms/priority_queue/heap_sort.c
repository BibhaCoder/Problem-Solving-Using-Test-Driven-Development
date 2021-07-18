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

#define MAX_BINARY_HEAP_SIZE (200000000)

static uint32_t binary_heap[MAX_BINARY_HEAP_SIZE];
static uint32_t input[MAX_BINARY_HEAP_SIZE];
static size_t binary_heap_current_index = 0;
static uint32_t print_control = 0;

static void print_array(uint32_t *a, size_t size)
{
	size_t i;

	if (!print_control)
		return;

	for (i = 0; i < size; i++)
		printf("[%u]->", a[i]);
	printf("\n");
}

static bool is_less(uint32_t parent_node, uint32_t child_node)
{
	if (binary_heap[parent_node] < binary_heap[child_node])
		return true;
	else
		return false;
}

static void swap(uint32_t *a, uint32_t p, uint32_t q)
{
	uint32_t t;

	t = a[p];
	a[p] = a[q];
	a[q] = t;
}

static void swim(uint32_t child)
{
	uint32_t parent;

	while (child > 1) {
		parent = child >> 1;
		if (is_less(parent, child))
			swap(binary_heap, parent, child);
		child = child >> 1;
	}
}

static void sink(uint32_t parent, size_t size)
{
	uint32_t child;

	child = parent << 1;

	while (child <= size) {
		if (child < size && is_less(child, child + 1))
			child++;
		if (!is_less(parent, child))
			break;
		else
			swap(binary_heap, parent, child);
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

static void build_max_binary_heap(size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		insert(input[i]);

}

static void generate_input(size_t n)
{
	size_t i;
	time_t t;
	uint32_t val;

	srand(time(&t));

	for (i = 0; i < n; i++) {
		val = rand() % n;
		input[i] = val;
	}
}

static uint32_t delete_max(void)
{
	uint32_t root;

	root = binary_heap[1];
	swap(binary_heap, 1, binary_heap_current_index);
	binary_heap_current_index--;
	sink(1, binary_heap_current_index);
	binary_heap[binary_heap_current_index + 1] = root;

	return root;
}

static void heap_sort(size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		delete_max();

	binary_heap_current_index = n;
	printf("max heap sorted output is:\n");
}

static void profile_heap_sort(size_t n)
{
	clock_t t;
	double time_taken;

	t = clock();
	build_max_binary_heap(n);
	heap_sort(n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("heap_sort %f seconds to execute for %zu numbers\n",
		time_taken, n);
	print_array(binary_heap, n);
}

static void quick_sort(uint32_t *a, int32_t left, int32_t right)
{
	size_t i;
	size_t last;

	if (left >= right)
		return;

	swap(a, left, (left + ((right - left) >> 1)));
	last = left;

	for (i = left + 1; i <= right; i++)
		if (a[i] < a[left])
			swap(a, ++last, i);
	swap(a, left, last);
	quick_sort(a, left, last - 1);
	quick_sort(a, last + 1, right);
}

static void profile_quick_sort(size_t n)
{
	clock_t t;
	double time_taken;

	t = clock();
	quick_sort(input, 0, n - 1);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("quick_sort %f seconds to execute for %zu numbers\n",
		time_taken, n);
	print_array(input, n);
}

int main(int argc, char *argv[])
{
	size_t n;

	if (argc < 3) {
		printf("invalid input\n");
		return -1;
	}

	n = atoi(argv[1]);
	generate_input(n);
	print_control = atoi(argv[2]);
	profile_quick_sort(n);
	profile_heap_sort(n);

	return 0;
}
