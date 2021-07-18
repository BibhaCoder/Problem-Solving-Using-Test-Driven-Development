/*  
 * Copyright (c) 2017 BibhaCoder(bibha.rajeev.2011@gmail.com). All rights reserved.  
 * Licensed under the MIT License. See MIT license for full license information.  
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ARRAY_MAX_SIZE (10) 

static uint32_t array[ARRAY_MAX_SIZE];

static void union_points(uint32_t p, uint32_t q)
{
	size_t i;

	if (array[p] == array[q]) {
		printf("%u and %u are already connected in component %u\n",
			p, q, array[q]);
		return;
	}

	for (i = 0; i < ARRAY_MAX_SIZE; i++) {
		if (array[i] == array[p])
			array[i] = array[q];
	}

}

static bool is_connected(uint32_t p, uint32_t q)
{
	if (array[p] == array[q]) {
		printf("points %u and %u are connected and belong to component %u\n",
			p, q, array[q]);
		return true;
	} else {
		printf("points %u and %u are not connected\n", p, q);
		return false;
	}
}

static void initialize_data_structure(void)
{
	size_t i;

	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		array[i] = i;
}

static void print_component(void)
{
	size_t i;

	for (i = 0; i < ARRAY_MAX_SIZE; i++)
		printf("[%u] ", array[i]);

	printf("\n");
}

int main()
{
	initialize_data_structure();

	union_points(1, 2);
	union_points(2, 3);

	union_points(4, 9);
	union_points(8, 4);

	is_connected(1, 3);
	is_connected(8, 9);

	is_connected(5, 6);
	union_points(5, 1);

	is_connected(5, 2);
	is_connected(0, 2);

	union_points(7, 2);
	union_points(0, 1);
	union_points(4, 0);

	is_connected(0, 2);

	print_component();

	return 0;
}
