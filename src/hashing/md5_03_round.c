/*
 * Challenge 3: One MD5 Round
 *
 * Goal: Implement one MD5 round (16 operations) that updates the
 *       state variables (a, b, c, d) using a message block.
 *
 * Structure of a round:
 *   - Each round performs 16 operations (steps)
 *   - Each round uses a different auxiliary function:
 *       Round 0: F(B,C,D)    Round 1: G(B,C,D)
 *       Round 2: H(B,C,D)    Round 3: I(B,C,D)
 *   - Each round accesses message words in a different order:
 *       Round 0: g = i
 *       Round 1: g = (5*i + 1) % 16
 *       Round 2: g = (3*i + 5) % 16
 *       Round 3: g = (7*i) % 16
 *   - Each step: A=D, D=C, C=B, B=B+left_rotate(A+func+K[i]+M[g], s[i])
 *
 * Tests:
 * Initial state: a=0x67452301, b=0xEFCDAB89, c=0x98BADCFE, d=0x10325476
 * Message block: padded "abc" (16 little-endian 32-bit words)
 * After round 1: compare with known MD5 intermediate values
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Copy your auxiliary functions from challenge 2, or reimplement them */

uint32_t F(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

uint32_t G(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

uint32_t H(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

uint32_t I(uint32_t B, uint32_t C, uint32_t D)
{
    /* Your code here */
    return 0;
}

uint32_t left_rotate(uint32_t x, uint32_t n)
{
    /* Your code here */
    return 0;
}

/*
 * The 64 K constants (derived from sin function):
 * K[i] = floor(2^32 * abs(sin(i + 1)))
 *
 * You need to fill this table. First few values:
 * K[0]  = 0xd76aa478, K[1]  = 0xe8c7b756, K[2]  = 0x242070db, ...
 */

/* The 64 shift amounts (s values), 4 per operation within each round */

/*
 * Perform one MD5 round (16 operations).
 * round_num: 0=F round, 1=G round, 2=H round, 3=I round
 * M: array of 16 message words (32-bit, little-endian)
 *
 * Steps for each of the 16 operations in this round:
 *   1. Select the auxiliary function based on round_num
 *   2. Compute f = aux_func(*b, *c, *d)
 *   3. Determine message word index g (depends on round_num)
 *   4. Compute: temp = *a + f + K[round_num*16 + i] + M[g]
 *   5. Left rotate: temp = left_rotate(temp, s[round_num*16 + i])
 *   6. Update state: *a = *d, *d = *c, *c = *b, *b = *b + temp
 */
void md5_round(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d,
               uint32_t *M, int round_num)
{
    /* Your code here */
}

int main(void)
{
    /* MD5 initial state */
    uint32_t a = 0x67452301;
    uint32_t b = 0xEFCDAB89;
    uint32_t c = 0x98BADCFE;
    uint32_t d = 0x10325476;

    /* Padded "abc" as 16 little-endian 32-bit words */
    uint32_t M[16] = {0};
    /* "abc" = 0x61, 0x62, 0x63 then 0x80 padding */
    M[0] = 0x80636261;  /* little-endian: 61 62 63 80 */
    M[14] = 24;          /* message length in bits (little-endian) */

    printf("=== Before Round 1 ===\n");
    printf("a = 0x%08X\n", a);
    printf("b = 0x%08X\n", b);
    printf("c = 0x%08X\n", c);
    printf("d = 0x%08X\n", d);

    md5_round(&a, &b, &c, &d, M, 0);

    printf("\n=== After Round 1 (F round) ===\n");
    printf("a = 0x%08X\n", a);
    printf("b = 0x%08X\n", b);
    printf("c = 0x%08X\n", c);
    printf("d = 0x%08X\n", d);

    return 0;
}
