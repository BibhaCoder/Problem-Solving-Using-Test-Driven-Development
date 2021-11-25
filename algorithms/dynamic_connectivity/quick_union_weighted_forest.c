/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE (10) 

static uint32_t array[ARRAY_MAX_SIZE];
static uint32_t wt_array[ARRAY_MAX_SIZE];

static uint32_t root(uint32_t i)
{
	while (i != array[i])
		i = array[i];

	return i;
}

static void quick_union(uint32_t p, uint32_t q)
{
	uint32_t i;
	uint32_t j;

	i = root(p);
	j = root(q);
	if (i == j) {
		printf("%u and %u are already connected in forest with root %u\n",
			p, q, i);
		return;
	}

	if (wt_array[i] > wt_array[j]) {
		array[j] = array[i];
		wt_array[i] += wt_array[j];
	} else {
		array[i] = array[j];
		wt_array[j] += wt_array[i];
	}
}

static bool is_connected(uint32_t p, uint32_t q)
{
	uint32_t i;
	uint32_t j;

	i = root(p);
	j = root(q);

	if (i == j) {
		printf("points %u and %u are connected and belong to forest with root %u\n",
			p, q, i);
		return true;
	} else {
		printf("points %u and %u are not connected in any forest\n", p, q);
		return false;
	}
}

static void initialize_data_structure(void)
{
	size_t i;

	for (i = 0; i < ARRAY_MAX_SIZE; i++) {
		array[i] = i;
		wt_array[i] = 1;
	}
}

static void print_forest(void)
{
	size_t i;

	printf("Forest is:\n");
	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		printf("[%u] ", array[i]);
	printf("\n");

	printf("Wieghted forest is:\n");
	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		printf("[%u] ", wt_array[i]);
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
