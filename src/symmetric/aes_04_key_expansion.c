/*
 * Challenge 4: AES Key Expansion
 *
 * Goal: Expand a 128-bit AES key into 11 round keys (44 words of 32 bits).
 *
 * Algorithm (AES-128):
 * Start with the original 4-word key: W[0], W[1], W[2], W[3]
 *
 * For i = 4 to 43:
 *   if i mod 4 == 0:
 *     temp = SubWord(RotWord(W[i-1])) XOR Rcon[i/4]
 *   else:
 *     temp = W[i-1]
 *   W[i] = W[i-4] XOR temp
 *
 * Where:
 * - RotWord: rotate the 4 bytes of a word left by 1 position
 * - SubWord: apply the S-box to each of the 4 bytes
 * - Rcon: round constants (powers of 2 in GF(2^8))
 *
 * Round constants:
 * Rcon[1]=0x01, Rcon[2]=0x02, Rcon[3]=0x04, Rcon[4]=0x08,
 * Rcon[5]=0x10, Rcon[6]=0x20, Rcon[7]=0x40, Rcon[8]=0x80,
 * Rcon[9]=0x1B, Rcon[10]=0x36
 *
 * Tests (AES-128):
 * Key: 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
 *
 * Round key 0 (original, column-major):
 *   2b 28 ab 09
 *   7e ae f7 cf
 *   15 d2 15 4f
 *   16 a6 88 3c
 *
 * Round key 1:
 *   a0 88 23 2a
 *   fa 54 a3 6c
 *   fe 2c 39 76
 *   17 b1 39 05
 *
 * Note: state matrix is filled column by column.
 */

#include <stdio.h>
#include <string.h>

/* AES S-box (copy from aes_01_sbox.c) */

/* Round constants */
static const unsigned char RCON[11] = {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10,
    0x20, 0x40, 0x80, 0x1B, 0x36
};

/* Expand 128-bit key into 11 round keys */
void key_expansion(const unsigned char key[16],
                   unsigned char round_keys[11][4][4])
{
    /* Your code here */
    /* Step 1: Copy the original key into round_keys[0] */
    /* Step 2: Generate words W[4] through W[43] */
    /* Remember: state is column-major */
}

/* Print a round key as a 4x4 matrix */
void print_round_key(const unsigned char rk[4][4])
{
    /* Your code here */
}

int main(void)
{
    unsigned char key[16] = {
        0x2B, 0x7E, 0x15, 0x16,
        0x28, 0xAE, 0xD2, 0xA6,
        0xAB, 0xF7, 0x15, 0x88,
        0x09, 0xCF, 0x4F, 0x3C
    };

    unsigned char round_keys[11][4][4];

    key_expansion(key, round_keys);

    printf("Key: ");
    for (int i = 0; i < 16; i++)
        printf("%02x ", key[i]);
    printf("\n\n");

    for (int r = 0; r < 11; r++) {
        printf("Round key %d:\n", r);
        print_round_key(round_keys[r]);
        printf("\n");
    }

    printf("Expected round key 0:\n");
    printf("  2b 28 ab 09\n");
    printf("  7e ae f7 cf\n");
    printf("  15 d2 15 4f\n");
    printf("  16 a6 88 3c\n\n");

    printf("Expected round key 1:\n");
    printf("  a0 88 23 2a\n");
    printf("  fa 54 a3 6c\n");
    printf("  fe 2c 39 76\n");
    printf("  17 b1 39 05\n");

    return 0;
}
