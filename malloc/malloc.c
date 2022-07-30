/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

Approach 1:

Do not preallocate fixed size bins and use small, medium, large and extra large hash bins

/* Create 4 separate bin of memory pools to avoid too many system calls
 *
 * Hash table based bins are used to avoid linear search and find the item from free cashed memory bin in O(1).
 *
 * Bin 1: small_hash_bin :  contains all memory allocations smaller than 64 bytes
 * Bin 2: medium_hash_bin:  contains all memory allocations between 64 bytes to 512 bytes
 * Bin 3: large_hash_bin: contains all memory allocations between 512 bytes to 1024 bytes
 * Bin 4: extra_large_bin: contains all memory allocations greater than 1024 bytes. This bin is served by system calls and has no caching.
 */

/* Bin: small_bin
 * memory is allocated as usual from system but at the time of free its stored in cashed
 * hash_table of small bin hashed based on size.
 * struct memory_bin {
 *       void *addr;
 *       size_t size;
 *       struct memory_bin *next;
 * };
 *
 * #define MAX_HASH_BIN_SIZE (1024)
 * 
 * struct memory_bin *cached_hash_bin[MAX_HASH_BIN_SIZE];
 * In cached_hash_bin all 3 bins of memory : small, medium and large are hashed by their size
 * for example:
 * 1) small_hash_bin: is stored in from index 1 to 64 in hash table cached_hash_bin.
 * 2) medium_hash_bin: is stored in from index 65 to 512 in hash table cached_hash_bin.
 * 3) large_hash_bin: is stored in from index 513 to 1024 in hash table cached_hash_bin.
 * 4) extra_large_bin: is not stored and served directly via system call assumign these large allocations are rare
 *
 * Threshold of extra large allocations can be changed depending upon use cases for example extra large bin threshold
 * can be increased to serve 4096 or even more size.
 *
 * void *malloc(size_t)
 * {
 *    if (size > MAX_HASH_BIN_SIZE) {
 *        its extra large request and use system call to allocate memory;
 *        return;
 *    }
 *     depending upon size look for free list 1st either in:
 *         1) small_hash_bin
 *         2) medium_hash_bin
 *         3) large_hash_bin
 *
 *
 *    if (cached_hash_bin[size]) {
 *        return head of linked list and removes it from cached_hash_bin;
 *        head = delete_from_hash_bin(cached_hash_bin[size]); 
 *        return head;
 *    } else {
 *      addr = alloc() -->use system call and allocate memory;
 *      return addr;
 *    }
 * }
 *
 * void free(void *addr) 
 * {
 *    get size from meta data of addr;
 *    size = get_size_from_meta_header(addr);
 *    if (size > MAX_HASH_BIN_SIZE) {
 *        its extra large request return it to system via free system call;
 *        return;
 *    } else {
 *       add_in_hash_bin(cached_hash_bin[size], addr);
 *   }
 * }
 */

Approach 2:

Pre allocate and cache fixed size chunks to serve various members size equal or smaller than bin size
For large allocations use system allocator by using system calls.
