/*
 * Challenge 5: Full AES-128 Encryption of One Block
 *
 * Goal: Implement complete AES-128 encryption and decryption
 *       of a single 128-bit (16-byte) block.
 *
 * Encryption:
 * 1. Key expansion (generate 11 round keys)
 * 2. AddRoundKey with round key 0
 * 3. Rounds 1-9: SubBytes, ShiftRows, MixColumns, AddRoundKey
 * 4. Round 10: SubBytes, ShiftRows, AddRoundKey (no MixColumns)
 *
 * Decryption (inverse operations in reverse order):
 * 1. Key expansion
 * 2. AddRoundKey with round key 10
 * 3. Rounds 9-1: InvShiftRows, InvSubBytes, AddRoundKey, InvMixColumns
 * 4. Final: InvShiftRows, InvSubBytes, AddRoundKey with round key 0
 *
 * Note: For decryption you need the inverse S-box and
 *       inverse MixColumns matrix:
 *       | 14 11 13  9 |
 *       |  9 14 11 13 |
 *       | 13  9 14 11 |
 *       | 11 13  9 14 |
 *
 * Tests (NIST FIPS 197 Appendix B):
 * Key:       2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
 * Plaintext: 32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
 * Expected:  39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32
 *
 * Decrypt the ciphertext → must return original plaintext
 */

#include <stdio.h>
#include <string.h>

/* Include AES S-box, inverse S-box, and round constants here */
/* Copy from previous challenge files */

/* SubBytes */
void sub_bytes(unsigned char state[4][4])
{
    /* Your code here */
}

/* InvSubBytes (for decryption) */
void inv_sub_bytes(unsigned char state[4][4])
{
    /* Your code here */
}

/* ShiftRows */
void shift_rows(unsigned char state[4][4])
{
    /* Your code here */
}

/* InvShiftRows (for decryption) */
void inv_shift_rows(unsigned char state[4][4])
{
    /* Your code here */
}

/* MixColumns */
void mix_columns(unsigned char state[4][4])
{
    /* Your code here */
}

/* InvMixColumns (for decryption) */
void inv_mix_columns(unsigned char state[4][4])
{
    /* Your code here */
}

/* AddRoundKey: XOR state with round key */
void add_round_key(unsigned char state[4][4],
                   const unsigned char round_key[4][4])
{
    /* Your code here */
}

/* Key expansion */
void key_expansion(const unsigned char key[16],
                   unsigned char round_keys[11][4][4])
{
    /* Your code here */
}

/* AES-128 encrypt a single 16-byte block */
void aes_encrypt(const unsigned char plaintext[16],
                 const unsigned char key[16],
                 unsigned char ciphertext[16])
{
    /* Your code here */
}

/* AES-128 decrypt a single 16-byte block */
void aes_decrypt(const unsigned char ciphertext[16],
                 const unsigned char key[16],
                 unsigned char plaintext[16])
{
    /* Your code here */
}

/* Print 16 bytes as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    unsigned char key[16] = {
        0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6,
        0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C
    };
    unsigned char plaintext[16] = {
        0x32, 0x43, 0xF6, 0xA8, 0x88, 0x5A, 0x30, 0x8D,
        0x31, 0x31, 0x98, 0xA2, 0xE0, 0x37, 0x07, 0x34
    };
    unsigned char ciphertext[16] = {0};
    unsigned char decrypted[16] = {0};

    printf("Key:       ");
    print_hex(key, 16);
    printf("\n");

    printf("Plaintext: ");
    print_hex(plaintext, 16);
    printf("\n");

    /* Encrypt */
    aes_encrypt(plaintext, key, ciphertext);
    printf("Encrypted: ");
    print_hex(ciphertext, 16);
    printf("\n");
    printf("Expected:  39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32\n\n");

    /* Decrypt */
    aes_decrypt(ciphertext, key, decrypted);
    printf("Decrypted: ");
    print_hex(decrypted, 16);
    printf("\n");
    printf("Expected:  32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34\n");

    return 0;
}
