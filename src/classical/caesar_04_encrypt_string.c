/*
 * Challenge 4: Encrypt String
 *
 * Goal: Encrypt an entire string with Caesar cipher
 *
 * Test:
 * plaintext = "Hello, World!"
 * shift = 3
 * ciphertext = "Khoor, Zruog!"
 *
 * Requirements:
 * - Preserve case (H→K, h→k)
 * - Keep non-letters unchanged (space, comma, !)
 * - Use your caesar_encrypt_char() function
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

void caesar_encrypt(char *plaintext, char *ciphertext, int shift)
{
    // Your code here
}

int main(void)
{
    char plaintext[] = "Hello, World!";
    char ciphertext[256];

    caesar_encrypt(plaintext, ciphertext, 3);
    printf("Plaintext:  %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
