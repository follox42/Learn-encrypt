/*
 * Challenge 4: Full MD5 Hash
 *
 * Goal: Implement the complete MD5 hash function.
 *       Combine padding, state initialization, and all 4 rounds.
 *
 * Tests (from RFC 1321):
 * md5("")               = "d41d8cd98f00b204e9800998ecf8427e"
 * md5("a")              = "0cc175b9c0f1b6a831c399e269772661"
 * md5("abc")            = "900150983cd24fb0d6963f7d28e17f72"
 * md5("message digest") = "f96b697d7cb7938d525a2f31aaf161d0"
 * md5("abcdefghijklmnopqrstuvwxyz")
 *                       = "c3fcd3d76192e4007dfb496cca67e13b"
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Computes the MD5 hash of the input message.
 * digest: output buffer, must be at least 16 bytes.
 *
 * Steps:
 * 1. Pad the message (from challenge 1)
 * 2. Initialize state: a0=0x67452301, b0=0xEFCDAB89,
 *                      c0=0x98BADCFE, d0=0x10325476
 * 3. For each 512-bit block:
 *    - Split into 16 little-endian 32-bit words
 *    - Run all 4 rounds (64 operations total)
 *    - Add results back to the running state
 * 4. Write final state to digest in little-endian byte order
 */
void md5(const unsigned char *message, size_t len, unsigned char *digest)
{
    /* Your code here */
}

/*
 * Converts a 16-byte digest to a 32-character hex string.
 * hex_string must be at least 33 bytes (32 hex chars + null terminator).
 */
void md5_to_hex(const unsigned char *digest, char *hex_string)
{
    /* Your code here */
}

int main(void)
{
    unsigned char digest[16];
    char hex[33];

    /* Test 1 */
    md5((unsigned char *)"", 0, digest);
    md5_to_hex(digest, hex);
    printf("md5(\"\")               = \"%s\"\n", hex);
    printf("expected                = \"d41d8cd98f00b204e9800998ecf8427e\"\n\n");

    /* Test 2 */
    md5((unsigned char *)"a", 1, digest);
    md5_to_hex(digest, hex);
    printf("md5(\"a\")              = \"%s\"\n", hex);
    printf("expected                = \"0cc175b9c0f1b6a831c399e269772661\"\n\n");

    /* Test 3 */
    md5((unsigned char *)"abc", 3, digest);
    md5_to_hex(digest, hex);
    printf("md5(\"abc\")            = \"%s\"\n", hex);
    printf("expected                = \"900150983cd24fb0d6963f7d28e17f72\"\n\n");

    /* Test 4 */
    md5((unsigned char *)"message digest", 14, digest);
    md5_to_hex(digest, hex);
    printf("md5(\"message digest\") = \"%s\"\n", hex);
    printf("expected                = \"f96b697d7cb7938d525a2f31aaf161d0\"\n\n");

    /* Test 5 */
    md5((unsigned char *)"abcdefghijklmnopqrstuvwxyz", 26, digest);
    md5_to_hex(digest, hex);
    printf("md5(\"abcdefghijklmnopqrstuvwxyz\")\n");
    printf("                        = \"%s\"\n", hex);
    printf("expected                = \"c3fcd3d76192e4007dfb496cca67e13b\"\n");

    return 0;
}
