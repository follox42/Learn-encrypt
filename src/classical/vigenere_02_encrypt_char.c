/*
 * Challenge 2: Encrypt Single Character
 *
 * Goal: Encrypt one character using a key character.
 *       The key character determines the shift (A=0, B=1, ..., Z=25).
 *       Preserve case of the plaintext character.
 *       Non-alphabetic characters are returned unchanged.
 *
 * Tests:
 * ('H', 'K') → 'R'     (7 + 10 = 17)
 * ('e', 'K') → 'o'     (4 + 10 = 14, lowercase preserved)
 * ('Z', 'B') → 'A'     (25 + 1 = 0, wraps around)
 * ('5', 'K') → '5'     (non-letter unchanged)
 * (' ', 'A') → ' '     (space unchanged)
 */

#include <stdio.h>

int mod(int a, int n)
{
    // Copy your mod() function from fundamentals/challenge_06
    return 0;
}

char vigenere_encrypt_char(char plain, char key)
{
    // Your code here
    // 1. If plain is not a letter, return it unchanged
    // 2. Convert key to a shift value (0-25): toupper(key) - 'A'
    // 3. Apply the shift like Caesar: (pos + shift) mod 26
    // 4. Preserve the case of the original character
    return plain;
}

int main(void)
{
    printf("('H', 'K') → '%c'\n", vigenere_encrypt_char('H', 'K'));
    printf("('e', 'K') → '%c'\n", vigenere_encrypt_char('e', 'K'));
    printf("('Z', 'B') → '%c'\n", vigenere_encrypt_char('Z', 'B'));
    printf("('5', 'K') → '%c'\n", vigenere_encrypt_char('5', 'K'));
    printf("(' ', 'A') → '%c'\n", vigenere_encrypt_char(' ', 'A'));

    return 0;
}
