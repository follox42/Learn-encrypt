/*
 * Challenge 6: Brute Force
 *
 * Goal: Try all 26 shifts to break a Caesar cipher
 *
 * Test:
 * ciphertext = "Khoor"
 *
 * Expected:
 * Shift 0: Khoor
 * Shift 1: Jgnnq
 * Shift 2: Ifmmp
 * Shift 3: Hello  <-- correct
 * ...
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

void caesar_bruteforce(char *ciphertext)
{
    // Your code here
}

int main(void)
{
    char ciphertext[] = "Khoor, Zruog!";

    printf("Ciphertext: %s\n\n", ciphertext);
    caesar_bruteforce(ciphertext);
    return 0;
}
