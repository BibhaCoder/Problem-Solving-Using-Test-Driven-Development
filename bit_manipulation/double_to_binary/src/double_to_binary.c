/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/double_to_binary.h"
#include <stdbool.h>
#include <stdlib.h>

static bool is_double_input_valid(double val)
{
	if (val >= 1)
		return false;
	else
		return true;
}

char *__double_to_binary(double val)
{
	size_t i = 0;
	char *binary_string = malloc(MAX_BINARY_SIZE);

	if (!binary_string)
		return NULL;

	while (val) {
		val = val * 2;
		if (val >= 1) {
			binary_string[i++] = '1';
			val = val -1;
		} else {
			binary_string[i++] = '0';
		}

		if (i >= MAX_BINARY_SIZE - 1) {
			free(binary_string);
			return NULL;
		}
	}

	binary_string[i] = '\0';

	return binary_string;
}

char *double_to_binary(double val)
{
	if (!is_double_input_valid(val))
		return NULL;

	return __double_to_binary(val);
}
