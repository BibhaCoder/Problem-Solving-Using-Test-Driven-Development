#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool test_strend(char const *s, char const *t)
{
	if (strlen(s) < strlen(t))
		return false;

	s = s + strlen(s) - strlen(t);

	while ((*s++ == *t++))
		if (*t == '\0')
			return true;

	return false;
}

static void test_1_str_end_pointer_version(void)
{
	char *s = "12345";
	char *t = "345";
	bool is_found;

	is_found = test_strend(s, t);
	printf("s: %s t: %s found: %d\n", s, t, is_found);
}

static void test_2_str_end_pointer_version(void)
{
	char *s = "12345";
	char *t = "45";
	bool is_found;

	is_found = test_strend(s, t);
	printf("s: %s t: %s found: %d\n", s, t, is_found);
}

static void test_3_str_end_pointer_version(void)
{
	char *s = "12345";
	char *t = "5";
	bool is_found;

	is_found = test_strend(s, t);
	printf("s: %s t: %s found: %d\n", s, t, is_found);
}

static void test_4_str_end_pointer_version(void)
{
	char *s = "12345";
	char *t = "6";
	bool is_found;

	is_found = test_strend(s, t);
	printf("s: %s t: %s found: %d\n", s, t, is_found);
}

static void test_5_str_end_pointer_version(void)
{
	char *s = "12345";
	char *t = "0123456789";
	bool is_found;

	is_found = test_strend(s, t);
	printf("s: %s t: %s found: %d\n", s, t, is_found);
}

int main()
{
	test_1_str_end_pointer_version();
	test_2_str_end_pointer_version();
	test_3_str_end_pointer_version();
	test_4_str_end_pointer_version();
	test_5_str_end_pointer_version();

	return 0;
}
