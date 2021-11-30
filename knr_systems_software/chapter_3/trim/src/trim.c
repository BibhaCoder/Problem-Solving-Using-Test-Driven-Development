/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../inc/trim.h"

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;

	if(!strlen(s))
		return false;

	if (!is_string_null_terminated(s))
		return false;

	return true;
}

static void remove_trailing_white_spaces(char *s)
{
	ssize_t i;

	i = strlen(s) - 1;

	while (i >= 0) {
		if (!isspace(s[i]))
			break;
		i--;
	}

	s[i + 1] = '\0';
}

int trim(char *s)
{
	if (!is_input_valid(s))
		return -1;

	remove_trailing_white_spaces(s);

	return 0;
}
