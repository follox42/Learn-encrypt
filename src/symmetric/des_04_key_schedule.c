/*
 * Challenge 4: DES Key Schedule
 *
 * Goal: Generate 16 round subkeys from a 64-bit DES key.
 *
 * Steps:
 * 1. Apply PC-1 to the 64-bit key to get 56 bits (drop parity bits)
 * 2. Split into C0 (28 bits) and D0 (28 bits)
 * 3. For each round (1-16):
 *    - Left-rotate C and D by 1 or 2 positions
 *    - Apply PC-2 to the combined C|D to get 48-bit subkey
 *
 * Rotation schedule:
 * Round:     1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16
 * Rotations: 1  1  2  2  2  2  2  2  1  2  2  2  2  2  2  1
 *
 * Test: Use key 0x133457799BBCDFF1 and verify all 16 subkeys
 *       match published DES test vectors.
 */

#include <stdio.h>
#include <string.h>

/* PC-1: Permuted Choice 1 (64-bit key → 56 bits, drops parity) */
static const int PC1_TABLE[56] = {
    57, 49, 41, 33, 25, 17,  9,
     1, 58, 50, 42, 34, 26, 18,
    10,  2, 59, 51, 43, 35, 27,
    19, 11,  3, 60, 52, 44, 36,
    63, 55, 47, 39, 31, 23, 15,
     7, 62, 54, 46, 38, 30, 22,
    14,  6, 61, 53, 45, 37, 29,
    21, 13,  5, 28, 20, 12,  4
};

/* PC-2: Permuted Choice 2 (56 bits → 48-bit subkey) */
static const int PC2_TABLE[48] = {
    14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

/* Number of left rotations per round */
static const int ROTATIONS[16] = {
    1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

/* Bit manipulation helpers (reuse from previous challenges) */
int get_bit(const unsigned char *data, int bit_pos)
{
    /* Your code here */
    return 0;
}

void set_bit(unsigned char *data, int bit_pos, int value)
{
    /* Your code here */
}

void permute(const unsigned char *input, unsigned char *output,
             const int *table, int table_size)
{
    /* Your code here */
}

/* Left-rotate a 28-bit value stored in a byte array */
void left_rotate_28(unsigned char *half, int positions)
{
    /* Your code here */
}

/* Generate 16 subkeys from a 64-bit key */
void des_key_schedule(const unsigned char *key_64bit,
                      unsigned char subkeys[16][6])
{
    /* Your code here */
    /* Step 1: Apply PC-1 to get 56 bits */
    /* Step 2: Split into C (28 bits) and D (28 bits) */
    /* Step 3: For each round, rotate C and D, then apply PC-2 */
}

/* Print byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    unsigned char key[8] = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};
    unsigned char subkeys[16][6];

    des_key_schedule(key, subkeys);

    printf("Key: ");
    print_hex(key, 8);
    printf("\n\n");

    for (int i = 0; i < 16; i++) {
        printf("K%2d: ", i + 1);
        print_hex(subkeys[i], 6);
        printf("\n");
    }

    return 0;
}
