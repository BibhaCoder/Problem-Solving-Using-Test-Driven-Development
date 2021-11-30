/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

char const *strstr(char const *s, char const *t)
{
	size_t i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; (t[k] != '\0') && (s[j] == t[k]); j++, k++)
			;
		if (k > 0 && t[k] == '\0') {
			printf("found pattern at %zd\n", i);
			return &s[i];
		}
	}

	return NULL;
}

int main(int argc, char *argv[])
{
	char const *s;

	if (argc < 2) {
		printf("missing arguement\n");
		return -1;
	}

	s = strstr(argv[1], argv[2]);
	if (s)
		printf("%s\n", s);
	else
		printf("did not found [%s] in [%s]\n", argv[2], argv[1]);

	return 0;
}

