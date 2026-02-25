/*
 * Challenge 7: Digital Signatures
 *
 * Goal: Sign a message hash with the RSA private key and verify
 *       the signature with the public key.
 *
 * Signing:
 *   signature = hash^d mod n  (use private key)
 *
 * Verification:
 *   recovered_hash = signature^e mod n  (use public key)
 *   Compare recovered_hash with the original hash
 *   If they match, the signature is valid
 *
 * Also implement a simple hash function for strings
 * (sum of ASCII values mod n).
 *
 * Tests (using e=17, d=2753, n=3233):
 *   sig = rsa_sign(42, 2753, 3233)
 *   rsa_verify(42, sig, 17, 3233)          = 1  (valid)
 *   rsa_verify(43, sig, 17, 3233)          = 0  (invalid - wrong hash)
 *   rsa_verify(42, sig + 1, 17, 3233)      = 0  (invalid - tampered)
 */

#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod)
{
    /* Your code here (or copy from challenge 1) */
    return 0;
}

long long rsa_sign(long long message_hash, long long d, long long n)
{
    /* Your code here */
    /* Sign: signature = hash^d mod n */
    return 0;
}

int rsa_verify(long long message_hash, long long signature, long long e, long long n)
{
    /* Your code here */
    /* Verify: recovered = signature^e mod n, compare with hash */
    /* Return 1 if valid, 0 if invalid */
    return 0;
}

/* Simple hash: sum of ASCII values mod n */
long long simple_hash(const char *message, long long n)
{
    /* Your code here */
    /* Sum all ASCII values of the characters, then mod n */
    return 0;
}

int main(void)
{
    long long e = 17;
    long long d = 2753;
    long long n = 3233;

    /* Test 1: Sign and verify a hash */
    printf("=== Digital Signatures ===\n\n");
    long long hash = 42;
    long long sig = rsa_sign(hash, d, n);
    printf("Hash:      %lld\n", hash);
    printf("Signature: %lld\n", sig);
    printf("Valid:     %d (expected 1)\n", rsa_verify(hash, sig, e, n));

    /* Test 2: Wrong hash should fail */
    printf("Wrong hash: %d (expected 0)\n", rsa_verify(43, sig, e, n));

    /* Test 3: Tampered signature should fail */
    printf("Tampered:   %d (expected 0)\n", rsa_verify(hash, sig + 1, e, n));

    /* Test 4: Sign a string message */
    printf("\n=== String message test ===\n\n");
    const char *msg = "Hello RSA";
    long long msg_hash = simple_hash(msg, n);
    long long msg_sig = rsa_sign(msg_hash, d, n);
    printf("Message:   \"%s\"\n", msg);
    printf("Hash:      %lld\n", msg_hash);
    printf("Signature: %lld\n", msg_sig);
    printf("Valid:     %d (expected 1)\n", rsa_verify(msg_hash, msg_sig, e, n));
    return 0;
}
