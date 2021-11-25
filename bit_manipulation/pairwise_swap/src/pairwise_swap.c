/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/pairwise_swap.h"

uint32_t pairwise_swap(uint32_t val)
{
	return (((val & 0xAAAAAAAA) >> 1) | ((val & 0x55555555) << 1));
}
