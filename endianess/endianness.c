#include <stdio.h>

int main() 
{
        uint32_t word = 0xaabbccdd;
        uint8_t *byte = (uint8_t *)&word;

        if (0xaa == (*byte))
                printf("Big endian");
        else
                printf("Little endian");

        return 0;
}
