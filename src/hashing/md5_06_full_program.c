/*
 * Challenge 6: Complete MD5 Tool
 *
 * Goal: Build a full-featured MD5 utility that can:
 *   1. Hash a string from the command line
 *   2. Hash the contents of a file
 *   3. Verify checksums from a checksum file
 *
 * Usage:
 *   ./md5tool -s "string"        Hash a string
 *   ./md5tool -f filename        Hash a file
 *   ./md5tool -c filename.md5    Verify checksums
 *
 * Expected output format (matches md5sum):
 *   hash  filename
 *   hash  "string"
 *
 * Tests:
 *   ./md5tool -s "abc"
 *   900150983cd24fb0d6963f7d28e17f72  "abc"
 *
 *   echo -n "abc" > test.txt && ./md5tool -f test.txt
 *   900150983cd24fb0d6963f7d28e17f72  test.txt
 *
 *   Compare all output with the system md5sum command.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

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
 * Hash a string and print the result.
 *
 * Output format: hash  "string"
 */
void hash_string(const char *str)
{
    /* Your code here */
}

/*
 * Read a file, compute its MD5 hash, and print the result.
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
 *
 * Hints:
 * - Read each line from the checksum file
 * - Parse the hash (first 32 hex chars) and filename (after two spaces)
 * - Hash the file and compare with the stored hash
 */
int verify_checksums(const char *checksum_file)
{
    /* Your code here */
    return -1;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("MD5 Hash Tool\n\n");
        printf("Usage:\n");
        printf("  %s -s \"string\"        Hash a string\n", argv[0]);
        printf("  %s -f filename        Hash a file\n", argv[0]);
        printf("  %s -c filename.md5    Verify checksums\n", argv[0]);
        return 1;
    }

    /* Your code here: parse argv[1] to determine the mode (-s, -f, -c) */
    /* Call the appropriate function based on the flag */

    return 0;
}
