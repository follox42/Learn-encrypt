/*
 * Challenge 2: GCD and Extended Euclidean Algorithm
 *
 * Goal: Implement the Euclidean algorithm for GCD and the Extended
 *       Euclidean algorithm to find modular inverses. The modular
 *       inverse is needed to compute the RSA private key exponent d.
 *
 * GCD algorithm:
 *   gcd(a, b) = gcd(b, a % b), base case: gcd(a, 0) = a
 *
 * Extended GCD:
 *   Find x, y such that: a*x + b*y = gcd(a, b)
 *
 * Modular inverse:
 *   Find x such that: (a * x) mod m = 1
 *   Only exists when gcd(a, m) = 1
 *
 * Tests:
 *   gcd(35, 15)           = 5
 *   gcd(12, 8)            = 4
 *   gcd(17, 3120)         = 1
 *   gcd(0, 5)             = 5
 *
 *   mod_inverse(7, 26)    = 15   (because 7 * 15 mod 26 = 1)
 *   mod_inverse(17, 3120) = 2753 (because 17 * 2753 mod 3120 = 1)
 *   mod_inverse(3, 26)    = 9    (because 3 * 9 mod 26 = 1)
 */

#include <stdio.h>

long long gcd(long long a, long long b)
{
    /* Your code here */
    return 0;
}

long long extended_gcd(long long a, long long b, long long *x, long long *y)
{
    /* Your code here */
    return 0;
}

long long mod_inverse(long long a, long long mod)
{
    /* Your code here */
    /* Use extended_gcd to find x such that a*x + mod*y = 1 */
    /* If x is negative, add mod to make it positive */
    return 0;
}

int main(void)
{
    printf("=== GCD ===\n\n");
    printf("gcd(35, 15)   = %lld (expected 5)\n", gcd(35, 15));
    printf("gcd(12, 8)    = %lld (expected 4)\n", gcd(12, 8));
    printf("gcd(17, 3120) = %lld (expected 1)\n", gcd(17, 3120));
    printf("gcd(0, 5)     = %lld (expected 5)\n", gcd(0, 5));

    printf("\n=== Modular Inverse ===\n\n");
    printf("mod_inverse(7, 26)    = %lld (expected 15)\n", mod_inverse(7, 26));
    printf("mod_inverse(17, 3120) = %lld (expected 2753)\n", mod_inverse(17, 3120));
    printf("mod_inverse(3, 26)    = %lld (expected 9)\n", mod_inverse(3, 26));

    /* Verification */
    printf("\n=== Verification ===\n\n");
    printf("7 * 15 mod 26       = %lld (expected 1)\n", (7LL * 15LL) % 26LL);
    printf("17 * 2753 mod 3120  = %lld (expected 1)\n", (17LL * 2753LL) % 3120LL);
    printf("3 * 9 mod 26        = %lld (expected 1)\n", (3LL * 9LL) % 26LL);
    return 0;
}
