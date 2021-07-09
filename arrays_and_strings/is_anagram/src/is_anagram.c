#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include "../inc/is_anagram.h"

#define MAX_UNIQUE_ASCII_CHARS (256)

static bool is_input_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i <= MAX_STRING_LENGTH; i++)
		if (s[i] == '\0')
			return true;

	return false;
}

static int get_char_asci_index(char c)
{
	return c - '\0';
}

static bool is_input_string_has_valid_ascii_chars(char const *s)
{
	size_t i;
	int ascii_char_index;

	for (i = 0; s[i]; i++) {
		ascii_char_index = get_char_asci_index(s[i]);
		if (ascii_char_index < 0)
			return false;
		if (ascii_char_index >= MAX_UNIQUE_ASCII_CHARS)
			return false;
	}

	return true;
}

static bool is_input_string_valid(char const *s)
{
	if (!s)
		return false;
	else if (!is_input_string_null_terminated(s))
		return false;
	else if (!is_input_string_has_valid_ascii_chars(s))
		return false;
	else
		return true;
}

static void add_in_char_map(ssize_t *char_map, char const *s)
{
	size_t i;
	int index;

	for (i = 0; s[i]; i++) {
		index = get_char_asci_index(s[i]);
		char_map[index]++;
	}
}

static void delete_from_char_map(ssize_t *char_map, char const *s)
{
	size_t i;
	int index;

	for (i = 0; s[i]; i++) {
		index = get_char_asci_index(s[i]);
		char_map[index]--;
	}
}

static bool __is_anagram(ssize_t const *char_map)
{
	size_t i;

	for (i = 0; i < MAX_UNIQUE_ASCII_CHARS; i++)
		if (char_map[i])
			return false;

	return true;
}

static bool is_string_a_permutation(char const *s, char const *t)
{
	ssize_t char_map[MAX_UNIQUE_ASCII_CHARS] = {0, };

	if (strlen(s) != strlen(t))
		return false;

	add_in_char_map(char_map, s);
	delete_from_char_map(char_map, t);

	return __is_anagram(char_map);
}

static bool is_string_a_permutation_optimized(char const *s, char const *t)
{
	size_t i;
	int index;
	ssize_t char_hash_map[MAX_UNIQUE_ASCII_CHARS] = {0, };

	if (strlen(s) != strlen(t))
		return false;

	for (i = 0; s[i]; i++) {
		index = get_char_asci_index(s[i]);
		char_hash_map[index]++;
	}

	for (i = 0; t[i]; i++) {
		index = get_char_asci_index(t[i]);
		char_hash_map[index]--;
		if (char_hash_map[index] < 0)
			return false;
	}

	return true;
}

bool is_anagram(char const *s, char const *t)
{
	if (!is_input_string_valid(s))
		return false;

	if (!is_input_string_valid(t))
		return false;

	return is_string_a_permutation_optimized(s, t);
}
