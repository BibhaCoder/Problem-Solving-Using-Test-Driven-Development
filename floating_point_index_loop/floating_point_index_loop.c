#include <stdio.h>

static void test_floating_point_limit_1(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.2)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_2(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.7)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_3(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.5)
		printf("i is %f and limit is %f\n", i, limit);

}

static void test_floating_point_limit_4(void)
{
	float const limit = 2e7;
	float i;

	for (i = limit - 10; i < limit; i += 1.0)
		printf("i is %f and limit is %f\n", i, limit);

}

int main()
{
	test_floating_point_limit_1();
	test_floating_point_limit_2();
	test_floating_point_limit_3();
	test_floating_point_limit_4();

	return 0;
}
