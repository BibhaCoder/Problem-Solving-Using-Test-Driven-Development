#include <stdio.h>

static int line_count(void)
{
	int c;
	int no_of_lines = 0;

	while ((c = getchar()) != '`')
		if (c == '\n')
			no_of_lines++;

	return no_of_lines;
}

int main()
{
	printf("No of lines %d\n", line_count());

	return 0;
}
