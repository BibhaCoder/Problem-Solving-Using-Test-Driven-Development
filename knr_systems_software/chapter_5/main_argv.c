#include <stdio.h>

static void print_input_argv(int argc, char const *argv[])
{
	size_t i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc) ? " ": "");

	printf("\n");
}

int main(int argc, char const *argv[])
{
	print_input_argv(argc, argv);

	return 0;
}

