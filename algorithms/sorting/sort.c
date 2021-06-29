#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define INPUT_MAX_SIZE (1000000)

enum sort_algorithm {
	bubble_sorting,
	selection_sorting,
	insertion_sorting,
	shell_sorting,
	quick_sorting,
	three_way_quick_sorting,
	merge_sorting,
	count_sorting,
	max_sorting_enum
};

static uint32_t input[INPUT_MAX_SIZE];
static uint32_t input_1[INPUT_MAX_SIZE];
static uint32_t input_2[INPUT_MAX_SIZE];
static uint32_t input_3[INPUT_MAX_SIZE];
static uint32_t input_4[INPUT_MAX_SIZE];
static uint32_t input_5[INPUT_MAX_SIZE];
static uint32_t input_6[INPUT_MAX_SIZE];
static uint32_t input_7[INPUT_MAX_SIZE];
static uint32_t count_array[INPUT_MAX_SIZE];

static uint32_t auxilary[INPUT_MAX_SIZE];
static bool is_print_enabled = false;

static void print_array(uint32_t *a, size_t size)
{
	size_t i;

	if (!is_print_enabled)
		return;

	for (i = 0; i < size; i++)
		printf("[%u]->", a[i]);
	printf("\n");
}

static void swap(uint32_t *a, size_t i, size_t j)
{
	uint32_t temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

static void bubble_sort(uint32_t *a, size_t n)
{
	size_t i ,j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a, j , j + 1);
	}
}

static void selection_sort(uint32_t *a, size_t n)
{
	size_t i ,j;
	size_t min;

	for (i = 0; i < n; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(a, i, min);
	}
}

static void insertion_sort(uint32_t *a, size_t n)
{
	ssize_t i ,j;

	for (i = 0; i < n; i++) {
		for (j = i; j > 0; j--) {
			if (a[j] < a[j - 1])
				swap(a, j, j - 1);
			else
				break; /* this break gives best case O(n) */
		}
	}
}

static void shell_sort(uint32_t *a, size_t n)
{
	size_t h;
	int32_t i ,j;

	h = 1;
	while (h < n)
		h = 3 * h + 1;

	while (h >= 1) {
		for (i = h; i < n; i++) {
			for (j = i; j >= h; j = j - h) {
				if (a[j] < a[j - h])
					swap(a, j, j - h);
				else
					break; /* this break gives best case O(n) */
			}
		}
		h = h / 3;
	}
}

static void quick_sort(uint32_t *a, int32_t left, int32_t right)
{
	size_t i;
	size_t last;

	if (left >= right)
		return;

	swap(a, left, (left + ((right - left) >> 1)));

	last = left;
	for (i = left + 1; i <= right; i++)
		if (a[i] < a[left])
			swap(a, ++last, i);

	swap(a, left, last);
	quick_sort(a, left, last - 1);
	quick_sort(a, last + 1, right);
}

static int quick_compare(uint32_t p, uint32_t q)
{
	return p - q;
}

static void three_way_quick_sort(uint32_t *a, int32_t lo, int32_t hi)
{
	size_t i;
	int32_t key, lt = lo, gt = hi, compare_output;

	if (lo >= hi)
		return;

        key = a[lo];
        i = lo;
        while (i <= gt) {
                compare_output = quick_compare(a[i], key);
                if (compare_output < 0)
                        swap(a, lt++, i++);
                else if (compare_output > 0)
                        swap(a, i, gt--);
                else
                        i++;
        }

	three_way_quick_sort(a, lo, lt - 1);
	three_way_quick_sort(a, gt + 1, hi);
}

static void merge(uint32_t *a, uint32_t *aux, size_t l, size_t m, size_t r)
{
	size_t i, j ,k;

	for (k = l; k <= r; k++)
		aux[k] = a[k];

	i = l;
	j = m + 1;

	for (k = l; k <= r; k++) {
		if (i > m)
			a[k] = aux[j++];
		else if (j > r)
			a[k] = aux[i++];
		else if (aux[i] < aux[j])
			a[k] = aux[i++];
		else
			a[k] = aux[j++];
	}
}

static void merge_sort(uint32_t *a, uint32_t *aux, size_t l, size_t r)
{
	size_t m;

	if (l >= r)
		return;

	m = l + ((r - l) >> 1);
	merge_sort(a, aux, l, m);
	merge_sort(a, aux, m + 1, r);
	/* this gives O(N) liner runtime for already sorted array */
	if (a[m + 1] > a[m])
		return;
	merge(a, aux, l, m, r);
}

static void generate_input(size_t n)
{
	time_t t;
	size_t i = 0;

	srand((unsigned) time(&t));

	while (i < n) {
		input[i] = rand() % n;
		input_1[i] = input[i];
		input_2[i] = input[i];
		input_3[i] = input[i];
		input_4[i] = input[i];
		input_5[i] = input[i];
		input_6[i] = input[i];
		input_7[i] = input[i];
		i++;
	}
}

static void shuffle_sorted_output(uint32_t *a, size_t n)
{
	size_t i;
	size_t r;
	time_t t;

	srand((unsigned) time(&t));

	for (i = 0; i < n; i++) {
		r = rand() % (i + 1);
		swap(a, i, r);
	}

	printf("random shuffled ouput is:\n");
	print_array(a, n);
}

static char const *sort_name(enum sort_algorithm e)
{
	switch (e) {
	case bubble_sorting:
		return "bubble sorting";
	case selection_sorting:
		return "selection sorting";
	case insertion_sorting:
		return "insertion sorting";
	case shell_sorting:
		return "shell sorting";
	case quick_sorting:
		return "quick sorting";
	case three_way_quick_sorting:
		return "three_way_quick sorting";
	case merge_sorting:
		return "merge sorting";
	case count_sorting:
		return "count sorting";
	default:
		printf("unknown sortign algorithm\n");
		return "";
	}
}

static uint32_t get_right_shift_bit_mask(uint32_t n, uint32_t i)
{
	return  n & (1 << i);
}

static void add_item_in_sorted_order(uint32_t item, uint32_t item_count,
				     uint32_t *out, uint32_t *out_index)
{
	while(item_count) {
		out[*out_index] = item;
		item_count--;
		(*out_index)++;
	}
}

static void count_sort(uint32_t *a, size_t n) 
{
	uint32_t i, j;

	for (i = 0; i < n; i++)
		count_array[a[i]]++;

	for (i = 0, j = 0; i < n; i++)
		if(count_array[i])
			add_item_in_sorted_order(i, count_array[i], a, &j);
}

static void profile_requested_sort_algorithm(enum sort_algorithm e,
					     uint32_t *a, size_t n)
{
	clock_t t;
	double time_taken;

	t = clock();
	switch (e) {
	case bubble_sorting:
		bubble_sort(a, n);
		break;
	case selection_sorting:
		selection_sort(a, n);
		break;
	case insertion_sorting:
		insertion_sort(a, n);
		break;
	case shell_sorting:
		shell_sort(a, n);
		break;
	case quick_sorting:
		shuffle_sorted_output(a, n);
		quick_sort(a, 0, n - 1);
		break;
	case three_way_quick_sorting:
		shuffle_sorted_output(a, n);
		three_way_quick_sort(a, 0, n - 1);
		break;
	case merge_sorting:
		merge_sort(a, auxilary, 0, n - 1);
		break;
	case count_sorting:
		count_sort(a, n);
		break;
	default:
		printf("unknown sortign algorithm\n");
		break;
	}
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("%s took %f seconds to execute for %zu numbers\n",
		sort_name(e), time_taken, n);
	print_array(a, n);
}

static void run_sort_test(size_t n)
{
	generate_input(n);
	printf("unsorted_input:\n");
	print_array(input, n);
	profile_requested_sort_algorithm(bubble_sorting, input, n);
	profile_requested_sort_algorithm(selection_sorting, input_1, n);
	profile_requested_sort_algorithm(insertion_sorting, input_2, n);
	profile_requested_sort_algorithm(quick_sorting, input_3, n);
	profile_requested_sort_algorithm(shell_sorting, input_4, n);
	profile_requested_sort_algorithm(merge_sorting, input_5, n);
	profile_requested_sort_algorithm(three_way_quick_sorting, input_6, n);
	profile_requested_sort_algorithm(count_sorting, input_7, n);
}

static int64_t binary_search_v1(uint32_t val, size_t n)
{
	size_t left, right, mid;

	left  = 0;
	right = n - 1;

	while (left < right) {
		mid = left + ((right - left) >> 1);
		if (val < input_4[mid])
			right = mid;
		else if (val > input_4[mid])
			left = mid + 1;
		else
			return mid;
	}

	return -1;
}

static int64_t binary_search(uint32_t val, size_t n)
{
	size_t left, right, mid;

	left  = 0;
	right = n - 1;
	mid = left + ((right - left) >> 1);

	while ((left <= right) && (input_4[mid] != val)) {
		if (val < input_4[mid])
			right = mid - 1;
		else
			left = mid + 1;
		mid = left + ((right - left) >> 1);
	}

	if (val == input_4[mid])
		return mid;
	else
		return -1;
}

static void perform_binary_search(size_t n)
{
	uint32_t val;
	int64_t pos;

	printf("enter the value to search in sorted array:");
	scanf("%u", &val);

	pos = binary_search_v1(val, n);
	if (pos >= 0)
		printf("found %u at index %ld\n", val, pos);
	else
		printf("%u not found\n", val);
}

int main(int argc, char **argv)
{
	if (argc < 3) {
		printf("invalid input. missing input array size fro sorting\n");
		return -1;
	}

	uint32_t n = atoi(argv[1]);
	if (atoi(argv[2]))
		is_print_enabled = true;

	run_sort_test(n);
#if 0
	shuffle_sorted_output(input, n);
	perform_binary_search(n);
#endif

	return 0;
}
