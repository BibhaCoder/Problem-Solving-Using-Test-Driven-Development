/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>

static void byte_pointer_arithmatic(void)
{
	uint8_t u8_array[] =  {0, 1, 2};
	uint8_t *u8_ptr = u8_array;

	printf("uint8_t *ptr: (addr: %p)[%d] (addr: %p)[%d] (addr: %p)[%d]\n",
		u8_ptr + 0, *(u8_ptr + 0), u8_ptr + 1, *(u8_ptr + 1),
		u8_ptr + 2, *(u8_ptr + 2));
}

static void word_pointer_arithmatic(void)
{
	uint32_t u32_array[] =  {0, 1, 2};
	uint32_t *u32_ptr = u32_array;

	printf("uint32_t *ptr: (addr: %p)[%d] (addr: %p)[%d] (addr: %p)[%d]\n",
		u32_ptr + 0, *(u32_ptr + 0), u32_ptr + 1, *(u32_ptr + 1),
		u32_ptr + 2, *(u32_ptr + 2));
}

int main()
{
	byte_pointer_arithmatic();

	word_pointer_arithmatic();

	return 0;
}
