/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE (128)

static void delete_from_char_hash_map(ssize_t *hash_map, char const *s,
				      size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
		hash_map[s[i] - '\0']--;
}

static void add_into_char_hash_map(ssize_t *hash_map, char const *s,
				   size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
		hash_map[s[i] - '\0']++;
}

static void print_substring(char const *s, size_t start, size_t end)
{
	size_t i;

	printf("found permuatation substring at index %zu:\n", start);
	for (i = start ; i < end; i++)
		printf("%c", s[i]);

	printf("\n");
}

static bool is_permutation(ssize_t const *char_hash_map)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if (char_hash_map[i])
			return false;

	return true;
}

static bool is_substring_a_permutation(char const *b, char const *s,
				       size_t start, size_t limit)
{
	ssize_t char_hash_map[MAX_STRING_SIZE] = {0,};

	add_into_char_hash_map(char_hash_map, b, start, start + limit);
	delete_from_char_hash_map(char_hash_map, s, 0, limit);

	return is_permutation(char_hash_map);
}

static void print_all_substring_permutation(char const *b, size_t b_len,
					    char const *s, size_t s_len)
{
	size_t i, limit;

	limit = b_len - s_len;
	printf("limit %zu\n", limit);
	for (i = 0; i <= limit; ) {
		if (is_substring_a_permutation(b, s, i, s_len)) {
			print_substring(b, i, i + s_len);
			i += s_len;
		} else {
			i++;
		}
	}
}

static bool is_string_null_terminated(char const *s)
{
	size_t i;

	for (i = 0; i < MAX_STRING_SIZE; i++)
		if (!s[i])
			return true;

	return false;
}

static void find_all_substring_permutation(char const *b, char const *s)
{
	size_t b_len, s_len;

	if (!b || !is_string_null_terminated(b))
		return;
	if (!s || !is_string_null_terminated(s))
		return;

	b_len = strlen(b);
	s_len = strlen(s);
	if (b_len < s_len)
		return;

	print_all_substring_permutation(b, b_len, s, s_len);
}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		printf("invalid input. substring_permutation <big_string> <small_string>");
		return -1;
	}

	find_all_substring_permutation(argv[1], argv[2]);

	return 0;
}
