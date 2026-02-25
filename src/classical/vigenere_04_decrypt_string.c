/*
 * Challenge 4: Decrypt String
 *
 * Goal: Decrypt a Vigenere-encrypted string back to plaintext.
 *       Decryption formula: P = (C - K[i]) mod 26
 *       Same rules as encryption: non-letters unchanged, key only
 *       advances for alphabetic characters, case preserved.
 *
 * Tests:
 * ("Rijvs, Ambpb!", "KEY")   → "Hello, World!"
 * ("LXFOPVEFRNHR", "LEMON")  → "ATTACKATDAWN"
 */

#include <stdio.h>
#include <string.h>

int mod(int a, int n)
{
    // Copy your mod() function from fundamentals/challenge_06
    // Important: must handle negative numbers correctly!
    // e.g., mod(-1, 26) should return 25, not -1
    return 0;
}

char vigenere_decrypt_char(char cipher, char key)
{
    // Your code here
    // Same as encrypt_char but SUBTRACT the shift instead of adding
    // P = (C - K) mod 26
    // Be careful with negative results! Use your mod() function.
    return cipher;
}

void vigenere_decrypt(const char *ciphertext, const char *key, char *plaintext)
{
    // Your code here
    // Same structure as vigenere_encrypt, but use decrypt_char
    // 1. Keep a key_index variable
    // 2. For letters: decrypt and advance key_index
    // 3. For non-letters: copy unchanged, do NOT advance key_index
}

int main(void)
{
    char result[128];

    vigenere_decrypt("Rijvs, Ambpb!", "KEY", result);
    printf("Decrypt \"Rijvs, Ambpb!\" + \"KEY\" → \"%s\"\n", result);

    vigenere_decrypt("LXFOPVEFRNHR", "LEMON", result);
    printf("Decrypt \"LXFOPVEFRNHR\" + \"LEMON\" → \"%s\"\n", result);

    /* Round-trip test: encrypt then decrypt */
    /* You can paste your vigenere_encrypt here to test the round trip */
    /* vigenere_encrypt("Hello, World!", "KEY", encrypted); */
    /* vigenere_decrypt(encrypted, "KEY", result); */
    /* printf("Round trip: \"%s\"\n", result); */

    return 0;
}
