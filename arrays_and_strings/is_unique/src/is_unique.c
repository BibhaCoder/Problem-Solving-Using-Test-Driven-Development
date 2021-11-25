/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stddef.h>
#include <stdbool.h>
#include "../inc/is_unique.h"

#define MAX_UNIQUE_ASCII_CHARS (256)

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_LENGTH; i++)
		if (s[i] == '\0')
			return true;

	return false;
}

static int get_char_asci_index(char c)
{
	return c - '\0';
}

static bool is_input_string_has_valid_ascii_chars(char const *s)
{
	size_t i;
	int ascii_char_index;

	for (i = 0; s[i]; i++) {
		ascii_char_index = get_char_asci_index(s[i]);
		if (ascii_char_index < 0)
			return false;
		if (ascii_char_index >= MAX_UNIQUE_ASCII_CHARS)
			return false;
	}

	return true;

}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;
	else if (!is_input_string_null_terminated(s))
		return false;
	else if (!is_input_string_has_valid_ascii_chars(s))
		return false;
	else
		return true;
}

static bool is_string_made_of_unique_chars(char const *s)
{
	size_t i;
	int char_key_index;
	bool ascii_char_map[MAX_UNIQUE_ASCII_CHARS] = {false, };

	for (i = 0; s[i]; i++) {
		char_key_index = get_char_asci_index(s[i]);
		if (ascii_char_map[char_key_index])
			return false;
		else
			ascii_char_map[char_key_index] = true;
	}

	return true;
}

bool is_unique(char const *s)
{
	if (!is_input_string_valid(s))
		return false;

	return is_string_made_of_unique_chars(s);
}
