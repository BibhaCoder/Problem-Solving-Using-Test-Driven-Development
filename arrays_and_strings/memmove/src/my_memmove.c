/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/my_memmove.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

static bool is_input_valid(void *d, void const *s, size_t size)
{
	if (!s || !d)
		return false;
	if (size > MAX_SIZE)
		return false;

	return true;
}

static void *memmove_left_to_right(void *d, void const *s, size_t size)
{
	size_t i;
	uint8_t *d_byte = d;
	uint8_t const *s_byte = s;

	for (i = 0; i < size; i++)
		d_byte[i] = s_byte[i];

	return d;
}

static void *memmove_right_to_left(void *d, void const *s, size_t size)
{
	ssize_t i;
	uint8_t *d_byte = (uint8_t *)d;
	uint8_t const *s_byte = (uint8_t *)s;

	for (i = size - 1; i >= 0; i--)
		d_byte[i] = s_byte[i];

	return d;
}

void *my_memmove(void *d, void const *s, size_t size)
{
	uintptr_t dest_addr_num, src_addr_num;

	if (!is_input_valid(d, s, size))
		return NULL;

	/* undefined behaviour is d and s do not belong to same
	 * object becasue 2 pointers pointing to 2 different
	 * locations in 2 different object can't be compared(as per)
	 * ANSI c standard this is undefined behaviour.
	 *
	 * As an alternative use typecast to uintptr_t to supress this
	 * undefined behaviour.
	 */
	dest_addr_num = (uintptr_t)d;
	src_addr_num = (uintptr_t)s;

	if (dest_addr_num == src_addr_num)
		return d;

	if (dest_addr_num < src_addr_num)
		return memmove_left_to_right(d, s, size);
	else
		return memmove_right_to_left(d, s, size);
}
