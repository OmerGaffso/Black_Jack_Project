#include "data.h"

void print_bits_u8(uint8_t num) {
    int x = 0;

    for (uint8_t mask = 1<<7; mask != 0; mask >>= 1) {
        putchar( (num & mask)  ? '1' : '0');
        if (x == 7) {
            putchar(' ');
            x = 0;
        }
        else {
            x++;
        }
    }
    puts("");
}
