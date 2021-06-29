#include "/Unity/src/unity.h"
#include "../inc/hello_world.h"
#include <string.h>

static void test_null_pointer_hello_world(void)
{
	int status;
        char *input_string = NULL;

        status = hello_world(input_string);

        TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_very_large_non_null_terminated_hello_world(void)
{
	int status;
        char input_string[] = "its a very large string buffer bigger than max allowed size";

        status = hello_world(input_string);

        TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_very_small_null_terminated_hello_world(void)
{
	int status;
        char input_string[] = "small";

        status = hello_world(input_string);

        TEST_ASSERT_EQUAL_INT(-1, status);
}

static void test_valid_all_lower_case_hello_world(void)
{
	int status;
        char input_string[] = "its my input buffer";
        char const *expected_output_string = "hello, world";

        status = hello_world(input_string);

        TEST_ASSERT_EQUAL_INT(0, status);
        TEST_ASSERT_EQUAL_STRING_LEN(expected_output_string, input_string,
				     strlen(expected_output_string));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_null_pointer_hello_world);
	RUN_TEST(test_very_large_non_null_terminated_hello_world);
	RUN_TEST(test_very_small_null_terminated_hello_world);

	RUN_TEST(test_valid_all_lower_case_hello_world);

	return UNITY_END();
}
