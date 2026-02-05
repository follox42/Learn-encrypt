/*
 * Challenge 7: String XOR
 *
 * Goal: XOR encrypt a string, print as hex, then decrypt back
 *
 * This is your first encryption program!
 *
 * Steps:
 * 1. Take a string and a key character
 * 2. XOR each character with the key
 * 3. Print encrypted bytes as hex
 * 4. XOR again with same key to decrypt
 * 5. Print decrypted string
 */

#include <stdio.h>

int main(void)
{
    char string[256];
    char key;
    char hex_chars[] = "0123456789ABCDEF";

    printf("Enter a string to encrypt: ");
    scanf("%s", string);
    printf("Enter a key character: ");
    scanf(" %c", &key);

    char encrypted_string[256];
    char encrypted_string_hex[512];
    int i = 0;
    while(string[i] != '\0'){
        encrypted_string[i] = string[i] ^ key;
        encrypted_string_hex[(i*2)] = hex_chars[(encrypted_string[i] >> 4) & 0xF];
        encrypted_string_hex[(i*2) + 1] = hex_chars[encrypted_string[i] & 0xF];
        i++;
    }
    encrypted_string[i] = '\0';
    encrypted_string_hex[i*2] = '\0';

    printf("Encrypted string as hex: %s\n", encrypted_string_hex);

    char decrypted_string[256];
    char decrypted_string_hex[512];
    i = 0;
    while(string[i] != '\0'){
        decrypted_string[i] = encrypted_string[i] ^ key;
        decrypted_string_hex[(i*2)] = hex_chars[(decrypted_string[i] >> 4) & 0xF];
        decrypted_string_hex[(i*2) + 1] = hex_chars[decrypted_string[i] & 0xF];
        i++;
    }
    decrypted_string[i] = '\0';
    decrypted_string_hex[i*2] = '\0';

    printf("Decrypted string as hex: %s\n", decrypted_string_hex);
    printf("Decrypted string: %s\n", decrypted_string);


    // Your code here
    return 0;
}
