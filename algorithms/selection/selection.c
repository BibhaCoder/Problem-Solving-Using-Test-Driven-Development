/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define SELECTION_ARRAY_SIZE (1000000)

static uint32_t input[SELECTION_ARRAY_SIZE];

static void print_input(uint32_t const *a, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
		printf("[%u]->", a[i]);

	printf("\n");
}

static void initialize_input(uint32_t *a, size_t num)
{
	time_t t;
	size_t i;

	srand(time(&t));
	for (i = 0; i < num; i++)
		a[i] = rand() % num;

	print_input(a, num);
}

static void swap(uint32_t *a, size_t i, size_t j)
{
	uint32_t t;

	t = a[i];
	a[i] = a[j];
	a[j] = t;
}

static void random_shuffle_input(uint32_t *a, size_t num)
{
	time_t t;
	size_t i, j;

	srand(time(&t));

	for (i = 0; i < num; i++) {
		j = rand () % (i + 1);
		swap(a, i, j);
	}

	print_input(a, num);
}

static uint32_t partition(uint32_t *a, size_t left,
			  size_t right, size_t num, uint32_t *iter)
{
	size_t mid, last;
	size_t i;

	if (left > right) {
		printf("invalid input");
		return SELECTION_ARRAY_SIZE;
	}

	mid = (left + ((right - left) >> 1));
	swap(a, left, mid);
	last = left;

	for (i = left + 1; i <= right; i++, (*iter)++)
		if (a[i] < a[left])
			swap(a, ++last, i);

	swap(a, left, last);

	return last;
}

static uint32_t select_given_item(uint32_t *a, size_t select_index,
				  size_t num, uint32_t *iter)
{
	size_t index;
	size_t lo, hi;

	lo = 0;
	hi = num - 1;

	while (lo < hi) {
		(*iter)++;
		index = partition(a, lo, hi, num, iter);
		if (index < select_index)
			lo = index + 1;
		else if (index > select_index)
			hi = index - 1;
		else
			return a[index];
	}

	return a[select_index];
}

static void run_selection_test(size_t num, size_t item_pos)
{
	uint32_t iter = 0;
	ssize_t element;

	initialize_input(input, num);
	random_shuffle_input(input, num);
	element = select_given_item(input, item_pos, num, &iter);

	printf("found item %zu at pos %zu after iter %u\n", element, item_pos, iter);
	print_input(input, num);
}

int main(int argc, char **argv)
{
	size_t num;
	size_t item_pos;

	if (argc < 3) {
		printf("invalid input\n");
		return -1;
	}

	num = atoi(argv[1]);
	item_pos = atoi(argv[2]);
	run_selection_test(num, item_pos);

	return 0;
}
