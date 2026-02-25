/*
 * Challenge 5: RSA Encryption
 *
 * Goal: Encrypt a number using the RSA public key.
 *       C = M^e mod n
 *
 * The message M must be a number less than n.
 * Uses modular exponentiation from challenge 1.
 *
 * Tests (using p=61, q=53, e=17, n=3233):
 *   encrypt(65, e=17, n=3233) = 2790
 *   encrypt(72, e=17, n=3233) = 2818
 *   encrypt(0, e=17, n=3233)  = 0
 *   encrypt(1, e=17, n=3233)  = 1
 */

#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod)
{
    /* Your code here (or copy from challenge 1) */
    return 0;
}

long long rsa_encrypt(long long message, long long e, long long n)
{
    /* Your code here */
    /* Encrypt: C = M^e mod n */
    return 0;
}

int main(void)
{
    long long e = 17;
    long long n = 3233;

    printf("=== RSA Encryption (e=%lld, n=%lld) ===\n\n", e, n);
    printf("encrypt(65, e, n) = %lld (expected 2790)\n", rsa_encrypt(65, e, n));
    printf("encrypt(72, e, n) = %lld (expected 2818)\n", rsa_encrypt(72, e, n));
    printf("encrypt(0, e, n)  = %lld (expected 0)\n", rsa_encrypt(0, e, n));
    printf("encrypt(1, e, n)  = %lld (expected 1)\n", rsa_encrypt(1, e, n));
    return 0;
}
