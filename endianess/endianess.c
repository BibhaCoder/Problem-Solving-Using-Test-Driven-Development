#include <stdio.h>

int main() 
{
        uint32_t word = 0xaabbccdd;
        uint8_t *byte = (uint8_t *)&word;

        if (0xdd == (*byte))
                printf("Little endian");
        else
                printf("Big endian");

        return 0;
}
