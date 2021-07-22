/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/count_digits_whites_others.h"

static bool is_string_null_terminated_valid(char const *s)
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

	if (!is_string_null_terminated_valid(input_string)) {
		printf("invalid string with no null terminator\n");
		return false;
	}

	if (strlen(input_string) >= MAX_INPUT_LINE_SIZE) {
		printf("input string longer than allowed size %d\n",
			MAX_INPUT_LINE_SIZE);
		return false;
	}

	return true;
}

static bool is_it_digit(char c)
{
	if ('0' <= c && c <= '9')
		return true;

	return false;
}

static bool is_it_white(char c)
{
	if (c == ' ' || c == 't' || c == 'n')
		return true;

	return false;
}

static void count_individual_chars(char const *s,
				   struct digits_whites_others *t)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++) {
		if (is_it_digit(s[i]))
			t->digits++;
		else if (is_it_white(s[i]))
			t->whites++;
		else
			t->others++;
	}
}

ssize_t count_digits_whites_others(char const *s, struct digits_whites_others *t)
{
	if (!is_input_string_valid(s))
		return -1;

	if (!t)
		return -1;

	count_individual_chars(s, t);

	return 0;
}
