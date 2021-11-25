/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE (10) 

static uint32_t array[ARRAY_MAX_SIZE];

static uint32_t root(uint32_t p)
{
	while (p != array[p])
		p = array[p];

	return p;
}

static void quick_union(uint32_t p, uint32_t q)
{
	uint32_t p_root;
	uint32_t q_root;

	p_root = root(p);
	q_root = root(q);
	if (p_root == q_root) {
		printf("%u and %u are already connected in forest with root %u\n",
			p, q, q_root);
		return;
	}

	array[p] = array[q];
}

static bool is_connected(uint32_t p, uint32_t q)
{
	uint32_t p_root;
	uint32_t q_root;

	p_root = root(p);
	q_root = root(q);

	if (p_root == q_root) {
		printf("points %u and %u are connected and belong to forest with root %u\n",
			p, q, q_root);
		return true;
	} else {
		printf("points %u and %u are not connected in any forest\n", p, q);
		return false;
	}
}

static void initialize_data_structure(void)
{
	uint32_t i;

	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		array[i] = i;
}

static void print_forest(void)
{
	size_t i;

	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		printf("[%u] ", array[i]);

	printf("\n");
}

int main()
{
	initialize_data_structure();

	quick_union(1, 2);
	quick_union(2, 3);
	quick_union(6, 2);
	quick_union(7, 6);

	quick_union(4, 9);
	quick_union(8, 4);
	quick_union(5, 2);
	quick_union(2, 4);

	is_connected(1, 7);
	is_connected(1, 9);

	is_connected(5, 6);
	is_connected(0, 9);

	print_forest();

	return 0;
}
