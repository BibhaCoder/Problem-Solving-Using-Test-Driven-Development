#include <stdio.h>

int main()
{
	char c = 255;

	if (c > 128)
		printf("char is unsigned\n");
	else
		printf("char is signed\n");

	return 0;
}
