/*
 * Challenge 6: RSA Decryption
 *
 * Goal: Decrypt a ciphertext using the RSA private key.
 *       M = C^d mod n
 *       Verify that decrypt(encrypt(M)) == M
 *
 * Uses modular exponentiation from challenge 1.
 *
 * Tests (using d=2753, n=3233):
 *   decrypt(2790, d=2753, n=3233) = 65
 *   decrypt(2818, d=2753, n=3233) = 72
 *   decrypt(0, d=2753, n=3233)    = 0
 */

#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod)
{
    /* Your code here (or copy from challenge 1) */
    return 0;
}

long long rsa_encrypt(long long message, long long e, long long n)
{
    /* Your code here (or copy from challenge 5) */
    return 0;
}

long long rsa_decrypt(long long ciphertext, long long d, long long n)
{
    /* Your code here */
    /* Decrypt: M = C^d mod n */
    return 0;
}

int main(void)
{
    long long e = 17;
    long long d = 2753;
    long long n = 3233;

    printf("=== RSA Decryption (d=%lld, n=%lld) ===\n\n", d, n);
    printf("decrypt(2790, d, n) = %lld (expected 65)\n", rsa_decrypt(2790, d, n));
    printf("decrypt(2818, d, n) = %lld (expected 72)\n", rsa_decrypt(2818, d, n));
    printf("decrypt(0, d, n)    = %lld (expected 0)\n", rsa_decrypt(0, d, n));

    /* Round-trip test: encrypt then decrypt */
    printf("\n=== Round-trip test ===\n\n");
    long long original = 42;
    long long encrypted = rsa_encrypt(original, e, n);
    long long decrypted = rsa_decrypt(encrypted, d, n);
    printf("Original:  %lld\n", original);
    printf("Encrypted: %lld\n", encrypted);
    printf("Decrypted: %lld (should match original)\n", decrypted);
    return 0;
}
