/*
 * Challenge 3: Break Single-Byte XOR by Frequency Analysis
 *
 * Goal: Break a single-byte XOR cipher without knowing the key.
 *       Try all 256 possible key bytes, decrypt with each,
 *       score by English character frequency, return the best key.
 *
 * Hint: The most common byte in English text is space (0x20),
 *       followed by 'e' (0x65), 't' (0x74), 'a' (0x61), etc.
 *       Score each candidate decryption by counting how many bytes
 *       are common English characters (letters, spaces).
 *
 * Tests:
 * Ciphertext (hex): "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
 * → Find the key byte that produces readable English plaintext
 */

#include <stdio.h>
#include <string.h>

/* Convert a hex string to byte array. Return number of bytes. */
int hex_to_bytes(const char *hex, unsigned char *bytes)
{
    /* Your code here */
    return 0;
}

/* Score a byte array by how much it looks like English text.
 * Higher score = more likely English.
 * Count letters, spaces, common punctuation. */
int score_english(const unsigned char *data, int len)
{
    /* Your code here */
    return 0;
}

/* Try all 256 keys, return the best key byte.
 * Write the best decryption into plaintext buffer. */
int break_single_byte_xor(const unsigned char *ciphertext, int len,
                          unsigned char *plaintext)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    const char *hex_cipher = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    unsigned char ciphertext[256];
    int len = hex_to_bytes(hex_cipher, ciphertext);

    unsigned char plaintext[256];
    int key = break_single_byte_xor(ciphertext, len, plaintext);

    plaintext[len] = '\0';
    printf("Key byte: 0x%02X\n", key);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}
