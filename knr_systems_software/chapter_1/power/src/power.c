#include "../inc/power.h"

uint64_t power(uint64_t num, uint8_t power)
{
	uint64_t out = 1;
	uint8_t i;

	for (i = 0; i < power; i++)
		out *= num;

	return out;
}
