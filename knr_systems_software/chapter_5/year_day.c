#include <stdio.h>
#include <stdbool.h>

static char const day_table[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

static void month_day(size_t year, size_t year_day, size_t *month, size_t *day)
{
	size_t i;
	bool leap;

	leap = (((year % 4 == 0 && year % 100 != 0) ||
		 (year % 400 == 0))? true: false);

	for (i = 1; i < 13 && year_day > day_table[leap][i]; i++)
		year_day -= day_table[leap][i];

	*month = i;
	*day = year_day;
}

static void month_day_test_1(void)
{
	size_t day;
	size_t month;

	month_day(2018, 100, &month, &day);

	printf("100th day of 2018 is month %zu and day %zu\n", month, day);

	return;
}

int main()
{
	month_day_test_1();

	return 0;
}
