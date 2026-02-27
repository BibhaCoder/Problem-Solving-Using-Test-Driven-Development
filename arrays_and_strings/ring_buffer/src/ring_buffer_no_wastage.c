/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "/Unity/src/unity.h"
#include "../inc/ring_buffer.h"
#include <stddef.h>

static int ring_buffer[MAX_RING_BUFFER_SIZE];
static size_t read_pointer;
static size_t write_pointer;
static size_t count;

static void increment_pointer(size_t *pointer)
{
	(*pointer)++;
	(*pointer) &= (MAX_RING_BUFFER_SIZE - 1);
}

int dequeue(int *out_val)
{
	if (!count)
		return -1;

	*out_val = ring_buffer[read_pointer];
	increment_pointer(&read_pointer);
	count--;

	return 0;
}

int enqueue(int val)
{
	if (MAX_RING_BUFFER_SIZE == count)
		return -1;

	ring_buffer[write_pointer] = val;
	increment_pointer(&write_pointer);
	count++;

	return 0;
}
