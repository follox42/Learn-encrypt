/*
 * Challenge 6: Complete SHA-256 Tool
 *
 * Goal: Build a full-featured SHA-256 utility that can:
 *   1. Hash a string from the command line
 *   2. Hash the contents of a file
 *   3. Compare a computed hash against an expected hash
 *
 * Usage:
 *   ./sha256tool -s "string"            Hash a string
 *   ./sha256tool -f filename            Hash a file
 *   ./sha256tool -c filename.sha256     Verify checksums
 *   ./sha256tool --compare hash         Hash stdin and compare
 *
 * Expected output format (matches sha256sum):
 *   hash  filename
 *   hash  "string"
 *
 * Tests:
 *   ./sha256tool -s "abc"
 *   ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad  "abc"
 *
 *   echo -n "abc" > test.txt && ./sha256tool -f test.txt
 *   ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad  test.txt
 *
 *   Compare all output with the system sha256sum command.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Copy your sha256() and sha256_to_hex() from challenge 5.
 */
void sha256(const unsigned char *message, size_t len, unsigned char *digest)
{
    /* Your code here (copy from challenge 5) */
}

void sha256_to_hex(const unsigned char *digest, char *hex_string)
{
    /* Your code here (copy from challenge 5) */
}

/*
 * Hash a string and print the result.
 *
 * Output format: hash  "string"
 */
void hash_string(const char *str)
{
    /* Your code here */
}

/*
 * Read a file, compute its SHA-256 hash, and print the result.
 * Returns 0 on success, -1 on error.
 *
 * Output format: hash  filename
 *
 * Hints:
 * - Open in binary mode ("rb")
 * - Read the entire file into memory, or implement incremental hashing
 * - Close the file when done
 */
int hash_file(const char *filename)
{
    /* Your code here */
    return -1;
}

/*
 * Verify checksums from a file.
 * The file format is: hash  filename (one per line)
 * For each line, hash the referenced file and compare.
 * Print "filename: OK" or "filename: FAILED" for each.
 * Returns 0 if all checks pass, -1 if any fail.
 */
int verify_checksums(const char *checksum_file)
{
    /* Your code here */
    return -1;
}

/*
 * Hash data from stdin and compare to a given hash string.
 * Useful for piping: echo -n "test" | ./sha256tool --compare hash
 */
int compare_hash(const char *expected_hash)
{
    /* Your code here */
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("SHA-256 Hash Tool\n\n");
        printf("Usage:\n");
        printf("  %s -s \"string\"            Hash a string\n", argv[0]);
        printf("  %s -f filename            Hash a file\n", argv[0]);
        printf("  %s -c filename.sha256     Verify checksums\n", argv[0]);
        printf("  %s --compare hash         Hash stdin, compare to hash\n", argv[0]);
        return 1;
    }

    /* Your code here: parse argv[1] to determine the mode */
    /* Call the appropriate function based on the flag */

    return 0;
}
