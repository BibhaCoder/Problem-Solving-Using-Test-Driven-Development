/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
	int sum, carry;

	while (b) {
		sum = a ^ b;
		carry = (a & b) << 1;

		a = sum;
		b = carry;
	}

	return a;
}

int main(int argc, char *argv[])
{
	int a, b;
	int sum;

	if (argc < 3) {
		printf("invalida rguement: a.out num1 num2\n");
		return -1;
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	sum = add(a, b);
	printf("%d + %d = %d without using addition and only using bit wise opearators\n",
		a, b, sum);

	return 0;
}
