#include <stdio.h>
#include <string.h>

static void str_reverse(char *s)
{
	char c;
	size_t i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;

	printf("%s\n", s);
}

int main()
{
	char test[] = "0123456789";

	printf("%s\n", test);
	str_reverse(test);

	return 0;
}
