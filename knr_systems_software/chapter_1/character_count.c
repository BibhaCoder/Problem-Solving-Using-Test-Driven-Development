#include <stdio.h>

static size_t count_characters(void)
{
	int c;
	size_t total_characters = 0;

	while ((c = getchar()) != '`')
		total_characters++;

	return total_characters;
}

int main()
{
	printf("found total %lu characters\n", count_characters());

	return 0;
}
