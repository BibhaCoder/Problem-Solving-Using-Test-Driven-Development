/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define MAX_STRING_SIZE (100)

static char s[MAX_STRING_SIZE];
static char symbol_array[MAX_STRING_SIZE];

static uint64_t get_total_possible_combinations(uint64_t n)
{
	uint64_t val = 2;
	uint64_t i = 1;

	while (i < n) {
		val *= 2;
		i++;
	}

	return val;
}

static void generate_all_possible_patterns(uint64_t max_combinations,
						uint64_t total_symbols)
{
	size_t i;
	size_t j;

	printf("%lu %lu\n", max_combinations, total_symbols);
	for (i = 0; i < max_combinations; i++) {
		for (j = 0; j < total_symbols; j++) {
			if (i & (1 << j))
				s[symbol_array[j]] = '1';
			else
				s[symbol_array[j]] = '0';
		}
	//	printf("[%zu] -> %s\n", i, s);
	}
}

static int64_t find_all_interested_symbols_and_store_their_position(char symbol)
{
	int64_t i = 0;
	size_t j = 0;
	int total_symbol = 0;

	printf("%s\n", s);
	i = strlen(s) - 1;
	while (i >= 0) {
		if (symbol == s[i]) {
			total_symbol++;
			symbol_array[j++] = i;
		}
		i--;
	}

	return total_symbol;
}

static void get_input(void)
{
	printf("Enter input string:");
	fgets(s, MAX_STRING_SIZE, stdin);
	printf("Input string is %s\n", s);
}

static void generate_ouput(uint64_t total_combinations, uint64_t total_symbols)
{
	clock_t t;
	double time_taken;

	t = clock();
	generate_all_possible_patterns(total_combinations, total_symbols);
	t = clock() - t;

	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("Iterative pattern generation took %f seconds to execute for %lu combinations\n",
		time_taken, total_combinations);
}

static void generate_iterative_all_patterns(void)
{
	uint64_t n;
	uint64_t total_combinations;

	n = find_all_interested_symbols_and_store_their_position('?');
	if (0 == n) {
		printf("No pattern found\n");
		return;
	}
	total_combinations = get_total_possible_combinations(n);
	generate_ouput(total_combinations, n);
}

static void generate_all_pattern(char *s, ssize_t index)
{
	if (!s)
		return;

	if (index < 0) {
	//	printf("%s\n", s);
		return;
	}

	if (s[index] == '?') {
		s[index] = '0';
		generate_all_pattern(s, index - 1);

		s[index] = '1';
		generate_all_pattern(s, index - 1);

		s[index] = '?';
	} else {
		generate_all_pattern(s, index - 1);
	}
}

static void generate_recursive_all_patterns(void)
{

        clock_t t;
        double time_taken;

        t = clock();
	generate_all_pattern(s, strlen(s) - 1);	
        t = clock() - t;

        time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("Recursive pattern generation took %f seconds to execute for input %s\n",
		time_taken, s);
}

int main()
{
	get_input();
	generate_recursive_all_patterns();
	generate_iterative_all_patterns();

	return 0;
}
