/*  
 * Copyright (c) 2017 BibhaCoder(bibha.rajeev.2011@gmail.com). All rights reserved.  
 * Licensed under the MIT License. See MIT license for full license information.  
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX_SIZE (1000000) 

static uint32_t array[ARRAY_MAX_SIZE];
static uint32_t wt_array[ARRAY_MAX_SIZE];

static uint32_t root(uint32_t i)
{
	while (i != array[i]) {
		/* iterating logarthim log*n optimization*/
		array[i] =  array[array[i]];
		i = array[i];
	}

	return i;
}

static uint32_t get_max_forest_depth(uint32_t *node)
{
	size_t i = 0;
	size_t j = 0;
	uint32_t depth = 0;
	uint32_t max_depth = 0;

	while (j < ARRAY_MAX_SIZE) {
		i = j;
		while (i != array[i]) {
			i = array[i];
			depth++;
		}
		if (depth > max_depth) {
			max_depth = depth;
			*node = j;
		}
		j++;
		depth = 0;
	}

	return max_depth;
}

static void quick_union(uint32_t p, uint32_t q)
{
	uint32_t i;
	uint32_t j;

	i = root(p);
	j = root(q);
	if (i == j)
		return;

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

static void create_random_input(void)
{
	time_t t;
	size_t i = 0;

	srand((unsigned) time(&t));

	while (i < ARRAY_MAX_SIZE) {
		array[i] = rand() % ARRAY_MAX_SIZE;
		i++;
	}
}

static void run_random_union(void)
{
	time_t t;
	size_t i = 0;
	uint32_t p = 0;
	uint32_t q = 0;


	srand((unsigned) time(&t));

	while (i < ARRAY_MAX_SIZE) {
		p = rand() % ARRAY_MAX_SIZE; 
		q = rand() % ARRAY_MAX_SIZE; 
		quick_union(array[p], array[q]);
		i++;
	}
}

static void calculate_forest_max_depth(void)
{
	size_t i = 0;
	uint32_t r = 0;
	uint32_t max_weight = 0;

	while (i < ARRAY_MAX_SIZE) {
		if (wt_array[i] > max_weight) {
			max_weight = wt_array[i];
			r = i;
		}
		i++;
	}

	printf("%d sized forest node [%u] has max weight %d\n",
		ARRAY_MAX_SIZE, root(r), wt_array[r]);
}

int main(int argc, char *argv[])
{
	uint32_t max_depth_node = 0;
	uint32_t p;
	uint32_t q;

	if (argc < 2) {
		printf("invalid command missing connected commands\n");
		return -1;
	}
	p = atoi(argv[1]);
	q = atoi(argv[2]);

	create_random_input();
	initialize_data_structure();
	run_random_union();
	calculate_forest_max_depth();
	printf("max depth of forest is %d\n", get_max_forest_depth(&max_depth_node));
	printf("node %d is in max depth forest with root [%d]\n", max_depth_node, root(max_depth_node));
	is_connected(p, q);

	return 0;
}
