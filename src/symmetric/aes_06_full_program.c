/*
 * Challenge 6: Complete AES Tool with CBC Mode
 *
 * Goal: Build a complete AES tool that can encrypt and decrypt
 *       messages longer than one block using CBC mode.
 *
 * CBC mode encryption:
 * - C[0] = AES_Encrypt(K, P[0] XOR IV)
 * - C[i] = AES_Encrypt(K, P[i] XOR C[i-1])
 *
 * CBC mode decryption:
 * - P[0] = AES_Decrypt(K, C[0]) XOR IV
 * - P[i] = AES_Decrypt(K, C[i]) XOR C[i-1]
 *
 * PKCS#7 padding:
 * - Pad the last block to 16 bytes
 * - Padding value = number of bytes added (1-16)
 * - If message is already a multiple of 16, add a full 16-byte padding block
 *
 * Tests:
 * - ECB: encrypt two identical 16-byte blocks → ciphertext blocks identical (insecure!)
 * - CBC: encrypt two identical 16-byte blocks → ciphertext blocks different (secure)
 * - CBC: encrypt then decrypt → returns original plaintext
 *
 * Menu:
 * === AES Cipher Tool ===
 * 1. AES-ECB encrypt
 * 2. AES-ECB decrypt
 * 3. AES-CBC encrypt
 * 4. AES-CBC decrypt
 * 5. Demonstrate ECB vs CBC
 * 6. Exit
 */

#include <stdio.h>
#include <string.h>

/* Copy all AES functions from previous challenges here:
 * - sub_bytes(), inv_sub_bytes()
 * - shift_rows(), inv_shift_rows()
 * - mix_columns(), inv_mix_columns()
 * - add_round_key()
 * - key_expansion()
 * - aes_encrypt(), aes_decrypt()
 * - AES S-box, inverse S-box, Rcon
 */

/* AES-ECB encrypt (each 16-byte block independently) */
void aes_ecb_encrypt(const unsigned char *plaintext, int len,
                     const unsigned char key[16],
                     unsigned char *ciphertext)
{
    /* Your code here */
}

/* AES-ECB decrypt */
void aes_ecb_decrypt(const unsigned char *ciphertext, int len,
                     const unsigned char key[16],
                     unsigned char *plaintext)
{
    /* Your code here */
}

/* AES-CBC encrypt */
void aes_cbc_encrypt(const unsigned char *plaintext, int len,
                     const unsigned char key[16],
                     const unsigned char iv[16],
                     unsigned char *ciphertext)
{
    /* Your code here */
}

/* AES-CBC decrypt */
void aes_cbc_decrypt(const unsigned char *ciphertext, int len,
                     const unsigned char key[16],
                     const unsigned char iv[16],
                     unsigned char *plaintext)
{
    /* Your code here */
}

/* Add PKCS#7 padding to a buffer. Returns new length. */
int pkcs7_pad(unsigned char *data, int len, int block_size)
{
    /* Your code here */
    return 0;
}

/* Remove PKCS#7 padding. Returns unpadded length. */
int pkcs7_unpad(unsigned char *data, int len)
{
    /* Your code here */
    return 0;
}

/* Print byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    /* Your code here */
    return 0;
}
