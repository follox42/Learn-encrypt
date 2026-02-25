/*
 * Challenge 6: Complete DES Tool with ECB Mode
 *
 * Goal: Build a complete DES tool that can encrypt and decrypt
 *       multi-block messages using ECB mode.
 *
 * Features:
 * - Single-block DES encrypt/decrypt
 * - ECB mode for multi-block messages (pad to 8-byte blocks)
 * - Triple DES (3DES-EDE) with three keys:
 *   Encrypt: C = DES_Encrypt(K3, DES_Decrypt(K2, DES_Encrypt(K1, P)))
 *   Decrypt: P = DES_Decrypt(K1, DES_Encrypt(K2, DES_Decrypt(K3, C)))
 *
 * Tests:
 * - Single DES: Key 0x133457799BBCDFF1, PT 0x0123456789ABCDEF → CT 0x85E813540F0AB405
 * - 3DES with K1=K2=K3: result must equal single DES
 * - Encrypt then decrypt multi-block message returns original plaintext
 *
 * Menu:
 * === DES Cipher Tool ===
 * 1. DES encrypt (single block)
 * 2. DES decrypt (single block)
 * 3. DES-ECB encrypt (multi-block)
 * 4. DES-ECB decrypt (multi-block)
 * 5. Triple DES encrypt
 * 6. Triple DES decrypt
 * 7. Exit
 */

#include <stdio.h>
#include <string.h>

/* Copy all DES functions from previous challenges here:
 * - get_bit(), set_bit(), permute()
 * - sbox_lookup()
 * - feistel_f()
 * - des_key_schedule()
 * - des_encrypt(), des_decrypt()
 * - All DES tables (IP, IP^-1, E, P, S-boxes, PC-1, PC-2)
 */

int main(void)
{
    /* Your code here */
    return 0;
}
