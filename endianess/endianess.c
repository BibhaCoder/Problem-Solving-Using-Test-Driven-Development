#include <stdio.h>

int main() 
{
        uint32_t word = 0x00000001;
        uint8_t *byte = (uint8_t *)&word;

        if (0x1 == (*byte))
                printf("Little endian");
        else
                printf("Big endian");

        return 0;
}
