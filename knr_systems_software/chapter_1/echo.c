#include <stdio.h>

static void echo(void)
{
	int c;

	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}

int main()
{
	echo();

	return 0;
}
