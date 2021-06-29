#include "../inc/expand.h"
#include "/Unity/src/unity.h"

static void test_invalid_input_exapand_0(void)
{
	char const *s = NULL;

	TEST_ASSERT_NULL(expand(s));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_invalid_input_exapand_0);

	UNITY_END();

	return 0;
}
