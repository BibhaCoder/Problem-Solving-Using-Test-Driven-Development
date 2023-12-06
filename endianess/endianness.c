#include <stdio.h>
#include <stdint.h>

static void dump_memory(uint8_t *byte)
{
        printf("address -> %p : val 0x%x\n", byte, *byte);
        printf("address -> %p : val 0x%x\n", (byte + 1), *(byte + 1));
        printf("address -> %p : val 0x%x\n", (byte + 2), *(byte + 2));
        printf("address -> %p : val 0x%x\n", (byte + 3), *(byte + 3));
}

int main()
{
        uint32_t word = 0xaabbccdd;
        uint8_t *byte = (uint8_t *)&word;

        if (0xaa == (*byte))
                printf("Big endian lowest address %p and val 0x%x\n", byte, *byte);
        else
                printf("Little endian lowest address %p and val 0x%x\n", byte, *byte);

        dump_memory(byte);
}
