#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void str_cpy(char *s, char const *t)
{
	while (*t) {
		*s = *t;
		s++;
		t++;
	}
}

static char *str_cat(char const *s, char const *t)
{
	size_t len;
	char *p;

	len = strlen(s) + strlen(t) + 1;
	p = malloc(len);
	if (!p)
		return NULL;

	memset(p, 0, len);
	str_cpy(p, s);
	str_cpy(p + strlen(p), t);

	return p;
}

int main()
{
	char *s = "hello";
	char *t = "world";
	char *p;

	p = str_cat(s, t);
	if (!p)
		return -1;

	printf("%s\n", p);
	free(p);

	return 0;
}
