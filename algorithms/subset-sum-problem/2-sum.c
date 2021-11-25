/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE (100000)

static uint32_t array[MAX_ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

static void print_array(void)
{
	size_t i;

	for (i = 0; i < MAX_ARRAY_SIZE; i++)
		printf("[%u] ", array[i]);

	printf("\n");
}

static void quick_swap(uint32_t *a, uint32_t i, uint32_t j)
{
	uint32_t temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

static void quick_sort(uint32_t *a, int32_t left, int32_t right)
{
	uint32_t i;
	uint32_t last;

	if (left >= right)
		return;

	quick_swap(a, left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++)
		if (a[i] < a[left])
			quick_swap(a, ++last, i);

	quick_swap(a, left, last);
	quick_sort(a, left, last - 1);
	quick_sort(a, last + 1, right);
}

static void generate_input(uint32_t sum)
{
        time_t t;
        size_t i = 0;

        srand((unsigned) time(&t));

	for(i = 0; i < MAX_ARRAY_SIZE; i++)
		array[i] = rand() % sum;
}


int32_t find_total_2_sum_sets(uint32_t sum)
{
	size_t l;
	size_t r;
	uint32_t t;
	int count = 0;

	l = 0;
	r = MAX_ARRAY_SIZE - 1;

	while (l < r) {
		t = array[l] + array[r];
		if (t == sum) {
			count++;
			printf("[%u] + [%u] = %u\n",
				array[l], array[r], sum);
			l =  l + 1;
		}
		else if (t > sum) {
			r = r -1;
		} else {
			l = l + 1;
		}
	}

	return count;
}

static void profile_2_sum_sets(uint32_t sum)
{
	clock_t t;
	double time_taken;
	uint32_t count;

	t = clock();
	quick_sort(array, 0, MAX_ARRAY_SIZE - 1);
	count = find_total_2_sum_sets(sum);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("2-sum set took %f seconds to execute for %u numbers and found %u 2-sum pairs\n",
		time_taken, MAX_ARRAY_SIZE, count);
}

int main(int argc, char *argv[])
{
	uint32_t sum;

	if (argc < 2) {
		printf("Invalid input");
		return -1;
	}

	sum = atoi(argv[1]);
	generate_input(sum);
	profile_2_sum_sets(sum);

	return 0;
}

