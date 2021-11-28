/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/strcat.h"

static bool is_input_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *s)
{
	if (!s) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_valid(s)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (!strlen(s)) {
		printf("0 length string\n");
		return false;
	}

	if (strlen(s) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

static size_t get_number_of_trailing_blanks(char const *s, size_t s_len)
{
	size_t no_of_blanks = 0;

	while (s[--s_len] == ' ') {
		no_of_blanks++;
		if (!s_len)
			break;
	}

	return no_of_blanks;
}

static bool is_destination_string_big_enough(char const *s, char const *t)
{
	size_t s_len = 0;
	size_t t_len = 0;

	while (s[s_len])
		s_len++;

	while (t[t_len])
		t_len++;

	if (s_len < t_len) {
		printf("dest string is %zu < source string is %zu\n",
			s_len, t_len);
		return false;
	}

	if (get_number_of_trailing_blanks(s, s_len) < t_len) {
		printf("dest string does not have enough blanks\n");
		return false;
	}

	return true;
}

static void add_t_at_end_of_s(char *s, char const *t)
{
	size_t i = 0;
	size_t pos = 0;

	pos = strlen(s) -  get_number_of_trailing_blanks(s, strlen(s));

	while (t[i]) {
		s[pos + i] = t[i];
		i++;
	}
}

int my_strcat(char *s, char const *t)
{
	if (!is_input_valid(s))
		return -1;

	if (!is_input_valid(t))
		return -1;

	if (!is_destination_string_big_enough(s, t))
		return -1;

	add_t_at_end_of_s(s, t);

	return 0;
}
