#include <stdio.h>

static void replace_space(void)
{
	putchar('\\');
	putchar('b');
}

static void replace_new_line(void)
{
	putchar('\\');
	putchar('n');
}

static void replace_tab(void)
{
	putchar('\\');
	putchar('t');
}

static void process_character(int c)
{
	switch (c) {
	case ' ':
		replace_space();
		break;
	case '\n':
		replace_new_line();
		break;
	case '\t':
		replace_tab();
		break;
	default:
		putchar(c);
		break;
	}
}

static void replace_balnk_space_by_symbols(void)
{
	int c;

	while ((c = getchar()) != EOF)
		process_character(c);
}

int main()
{
	replace_balnk_space_by_symbols();

	return 0;
}
