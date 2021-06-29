#include <stdbool.h>

struct list {
	int val;
	struct list *next;
};
struct list *list_reverse(struct list *l);
int insert_number(int val, struct list **head);
int destroy_list(struct list *head);
