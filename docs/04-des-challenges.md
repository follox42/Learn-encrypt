# DES - Challenges

Implement the Data Encryption Standard step by step in C.

DES is complex. Each challenge builds on the previous one. Take your time.

---

## Challenge 1: Initial Permutation

Implement a generic bit permutation function and use it to apply the DES Initial Permutation (IP) table to a 64-bit block.

**How it works:**
- The IP table has 64 entries. Entry i tells you which input bit goes to output position i.
- Bit numbering: bit 1 is the most significant bit of byte 0.
- To get bit n from a byte array: (input[(n-1)/8] >> (7 - (n-1)%8)) & 1
- To set bit n in a byte array: output[(n-1)/8] |= (bit << (7 - (n-1)%8))

**Test case:**
- Input: 0x0123456789ABCDEF (64 bits)
- Apply the DES Initial Permutation table
- Expected output: 0xCC00CCFFF0AAF0AA
- Apply IP-inverse to the result and get back the original input

---

## Challenge 2: S-Box Substitution

Implement S-box lookup. Given a 6-bit input and an S-box index, return the 4-bit output.

**How it works:**
- Input: 6 bits (b1 b2 b3 b4 b5 b6)
- Row = b1*2 + b6 (first and last bit, gives 0-3)
- Column = b2*8 + b3*4 + b4*2 + b5 (middle four bits, gives 0-15)
- Output = sbox[row][column]

**Test cases (S-box 1):**
- Input: 0b000000 (0x00) -> Row 0, Col 0 -> S1[0][0] = 14
- Input: 0b101100 (0x2C) -> Row 2, Col 6 -> S1[2][6] = 2
- Input: 0b110001 (0x31) -> Row 3, Col 8 -> S1[3][8] = 10

Provide all 8 DES S-box tables as constant arrays in the file.

---

## Challenge 3: Feistel Round Function

Implement one complete round of the Feistel function F(R, K).

**Steps inside F:**
1. Expand R from 32 bits to 48 bits using the E expansion table
2. XOR the expanded 48 bits with the 48-bit subkey
3. Split into 8 groups of 6 bits
4. Apply each S-box to its corresponding group
5. Combine the 8 groups of 4 bits into 32 bits
6. Apply the P permutation

Test with known intermediate values from a DES reference implementation.

---

## Challenge 4: Key Schedule

Generate 16 subkeys from the 56-bit DES key.

**Steps:**
1. Apply PC-1 (Permuted Choice 1) to get 56 bits from the 64-bit key
2. Split into C0 (28 bits) and D0 (28 bits)
3. For each round (1 to 16): left-rotate C and D by 1 or 2 positions, then apply PC-2 to get the 48-bit subkey

**Rotation schedule:**
- Round 1,2,9,16: rotate by 1
- All other rounds: rotate by 2

Test with a known key and verify all 16 subkeys match published test vectors.

---

## Challenge 5: Full DES Encryption

Put it all together: complete DES encryption and decryption of one 64-bit block.

**Steps:**
1. Generate 16 subkeys (key schedule)
2. Apply Initial Permutation (IP)
3. Split into L0 and R0
4. 16 Feistel rounds
5. Final swap (R16 | L16)
6. Apply Final Permutation (IP-inverse)

Decryption is the same algorithm with subkeys in reverse order.

**Test case (NIST):**
- Key: 0x133457799BBCDFF1
- Plaintext: 0x0123456789ABCDEF
- Expected ciphertext: 0x85E813540F0AB405
- Decrypt the ciphertext and verify it returns the original plaintext

---

## Challenge 6: Complete DES Tool with ECB Mode

Build a complete DES tool that can encrypt and decrypt multi-block messages using ECB mode.

**Requirements:**
- Encrypt and decrypt arbitrary-length messages (pad to 64-bit blocks)
- ECB mode: encrypt each 8-byte block independently
- Include a Triple DES (3DES-EDE) option using three keys
- Display intermediate values for debugging

**Test cases:**
- When K1 = K2 = K3 in 3DES, result must equal single DES
- Encrypt then decrypt must return original plaintext
- Multi-block messages should work correctly

---

## Validation

When all challenges work:
- You understand the Feistel network structure
- You can implement bit-level permutations
- You understand why S-boxes provide non-linearity
- You know why DES is no longer secure
- You are ready for AES

**Next:** [05-aes-challenges.md](05-aes-challenges.md)
