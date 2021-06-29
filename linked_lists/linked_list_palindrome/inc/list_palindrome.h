#include <stdbool.h>

struct list {
	int val;
	struct list *next;
	struct list *prev;
};

bool is_list_palindrome(struct list *l);
int insert_number(int val, struct list **head);
int destroy_list(struct list *head);
