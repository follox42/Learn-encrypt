/*
 * Challenge 5: Full SHA-256 Hash
 *
 * Goal: Implement the complete SHA-256 hash function.
 *       Combine padding, message schedule, and compression.
 *
 * Tests (from NIST examples):
 * sha256("")
 *   = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"
 *
 * sha256("abc")
 *   = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"
 *
 * sha256("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq")
 *   = "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Computes the SHA-256 hash of the input message.
 * digest: output buffer, must be at least 32 bytes.
 *
 * Steps:
 * 1. Pad the message (from challenge 1, big-endian length)
 * 2. Initialize state: H0..H7 (from square roots of first 8 primes)
 * 3. For each 512-bit block:
 *    a. Parse block into 16 big-endian 32-bit words
 *    b. Expand to 64 words via message schedule (challenge 3)
 *    c. Run compression function with 64 rounds (challenge 4)
 *    d. Add results back to running state
 * 4. Write final state to digest in big-endian byte order
 */
void sha256(const unsigned char *message, size_t len, unsigned char *digest)
{
    /* Your code here */
}

/*
 * Converts a 32-byte digest to a 64-character hex string.
 * hex_string must be at least 65 bytes (64 hex chars + null terminator).
 */
void sha256_to_hex(const unsigned char *digest, char *hex_string)
{
    /* Your code here */
}

int main(void)
{
    unsigned char digest[32];
    char hex[65];

    /* Test 1: empty string */
    sha256((unsigned char *)"", 0, digest);
    sha256_to_hex(digest, hex);
    printf("sha256(\"\")\n");
    printf("  = \"%s\"\n", hex);
    printf("exp \"e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855\"\n\n");

    /* Test 2: "abc" */
    sha256((unsigned char *)"abc", 3, digest);
    sha256_to_hex(digest, hex);
    printf("sha256(\"abc\")\n");
    printf("  = \"%s\"\n", hex);
    printf("exp \"ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad\"\n\n");

    /* Test 3: multi-block message */
    const char *long_msg = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";
    sha256((unsigned char *)long_msg, strlen(long_msg), digest);
    sha256_to_hex(digest, hex);
    printf("sha256(\"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq\")\n");
    printf("  = \"%s\"\n", hex);
    printf("exp \"248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1\"\n");

    return 0;
}
