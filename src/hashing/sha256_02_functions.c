/*
 * Challenge 2: SHA-256 Logical Functions
 *
 * Goal: Implement the 6 core SHA-256 logical functions plus the
 *       rotate and shift primitives. SHA-256 uses more functions
 *       than MD5 (6 vs 4), and they serve different roles:
 *
 *   Primitives:
 *     rotr(x, n) - right rotate (bits wrap around)
 *     shr(x, n)  - right shift (bits are lost)
 *
 *   Used in compression (each of 64 rounds):
 *     Ch(x, y, z)   - Choice: x chooses between y and z
 *     Maj(x, y, z)  - Majority: output the most common bit
 *     Sigma0(x)      - Big sigma 0 (rotations only)
 *     Sigma1(x)      - Big sigma 1 (rotations only)
 *
 *   Used in message schedule (expanding 16 words to 64):
 *     sigma0(x)      - Small sigma 0 (rotations + shift)
 *     sigma1(x)      - Small sigma 1 (rotations + shift)
 *
 * Tests:
 * rotr(0x00000001, 1)    = 0x80000000
 * rotr(0xABCD1234, 4)    = 0x4ABCD123
 * shr(0xABCD1234, 4)     = 0x0ABCD123
 *
 * Ch(0xFFFFFFFF, 0x12345678, 0xABCDEF01)  = 0x12345678
 * Ch(0x00000000, 0x12345678, 0xABCDEF01)  = 0xABCDEF01
 * Maj(0xFF00FF00, 0xFF0000FF, 0x00FF00FF) = 0xFF0000FF
 */

#include <stdio.h>
#include <stdint.h>

/* rotr(x, n) = (x >> n) | (x << (32 - n)) */
uint32_t rotr(uint32_t x, uint32_t n)
{
    /* Your code here */
    return 0;
}

/* shr(x, n) = x >> n */
uint32_t shr(uint32_t x, uint32_t n)
{
    /* Your code here */
    return 0;
}

/* Ch(x, y, z) = (x & y) ^ (~x & z) */
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z)
{
    /* Your code here */
    return 0;
}

/* Maj(x, y, z) = (x & y) ^ (x & z) ^ (y & z) */
uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    /* Your code here */
    return 0;
}

/* Sigma0(x) = rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22) */
uint32_t Sigma0(uint32_t x)
{
    /* Your code here */
    return 0;
}

/* Sigma1(x) = rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25) */
uint32_t Sigma1(uint32_t x)
{
    /* Your code here */
    return 0;
}

/* sigma0(x) = rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3) */
uint32_t sigma0(uint32_t x)
{
    /* Your code here */
    return 0;
}

/* sigma1(x) = rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10) */
uint32_t sigma1(uint32_t x)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    /* Test: rotate and shift */
    printf("=== Rotate and Shift ===\n");
    printf("rotr(0x00000001, 1) = 0x%08X (expected 0x80000000)\n",
           rotr(0x00000001, 1));
    printf("rotr(0xABCD1234, 4) = 0x%08X (expected 0x4ABCD123)\n",
           rotr(0xABCD1234, 4));
    printf("shr(0xABCD1234, 4)  = 0x%08X (expected 0x0ABCD123)\n",
           shr(0xABCD1234, 4));

    /* Test: Ch and Maj */
    printf("\n=== Ch and Maj ===\n");
    printf("Ch(0xFFFFFFFF, 0x12345678, 0xABCDEF01) = 0x%08X (expected 0x12345678)\n",
           Ch(0xFFFFFFFF, 0x12345678, 0xABCDEF01));
    printf("Ch(0x00000000, 0x12345678, 0xABCDEF01) = 0x%08X (expected 0xABCDEF01)\n",
           Ch(0x00000000, 0x12345678, 0xABCDEF01));
    printf("Maj(0xFF00FF00, 0xFF0000FF, 0x00FF00FF) = 0x%08X (expected 0xFF0000FF)\n",
           Maj(0xFF00FF00, 0xFF0000FF, 0x00FF00FF));

    /* Test: Sigma and sigma functions with initial hash values */
    printf("\n=== Sigma Functions ===\n");
    printf("Sigma0(0x6a09e667) = 0x%08X\n", Sigma0(0x6a09e667));
    printf("Sigma1(0x510e527f) = 0x%08X\n", Sigma1(0x510e527f));

    printf("\n=== sigma Functions (message schedule) ===\n");
    printf("sigma0(0x61626380) = 0x%08X\n", sigma0(0x61626380));
    printf("sigma1(0x00000018) = 0x%08X\n", sigma1(0x00000018));

    return 0;
}
