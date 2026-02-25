/*
 * Challenge 4: Break Repeating-Key XOR
 *
 * Goal: Break a repeating-key XOR cipher without knowing the key.
 *       Combines Kasiski-style key length detection with single-byte breaking.
 *
 * Approach:
 * 1. Hamming distance: count differing bits between two byte sequences.
 *    Test: hamming_distance("this is a test", "wokka wokka!!!") = 37
 *
 * 2. Find key length: for each candidate length L (2 to 40),
 *    take the first few blocks of size L, compute normalized Hamming distance
 *    (distance / L). The correct key length gives the lowest normalized distance.
 *    Why? At the correct shift, you compare plaintext-vs-plaintext patterns
 *    (low Hamming distance) rather than random data.
 *
 * 3. Split into groups: group every L-th byte together.
 *    Bytes at positions 0, L, 2L, 3L, ... all use key[0].
 *    Bytes at positions 1, L+1, 2L+1, ... all use key[1].
 *
 * 4. Break each group as single-byte XOR (reuse Challenge 3 logic).
 *
 * 5. Reconstruct the full key from the individual key bytes.
 *
 * Tests:
 * Encrypt a known long message with a known key,
 * then break it and verify the key is recovered correctly.
 */

#include <stdio.h>
#include <string.h>

/* Count the number of differing bits between two byte sequences */
int hamming_distance(const unsigned char *a, const unsigned char *b, int len)
{
    /* Your code here */
    return 0;
}

/* Find the most likely key length (try lengths 2 to max_key_len) */
int find_key_length(const unsigned char *ciphertext, int len, int max_key_len)
{
    /* Your code here */
    return 0;
}

/* Score a byte array by English frequency (reuse from Challenge 3) */
int score_english(const unsigned char *data, int len)
{
    /* Your code here */
    return 0;
}

/* Break single-byte XOR on a group of bytes (reuse from Challenge 3) */
int break_single_byte(const unsigned char *data, int len)
{
    /* Your code here */
    return 0;
}

/* Break repeating-key XOR. Returns key length, fills key buffer. */
int break_repeating_key_xor(const unsigned char *ciphertext, int len,
                            unsigned char *key, int max_key_len)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    /* Test 1: Hamming distance */
    const char *s1 = "this is a test";
    const char *s2 = "wokka wokka!!!";
    int dist = hamming_distance((unsigned char *)s1, (unsigned char *)s2,
                                strlen(s1));
    printf("Hamming distance: %d (expected: 37)\n\n", dist);

    /* Test 2: Encrypt a known message, then break it */
    const char *secret_message = "This is a secret message that should be long "
                                 "enough to allow frequency analysis to work "
                                 "correctly when breaking repeating key XOR.";
    const char *secret_key = "MYKEY";
    int msg_len = strlen(secret_message);
    int key_len = strlen(secret_key);

    /* Encrypt (this part is given so you can test your breaker) */
    unsigned char ciphertext[512];
    for (int i = 0; i < msg_len; i++)
        ciphertext[i] = secret_message[i] ^ secret_key[i % key_len];

    /* Break it */
    unsigned char recovered_key[64];
    int recovered_len = break_repeating_key_xor(ciphertext, msg_len,
                                                recovered_key, 40);

    printf("Recovered key length: %d (expected: %d)\n", recovered_len, key_len);
    recovered_key[recovered_len] = '\0';
    printf("Recovered key: \"%s\" (expected: \"%s\")\n", recovered_key,
           secret_key);

    return 0;
}
