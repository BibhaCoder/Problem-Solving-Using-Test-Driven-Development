#include <stdio.h>

void test(void)
{
	char s[10] = "hello";

	printf("%.*s\n", 2, s);
}

int main()
{
	test();
	return 0;
}
