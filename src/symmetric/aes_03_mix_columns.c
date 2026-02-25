/*
 * Challenge 3: AES MixColumns
 *
 * Goal: Implement the MixColumns transformation using
 *       Galois Field GF(2^8) multiplication.
 *
 * Galois Field GF(2^8) arithmetic:
 * - Elements are bytes (polynomials of degree < 8)
 * - Addition = XOR (no carries)
 * - Multiplication = polynomial multiplication modulo
 *   the irreducible polynomial x^8 + x^4 + x^3 + x + 1 (0x11B)
 *
 * The "xtime" operation (multiply by 2):
 *   result = a << 1
 *   if high bit was set (a & 0x80): result ^= 0x1B
 *   return result & 0xFF
 *
 * Multiply by 3: xtime(a) ^ a
 * Multiply by 1: identity
 *
 * MixColumns matrix (applied to each column):
 * | 2  3  1  1 |   | s0 |
 * | 1  2  3  1 | x | s1 |
 * | 1  1  2  3 |   | s2 |
 * | 3  1  1  2 |   | s3 |
 *
 * Tests:
 * gf_mul(0xD4, 2) = 0xB3
 *
 * Input state (after ShiftRows):
 *   d4 e0 b8 1e
 *   bf b4 41 27
 *   5d 52 11 98
 *   30 ae f1 e5
 *
 * After MixColumns:
 *   04 e0 48 28
 *   66 cb f8 06
 *   81 19 d3 26
 *   e5 9a 7a 4c
 */

#include <stdio.h>

/* Multiply two bytes in GF(2^8) */
unsigned char gf_mul(unsigned char a, unsigned char b)
{
    /* Your code here */
    /* Hint: you only need multiply by 1, 2, and 3 for MixColumns */
    /* For general multiplication, use the "peasant multiplication" algorithm */
    return 0;
}

/* Apply MixColumns to the 4x4 state */
void mix_columns(unsigned char state[4][4])
{
    /* Your code here */
    /* For each column, multiply by the fixed matrix using gf_mul */
}

/* Print state matrix */
void print_state(const unsigned char state[4][4])
{
    /* Your code here */
}

int main(void)
{
    /* Test GF multiplication */
    printf("=== GF(2^8) Multiplication Tests ===\n");
    printf("gf_mul(0xD4, 2) = 0x%02X (expected: 0xB3)\n\n", gf_mul(0xD4, 2));

    /* Full state test */
    unsigned char state[4][4] = {
        {0xD4, 0xE0, 0xB8, 0x1E},
        {0xBF, 0xB4, 0x41, 0x27},
        {0x5D, 0x52, 0x11, 0x98},
        {0x30, 0xAE, 0xF1, 0xE5}
    };

    printf("Before MixColumns:\n");
    print_state(state);

    mix_columns(state);

    printf("After MixColumns:\n");
    print_state(state);

    printf("Expected:\n");
    printf("  04 e0 48 28\n");
    printf("  66 cb f8 06\n");
    printf("  81 19 d3 26\n");
    printf("  e5 9a 7a 4c\n");

    return 0;
}
