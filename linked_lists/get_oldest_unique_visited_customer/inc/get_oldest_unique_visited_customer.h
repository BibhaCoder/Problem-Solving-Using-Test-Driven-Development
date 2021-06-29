#include <stdint.h>

#define MAX_NUM_CUSTOMERS (100000001)

int visit_service(uint32_t customer_id);
int get_oldest_unique_visited_customer(void);
int reset_customer_visits(void);
