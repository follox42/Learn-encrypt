/*
 * Challenge 2: Binary Printer
 *
 * Goal: Convert a number (0-255) to its 8-bit binary representation
 *
 * Tests:
 * 65  -> 01000001
 * 255 -> 11111111
 * 0   -> 00000000
 */

#include <stdio.h>

int main(void)
{
    char bits[9];
    int nb = 65;
    for(int i = 0; i < 8; i++){
        bits[7 - i] = '0' + ((nb >> i) & 1);
    }
    bits[8] = '\0';
    printf("%c -> %s", nb, bits);
    return 0;
}
