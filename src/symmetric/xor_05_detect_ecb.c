/*
 * Challenge 5: Detect ECB Mode (Repeated Blocks)
 *
 * Goal: Detect if data was encrypted using ECB mode by looking
 *       for repeated blocks in the ciphertext.
 *
 * Concept:
 * In ECB (Electronic Codebook) mode, each block of plaintext is
 * encrypted independently with the same key. This means identical
 * plaintext blocks produce identical ciphertext blocks. If you see
 * repeated blocks in the ciphertext, it was almost certainly
 * encrypted with ECB mode.
 *
 * Approach:
 * 1. Choose a block size (16 bytes for AES, 8 bytes for DES)
 * 2. Split the ciphertext into blocks of that size
 * 3. Compare all blocks pairwise (or use sorting/hashing)
 * 4. If any two blocks are identical, flag it as ECB
 *
 * Tests:
 * - Create a plaintext with repeated 16-byte blocks,
 *   encrypt with a repeating key, and detect the repetition
 * - Random ciphertext should have no repeated blocks
 * - Count and report how many duplicate blocks are found
 */

#include <stdio.h>
#include <string.h>

/* Check if two blocks of given size are identical */
int blocks_equal(const unsigned char *a, const unsigned char *b, int block_size)
{
    /* Your code here */
    return 0;
}

/* Count the number of duplicate blocks in the data.
 * Returns the number of duplicate pairs found.
 * block_size is typically 16 (AES) or 8 (DES). */
int count_duplicate_blocks(const unsigned char *data, int len, int block_size)
{
    /* Your code here */
    return 0;
}

/* Detect if data was likely encrypted with ECB mode.
 * Returns 1 if ECB detected (duplicates found), 0 otherwise. */
int detect_ecb(const unsigned char *data, int len, int block_size)
{
    /* Your code here */
    return 0;
}

/* Print byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    /* Test 1: Data with repeated blocks (should detect ECB) */
    printf("=== Test 1: Repeated blocks ===\n");
    unsigned char ecb_data[64];
    /* Fill with two identical 16-byte blocks */
    for (int i = 0; i < 16; i++) {
        ecb_data[i] = (unsigned char)(i * 17);       /* Block 0 */
        ecb_data[16 + i] = (unsigned char)(i * 17);   /* Block 1 = Block 0 */
        ecb_data[32 + i] = (unsigned char)(i * 31);   /* Block 2 (different) */
        ecb_data[48 + i] = (unsigned char)(i * 17);   /* Block 3 = Block 0 */
    }
    int dup_count = count_duplicate_blocks(ecb_data, 64, 16);
    printf("Duplicate blocks found: %d (expected: > 0)\n", dup_count);
    printf("ECB detected: %s\n\n", detect_ecb(ecb_data, 64, 16) ? "YES" : "NO");

    /* Test 2: Random-looking data (should not detect ECB) */
    printf("=== Test 2: No repeated blocks ===\n");
    unsigned char random_data[64];
    for (int i = 0; i < 64; i++)
        random_data[i] = (unsigned char)(i * 37 + 13);  /* All different blocks */
    dup_count = count_duplicate_blocks(random_data, 64, 16);
    printf("Duplicate blocks found: %d (expected: 0)\n", dup_count);
    printf("ECB detected: %s\n", detect_ecb(random_data, 64, 16) ? "YES" : "NO");

    return 0;
}
