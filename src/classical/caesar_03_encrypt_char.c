/*
 * Challenge 3: Encrypt Single Character
 *
 * Goal: Encrypt one character with Caesar cipher
 *
 * Tests:
 * ('A', 3) → 'D'
 * ('Z', 3) → 'C'
 * ('a', 3) → 'd'
 * ('5', 3) → '5' (non-letter unchanged)
 */

#include <stdio.h>

int mod(int a, int n)
{
    // Copy your mod() function from fundamentals/challenge_06
    return 0;
}

char caesar_encrypt_char(char c, int shift)
{
    // Your code here
    return c;
}

int main(void)
{
    printf("('A', 3) → '%c'\n", caesar_encrypt_char('A', 3));
    printf("('Z', 3) → '%c'\n", caesar_encrypt_char('Z', 3));
    printf("('a', 3) → '%c'\n", caesar_encrypt_char('a', 3));
    printf("('5', 3) → '%c'\n", caesar_encrypt_char('5', 3));
    return 0;
}
