/*
 * Challenge 7: ROT13
 *
 * Goal: Implement ROT13 (Caesar with shift 13)
 *
 * Special property: encrypting twice gives the original
 *
 * Tests:
 * rot13("Hello")  → "Uryyb"
 * rot13("Uryyb")  → "Hello"
 * rot13(rot13(x)) == x (always!)
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

void rot13(char *input, char *output)
{
    // Your code here
}

int main(void)
{
    char input[] = "Hello, World!";
    char encrypted[256];
    char decrypted[256];

    rot13(input, encrypted);
    rot13(encrypted, decrypted);

    printf("Original:  %s\n", input);
    printf("ROT13:     %s\n", encrypted);
    printf("ROT13x2:   %s\n", decrypted);
    return 0;
}
