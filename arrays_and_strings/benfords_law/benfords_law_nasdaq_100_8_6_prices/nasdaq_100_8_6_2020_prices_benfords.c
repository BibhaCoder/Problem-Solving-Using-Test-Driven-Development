#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define NUM_FIRST_DIGITS (9)

static void test_benfords_law_nasdaq_100_prices(void)
{
	uint64_t i;
	double result;
	uint64_t sum = 0;
	uint64_t nasdaq_100_stock_prices_1st_digit_count[NUM_FIRST_DIGITS + 1] =
						{0, 27, 19, 15, 13, 4, 9, 5, 6, 5};

	printf("benford's law: for august-06 2020 nasdaq 100 daily prices\n");

	for (i = 1; i <= NUM_FIRST_DIGITS; i++)
		sum += nasdaq_100_stock_prices_1st_digit_count[i];

	printf("nasdaq 100 total stock %lu\n", sum);
	for (i = 1; i <= NUM_FIRST_DIGITS; i++) {
		result = (nasdaq_100_stock_prices_1st_digit_count[i] * 100.0) / sum;
		printf("digit %lu occured %lf precent\n", i, result);
	}
}

int main()
{
	test_benfords_law_nasdaq_100_prices();

	return 0;
}
