/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/escape.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool is_input_valid(char const *s)
{
	if (!s)
		return false;
	else
		return true;
}

static bool is_escape_char(char c)
{
	if ((c == '\n') || (c == '\t'))
		return true;
	else
		return false;
}

static size_t get_no_of_escape_chars(char const *s)
{
	size_t i;
	size_t num_escape = 0;

	for (i = 0; s[i]; i++) {
		if (is_escape_char(s[i]))
			num_escape++;
	}

	return num_escape;
}

static char get_escape_char(char c)
{
	switch (c) {
	case '\n':
		return 'n';
	case '\t':
		return 't';
	default:
		return '\0';
	}
}

static char const *__escape(char const *s)
{
	char *t;
	size_t i, j;
	size_t new_size;
	size_t s_size = strlen(s);
	size_t no_of_escape_chars= get_no_of_escape_chars(s);

	new_size = s_size + (no_of_escape_chars * 2) + 1;

	t = malloc(new_size);
	if (!t)
		return NULL;

	for (i = j = 0; s[i]; i++, j++) {
		if (is_escape_char(s[i])) {
			t[j] = '\\';
			j++;
			t[j] = get_escape_char(s[i]);
		} else {
			t[j] = s[i];
		}
	}
	t[j] = '\0';

	return t;
}

char const *escape(char const *s)
{
	if (!is_input_valid(s))
		return NULL;

	return __escape(s);
}
