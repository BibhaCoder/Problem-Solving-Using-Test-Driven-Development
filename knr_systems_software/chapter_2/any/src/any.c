#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "../inc/any.h"

#define MAX_ASCII_CHAR (128)

struct char_map {
	size_t count;
	size_t index;
};

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
	size_t len;

	if (!s)
		return false;

	if (!is_input_string_valid(s))
		return false;

	len = strlen(s);

	if (!len)
		return false;

	if (len >= MAX_INPUT_LINE_SIZE)
		return false;

	return true;
}

static bool is_char_found_in_string(char c, char const *s, ssize_t *pos)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++) {
		if (c == s[i]) {
			*pos = i;
			return true;
		}
	}

	return false;
}

static ssize_t any_search(char const *s, char const *t)
{
	size_t i;
	ssize_t pos = -1;

	for (i = 0; t[i] != '\0'; i++)
		if (is_char_found_in_string(t[i], s, &pos))
			return pos;

	return pos;
}

static void print_char_hash_map(struct char_map *map)
{
	int i;

	for (i = 0; i < MAX_ASCII_CHAR; i++)
		if (map[i].count)
			printf("char %c count %zu index %zu\n",
				i, map[i].count, map[i].index);
}

static void add_string_in_hash_map(struct char_map *map, char const *s)
{
	size_t i, pos;

	for (i = 0; s[i]; i++) {
		pos = s[i] - '\0';
		if (!map[pos].count)
			map[pos].index = i;
		map[pos].count++;
	}
}

static bool is_char_present_in_hash_map(struct char_map const *map, char c,
					ssize_t *index)
{
	size_t pos = c - '\0';

	if (map[pos].count) {
		*index = map[pos].index;
		return true;
	} else {
		return false;
	}
}

static ssize_t any_search_using_char_hash_map(char const *s, char const *t)
{
	size_t i;
	ssize_t index;
	struct char_map map[MAX_ASCII_CHAR] = {{0, 0}};

	add_string_in_hash_map(map, s);

	print_char_hash_map(map);

	for (i = 0; t[i]; i++)
		if (is_char_present_in_hash_map(map, t[i], &index))
			return index;

	return -1;
}

ssize_t any(char const *s, char const *t)
{
	if (!is_input_valid(s))
		return -1;

	if (!is_input_valid(t))
		return -1;

	/* return any_search(s, t); */
	return any_search_using_char_hash_map(s, t);
}
