/*
 * Challenge 5: MD5 Collision Demonstration
 *
 * Goal: Demonstrate that MD5 is broken by verifying a known collision
 *       pair -- two different inputs that produce the same MD5 hash.
 *
 * This challenge does NOT ask you to find a collision (that requires
 * specialized algorithms like Wang's differential attack). Instead,
 * you will:
 *   1. Hardcode two known colliding byte sequences
 *   2. Compute the MD5 hash of each
 *   3. Show that the inputs are different but the hashes are identical
 *
 * Known collision example (from Marc Stevens, 2007):
 * Two 128-byte messages that produce the same MD5 hash.
 * The messages differ in only a few bytes.
 *
 * Steps:
 *   1. Copy your md5() function from challenge 4
 *   2. Define two byte arrays with known colliding inputs
 *   3. Hash both and print the results
 *   4. Compare the inputs byte-by-byte to show they differ
 *   5. Compare the hashes to show they match
 *
 * This proves why MD5 must never be used for digital signatures,
 * certificates, or any security-critical application.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
 * Copy your md5() and md5_to_hex() from challenge 4.
 */
void md5(const unsigned char *message, size_t len, unsigned char *digest)
{
    /* Your code here (copy from challenge 4) */
}

void md5_to_hex(const unsigned char *digest, char *hex_string)
{
    /* Your code here (copy from challenge 4) */
}

/*
 * Prints a byte array in hex format, 16 bytes per line.
 */
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

/*
 * Demonstrate MD5 collision.
 *
 * TODO:
 * 1. Define two byte arrays (message_a and message_b) containing
 *    a known MD5 collision pair. Search for "MD5 collision example
 *    bytes" to find published pairs.
 * 2. Hash both messages with your md5() function
 * 3. Print both messages in hex
 * 4. Print both hashes
 * 5. Compare: show that messages differ but hashes match
 */
void demonstrate_collision(void)
{
    /* Your code here */

    /*
     * Example structure:
     *
     * unsigned char message_a[128] = { ... known collision bytes ... };
     * unsigned char message_b[128] = { ... known collision bytes ... };
     *
     * unsigned char digest_a[16], digest_b[16];
     * char hex_a[33], hex_b[33];
     *
     * md5(message_a, 128, digest_a);
     * md5(message_b, 128, digest_b);
     * md5_to_hex(digest_a, hex_a);
     * md5_to_hex(digest_b, hex_b);
     *
     * printf("Message A:\n"); print_hex(message_a, 128);
     * printf("Message B:\n"); print_hex(message_b, 128);
     *
     * printf("MD5(A) = %s\n", hex_a);
     * printf("MD5(B) = %s\n", hex_b);
     *
     * // Show where messages differ
     * int diff_count = 0;
     * for (int i = 0; i < 128; i++) {
     *     if (message_a[i] != message_b[i]) {
     *         printf("Byte %d differs: 0x%02x vs 0x%02x\n",
     *                i, message_a[i], message_b[i]);
     *         diff_count++;
     *     }
     * }
     * printf("Total bytes that differ: %d\n", diff_count);
     * printf("Hashes match: %s\n",
     *        strcmp(hex_a, hex_b) == 0 ? "YES" : "NO");
     */
}

int main(void)
{
    printf("=== MD5 Collision Demonstration ===\n\n");
    demonstrate_collision();
    return 0;
}
