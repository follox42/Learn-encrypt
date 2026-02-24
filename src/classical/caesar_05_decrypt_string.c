/*
 * Challenge 5: Decrypt String
 *
 * Goal: Decrypt a Caesar-encrypted string
 *
 * Test:
 * ciphertext = "Khoor, Zruog!"
 * shift = 3
 * plaintext = "Hello, World!"
 *
 * Hint: Decryption is encryption with -shift
 */

#include <stdio.h>

int mod(int a, int n)
{
    // Copy from challenge_06
    return 0;
}

char caesar_encrypt_char(char c, int shift)
{
    // Copy from challenge_03
    return c;
}

void caesar_decrypt(char *ciphertext, char *plaintext, int shift)
{
    // Your code here
}

int main(void)
{
    char ciphertext[] = "Khoor, Zruog!";
    char plaintext[256];

    caesar_decrypt(ciphertext, plaintext, 3);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext:  %s\n", plaintext);
    return 0;
}
