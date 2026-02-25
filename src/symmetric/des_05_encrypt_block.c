/*
 * Challenge 5: Full DES Encryption of One 64-bit Block
 *
 * Goal: Complete DES encryption and decryption of a single 64-bit block.
 *
 * Steps:
 * 1. Generate 16 subkeys (key schedule from Challenge 4)
 * 2. Apply Initial Permutation (IP) from Challenge 1
 * 3. Split into L0 (32 bits) and R0 (32 bits)
 * 4. 16 Feistel rounds: L(i+1) = R(i), R(i+1) = L(i) XOR F(R(i), K(i))
 *    (Feistel function from Challenge 3)
 * 5. Final swap: R16 | L16
 * 6. Apply Final Permutation (IP^-1)
 *
 * Decryption: same algorithm, subkeys in reverse order (K16 first, K1 last)
 *
 * Tests (NIST):
 * Key:       0x133457799BBCDFF1
 * Plaintext: 0x0123456789ABCDEF
 * Expected:  0x85E813540F0AB405
 *
 * Decrypt the ciphertext → must return original plaintext
 */

#include <stdio.h>
#include <string.h>

/* Include all DES tables: IP, IP^-1, E, P, S-boxes, PC-1, PC-2 */
/* Copy from previous challenge files or define here */

/* All helper functions from previous challenges */

/* Bit manipulation */
int get_bit(const unsigned char *data, int bit_pos)
{
    /* Your code here */
    return 0;
}

void set_bit(unsigned char *data, int bit_pos, int value)
{
    /* Your code here */
}

/* Permutation */
void permute(const unsigned char *input, unsigned char *output,
             const int *table, int table_size)
{
    /* Your code here */
}

/* S-box lookup */
unsigned char sbox_lookup(int sbox_index, unsigned char input_6bit)
{
    /* Your code here */
    return 0;
}

/* Feistel round function */
void feistel_f(const unsigned char *right_32bit,
               const unsigned char *subkey_48bit,
               unsigned char *output_32bit)
{
    /* Your code here */
}

/* Key schedule */
void des_key_schedule(const unsigned char *key_64bit,
                      unsigned char subkeys[16][6])
{
    /* Your code here */
}

/* DES encrypt a single 64-bit block */
void des_encrypt(const unsigned char *plaintext_64bit,
                 const unsigned char *key_64bit,
                 unsigned char *ciphertext_64bit)
{
    /* Your code here */
}

/* DES decrypt a single 64-bit block */
void des_decrypt(const unsigned char *ciphertext_64bit,
                 const unsigned char *key_64bit,
                 unsigned char *plaintext_64bit)
{
    /* Your code here */
}

/* Print byte array as hex */
void print_hex(const unsigned char *data, int len)
{
    /* Your code here */
}

int main(void)
{
    unsigned char key[8]       = {0x13, 0x34, 0x57, 0x79, 0x9B, 0xBC, 0xDF, 0xF1};
    unsigned char plaintext[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    unsigned char ciphertext[8] = {0};
    unsigned char decrypted[8]  = {0};

    printf("Key:       ");
    print_hex(key, 8);
    printf("\n");

    printf("Plaintext: ");
    print_hex(plaintext, 8);
    printf("\n");

    /* Encrypt */
    des_encrypt(plaintext, key, ciphertext);
    printf("Encrypted: ");
    print_hex(ciphertext, 8);
    printf("\n");
    printf("Expected:  85E813540F0AB405\n\n");

    /* Decrypt */
    des_decrypt(ciphertext, key, decrypted);
    printf("Decrypted: ");
    print_hex(decrypted, 8);
    printf("\n");
    printf("Expected:  0123456789ABCDEF\n");

    return 0;
}
