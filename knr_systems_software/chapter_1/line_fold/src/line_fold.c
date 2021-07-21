/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/line_fold.h"

enum cursor_position {
	inside_word,
	outside_word
};

static void copy_remaining_chars_from_input_line(char *t, char const *s)
{
	size_t i = 0;
	size_t j = 0;

	for (i = j = 0; '\0' != s[i]; i++, j++)
		if ('\n' != t[j])
			t[j] = s[i];
}

static size_t find_desired_position(char const *s, ssize_t pos)
{
	char c;
	enum cursor_position cursor_pos = inside_word;
	size_t desired_position = pos;

	if (!pos)
		return 0;

	while (desired_position) {
		desired_position--;
		c = s[desired_position];
		if (isspace(c))
			cursor_pos = outside_word;
		if (!isspace(c) && (cursor_pos == outside_word))
			break;
	}

	if (!desired_position)
		return 0;

	return ++desired_position;
}

static void insert_new_lines(char *t, char const *s,
			     size_t no_of_required_new_lines)
{
	char c = 0;
	size_t pos = 0;
	size_t desired_pos = 0;
	size_t inserted_new_lines = 0;

	while (inserted_new_lines < no_of_required_new_lines) {
		pos += LINE_FOLD_LIMIT;
		desired_pos = pos - 1;
		c = s[desired_pos];
		if (isspace(c)) {
			t[desired_pos] = '\n';
		} else {
			desired_pos = find_desired_position(s, desired_pos);
			if (desired_pos)
				t[desired_pos] = '\n';
		}
		inserted_new_lines++;
	}
}

static size_t get_required_new_lines(size_t input_string_length)
{
	return input_string_length / LINE_FOLD_LIMIT;
}

static bool is_input_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *input_line)
{
	if (!input_line) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_valid(input_line)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (strlen(input_line) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

static char *allocate_memory_for_output_string(char const *input_line,
					     size_t needed_newline_inserts)
{
	char *out;
	size_t input_string_length;
	size_t output_string_length;

	input_string_length = strlen(input_line);
	/* +1 for null terminator */
	output_string_length = input_string_length + needed_newline_inserts + 1;
	out = malloc(output_string_length);
	if (!out) {
		printf("failed to allocate memory for size %zu\n",
			output_string_length);
		return NULL;
	}
	memset(out, 0, output_string_length);

	return out;
}

char *line_fold(char const *input_line)
{
	char *output_line;
	size_t needed_newline_inserts;

	if (!is_input_valid(input_line))
		return NULL;

	needed_newline_inserts = get_required_new_lines(strlen(input_line));
	output_line = allocate_memory_for_output_string(input_line,
							needed_newline_inserts);
	if (!output_line)
		return NULL;

	if (!needed_newline_inserts) {
		memcpy(output_line, input_line, strlen(input_line));
		return output_line;
	}

	insert_new_lines(output_line, input_line, needed_newline_inserts);
	copy_remaining_chars_from_input_line(output_line, input_line);

	return output_line;
}
