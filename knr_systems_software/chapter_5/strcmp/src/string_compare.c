/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include "../inc/string_compare.h"
#include <stdbool.h>
#include <string.h>

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;

	if (!is_string_null_terminated(s))
		return false;

	if (!strlen(s))
		return false;

	return true;
}

static ssize_t compare_each_char_in_strings(char const *s, char const *t)
{
	size_t i;
	ssize_t diff;

	for (i = 0; s[i] && s[i] == t[i]; i++)
		;

	if (!s[i])
		diff = 0;
	else
		diff = s[i] - t[i];

	return diff;
}

int string_compare(char const *s, char const *t, ssize_t *diff)
{
	if (!is_input_valid(s))
		return -1;

	if (!is_input_valid(t))
		return -1;

	if (strlen(s) > strlen(t))
		return -1;

	*diff = compare_each_char_in_strings(s, t);

	return 0;
}
