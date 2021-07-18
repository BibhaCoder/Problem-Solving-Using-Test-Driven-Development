/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 *
 * Licensed under the MIT License. See MIT license for full license information.
 */

#include <stdio.h>
#include <stdint.h>

static uint8_t g_dst[20];
static uint8_t g_src[20] = {0xf0, 0xf1, 0xf2, 0xf3, 0xf4,0xf5, 0xf6, 0xf7, 0xf8, 0xf9};

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
	uint8_t *byte_dest_addr = dst;
	uint8_t const *byte_src_addr = src;
	uint32_t *word_dest_addr = dst;
	uint32_t const *word_src_addr = src;
	size_t word_len = len / sizeof(uint32_t);
	size_t byte_len = len % sizeof(uint32_t);

	/* N byte(4 bytes for uint32_t) aligned word will have at least log
	 * base 2 N least siginificant bit 0 which means log(base 2)4 = 2 least
	 * significant bits should be 0 and that means bit mast 0x3 for 2 bits.
	 */
	src_word_address_mask = (uint64_t)src & 0x3;
	dst_word_address_mask = (uint64_t)dst & 0x3;
	if (src_word_address_mask != dst_word_address_mask) {
		printf("copy byte wise becasue src and dest addr are not 32 bit word aligned\n");
		copy_byte_wise(dst, src, len);
		return;
	}
	printf("32 bit word byse copy is possible since 2 least significant bits %u and same in both src and dst\n", dst_word_address_mask);
	printf("words to copy %zu and remaining bytes to copy %zu\n", word_len, byte_len);
	copy_byte_wise(byte_dest_addr, byte_src_addr, dst_word_address_mask);
	word_dest_addr = (uint32_t *)(byte_dest_addr + dst_word_address_mask);
	word_src_addr = (uint32_t *)(byte_src_addr + dst_word_address_mask);
	byte_len -= dst_word_address_mask;

	copy_uint32_word_wise(word_dest_addr, word_src_addr, word_len);

	byte_dest_addr = (uint8_t *)word_dest_addr + word_len * sizeof(uint32_t);
	byte_src_addr = (uint8_t *)word_src_addr + word_len * sizeof(uint32_t);
	copy_byte_wise(byte_dest_addr, byte_src_addr, byte_len);
}

static void print_array(uint8_t const *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("[0x%x] ", a[i]);

	printf("\n");
}

int main()
{
	uint8_t *u8_p;
	uint32_t *u32_p;

	printf("size of uint8_t pointer %zu size of uint32_t pointer %zu\n",
	       sizeof(u8_p), sizeof(u32_p));
	printf("src %p dest %p\n", g_src, g_dst);
	printf("destination buffer before optimized memcpy:\n");
	print_array(g_dst, 10);
	optimized_mem_copy(g_dst, g_src, 10);
	printf("destination buffer after optimized memcpy:\n");
	print_array(g_dst, 10);
	normal_bytewise_mem_copy(g_dst, g_src, 10);

	return 0;
}
