/*
 * Challenge 1: MD5 Message Padding
 *
 * Goal: Pad a message to a 512-bit (64-byte) boundary following the
 *       MD5 padding rules:
 *       1. Append 0x80 byte
 *       2. Append 0x00 bytes until 8 bytes remain in the block
 *       3. Append original length in bits as 64-bit little-endian
 *
 * Tests:
 * pad("abc")         -> 64 bytes: 61 62 63 80 00...00 18 00 00 00 00 00 00 00
 * pad("")            -> 64 bytes: 80 00...00 00 00 00 00 00 00 00 00
 * pad(55 x 'a')      -> 64 bytes (fits in one block)
 * pad(56 x 'a')      -> 128 bytes (needs two blocks)
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Pads the message and writes the result to output.
 * Returns the total number of bytes in the padded output.
 * output must be large enough to hold the padded message.
 */
int md5_pad(const unsigned char *message, size_t len, unsigned char *output)
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
    padded_len = md5_pad((unsigned char *)"abc", 3, output);
    printf("Padded length: %d bytes (expected 64)\n", padded_len);
    print_hex(output, padded_len);

    /* Test 2: empty string */
    printf("\n=== Padding \"\" ===\n");
    padded_len = md5_pad((unsigned char *)"", 0, output);
    printf("Padded length: %d bytes (expected 64)\n", padded_len);
    print_hex(output, padded_len);

    /* Test 3: 55 bytes (should fit in one block) */
    printf("\n=== Padding 55 x 'a' ===\n");
    unsigned char input55[55];
    memset(input55, 'a', 55);
    padded_len = md5_pad(input55, 55, output);
    printf("Padded length: %d bytes (expected 64)\n", padded_len);

    /* Test 4: 56 bytes (needs two blocks) */
    printf("\n=== Padding 56 x 'a' ===\n");
    unsigned char input56[56];
    memset(input56, 'a', 56);
    padded_len = md5_pad(input56, 56, output);
    printf("Padded length: %d bytes (expected 128)\n", padded_len);

    return 0;
}
