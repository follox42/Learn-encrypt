/*
 * Challenge 4: RSA Key Generation
 *
 * Goal: Generate an RSA key pair from two primes.
 *       Compute n = p * q, phi = (p-1)*(q-1), choose e, compute d.
 *       Uses functions from challenges 2 and 3.
 *
 * Key generation steps:
 *   1. Compute n = p * q
 *   2. Compute phi = (p-1) * (q-1)
 *   3. Choose e coprime to phi (try 65537, then 17, or find smallest)
 *   4. Compute d = mod_inverse(e, phi)
 *
 * Tests:
 *   p=61, q=53  -> n=3233, phi=3120, e=17, d=2753
 *     Check: (17 * 2753) % 3120 == 1
 *
 *   p=11, q=13  -> n=143, phi=120, e=7, d=103
 *     Check: (7 * 103) % 120 == 1
 */

#include <stdio.h>

typedef struct {
    long long n;    /* modulus */
    long long e;    /* public exponent */
    long long d;    /* private exponent */
} rsa_key_t;

long long gcd(long long a, long long b)
{
    /* Your code here (or copy from challenge 2) */
    return 0;
}

long long mod_inverse(long long a, long long mod)
{
    /* Your code here (or copy from challenge 2) */
    return 0;
}

rsa_key_t rsa_keygen(long long p, long long q)
{
    rsa_key_t key;
    /* Your code here */
    /* 1. Compute n = p * q */
    /* 2. Compute phi = (p-1) * (q-1) */
    /* 3. Choose e (try 65537, then 17, or find smallest coprime to phi) */
    /* 4. Compute d = mod_inverse(e, phi) */
    key.n = 0;
    key.e = 0;
    key.d = 0;
    return key;
}

int main(void)
{
    printf("=== RSA Key Generation ===\n\n");

    rsa_key_t key1 = rsa_keygen(61, 53);
    printf("p=61, q=53:\n");
    printf("  n = %lld (expected 3233)\n", key1.n);
    printf("  e = %lld (expected 17)\n", key1.e);
    printf("  d = %lld (expected 2753)\n", key1.d);
    printf("  Verify: (e * d) %% phi = %lld (expected 1)\n", (key1.e * key1.d) % 3120LL);
    printf("\n");

    rsa_key_t key2 = rsa_keygen(11, 13);
    printf("p=11, q=13:\n");
    printf("  n = %lld (expected 143)\n", key2.n);
    printf("  e = %lld\n", key2.e);
    printf("  d = %lld\n", key2.d);
    printf("  Verify: (e * d) %% phi = %lld (expected 1)\n", (key2.e * key2.d) % 120LL);
    return 0;
}
