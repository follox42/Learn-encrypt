/*
 * Challenge 4: SHA-256 Compression Function
 *
 * Goal: Implement the SHA-256 compression function that processes
 *       one 512-bit block through 64 rounds, updating the hash state.
 *
 * How it works:
 *   1. Initialize 8 working variables (a through h) from the state
 *   2. For each round t (0 to 63):
 *      T1 = h + Sigma1(e) + Ch(e, f, g) + K[t] + W[t]
 *      T2 = Sigma0(a) + Maj(a, b, c)
 *      h = g, g = f, f = e, e = d + T1
 *      d = c, c = b, b = a, a = T1 + T2
 *   3. After 64 rounds, add working variables back to state
 *
 * You will need:
 *   - The 64 round constants K[0..63] (from cube roots of first 64 primes)
 *   - The 64 schedule words W[0..63] (from challenge 3)
 *   - All 6 logical functions (from challenge 2)
 *
 * Test case:
 *   Initial state (SHA-256 IV):
 *     {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
 *      0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19}
 *
 *   After processing the "abc" block, state should become
 *   the SHA-256 hash of "abc":
 *     state[0] = 0xba7816bf
 *     state[1] = 0x8f01cfea
 *     ...
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Copy your logical functions from challenge 2 */

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

uint32_t Ch(uint32_t x, uint32_t y, uint32_t z)
{
    /* Your code here */
    return 0;
}

uint32_t Maj(uint32_t x, uint32_t y, uint32_t z)
{
    /* Your code here */
    return 0;
}

uint32_t Sigma0(uint32_t x)
{
    /* Your code here */
    return 0;
}

uint32_t Sigma1(uint32_t x)
{
    /* Your code here */
    return 0;
}

uint32_t sigma0(uint32_t x)
{
    /* Your code here */
    return 0;
}

uint32_t sigma1(uint32_t x)
{
    /* Your code here */
    return 0;
}

/* Copy your message schedule from challenge 3 */
void sha256_message_schedule(const uint32_t *block, uint32_t *W)
{
    /* Your code here */
}

/*
 * The 64 round constants K[0..63].
 * First 32 bits of the fractional parts of the cube roots
 * of the first 64 prime numbers (2, 3, 5, 7, ..., 311).
 *
 * You need to fill this table:
 * K[0]  = 0x428a2f98, K[1]  = 0x71374491, ...
 * K[63] = 0xc67178f2
 */

/*
 * SHA-256 compression function.
 * state: 8 x 32-bit words (modified in place)
 * W: 64 schedule words (from sha256_message_schedule)
 *
 * Steps:
 *   1. Copy state[0..7] into working variables a..h
 *   2. 64 rounds:
 *      T1 = h + Sigma1(e) + Ch(e,f,g) + K[t] + W[t]
 *      T2 = Sigma0(a) + Maj(a,b,c)
 *      Shift: h=g, g=f, f=e, e=d+T1, d=c, c=b, b=a, a=T1+T2
 *   3. Add a..h back to state[0..7]
 */
void sha256_compress(uint32_t *state, const uint32_t *W)
{
    /* Your code here */
}

int main(void)
{
    /* SHA-256 initial state (IV) */
    uint32_t state[8] = {
        0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
        0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
    };

    /* Padded "abc" as 16 big-endian words */
    uint32_t block[16] = {0};
    block[0]  = 0x61626380;
    block[15] = 0x00000018;

    /* Expand to 64 words */
    uint32_t W[64];
    sha256_message_schedule(block, W);

    printf("=== Before Compression ===\n");
    for (int i = 0; i < 8; i++)
        printf("H%d = 0x%08X\n", i, state[i]);

    /* Run compression */
    sha256_compress(state, W);

    printf("\n=== After Compression (SHA-256 of \"abc\") ===\n");
    for (int i = 0; i < 8; i++)
        printf("H%d = 0x%08X\n", i, state[i]);

    printf("\nExpected:\n");
    printf("H0 = 0xBA7816BF\n");
    printf("H1 = 0x8F01CFEA\n");
    printf("H2 = 0x414140DE\n");
    printf("H3 = 0x5DAE2223\n");
    printf("H4 = 0xB00361A3\n");
    printf("H5 = 0x96177A9C\n");
    printf("H6 = 0xB410FF61\n");
    printf("H7 = 0xF20015AD\n");

    return 0;
}
