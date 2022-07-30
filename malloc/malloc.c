/*
 * Copyright (c) 2017 BibhaCoder(https://github.com/BibhaCoder). All rights reserved.
 */

/*
 * Approach 1: Without PRE-ALLOCATION
 *
 * Do not preallocate fixed size bins and use small, medium, large and extra large hash bins
 *
 * Create 4 separate bin of memory pools to avoid too many system calls
 *
 * Hash table based bins are used to avoid linear search and find the item from free cashed memory bin in O(1).
 *
 * Bin 1: small_hash_bin :  contains all memory allocations smaller than 64 bytes
 * Bin 2: medium_hash_bin:  contains all memory allocations between 64 bytes to 512 bytes
 * Bin 3: large_hash_bin: contains all memory allocations between 512 bytes to 1024 bytes
 * Bin 4: extra_large_bin: contains all memory allocations greater than 1024 bytes. This bin is served by system calls and has no caching.
 *
 * All memory allication request is allocated as usual from system but at the time of free its stored in cashed_hash_bin by directly using
 * size as index in cached_hash_bin.
 * /
  
struct memory_meta_data {
       size_t size;
       uint32_t header;
       void *addr;
       uint32_t footer;
}


struct memory_bin {
       struct memory_meta_data *mem;
       struct memory_bin *next;
};
 
#define MAX_HASH_BIN_SIZE (1024)
struct memory_bin *cached_hash_bin[MAX_HASH_BIN_SIZE];
 
/*
 * In cached_hash_bin all 3 bins of memory : small, medium and large are hashed by their size index
 * for example:
 * 1) small_hash_bin: is stored in from index 1 to 64(for size 1 bytes to 64 bytes allocations) in hash table cached_hash_bin.
 * 2) medium_hash_bin: is stored in from index 65 to 512(for size 65 bytes to 256 bytes allocations) in hash table cached_hash_bin.
 * 3) large_hash_bin: is stored in from index 513 to 1024(for size 513 bytes to 1024 bytes allocations) in hash table cached_hash_bin.
 * 4) extra_large_bin: is not stored and served directly via system call assumign these large allocations are rare. 
 *
 * Threshold of extra large allocations can be changed depending upon use cases, for example extra large bin threshold
 * can be increased to serve 4096 bytes allocations or even larger size. Idea is upto a given large size (1k, 4k, 8k etc.) will be served
 * from local hash cached bin and beyond that allocations will be served from system memory directly.
 */

void *malloc(size_t size)
{
    size_t new_size;
    struct memory_meta_data *mem;

    if (!size)
            return NULL;

    if (size > MAX_HASH_BIN_SIZE) {
            /* its extra large request and not served by cashed hash bin
             * use system call to allocate memory
             */
             addr = alloc(size);
             return addr;
     }

     new_size = size + sizeof(size_t) + 2 * sizeof(uint32_t);

     /* Look up in O(1) in corresponding cached hash bin directly using input size as index */
     if (cached_hash_bin[size]) {
            mem = delete_head_from_hash_bin(cached_hash_bin[size]); 
     } else {
            mem = alloc(new_size);
            if (!mem)
                  return NULL;

            mem->size = size;
            mem->header = 0xdeaddead;
            mem->footer = 0xdeaddead;
            add_to_head_of_bash_bin(cached_hash_bin[size], mem);
     }

     return mem->addr;
 }

void free(void *addr) 
{
    get size from meta data of addr;
    size = get_size_from_meta_header(addr);
    if (size > MAX_HASH_BIN_SIZE) {
        its extra large request return it to system via free system call;
       return;
   } else {
       add_in_hash_bin(cached_hash_bin[size], addr);
 
   }
 }


Approach 2: PRE-ALLOCATION

Pre allocate and cache fixed size chunks to serve various members size equal or smaller than bin size
For large allocations use system allocator by using system calls.
For example;
pool_128: serves all allocations of size <= 128 bytes
pool_256: serves all allocations of size <= 256 bytes 
pool_512: serves all allocations of size <= 512 bytes 
pool_1024: serves all allocations of size <= 1024 bytes 
pool_extra_large: al allocations of size > 1024 bytes are served via system calls directly 

