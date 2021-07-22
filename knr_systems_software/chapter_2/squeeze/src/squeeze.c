/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/squeeze.h"

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_LINE_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *input_string)
{
	if (!input_string) {
		printf("null pointer input\n");
		return false;
	}

	if (!is_input_string_null_terminated(input_string)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (!strlen(input_string)) {
		printf("input string lenght is 0\n");
		return false;
	}

	return true;
}

static void squeeze_input_string(char *s, char c)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';

	return;
}

int squeeze(char *s, char c)
{
	if (!is_input_string_valid(s))
		return -1;

	squeeze_input_string(s, c);

	return 0;
}
