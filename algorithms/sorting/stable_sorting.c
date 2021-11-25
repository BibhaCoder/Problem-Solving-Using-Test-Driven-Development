/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define STUDENT_NAME_MAX_LEN (20)
#define MAX_STUDENTS (10)

struct student {
	uint32_t rank;
	char name[STUDENT_NAME_MAX_LEN];
};

struct student s[MAX_STUDENTS];
struct student s1[MAX_STUDENTS];

typedef bool (*cmp) (struct student *a, struct student *b);

static void build_student_table(void)
{
	time_t t;
	size_t i;
	uint32_t n, r;

	srand((unsigned) time(&t));

	for (i = 0; i < MAX_STUDENTS; i++) {
		r = rand() % MAX_STUDENTS;
		n = rand() % MAX_STUDENTS;
		s[i].rank = r;
		s[i].name[0] = n + '0';
		s1[i].rank = r;
		s1[i].name[0] = n + '0';
	}
}

static void print_student_table(struct student const *s)
{
	size_t i;

	for (i = 0; i < MAX_STUDENTS; i++)
		printf("Name: %s, Rank %u\n", s[i].name, s[i].rank);
}

static void swap_student(struct student *s1, struct student *s2)
{
	struct student t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

static bool name_comparator(struct student *a,struct student *b)
{
	if (a->name[0] < b->name[0])
		return true;
	else
		return false;
}

static bool rank_comparator(struct student *a,struct student *b)
{
	if (a->rank < b->rank)
		return true;
	else
		return false;
}

static void insertion_sort_student_table_by_param(cmp c)
{
	size_t i, j;

	for (i = 1; i < MAX_STUDENTS; i++) {
		for (j = i; j > 0; j--) {
			if (c(&s[j], &s[j - 1]))
				swap_student(&s[j], &s[j - 1]);
			else
				break;
		}
	}
}

static void stable_sort_student_table(void)
{
	insertion_sort_student_table_by_param(name_comparator);
	printf("after stable insertion sort by name\n");
	print_student_table(s);

	insertion_sort_student_table_by_param(rank_comparator);
	printf("after stable insertion sort by rank\n");
	print_student_table(s);
}

static void selection_sort_student_table_by_param(cmp c)
{
	size_t i, j;
	size_t smallest;

	for (i = 0; i < MAX_STUDENTS; i++) {
		smallest = i;
		for (j = i + 1; j < MAX_STUDENTS; j++) {
			if (c(&s1[j], &s1[smallest]))
				smallest = j;
		}
		swap_student(&s1[i], &s1[smallest]);
	}
}

static void unstable_sort_student_table(void)
{
	selection_sort_student_table_by_param(name_comparator);
	printf("after unstable selection sort by name\n");
	print_student_table(s1);

	selection_sort_student_table_by_param(rank_comparator);
	printf("after unstable sort by rank\n");
	print_student_table(s1);
}

int main()
{
	build_student_table();
	printf("before stable sort\n");
	print_student_table(s);
	stable_sort_student_table();
	printf("before unstable sort\n");
	print_student_table(s1);
	unstable_sort_student_table();

	return 0;
}
