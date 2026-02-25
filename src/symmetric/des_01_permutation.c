/*
 * Challenge 1: DES Initial Permutation
 *
 * Goal: Implement the Initial Permutation (IP) table for DES.
 *       Build a generic bit permutation function that rearranges bits
 *       according to a permutation table.
 *
 * How it works:
 * - table[i] tells you which input bit goes to output position i+1
 * - Bit numbering: bit 1 is the MSB of byte 0
 * - To get bit n: (input[(n-1)/8] >> (7 - (n-1)%8)) & 1
 * - To set bit n: output[(n-1)/8] |= (bit << (7 - (n-1)%8))
 *
 * Tests:
 * Input: 0x0123456789ABCDEF (64 bits)
 * After IP: 0xCC00CCFFF0AAF0AA
 * After IP^-1 on that result: back to 0x0123456789ABCDEF
 */

#include <stdio.h>
#include <string.h>

/* DES Initial Permutation table (64 entries) */
static const int IP_TABLE[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17,  9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

/* DES Inverse Initial Permutation table (64 entries) */
static const int IP_INV_TABLE[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41,  9, 49, 17, 57, 25
};

/* Get a single bit from a byte array (bit numbering starts at 1) */
int get_bit(const unsigned char *data, int bit_pos)
{
    /* Your code here */
    return 0;
}

/* Set a single bit in a byte array (bit numbering starts at 1) */
void set_bit(unsigned char *data, int bit_pos, int value)
{
    /* Your code here */
}

/* Apply a permutation: rearrange bits according to table */
void permute(const unsigned char *input, unsigned char *output,
             const int *table, int table_size)
{
    /* Your code here */
}

/* Print a byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    unsigned char input[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    unsigned char permuted[8] = {0};
    unsigned char restored[8] = {0};

    printf("Input:    ");
    print_hex(input, 8);
    printf("\n");

    /* Apply Initial Permutation */
    permute(input, permuted, IP_TABLE, 64);
    printf("After IP: ");
    print_hex(permuted, 8);
    printf("\n");
    printf("Expected: CC00CCFFF0AAF0AA\n\n");

    /* Apply Inverse IP to get back original */
    permute(permuted, restored, IP_INV_TABLE, 64);
    printf("After IP^-1: ");
    print_hex(restored, 8);
    printf("\n");
    printf("Expected:    0123456789ABCDEF\n");

    return 0;
}
