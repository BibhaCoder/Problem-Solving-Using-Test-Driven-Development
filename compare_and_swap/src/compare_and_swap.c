/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/compare_and_swap.h"

int compare_and_swap(int32_t volatile *ref, int32_t old_val, int32_t new_val)
{
	if (!ref)
		return -1;

	if (*ref == old_val) {
		*ref = new_val;
		return 0;
	} else {
		return -1;
	}
}
