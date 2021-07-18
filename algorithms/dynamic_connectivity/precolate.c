/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_MAX_SIZE (1000)
#define MATRIX_MAX_SIZE_SQUARE (MATRIX_MAX_SIZE * MATRIX_MAX_SIZE)

struct matrix_node {
	bool open;
	uint32_t val;
	uint32_t weight;
};

static struct matrix_node array[MATRIX_MAX_SIZE * MATRIX_MAX_SIZE + 2];

static uint32_t root(uint32_t i)
{
	while (i != array[i].val) {
		/* iterating logarthim log*n optimization*/
		array[i].val =  array[array[i].val].val;
		i = array[i].val;
	}

	return i;
}

static void quick_union(uint32_t p, uint32_t q)
{
	uint32_t i;
	uint32_t j;

	i = root(p);
	j = root(q);
	if (i == j)
		return;

	if (array[i].weight > array[j].weight) {
		array[j].val = array[i].val;
		array[i].weight += array[j].weight;
	} else {
		array[i].val = array[j].val;
		array[j].weight += array[i].weight;
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
		return false;
	}
}

static void print_forest(void)
{
	size_t i;

	printf("Prelocate matrix is:\n");
	for (i = 1; i < MATRIX_MAX_SIZE_SQUARE + 1; i++) {
		if (array[i].open)
			printf("O");
		else
			printf("X");
		if (!(i % MATRIX_MAX_SIZE))
			printf("\n");
	}
	printf("\n");
}

static void initialize_data_structure(void)
{
	size_t i;

	/* +2 is for for 1 top and 1 bottom virtual nodes */
	for (i = 0; i < (MATRIX_MAX_SIZE_SQUARE + 2); i++) {
		array[i].val = i;
		array[i].open = false;
		array[i].weight = 1;
	}
}


static void connect_top_virtual_node(size_t slot)
{
	if (slot <= MATRIX_MAX_SIZE)
		quick_union(0, slot);
}

static void connect_bottom_virtual_node(size_t slot)
{
	if (slot >= ((MATRIX_MAX_SIZE_SQUARE + 1) - MATRIX_MAX_SIZE))
		quick_union((MATRIX_MAX_SIZE_SQUARE + 1), slot);
}

static void connect_with_left_node(int32_t slot)
{
	int32_t left = 0;

	/* skip union to previous row last column node */
	if (1 == (slot % MATRIX_MAX_SIZE))
		return;

	left = slot - 1;
	if (left > 0)
		if (array[left].open)
			quick_union(slot, left);
}

static void connect_with_right_node(int32_t slot)
{
	int32_t right = 0;

	/* skip union to neext row 1st column node */
	if (!(slot % MATRIX_MAX_SIZE))
		return;

	right  = slot + 1;
	if (right <= MATRIX_MAX_SIZE_SQUARE)
		if (array[right].open)
			quick_union(slot, right);

}

static void connect_with_up_node(int32_t slot)
{
	int32_t up = 0;
	up  = slot - MATRIX_MAX_SIZE;

	if (up > 0)
		if (array[up].open)
			quick_union(slot, up);

}

static void connect_with_down_node(int32_t slot)
{
	int32_t down = 0;

	down  = slot + MATRIX_MAX_SIZE;

	if (down <= MATRIX_MAX_SIZE_SQUARE)
		if (array[down].open)
			quick_union(slot, down);
}

static void connect_adjacent_opened_nodes(int32_t slot)
{
	connect_with_left_node(slot);
	connect_with_right_node(slot);
	connect_with_up_node(slot);
	connect_with_down_node(slot);
	connect_top_virtual_node(slot);
	connect_bottom_virtual_node(slot);
}

static void open_node(int32_t slot)
{
	if (array[slot].open)
		return;

	array[slot].open = true;
	connect_adjacent_opened_nodes(slot);
}

static size_t get_total_opened_nodes(void)
{
	size_t i;
	size_t total_open = 0;

	for (i = 0; i < MATRIX_MAX_SIZE_SQUARE + 2; i++)
		if (array[i].open)
			total_open++;

	return total_open;
}

static void calculate_percolate_percentage(void)
{
	double total_opened = 0;
	double percolate_ratio;

	total_opened = get_total_opened_nodes();
	percolate_ratio = total_opened / MATRIX_MAX_SIZE_SQUARE;

	print_forest();
 
	printf("Matrix of size [%u x %u] percolates with ratio %lf [%lf/%lf]\n",
		MATRIX_MAX_SIZE, MATRIX_MAX_SIZE, percolate_ratio, total_opened,
		(double)MATRIX_MAX_SIZE_SQUARE);

}

static void run_percolate(void)
{
	time_t t;
	int32_t slot = 0;

	srand((unsigned) time(&t));

	while (!is_connected(0, (MATRIX_MAX_SIZE_SQUARE + 1))) {
		slot = rand() % (MATRIX_MAX_SIZE_SQUARE + 1); 
		/* 0 is top virtual node so skip its opening */
		if (slot)
			open_node(slot);
	}

	calculate_percolate_percentage();
}

int main(int argc, char *argv[])
{
	clock_t t;
	double time_taken;

	initialize_data_structure();
	t = clock();
	print_forest();
	run_percolate();
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("precloate model took %lf seconds to execute for %u numbers\n",
		time_taken, MATRIX_MAX_SIZE_SQUARE + 1);

	return 0;
}
