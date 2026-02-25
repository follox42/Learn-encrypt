/*
 * Challenge 5: Kasiski Examination
 *
 * Goal: Find repeated sequences in ciphertext to guess the key length.
 *
 * Concept:
 *   When the same plaintext aligns with the same key position, it produces
 *   identical ciphertext. The distance between these repeated sequences is
 *   a multiple of the key length.
 *
 * Algorithm:
 *   1. Scan the ciphertext for all repeated substrings of length >= 3
 *   2. For each repeated substring, record the positions where it appears
 *   3. Compute the distances between positions
 *   4. Find the GCD of all distances
 *   5. The GCD is the likely key length
 *
 * Example:
 *   Ciphertext: "ABCXYZABCMNOPQRABCXYZ"
 *   "ABC" appears at positions 0, 6, 15
 *   Distances: 6, 15, 9
 *   GCD(6, 15, 9) = 3
 *   → Likely key length = 3
 *
 * This is an open-ended challenge. Suggested functions:
 *
 *   int gcd(int a, int b);
 *   void find_repeated_sequences(const char *ciphertext, int min_length);
 */

#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    // Your code here
    // Euclidean algorithm: gcd(a, b) = gcd(b, a % b), base case: gcd(a, 0) = a
    return 0;
}

void find_repeated_sequences(const char *ciphertext, int min_length)
{
    // Your code here
    // 1. For each position i in the ciphertext:
    //    - Extract a substring of length min_length starting at i
    //    - Search for the same substring later in the ciphertext
    //    - If found, print the substring, both positions, and the distance
    // 2. After finding all distances, compute the GCD
    // 3. Print the likely key length
    //
    // Hint: use strncmp() to compare substrings
    // Hint: be careful not to count overlapping matches twice
}

int main(void)
{
    /* Example ciphertext encrypted with a key of length 3 */
    const char *ciphertext = "ABCXYZABCMNOPQRABCXYZ";

    printf("Ciphertext: \"%s\"\n", ciphertext);
    printf("Looking for repeated sequences (min length 3)...\n\n");

    find_repeated_sequences(ciphertext, 3);

    return 0;
}
