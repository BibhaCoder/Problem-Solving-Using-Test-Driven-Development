#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FIRST_DIGITS (9)
#define MAX_NUM (1000000000000)

static uint64_t extract_first_digit(uint64_t n)
{
	while (n > 9)
		n = n / 10;

	return n;
}

static uint64_t get_64_bit_random_num(void)
{
	uint8_t shift_size =  sizeof(uint32_t) * CHAR_BIT;
	uint64_t out = 0;

	out = ((uint32_t)rand() << shift_size) | ((uint32_t)rand());

	return out;
}

static void test_benfords_law(void)
{
	uint64_t i;
	time_t t;
	double result;
	uint64_t first_digit;
	uint64_t random_num;
	uint64_t first_digit_count[NUM_FIRST_DIGITS + 1] = {0, };

	srand((unsigned) time(&t));

	printf("RAND_MAX is %d\n", RAND_MAX);
	printf("benford's law: for %ld random numbers\n", MAX_NUM);
	for (i = 0; i < MAX_NUM; i++) {
		random_num = get_64_bit_random_num();
		first_digit = extract_first_digit(random_num);
		first_digit_count[first_digit]++;
	}

	for (i = 1; i <= NUM_FIRST_DIGITS; i++) {
		result = (first_digit_count[i] * 100.0) / (MAX_NUM);
		printf("digit %lu occured %lf precent\n", i, result);
	}
}

int main()
{
	test_benfords_law();

	return 0;
}
