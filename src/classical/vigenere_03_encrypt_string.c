/*
 * Challenge 3: Encrypt String
 *
 * Goal: Encrypt a full string using the Vigenere cipher.
 *       The key repeats to match the plaintext length.
 *       Non-alphabetic characters are copied unchanged and do NOT advance the key.
 *       Case is preserved from the plaintext.
 *
 * Tests:
 * ("Hello, World!", "KEY") → "Rijvs, Ambpb!"
 * ("ATTACKATDAWN", "LEMON") → "LXFOPVEFRNHR"
 * ("abc", "A")             → "abc"   (key 'A' = shift 0, no change)
 */

#include <stdio.h>
#include <string.h>

int mod(int a, int n)
{
    // Copy your mod() function from fundamentals/challenge_06
    return 0;
}

char vigenere_encrypt_char(char plain, char key)
{
    // Copy your function from vigenere_02
    return plain;
}

void vigenere_encrypt(const char *plaintext, const char *key, char *ciphertext)
{
    // Your code here
    // 1. Keep a key_index variable, starting at 0
    // 2. Loop through each character of plaintext
    // 3. If the character is a letter:
    //    - Encrypt it using key[key_index % key_length]
    //    - Advance key_index by 1
    // 4. If the character is NOT a letter:
    //    - Copy it unchanged
    //    - Do NOT advance key_index
    // 5. Null-terminate ciphertext
}

int main(void)
{
    char result[128];

    vigenere_encrypt("Hello, World!", "KEY", result);
    printf("\"Hello, World!\" + \"KEY\" → \"%s\"\n", result);

    vigenere_encrypt("ATTACKATDAWN", "LEMON", result);
    printf("\"ATTACKATDAWN\" + \"LEMON\" → \"%s\"\n", result);

    vigenere_encrypt("abc", "A", result);
    printf("\"abc\" + \"A\" → \"%s\"\n", result);

    return 0;
}
