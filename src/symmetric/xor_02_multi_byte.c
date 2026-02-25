/*
 * Challenge 2: Multi-Byte Repeating Key XOR
 *
 * Goal: XOR encrypt/decrypt with a multi-byte key that repeats cyclically.
 *       For each byte at position i, XOR with key[i % key_length].
 *       Same function works for encrypt and decrypt (XOR is self-inverse).
 *
 * Tests:
 * "Hello, World!" XOR "KEY" → verify round-trip encrypt/decrypt
 *
 * "Burning 'em, if you ain't quick and nimble" XOR "ICE"
 * → hex: 0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20
 */

#include <stdio.h>
#include <string.h>

/* Encrypt/decrypt with repeating XOR key */
void repeating_key_xor(const unsigned char *input, int input_len,
                       const unsigned char *key, int key_len,
                       unsigned char *output)
{
    /* Your code here */
}

/* Print byte array as hex string */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    /* Test 1: Round-trip with "Hello, World!" and key "KEY" */
    const char *plaintext1 = "Hello, World!";
    const char *key1 = "KEY";
    unsigned char encrypted[256];
    unsigned char decrypted[256];

    printf("=== Test 1: Round-trip ===\n");
    printf("Plaintext: %s\n", plaintext1);
    printf("Key: %s\n", key1);

    repeating_key_xor((unsigned char *)plaintext1, strlen(plaintext1),
                      (unsigned char *)key1, strlen(key1), encrypted);
    printf("Encrypted (hex): ");
    print_hex(encrypted, strlen(plaintext1));
    printf("\n");

    repeating_key_xor(encrypted, strlen(plaintext1),
                      (unsigned char *)key1, strlen(key1), decrypted);
    decrypted[strlen(plaintext1)] = '\0';
    printf("Decrypted: %s\n\n", decrypted);

    /* Test 2: Known answer test */
    const char *plaintext2 = "Burning 'em, if you ain't quick and nimble";
    const char *key2 = "ICE";

    printf("=== Test 2: Known answer ===\n");
    printf("Plaintext: %s\n", plaintext2);
    printf("Key: %s\n", key2);

    repeating_key_xor((unsigned char *)plaintext2, strlen(plaintext2),
                      (unsigned char *)key2, strlen(key2), encrypted);
    printf("Encrypted (hex): ");
    print_hex(encrypted, strlen(plaintext2));
    printf("\n");
    printf("Expected:        0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20\n");

    return 0;
}
