/*
 * Challenge 1: SHA-256 Message Padding
 *
 * Goal: Pad a message to a 512-bit (64-byte) boundary following the
 *       SHA-256 padding rules:
 *       1. Append 0x80 byte
 *       2. Append 0x00 bytes until 8 bytes remain in the block
 *       3. Append original length in bits as 64-bit BIG-ENDIAN integer
 *
 * Key difference from MD5: the length field is big-endian, and the
 * message words are also interpreted as big-endian.
 *
 * Tests:
 * pad("abc") -> 64 bytes:
 *   61 62 63 80 00 00 00 00  00 00 00 00 00 00 00 00
 *   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
 *   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
 *   00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 18
 *
 * pad("")    -> 64 bytes: 80 00...00 00 00 00 00 00 00 00 00
 * pad(56 x 'a') -> 128 bytes (needs two blocks)
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Pads the message following SHA-256 rules and writes to output.
 * Returns the total number of bytes in the padded output.
 * output must be large enough to hold the padded message.
 *
 * Hints:
 * - Same structure as MD5 padding
 * - The only difference is the length is stored as big-endian
 * - For a length L in bits, the last 8 bytes should be:
 *     (L >> 56) & 0xFF, (L >> 48) & 0xFF, ..., L & 0xFF
 */
int sha256_pad(const unsigned char *message, size_t len, unsigned char *output)
{
    /* Your code here */
    return 0;
}

void print_hex(const unsigned char *data, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        printf("%02x ", data[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    if (len % 16 != 0)
        printf("\n");
}

int main(void)
{
    unsigned char output[256];
    int padded_len;

    /* Test 1: "abc" */
    printf("=== Padding \"abc\" ===\n");
    padded_len = sha256_pad((unsigned char *)"abc", 3, output);
    printf("Padded length: %d bytes (expected 64)\n", padded_len);
    print_hex(output, padded_len);
    /* Last byte should be 0x18 (24 bits in big-endian) */

    /* Test 2: empty string */
    printf("\n=== Padding \"\" ===\n");
    padded_len = sha256_pad((unsigned char *)"", 0, output);
    printf("Padded length: %d bytes (expected 64)\n", padded_len);
    print_hex(output, padded_len);

    /* Test 3: 56 bytes (needs two blocks) */
    printf("\n=== Padding 56 x 'a' ===\n");
    unsigned char input56[56];
    memset(input56, 'a', 56);
    padded_len = sha256_pad(input56, 56, output);
    printf("Padded length: %d bytes (expected 128)\n", padded_len);

    return 0;
}
