#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

static void dyamically_resize_arry(size_t n)
{
	uint32_t dynamic_size_array[n];
	size_t i;

	printf("new size %zu\n", n);
	for (i = 0; i < n; i++)
		dynamic_size_array[i] = i;
		
	for (i = 0; i < n; i++)
			printf("[%zu] -> %u\n", i, dynamic_size_array[i]);
}

static void test_dynamic_array(size_t n)
{
	dyamically_resize_arry(n);
	dyamically_resize_arry(n + 1);
	dyamically_resize_arry(n + 2);
	dyamically_resize_arry(n + n);
} 

int main(int argc, char *argv[])
{
	size_t n;

	if (argc < 2) {
		printf("invalid input\n");
		return -1;
	}

	n = atoi(argv[1]);
	test_dynamic_array(n);

	return 0;
}
