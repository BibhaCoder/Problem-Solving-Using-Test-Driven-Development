#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE (100)

static size_t get_line(char *line, size_t limit)
{
	int c;
	size_t i;

	c = getchar();
	for (i = 0; i < (limit - 1) && (c != '`') && (c != '\n'); i++) {
		line[i] = c;
		c =  getchar();
	}

	if ('\n' == c) {
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return strlen(line);
}

static void get_longest_line(void)
{
	size_t current_line_length = 0;
	char line[MAX_LINE_SIZE];
	char longest_line[MAX_LINE_SIZE];
	size_t longest_line_length = 0;

	while ((current_line_length = get_line(line, MAX_LINE_SIZE)) > 0) {
		if (current_line_length > longest_line_length) {
			longest_line_length = current_line_length;
			strncpy(longest_line, line, longest_line_length);
		}
	}

	printf("longest input line is -> %s length %zu\n",
		longest_line, longest_line_length);
}

int main()
{
	get_longest_line();

	return 0;
}
