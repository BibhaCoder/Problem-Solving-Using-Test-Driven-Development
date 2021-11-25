/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include "../inc/one_away.h"
#include <string.h>
#include <stddef.h>

#define ABS_DIFF(a, b) (a > b ? (a - b) : (b - a))

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if ('\0' == s[i])
			return true;

	return false;
}

static bool is_input_valid(char const *s, char const *t)
{
	if (!s || !t)
		return false;
	else if (!is_string_null_terminated(s))
		return false;
	else if (!is_string_null_terminated(s))
		return false;
	else if (ABS_DIFF(strlen(s), strlen(t)) >= 2)
		return false;
	else
		return true;
}

static bool
is_non_equal_length_string_one_insert_away(char const *big_str,
					   char const *small_str,
					   size_t big_len,
					   size_t small_len)
{
	size_t small_str_index = 0;
	size_t big_str_index = 0;

	while (small_str_index < small_len) {
		if (small_str[small_str_index] != big_str[big_str_index]) {
			if (small_str_index != big_str_index)
				return false;
			else
				big_str_index++;
		} else {
			small_str_index++;
			big_str_index++;
		}
	}

	return true;
}

static bool
is_equal_length_string_one_edit_away(char const *s,
				     char const *t,
				     size_t size)
{
	size_t index;
	bool diff_found = false;

	for (index = 0; index < size; index++) {
		if (s[index] != t[index]) {
			if (diff_found)
				return false;
			else
				diff_found = true;
		}
	}

	return true;
}

static bool are_input_strings_one_edit_away(char const *s, char const *t)
{
	size_t s_len, t_len;

	s_len = strlen(s);
	t_len = strlen(t);

	if (s_len == t_len)
		return is_equal_length_string_one_edit_away(s, t, s_len);
	else if (s_len > t_len)
		return is_non_equal_length_string_one_insert_away(s, t,
								  s_len, t_len);
	else
		return is_non_equal_length_string_one_insert_away(t, s,
								  t_len, s_len);
}

bool is_one_edit_away(char const *s, char const *t)
{
	if (!is_input_valid(s, t))
		return false;

	return are_input_strings_one_edit_away(s, t);
}
