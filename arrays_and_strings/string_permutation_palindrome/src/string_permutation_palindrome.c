/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include "../inc/string_permutation_palindrome.h"

#define MAX_CHARS (128)

static bool is_all_char_alphabet(char const *s)
{
	size_t i;

	for (i = 0; s[i]; i++)
		if (!isalpha(s[i]))
			return false;

	return true;
}

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

	if (!is_all_char_alphabet(s))
		return false;

	return true;
}

static size_t get_char_num(char c)
{
	return c - 'a';
}

static void toggle_char_bit(uint32_t *char_bit_map, char c)
{
	size_t pos =  get_char_num(c);

	if ((*char_bit_map) & (1 << pos))
		*char_bit_map &= (~(1 << pos));
	else
		*char_bit_map |= (1 << pos);
}

static bool is_string_perm_palindrome(char const *s)
{
	size_t i;
	uint32_t char_bit_map = 0;

	for (i = 0; s[i]; i++)
		toggle_char_bit(&char_bit_map, s[i]);

	if (!char_bit_map)
		return true;

	if (!(char_bit_map & (char_bit_map - 1)))
		return true;
	else
		return false;
}

bool is_string_permutation_palindrome(char const *s)
{
	if (!is_input_string_valid(s))
		return false;

	return is_string_perm_palindrome(s);
}
