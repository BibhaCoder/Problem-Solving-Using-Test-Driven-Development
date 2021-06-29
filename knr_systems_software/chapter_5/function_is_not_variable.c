#include <stdio.h>
#include <stdint.h>

static void test_func(uint32_t n)
{
	printf("hi i am called with %d\n", n);
}

static void function_test(void)
{
	void (*function_pointer)(uint32_t);

	function_pointer = test_func;

	function_pointer(1);
	function_pointer(2);
	function_pointer(3);
	function_pointer(4);
	function_pointer(5);
}

int main()
{
	function_test();

	return 0;
}
