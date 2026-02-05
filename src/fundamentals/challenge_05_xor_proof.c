/*
 * Challenge 5: XOR Encryption Proof
 *
 * Goal: Demonstrate that (A ^ K) ^ K == A
 *
 * Steps:
 * 1. Take a byte A and a key K
 * 2. Compute encrypted = A ^ K
 * 3. Compute decrypted = encrypted ^ K
 * 4. Verify decrypted == A
 */

#include <stdio.h>

int main(void)
{
    int A = 'A';
    int K = 'B';

    int encrypted = A ^ K;

    int decrypted = encrypted ^ K;
    if (decrypted == A) {
        printf("xor proof validated");
    };
    // Your code here
    return 0;
}
