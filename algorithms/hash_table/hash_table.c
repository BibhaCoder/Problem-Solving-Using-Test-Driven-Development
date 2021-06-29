#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HASH_TABLE_SIZE (10)
#define INPUT_TIMES (1)

struct hash_table {
	uint32_t val;
	struct hash_table *next;
};

static struct hash_table *hash_map[MAX_HASH_TABLE_SIZE] = {NULL, };

static uint32_t hash(uint32_t key)
{
	return (key % MAX_HASH_TABLE_SIZE);
}

static struct hash_table *lookup(uint32_t key)
{
	struct hash_table *t;

	for (t = hash_map[hash(key)]; NULL != t; t = t->next) {
		if (key == t->val) {
			printf("found key %u at hash index %u\n", key, hash(key));
			return t;
		}
	}

	printf("did not find %u in table\n", key);

	return NULL;
}

static void install(uint32_t key)
{
	uint32_t i;
	struct hash_table *t;

	i = hash(key);
	t = hash_map[i];

	t = malloc(sizeof(*t));
	if (!t)
		return;

	t->val = key;
	t->next = hash_map[i];
	hash_map[i] = t;
}

static void delete(uint32_t key)
{
	uint32_t i;
	struct hash_table *t;

	i = hash(key);
	t = hash_map[i];
	if (!t)
		return;

	hash_map[i] = t->next;
	free(t);
}

static void generate_hash_input(void)
{
	size_t i;
	uint32_t val;
	time_t t;

	srand((unsigned) time(&t));

	for (i = 0; i < (INPUT_TIMES * MAX_HASH_TABLE_SIZE); i++) {
		val = rand() % MAX_HASH_TABLE_SIZE;
		install(val);
	}
}

static void print_hash_map(void)
{
	size_t i;
	struct hash_table *t;

	for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
		t = hash_map[i];
		printf("(%zu)->", i);
		while (t) {
			printf("[%u]->", t->val);
			t = t->next;
		}
		printf("NULL\n");
	}
}

static void free_hash_map(void)
{
	size_t i;
	struct hash_table *t;
	struct hash_table *p;

	for (i = 0; i < MAX_HASH_TABLE_SIZE; i++) {
		t = hash_map[i];
		while (t) {
			p = t;
			t = t->next;
			free(p);
		}
	}
}

static void run_hash_map_tests(void)
{
	uint32_t val;
	uint32_t choice;

	while (1) {
		printf("\n0 for install\n1 for lookup\n2 for delete\n3 for exit:");
		scanf("%u", &choice);
		switch (choice) {
		case 0:
			printf("enter value install in hash map:");
			scanf("%u", &val);
			install(val);
			print_hash_map();
			break;
		case 1:
			printf("enter value to look up in hash map:");
			scanf("%u", &val);
			lookup(val);
			print_hash_map();
			break;
		case 2:
			printf("enter value to delete from hash map:");
			scanf("%u", &val);
			delete(val);
			print_hash_map();
			break;
		case 3:
		default:
			free_hash_map();
			printf("good bye\n");
			return;
		}
	}
}

static void hash_map_tests(void)
{
	generate_hash_input();
	print_hash_map();
	run_hash_map_tests();
}

int main()
{
	hash_map_tests();

	return 0;
}
