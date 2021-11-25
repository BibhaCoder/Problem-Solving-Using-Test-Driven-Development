/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/urlify.h"
#include <stdbool.h>
#include <stdio.h>

static bool is_string_valid(char *s, size_t len)
{
	if (!s)
		return false;

	return true;
}

static size_t count_no_of_spaces(char *s, size_t len)
{
	size_t i;
	size_t no_of_spaces = 0;

	for (i = 0; i < len; i++)
		if (s[i] == ' ')
			no_of_spaces++;

	return no_of_spaces;
}

static int expand_and_urlify_string(char *s, size_t len)
{
	ssize_t i;
	size_t index;
	size_t no_of_spaces;
	size_t expanded_string_size;

	no_of_spaces = count_no_of_spaces(s, len);
	expanded_string_size = len + 2 * no_of_spaces;

	s[expanded_string_size] = '\0';
	index = expanded_string_size;

	for (i = len - 1; i >= 0; i--) {
		if (' ' == s[i]) {
			s[index - 1] = '0';
			s[index - 2] = '2';
			s[index - 3] = '%';
			index -= 3;
		} else {
			s[index - 1] = s[i];
			index -= 1;
		}
	}

	return 0;
}

int urlify(char *s, size_t len)
{
	if (!is_string_valid(s, len))
		return -1;

	return expand_and_urlify_string(s, len);
}
