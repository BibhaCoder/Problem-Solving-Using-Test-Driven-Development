#include "/Unity/src/unity.h"
#include "../inc/get_largest_line.h"

void setUp(void)
{
	clear_result();
}

void tearDown(void)
{
	clear_result();
}

static void test_get_largest_line(void)
{
	get_largest_line();
}

int main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_get_largest_line);

	return UNITY_END();
}
