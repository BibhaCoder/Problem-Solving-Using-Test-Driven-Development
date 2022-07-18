/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/string_compress.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static bool is_string_valid(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_INPUT_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;
	else if (!is_string_valid(s))
		return false;
	else
		return true;
}

static void encode_compress_string(char const *s, char *t,
				   size_t s_len, size_t t_len)
{
	size_t s_index, t_index;
	size_t no_of_consecutive_chars = 0;

	for (s_index = t_index = 0; s_index < s_len; s_index++) {
		no_of_consecutive_chars++;
		if ((s_index == s_len - 1) || (s[s_index] != s[s_index + 1])) {
			t[t_index] = s[s_index];
			t[t_index + 1] = no_of_consecutive_chars + '0';
			no_of_consecutive_chars = 0;
			t_index += 2;
		}
	}

	t[t_index] = '\0';
}

static char *compress_string(char const *s)
{
	size_t input_len, output_len;
	char *output_string;

	input_len = strlen(s);
	output_len = input_len << 1;
	/* 1 extra byte for null termiator */
	output_len += 1;
	output_string = malloc(output_len);
	if (!output_string) {
		printf("failed to allocate memory for size %zu\n",
		       output_len);
		return NULL;
	}

	encode_compress_string(s, output_string, input_len, output_len);

	return output_string;
}

char *compress(char const *s)
{
	if (!is_input_string_valid(s))
		return NULL;

	return compress_string(s);
}
