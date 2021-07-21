/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include "../inc/word_count.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

enum current_cursor_pos {
	inside_word,
	outside_word,
};

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if (s[i] == '\0')
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

static size_t count_words_in_string(char const *s)
{
	size_t i = 0;
	size_t words = 0;
	enum current_cursor_pos pos = outside_word;

	while (s[i]) {
		if (isspace(s[i])) {
			pos = outside_word;
		} else if (outside_word == pos) {
			words++;
			pos = inside_word;
		}
		i++;
	}

	return words;
}

size_t word_count(char const *s)
{
	if (!is_input_string_valid(s))
		return 0;

	return count_words_in_string(s);
}
