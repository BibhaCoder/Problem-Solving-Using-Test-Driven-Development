/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <string.h>
#include "../inc/unique_chars_in_string.h"

#define MAX_CHARS (128)

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;

	if (!is_string_null_terminated(s))
		return false;

	if (!strlen(s))
		return false;

	return true;
}

static bool is_char_present(bool *char_map, char c)
{
	if (char_map[c])
		return true;
	else
		return false;
}

static void add_char_in_char_map(bool *char_map, char c)
{
	char_map[c] = true;
}

static bool is_string_made_of_unique_chars(char const *s)
{
	size_t i;
	bool char_map[MAX_CHARS] = {0, };

	for (i = 0; s[i]; i++) {
		if (is_char_present(char_map, s[i]))
			return false;
		else
			add_char_in_char_map(char_map, s[i]);
	}

	return true;
}

bool is_string_made_of_unique_char(char const *s)
{
	if (!is_input_string_valid(s))
		return false;

	return is_string_made_of_unique_chars(s);
}
