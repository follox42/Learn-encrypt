# AES - Challenges

Implement the Advanced Encryption Standard step by step in C.

AES-128 (10 rounds, 128-bit key) is the target. Build each operation separately, then combine.

---

## Challenge 1: AES S-Box (SubBytes)

Implement the SubBytes transformation using the AES S-box lookup table.

**How it works:**
- For each byte in the 4x4 state matrix, replace it with the S-box value
- For byte 0xAB: use upper nibble (0xA) as row, lower nibble (0xB) as column

**Test cases:**
- sbox[0x00] = 0x63
- sbox[0x53] = 0xED
- sbox[0xFF] = 0x16

Full state test:
- Input state: 19 a0 9a e9 / 3d f4 c6 f8 / e3 e2 8d 48 / be 2b 2a 08
- After SubBytes: d4 e0 b8 1e / 27 bf b4 41 / 11 98 5d 52 / ae f1 e5 30

Provide the full 256-byte AES S-box as a constant array.

---

## Challenge 2: ShiftRows

Implement the ShiftRows transformation on the 4x4 state matrix.

**Rules:**
- Row 0: no shift
- Row 1: circular left shift by 1
- Row 2: circular left shift by 2
- Row 3: circular left shift by 3

**Test case:**
- Input: d4 e0 b8 1e / 27 bf b4 41 / 11 98 5d 52 / ae f1 e5 30
- After ShiftRows: d4 e0 b8 1e / bf b4 41 27 / 5d 52 11 98 / 30 ae f1 e5

---

## Challenge 3: MixColumns

Implement the MixColumns transformation using GF(2^8) multiplication.

**Galois Field operations needed:**
- Multiply by 1: identity (no change)
- Multiply by 2 (xtime): left shift by 1; if high bit was set, XOR with 0x1B
- Multiply by 3: xtime(a) XOR a

**Matrix multiplication per column:**
- [2 3 1 1] * [s0 s1 s2 s3] for each column

**Test case:**
- Input (after ShiftRows): d4 e0 b8 1e / bf b4 41 27 / 5d 52 11 98 / 30 ae f1 e5
- After MixColumns: 04 e0 48 28 / 66 cb f8 06 / 81 19 d3 26 / e5 9a 7a 4c

Hint: gf_mul(0xD4, 2) = 0xB3

---

## Challenge 4: Key Expansion

Expand a 128-bit key into 11 round keys (44 words of 32 bits).

**Steps for each new word W[i] (i >= 4):**
- If i mod 4 == 0: temp = SubWord(RotWord(W[i-1])) XOR Rcon[i/4]
- Otherwise: temp = W[i-1]
- W[i] = W[i-4] XOR temp

**Test case (AES-128):**
- Key: 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
- Round key 0 (original): 2b 28 ab 09 / 7e ae f7 cf / 15 d2 15 4f / 16 a6 88 3c
- Round key 1: a0 88 23 2a / fa 54 a3 6c / fe 2c 39 76 / 17 b1 39 05

Remember: the state matrix is filled column by column.

---

## Challenge 5: Full AES-128 Block Encryption

Implement complete AES-128 encryption and decryption of one 128-bit block.

**Encryption:**
1. Key expansion (generate 11 round keys)
2. AddRoundKey with round key 0
3. Rounds 1-9: SubBytes, ShiftRows, MixColumns, AddRoundKey
4. Round 10: SubBytes, ShiftRows, AddRoundKey (no MixColumns)

**Decryption (inverse operations in reverse order):**
1. Key expansion
2. AddRoundKey with round key 10
3. Rounds 9-1: InvShiftRows, InvSubBytes, AddRoundKey, InvMixColumns
4. Final: InvShiftRows, InvSubBytes, AddRoundKey with round key 0

**Test case (NIST FIPS 197 Appendix B):**
- Key: 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
- Plaintext: 32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
- Expected: 39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32
- Decrypt the ciphertext and verify it returns the original plaintext

Note: For decryption you need the inverse S-box and inverse MixColumns matrix.

---

## Challenge 6: Complete AES Tool with CBC Mode

Build a complete AES tool with CBC mode for encrypting messages longer than one block.

**CBC mode encryption:**
- C[0] = AES_Encrypt(K, P[0] XOR IV)
- C[i] = AES_Encrypt(K, P[i] XOR C[i-1])

**CBC mode decryption:**
- P[0] = AES_Decrypt(K, C[0]) XOR IV
- P[i] = AES_Decrypt(K, C[i]) XOR C[i-1]

**Requirements:**
- Handle PKCS#7 padding (pad last block to 16 bytes; if already 16, add full padding block)
- Demonstrate that ECB leaks patterns (identical blocks produce identical ciphertext)
- Demonstrate that CBC does not (identical blocks produce different ciphertext)

**Test cases:**
- ECB: encrypt two identical 16-byte blocks, ciphertext blocks are identical
- CBC: encrypt two identical 16-byte blocks, ciphertext blocks are different
- CBC: encrypt then decrypt returns original plaintext

---

## Validation

When all challenges work:
- You understand the AES substitution-permutation network
- You can implement Galois field arithmetic
- You know why each step (SubBytes, ShiftRows, MixColumns, AddRoundKey) is needed
- You understand the difference between ECB and CBC modes
- You have built a complete, working AES implementation from scratch
