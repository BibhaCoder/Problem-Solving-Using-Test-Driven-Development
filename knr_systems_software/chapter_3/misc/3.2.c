/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>
#include <string.h>

static void unescape(char const *s)
{
	size_t i, j;
	size_t len = strlen(s);
	char t[len];

	for (j = i = 0; i < len; i++, j++) {
		if (s[i] == '\\' && s[i + 1] == 't') {
			t[j] = '\t';
			i++;
		} else if (s[i] == '\\' && s[i + 1] == 'n') {
			t[j] = '\n';
			i++;
		} else {
			t[j] = s[i];
		}
	}
	t[j] = '\0';

	printf("%s:\n%s\n", __func__, t);
}

static void escape(char const *s, size_t special_chars)
{
	size_t i, j;
	size_t len = strlen(s);
	char t[len + special_chars];

	for (j = i = 0; i < len; i++) {
		switch(s[i]) {
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		default:
			t[j++] = s[i];
		}
	}
	t[j] = '\0';

	printf("%s: %s\n", __func__, t);
	unescape(t);
}

int main()
{
	char const *s = "hello\n\t\n\t\n\t\n\tworld";

	printf("%s\n", s);
	escape(s, 8);

	return 0;
}
