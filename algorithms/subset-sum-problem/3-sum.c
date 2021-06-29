#include <stdio.h>
#include <stdint.h>

int32_t find_total_3_sums(uint32_t *in, uint32_t num, uint32_t sum)
{
	int count = 0;
	size_t i;
	size_t j;
	size_t k;

	if (num < 3) {
		printf("invalid input\n");
		return -1;
	}

	for (i = 0; i < num - 2; i++)
		for (j =  i + 1; j < num - 1; j++)
			for (k = j + 1; k < num; k++)
				if ((in[i] + in[j] + in[k]) == sum)
					count++;

	return count;
}

void unit_tests_3_sum()
{
	uint32_t sum = 3;
	int32_t out = 0;
	uint32_t array[] = {1, 1, 1, 1};

	out = find_total_3_sums(array, sizeof(array)/sizeof(array[0]), sum);

	if (out > 0)
		printf("found total (%u) 3-sums pairs whose sums are equal to %u\n", out, sum);
	else
		printf("No pair found\n");

}

int main()
{
	unit_tests_3_sum();

	return 0;
}

