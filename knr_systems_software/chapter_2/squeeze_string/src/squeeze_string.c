/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/squeeze_string.h"

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *input_number)
{
	if (!input_number) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_null_terminated(input_number)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (!strlen(input_number)) {
		printf("input string with 0 length\n");
		return false;
	}

	return true;
}

static bool is_char_present(char const *s, char c)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
		if (c == s[i])
			return true;

	return false;
}

static void squeeze_input_string(char *s, char const *t)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++)
		if (!is_char_present(t, s[i]))
			s[j++] = s[i];

	s[j] = '\0';

	return;
}

int squeeze_string(char *s, char const *t)
{
	if (!is_input_string_valid(s))
		return -1;

	squeeze_input_string(s, t);

	return 0;
}
