#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/circus.h"

#define MAX_HEIGHT (300)
enum attribute {
	min,
	height,
	weight,
	max
};

static void create_people_hash_map(uint16_t *h, struct person *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		h[p[i].height] = p[i].weight;
}

void print_people(struct person *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("[%zu] height %u weight %u\n", i, p[i].height, p[i].weight);
}

static void swap(struct person *p, ssize_t l, ssize_t r)
{
	uint16_t temp_h, temp_w;

	temp_h = p[l].height;
	temp_w = p[l].weight;

	p[l].height = p[r].height;
	p[l].weight = p[r].weight;

	p[r].height = temp_h;
	p[r].weight = temp_w;
}

static void copy_struct(struct person *dest, struct person const *src, size_t n)
{
	size_t i;

	for (i = 0; i <= n; i++) {
		dest[i].height = src[i].height;
		dest[i].weight = src[i].weight;
	}
}

static void arrange_people_in_asecending_height_and_weight(uint16_t *h,
							   struct person *p,
							   struct person *q,
							   size_t n)
{
	struct person r[MAX_PEOPLE] = {{0,0}};
	size_t i, j;

	for (i = 0, j = 0; i <= n; i++) {
		if (h[p[i].height] == q[i].weight) {
			r[j].height = p[i].height;
			r[j].weight = q[i].weight;
			j++;
		}
	}
	
	copy_struct(p, r, MAX_PEOPLE);
}

static void quick_sort_people_by_attribute(struct person *p, ssize_t left,
					   ssize_t right, enum attribute a)
{
	size_t i, last;

	if (left >= right)
		return;

	swap(p, left , left + ((right - left) >> 1));
	last = left;

	for (i = left + 1; i <= right; i++) {
		if ((a == height) && (p[i].height < p[left].height))
			swap(p, ++last, i);
		else if ((a == weight) && (p[i].weight < p[left].weight))
			swap(p, ++last, i);
	}
	swap(p, left, last);

	quick_sort_people_by_attribute(p, left, last - 1, a);
	quick_sort_people_by_attribute(p, last + 1, right, a);
}

static void process_people_data(struct person *p, size_t n)
{
	struct person q[n];
	ssize_t left = 0, right = n - 1;
	uint16_t people_hash_map[MAX_HEIGHT] = {0,};

	copy_struct(q, p, n);
	create_people_hash_map(people_hash_map, p, n);

	quick_sort_people_by_attribute(p, left, right, height);
	quick_sort_people_by_attribute(q, left, right, weight);
	
	arrange_people_in_asecending_height_and_weight(people_hash_map, p, q, right);
}

static bool is_heights_valid(struct person *p, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		if (p[i].height >= MAX_HEIGHT)
			return false;

	return true;
}

int find_total_possible_human_towers(struct person *p, size_t n)
{
	if (!p)
		return -1;
	if (!n)
		return -1;
	if (!is_heights_valid(p, n))
		return -1;

	process_people_data(p, n);

	return 0;
}
