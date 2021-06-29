#include <stdint.h>

struct list {
	int32_t val;
	struct list *next;
};

int add_item(struct list **head, uint8_t n);
int return_kth_to_last(struct list *head, uint32_t k);
int destroy_items(struct list *head);
