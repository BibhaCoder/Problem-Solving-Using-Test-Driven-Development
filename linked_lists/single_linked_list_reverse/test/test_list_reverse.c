#include "../inc/list_reverse.h"
#include </Unity/src/unity.h>

static void list_reverse_invalid_input_1(void)
{
	struct list *l = NULL;

	TEST_ASSERT_NULL(list_reverse(l));
}

static void list_reverse_valid_input_1(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_2(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(2, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_3(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(2, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(3, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(3, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_4(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	status = insert_number(1, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(2, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(3, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);
	status = insert_number(4, &l);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_NOT_NULL(l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(3, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(4, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_5(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(3, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(4, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(5, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_6(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);
	insert_number(6, &l);
	insert_number(7, &l);
	insert_number(8, &l);
	insert_number(9, &l);
	insert_number(10, &l);
	insert_number(11, &l);
	insert_number(12, &l);
	insert_number(13, &l);
	insert_number(14, &l);
	insert_number(15, &l);
	insert_number(16, &l);
	insert_number(17, &l);
	insert_number(18, &l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(3, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(4, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(5, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(6, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(7, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(8, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(9, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(10, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(11, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(12, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(13, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(14, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(15, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(16, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(17, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(18, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

static void list_reverse_valid_input_7(void)
{
	struct list *l = NULL;
	struct list *h;
	int status;

	insert_number(1, &l);
	insert_number(2, &l);
	insert_number(3, &l);
	insert_number(4, &l);
	insert_number(5, &l);
	insert_number(6, &l);
	insert_number(7, &l);
	insert_number(8, &l);
	insert_number(9, &l);
	insert_number(10, &l);
	insert_number(11, &l);
	insert_number(12, &l);
	insert_number(13, &l);
	insert_number(14, &l);
	insert_number(15, &l);
	insert_number(16, &l);
	insert_number(17, &l);
	insert_number(18, &l);
	insert_number(19, &l);

	h = list_reverse(l);
	TEST_ASSERT_NOT_NULL(h);

	TEST_ASSERT_EQUAL_INT(1, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(2, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(3, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(4, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(5, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(6, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(7, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(8, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(9, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(10, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(11, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(12, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(13, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(14, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(15, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(16, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(17, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(18, h->val);
	h = h->next;
	TEST_ASSERT_EQUAL_INT(19, h->val);
	h = h->next;
	TEST_ASSERT_NULL(h);
	status = destroy_list(l);
	TEST_ASSERT_EQUAL_INT(0, status);
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(list_reverse_invalid_input_1);

	RUN_TEST(list_reverse_valid_input_1);
	RUN_TEST(list_reverse_valid_input_2);
	RUN_TEST(list_reverse_valid_input_3);
	RUN_TEST(list_reverse_valid_input_4);
	RUN_TEST(list_reverse_valid_input_5);
	RUN_TEST(list_reverse_valid_input_6);
	RUN_TEST(list_reverse_valid_input_7);

	UNITY_END();

	return 0;
}
