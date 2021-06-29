#include <stdint.h>

#define MAX_INPUT_VAL (100)

struct list {
	int32_t val;
	struct list *next;
};

int add_item(struct list **head, uint8_t n);
int remove_duplicates(struct list *l);
int assert_no_duplicates(struct list *head);
int destroy_items(struct list *l);
