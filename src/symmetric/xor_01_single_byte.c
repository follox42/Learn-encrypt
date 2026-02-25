/*
 * Challenge 1: Single-Byte XOR Encrypt/Decrypt
 *
 * Goal: XOR encrypt and decrypt a message with a single byte key.
 *       Every byte of the input is XOR-ed with the same key byte.
 *       The same operation works for both encryption and decryption
 *       because XOR is self-inverse: (A ^ K) ^ K = A
 *
 * Tests:
 * "Hello" XOR 0x4B → hex: 03 2E 27 27 24
 * Decrypt: hex 03 2E 27 27 24 XOR 0x4B → "Hello"
 */

#include <stdio.h>
#include <string.h>

/* XOR encrypt/decrypt a byte array with a single key byte */
void single_byte_xor(const unsigned char *input, int len,
                     unsigned char key, unsigned char *output)
{
    /* Your code here */
}

/* Print a byte array as a hex string */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    const char *plaintext = "Hello";
    unsigned char key = 0x4B;
    int len = strlen(plaintext);
    unsigned char encrypted[256];
    unsigned char decrypted[256];

    printf("=== Single-Byte XOR ===\n");
    printf("Plaintext: %s\n", plaintext);
    printf("Key: 0x%02X\n", key);

    /* Encrypt */
    single_byte_xor((unsigned char *)plaintext, len, key, encrypted);
    printf("Encrypted (hex): ");
    print_hex(encrypted, len);
    printf("\n");
    printf("Expected:        03 2E 27 27 24\n\n");

    /* Decrypt (same operation) */
    single_byte_xor(encrypted, len, key, decrypted);
    decrypted[len] = '\0';
    printf("Decrypted: %s\n", decrypted);
    printf("Expected:  Hello\n");

    return 0;
}
