#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../inc/kth_multiple.h"

#define MIN(a, b) (a > b ? b : a)

static size_t queue_3[MAX_NUMBER];
static size_t queue_3_front_pointer;
static size_t queue_3_rear_pointer;

static size_t queue_5[MAX_NUMBER];
static size_t queue_5_front_pointer;
static size_t queue_5_rear_pointer;

static size_t queue_7[MAX_NUMBER];
static size_t queue_7_front_pointer;
static size_t queue_7_rear_pointer;

enum queue_num {
	min,
	three,
	five,
	seven,
	max
};

void reset_all_queues(void)
{
	queue_3_front_pointer = 0;
	queue_3_rear_pointer = 0;

	queue_5_front_pointer = 0;
	queue_5_rear_pointer = 0;

	queue_7_front_pointer = 0;
	queue_7_rear_pointer = 0;
}

static size_t __peek(size_t const *q, size_t const *f, size_t const *r)
{
	if (*f == *r || *f > *r)
		return SIZE_MAX;

	return q[*f];
}

static size_t peek(enum queue_num n)
{
	switch(n) {
	case three:
		return __peek(queue_3,
			      &queue_3_front_pointer,
			      &queue_3_rear_pointer);
	case five:
		return __peek(queue_5,
			      &queue_5_front_pointer,
			      &queue_5_rear_pointer);
	case seven:
		return __peek(queue_7,
			      &queue_7_front_pointer,
			      &queue_7_rear_pointer);
	default:
		return SIZE_MAX;
	}
}

static int __enqueue(size_t *q, size_t *r, size_t val)
{
	if (*r >= MAX_NUMBER) {
		printf("err: queue_3 is full\n");
		return -1;
	}
	q[*r] = val;

	(*r)++;

	return 0;
}

static int enqueue(enum queue_num n, size_t val)
{
	switch(n) {
	case three:
		return __enqueue(queue_3, &queue_3_rear_pointer, val);
	case five:
		return __enqueue(queue_5, &queue_5_rear_pointer, val);
	case seven:
		return __enqueue(queue_7, &queue_7_rear_pointer, val);
	default:
		return -1;
	}
}

static int __dequeue(size_t *q, size_t *f, size_t *r, size_t *val)
{
	if (*f > *r) {
		printf("err: queue_3 is empty\n");
		return -1;
	}

	*val = q[*f];
	(*f)++;

	return 0;
}

static int dequeue(enum queue_num n, size_t *val)
{
	switch(n) {
	case three:
		return __dequeue(queue_3, &queue_3_front_pointer,
				 &queue_3_rear_pointer, val);
	case five:
		return __dequeue(queue_5, &queue_5_front_pointer,
				 &queue_5_rear_pointer, val);
	case seven:
		return __dequeue(queue_7, &queue_7_front_pointer,
				 &queue_7_rear_pointer, val);
	default:
		return -1;
	}
}

static enum queue_num find_min(size_t *min)
{
	size_t q3, q5, q7;

	q3 = peek(three);
	q5 = peek(five);
	q7 = peek(seven);

	*min = MIN(q3, MIN(q5, q7));

	if (*min == q3)
		return three;
	else if (*min == q5)
		return five;
	else
		return seven;
}

size_t kth_multiple(size_t k)
{
	size_t removed;
	size_t i, min, val;
	enum queue_num q;

	enqueue(three, 1);

	for (i = 0; i <= k ; i++) {
		q = find_min(&min);
		val = min;
		printf("%zuth num is %zu\n", i, val);
		if (three == q) {
			dequeue(three, &removed);
			enqueue(three, 3 * min);
			enqueue(five, 5 * min);
			enqueue(seven, 7 * min);
		} else if (five == q) {
			dequeue(five, &removed);
			enqueue(five, 5 * min);
			enqueue(seven, 7 * min);
		} else {
			dequeue(seven, &removed);
			enqueue(seven, 7 * min);
		}
	}
	
	return val;
}
