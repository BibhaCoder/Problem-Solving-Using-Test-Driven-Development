#include <stdio.h>
#include <stdint.h>

static uint8_t g_dst[20];
uint32_t pad1 = 0;
static uint8_t g_src[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

static void normal_bytewise_mem_copy(void *dst, void const *src, size_t len)
{
	size_t i;
	uint8_t *d = dst;
	uint8_t const *s = src;

	printf("%s src %p dst %p len %zu\n", __func__, src, dst, len);
	for (i = 0; i < len; i++)
		*d++ = *s++;
}

static void copy_byte_wise(uint8_t *dst, uint8_t const *src, size_t len)
{
	size_t i;

	printf("%s src %p dst %p len %zu\n", __func__, src, dst, len);
	for (i = 0; i < len; i++)
		*dst++ = *src++;
}

static void copy_uint32_word_wise(uint32_t *dst, uint32_t const *src, size_t len)
{
	size_t i;

	printf("%s src %p dst %p len %zu\n", __func__, src, dst, len);
	for (i = 0; i < len; i++)
		*dst++ = *src++;
}

static void optimized_mem_copy(void *dst, void const *src, size_t len)
{
	uint8_t src_word_address_mask = 0;
	uint8_t dst_word_address_mask = 0;
	uint8_t *byte_dest = dst;
	uint8_t const *byte_src = src;
	uint32_t *word_dest = dst;
	uint32_t const *word_src = src;
	size_t word_len = len / sizeof(uint32_t);
	size_t byte_len = len % sizeof(uint32_t);

	/* N byte aligned word will have at least log base 2 N
	 * bits 0 least significant bits (or bit mask of (N - 1))
	 * and for 32 bit(4 byte) word it should be 2==>log(base 2)4 = 2
	 * least significant bits.
	 */
	src_word_address_mask = (uintptr_t)src & 0x3; /* 4 bytes aligned word */
	dst_word_address_mask = (uintptr_t)dst & 0x3; /* 4 bytes aligned word */
	if (src_word_address_mask != dst_word_address_mask) {
		printf("copy byte wise becasue src and dest addr are not 32 bit word aligned\n");
		copy_byte_wise(dst, src, len);
		return;
	}
	printf("32 bit word byse copy is possible since 2 least significant bits %u and same in both src and dst\n", dst_word_address_mask);
	printf("words to copy %zu and remaining bytes to copy %zu\n", word_len, byte_len);
	copy_byte_wise(byte_dest, byte_src, dst_word_address_mask);
	word_dest = (uint32_t *)byte_dest + dst_word_address_mask;
	word_src = (uint32_t *)byte_src + dst_word_address_mask;
	byte_len -= dst_word_address_mask;

	copy_uint32_word_wise(word_dest, word_src, word_len);

	byte_dest = (uint8_t *)word_dest + word_len * sizeof(uint32_t);
	byte_src = (uint8_t *)word_src + word_len * sizeof(uint32_t);
	copy_byte_wise(byte_dest, byte_src, byte_len);
}

static void print_array(uint8_t const *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("[%u] ", a[i]);

	printf("\n");
}

int main()
{
	uint8_t *u8_p;
	uint32_t *u32_p;

	printf("size of uint8_t pointer %zu size of uint32_t pointer %zu\n",
	       sizeof(u8_p), sizeof(u32_p));
	printf("pad1 size %zu\n", sizeof(pad1)); 
	printf("src %p dest %p\n", g_src, g_dst);
	printf("destination buffer before optimized memcpy:\n");
	print_array(g_dst, 10);
	optimized_mem_copy(g_dst, g_src, 10);
	printf("destination buffer after optimized memcpy:\n");
	print_array(g_dst, 10);
	normal_bytewise_mem_copy(g_dst, g_src, 10);

	return 0;
}
