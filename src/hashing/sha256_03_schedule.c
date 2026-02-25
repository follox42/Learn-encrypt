/*
 * Challenge 3: SHA-256 Message Schedule
 *
 * Goal: Expand 16 message words into 64 words. This is the "message
 *       schedule" step that ensures every bit of the input influences
 *       the entire hash computation.
 *
 * How it works:
 *   W[0]  to W[15]:  Copied directly from the 512-bit message block
 *                     (each word is 32 bits, big-endian byte order)
 *
 *   W[16] to W[63]:  Computed from previous words:
 *     W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16]
 *
 *   All additions are modulo 2^32 (uint32_t overflow wraps naturally).
 *
 * Test case:
 *   Input block from "abc" (padded, 16 big-endian words):
 *     W[0]  = 0x61626380   ("abc" + 0x80)
 *     W[1]  = 0x00000000
 *     ...
 *     W[15] = 0x00000018   (24 bits = message length)
 *
 *   After expansion, verify W[16] through W[63] match known
 *   SHA-256 intermediate values for "abc".
 */

#include <stdio.h>
#include <stdint.h>

/* Copy your functions from challenge 2 */

uint32_t rotr(uint32_t x, uint32_t n)
{
    /* Your code here */
    return 0;
}

uint32_t shr(uint32_t x, uint32_t n)
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

/*
 * Expand 16 message words into 64 words.
 * block: 16 big-endian 32-bit words from the padded message
 * W: output array of 64 words
 *
 * Steps:
 *   1. Copy block[0..15] into W[0..15]
 *   2. For t = 16 to 63:
 *      W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16]
 */
void sha256_message_schedule(const uint32_t *block, uint32_t *W)
{
    /* Your code here */
}

int main(void)
{
    /* Padded "abc" as 16 big-endian 32-bit words */
    uint32_t block[16] = {0};
    block[0]  = 0x61626380;  /* "abc" + 0x80 in big-endian */
    block[15] = 0x00000018;  /* 24 bits = length in big-endian */

    uint32_t W[64];
    sha256_message_schedule(block, W);

    /* Print all 64 schedule words */
    printf("=== Message Schedule for \"abc\" ===\n");
    for (int i = 0; i < 64; i++) {
        printf("W[%2d] = 0x%08X", i, W[i]);
        if (i < 16)
            printf("  (from message)");
        else
            printf("  (computed)");
        printf("\n");
    }

    return 0;
}
