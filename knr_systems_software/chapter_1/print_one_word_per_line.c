/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

#include <stdio.h>

enum cursor_position {
	inside_word,
	outside_word,
};

static void word_count()
{
	int c;
	size_t no_of_words = 0;
	size_t no_of_characters = 0;
	enum cursor_position pos = outside_word;

	while ((c = getchar()) != '`') {
		no_of_characters++;

		if (c == ' ' || c == '\t' || c == '\n')
			pos = outside_word;

		else if (pos == outside_word) {
			no_of_words++;
			pos = inside_word;
		}
	}

	printf("number of characters %zu\n", no_of_characters);
	printf("number of words %zu\n", no_of_words);
}

int main()
{
	word_count();

	return 0;
}
