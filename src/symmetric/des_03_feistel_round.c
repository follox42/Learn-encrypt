/*
 * Challenge 3: DES Feistel Round Function
 *
 * Goal: Implement one complete round of the Feistel function F(R, K).
 *
 * Steps inside F:
 * 1. Expand R from 32 bits to 48 bits using the E expansion table
 * 2. XOR the expanded 48 bits with the 48-bit subkey
 * 3. Split into 8 groups of 6 bits
 * 4. Apply each S-box (reuse sbox_lookup from Challenge 2)
 * 5. Combine the 8 groups of 4 bits into 32 bits
 * 6. Apply the P permutation
 *
 * Test: Apply one round with known R and K values,
 *       verify output matches a DES reference implementation.
 */

#include <stdio.h>
#include <string.h>

/* DES Expansion table: 32 bits → 48 bits */
static const int E_TABLE[48] = {
    32,  1,  2,  3,  4,  5,
     4,  5,  6,  7,  8,  9,
     8,  9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32,  1
};

/* DES P permutation table: 32 bits → 32 bits */
static const int P_TABLE[32] = {
    16,  7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26,  5, 18, 31, 10,
     2,  8, 24, 14, 32, 27,  3,  9,
    19, 13, 30,  6, 22, 11,  4, 25
};

/* S-boxes: copy from des_02_sbox.c or include them here */

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

/* Apply a permutation (reuse from Challenge 1) */
void permute(const unsigned char *input, unsigned char *output,
             const int *table, int table_size)
{
    /* Your code here */
}

/* S-box lookup (reuse from Challenge 2) */
unsigned char sbox_lookup(int sbox_index, unsigned char input_6bit)
{
    /* Your code here */
    return 0;
}

/* The Feistel round function F(R, K) */
void feistel_f(const unsigned char *right_32bit,
               const unsigned char *subkey_48bit,
               unsigned char *output_32bit)
{
    /* Your code here */
    /* Step 1: Expand R from 32 to 48 bits using E_TABLE */
    /* Step 2: XOR expanded R with subkey */
    /* Step 3: Split into 8 groups of 6 bits, apply S-boxes */
    /* Step 4: Combine S-box outputs (32 bits total) */
    /* Step 5: Apply P permutation */
}

/* Print byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    /* Test with known values from DES reference */
    unsigned char right[4] = {0xF0, 0xAA, 0xF0, 0xAA};
    unsigned char subkey[6] = {0x1B, 0x02, 0xEF, 0xFC, 0x70, 0x72};
    unsigned char output[4] = {0};

    feistel_f(right, subkey, output);

    printf("R:      ");
    print_hex(right, 4);
    printf("\n");

    printf("K:      ");
    print_hex(subkey, 6);
    printf("\n");

    printf("F(R,K): ");
    print_hex(output, 4);
    printf("\n");

    return 0;
}
