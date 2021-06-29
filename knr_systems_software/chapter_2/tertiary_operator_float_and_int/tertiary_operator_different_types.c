#include <stdio.h>

static int tertiary_operator_test()
{
	int a = -1;
	int b = 2.14;
	float f = 3.14;

	/* as per c type conversion rules this tertiary expression is float */
	printf("result is %d\n", (a > 0) ? f : b);

	return 0;
}

int main()
{
	tertiary_operator_test();

	return 0;
}
