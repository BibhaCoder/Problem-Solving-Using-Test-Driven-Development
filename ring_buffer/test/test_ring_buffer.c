#include "/Unity/src/unity.h"
#include "../inc/ring_buffer.h"


static void invalid_test_ring_buffer_dequeue(void)
{
	int out_val = 0;

	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
}

static void valid_test_ring_buffer_enqueue_full(void)
{
	TEST_ASSERT_EQUAL_INT(0, enqueue(1));
	TEST_ASSERT_EQUAL_INT(0, enqueue(2));
	TEST_ASSERT_EQUAL_INT(0, enqueue(3));
	TEST_ASSERT_EQUAL_INT(0, enqueue(4));
	TEST_ASSERT_EQUAL_INT(0, enqueue(5));
	TEST_ASSERT_EQUAL_INT(0, enqueue(6));
	TEST_ASSERT_EQUAL_INT(0, enqueue(7));

	TEST_ASSERT_EQUAL_INT(-1, enqueue(8));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(9));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(10));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(11));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(12));
}

static void valid_test_ring_buffer_dequeue_empty(void)
{
	int out_val = 0;

	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(1, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(2, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(3, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(4, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(5, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(6, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(7, out_val);

	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
}

static void valid_test_ring_buffer_enqueue_full_1(void)
{
	TEST_ASSERT_EQUAL_INT(0, enqueue(11));
	TEST_ASSERT_EQUAL_INT(0, enqueue(12));
	TEST_ASSERT_EQUAL_INT(0, enqueue(13));
	TEST_ASSERT_EQUAL_INT(0, enqueue(14));
	TEST_ASSERT_EQUAL_INT(0, enqueue(15));
	TEST_ASSERT_EQUAL_INT(0, enqueue(16));
	TEST_ASSERT_EQUAL_INT(0, enqueue(17));

	TEST_ASSERT_EQUAL_INT(-1, enqueue(18));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(19));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(20));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(21));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(22));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(23));
	TEST_ASSERT_EQUAL_INT(-1, enqueue(24));
}

static void valid_test_ring_buffer_dequeue_empty_1(void)
{
	int out_val = 0;

	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(11, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(12, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(13, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(14, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(15, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(16, out_val);
	TEST_ASSERT_EQUAL_INT(0, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(17, out_val);

	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
	TEST_ASSERT_EQUAL_INT(-1, dequeue(&out_val));
}

int main()
{
	UNITY_BEGIN();

	RUN_TEST(invalid_test_ring_buffer_dequeue);
	RUN_TEST(valid_test_ring_buffer_enqueue_full);
	RUN_TEST(valid_test_ring_buffer_dequeue_empty);
	RUN_TEST(valid_test_ring_buffer_enqueue_full_1);
	RUN_TEST(valid_test_ring_buffer_dequeue_empty_1);

	UNITY_END();

	return 0;
}
