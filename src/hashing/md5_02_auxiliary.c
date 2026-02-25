/*
 * Challenge 2: MD5 Auxiliary Functions
 *
 * Goal: Implement the four MD5 auxiliary functions (F, G, H, I) and
 *       the left rotate operation. These are the building blocks of
 *       each MD5 round.
 *
 * The four functions each mix three 32-bit words differently:
 *   F acts as a multiplexer (if B then C else D)
 *   G is a rearranged multiplexer (if D then B else C)
 *   H computes parity (XOR of all three)
 *   I introduces nonlinearity through OR + XOR
 *
 * Tests:
 * F(0xFF, 0x00, 0xAA) = 0x00
 *   (B=0xFF: all 1s in low byte, so pick C=0x00 for those bits)
 *
 * F(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = compute and verify
 * G(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = compute and verify
 * H(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = compute and verify
 * I(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = compute and verify
 *
 * left_rotate(0x00000001, 1)  = 0x00000002
 * left_rotate(0x80000000, 1)  = 0x00000001
 * left_rotate(0xABCD1234, 4)  = 0xBCD1234A
 * left_rotate(0x12345678, 0)  = 0x12345678
 */

#include <stdio.h>
#include <stdint.h>

/* F(B,C,D) = (B & C) | (~B & D) */
uint32_t F(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

/* G(B,C,D) = (B & D) | (C & ~D) */
uint32_t G(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

/* H(B,C,D) = B ^ C ^ D */
uint32_t H(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

/* I(B,C,D) = C ^ (B | ~D) */
uint32_t I(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

/* left_rotate(x, n) = (x << n) | (x >> (32 - n)) */
uint32_t left_rotate(uint32_t x, uint32_t n)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    /* Test: simple case for F */
    printf("=== Simple F Test ===\n");
    printf("F(0xFF, 0x00, 0xAA) = 0x%08X (expected 0x00000000)\n",
           F(0xFF, 0x00, 0xAA));

    /* Test: auxiliary functions with larger values */
    uint32_t B = 0xFF00FF00;
    uint32_t C = 0x0F0F0F0F;
    uint32_t D = 0xAAAAAAAA;

    printf("\n=== Auxiliary Functions ===\n");
    printf("B = 0x%08X, C = 0x%08X, D = 0x%08X\n\n", B, C, D);
    printf("F(B, C, D) = 0x%08X\n", F(B, C, D));
    printf("G(B, C, D) = 0x%08X\n", G(B, C, D));
    printf("H(B, C, D) = 0x%08X\n", H(B, C, D));
    printf("I(B, C, D) = 0x%08X\n", I(B, C, D));

    /* Test: left rotate */
    printf("\n=== Left Rotate ===\n");
    printf("left_rotate(0x00000001, 1)  = 0x%08X (expected 0x00000002)\n",
           left_rotate(0x00000001, 1));
    printf("left_rotate(0x80000000, 1)  = 0x%08X (expected 0x00000001)\n",
           left_rotate(0x80000000, 1));
    printf("left_rotate(0xABCD1234, 4)  = 0x%08X (expected 0xBCD1234A)\n",
           left_rotate(0xABCD1234, 4));
    printf("left_rotate(0x12345678, 0)  = 0x%08X (expected 0x12345678)\n",
           left_rotate(0x12345678, 0));

    return 0;
}
