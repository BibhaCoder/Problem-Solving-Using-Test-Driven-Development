#include "../inc/lower.h"
#include <stdbool.h>
#include <stddef.h>

static bool is_uper_case(char c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return true;
	else
		return false;
}

static size_t diff_between_lower_and_uper_case_char(void)
{
	return 'a' - 'A';
}

char lower(char c)
{
	if (is_uper_case(c))
		return c + diff_between_lower_and_uper_case_char();
	else
		return c;
}
