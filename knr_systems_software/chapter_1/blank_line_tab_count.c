#include <stdio.h>

static void blank_line_and_tab_count(void)
{
	int c;
	int no_of_lines = 0;
	int no_of_blanks = 0;
	int no_of_tabs = 0;

	while ((c = getchar()) != '`') {
		if (c == '\n')
			no_of_lines++;
		if (c == '\t')
			no_of_tabs++;
		if (c == ' ')
			no_of_blanks++;
	}

	printf("blanks %d tabs %d new lines %d\n",
		no_of_blanks, no_of_tabs, no_of_lines);	
}

int main()
{
	blank_line_and_tab_count();

	return 0;
}
