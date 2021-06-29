#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

static char *get_input(void)
{
	size_t size;
	char *str;

	printf("Enter the size of input string:");
	scanf("%zd\n", &size);

	str = malloc(size);
	if (!str) {
		printf("Failed to allocate memory for size %zd\n", size);
		return NULL;
	}

	printf("size %zd now enter input string:\n", size);
	if (NULL == fgets(str, size, stdin)) {
		printf("failed to get input\n");
		free(str);
		return NULL;
	}

	printf("Input string: %s\n", str);

	return str; 
}

static int skip_white_spaces(const char *s)
{
	const char *t = s;

	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;

	return s - t;
}

static int skip_front_start_literal(const char *s)
{
	const char *t = s;

	while (*s == '-')
		s++;

	return s - t;
}

static int find_start_literal(const char *s, uint8_t *start)
{
	if (isalnum(*s)) {
		*start = *s;
		printf("start %c\n", *start);
		return 1;
	} else {
		return -1;
	}
}

static int find_end_literal(const char *s, uint8_t *end)
{
	if (*s != '-') {
		return -1;
	} else {
		s++;
		*end = *s;
		printf("end %c\n", *end);
		return 2;
	}
}

static char *generate_string(uint8_t start, uint8_t end)
{
	int i;
	int len;
	char *out;

	if (start > end) {
		printf("invalid start %d end %d\n", start, end);
		return NULL;
	}

	len = 1 /* for \0 */ + 1 /* for - */ + end - start;
	out  = malloc(len);
	if (!out) {
		printf("Mem alloc failed\n");
		return NULL;
	}

	for (i = 0; i < len; i++)
		out[i] = start + i;

	out[i - 1] = '\0';

	return out;
}

static int parse_input(const char *s)
{
	int skip;
	char *out;
	uint8_t start, end;

	while (*s != '\0') {
		skip = skip_white_spaces(s);
		s += skip;
		skip = skip_front_start_literal(s);
		s += skip;
		skip = find_start_literal(s, &start);
		if (skip < 0)
			return -1;
		s += skip;
		skip = find_end_literal(s, &end);
		if (skip < 0)
			return -1;
		s += skip;

		out = generate_string(start, end);
		if (!out)
			return -1;
		printf("Expanded str: %s\n", out);
		free(out);
	}

	return 0;
}

int main()
{
	char *s;

	s = get_input();
	if (!s)
		return -1;

	if (parse_input(s))
		return -1;

	free(s);

	return 0;
}
