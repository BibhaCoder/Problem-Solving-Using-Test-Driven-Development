#include "../inc/is_perm_palindrome.h"
#include <stddef.h>
#include <stdint.h>

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
	else if (!is_string_null_terminated(s))
		return false;
	else
		return true;
}

static void toggle_bit(uint32_t *bitmap, int pos)
{
	size_t mask = 1 << pos;

	if ((*bitmap) & (mask))
		*bitmap &= ~mask;
	else
		*bitmap |= mask;
}

static bool is_extactly_one_bit_set(uint32_t bitmap)
{
	if (!(bitmap & (bitmap - 1)))
		return true;
	else
		return false;
}

static bool __is_perm_palindrome(char const *s)
{
	size_t i;
	uint32_t char_bit_map = 0;

	for (i = 0; s[i]; i++)
		toggle_bit(&char_bit_map, s[i] - '\0');

	/*
	 * string is only palindrome is it has:
	 * 1) all even number of characters OR
	 * 2) exactly only 1 odd no of character
	 */
	if (!char_bit_map)
		return true;
	else if (is_extactly_one_bit_set(char_bit_map))
		return true;
	else
		return false;
}

bool is_perm_palindrome(char const *s)
{
	if (!is_input_string_valid(s))
		return false;

	return __is_perm_palindrome(s);
}
