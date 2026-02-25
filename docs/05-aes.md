# AES - Advanced Encryption Standard

The gold standard of symmetric encryption, adopted by NIST in 2001 to replace DES.

---

## Why AES Replaced DES

DES was broken due to its 56-bit key being too short for brute-force resistance. NIST held an open competition from 1997 to 2000, evaluating 15 candidate ciphers. The Rijndael algorithm by Joan Daemen and Vincent Rijmen was selected for its combination of security, performance, and elegance. Unlike DES, AES was designed in the open with full public scrutiny.

---

## Overview

AES encrypts data in 128-bit blocks using keys of 128, 192, or 256 bits. The block size is always 128 bits (16 bytes). The structure is a Substitution-Permutation Network (SPN), not a Feistel network like DES. This means every bit of the state is transformed in every round, rather than only half.

---

## The Four Operations

Each AES round applies four operations in sequence.

### SubBytes (S-Box Substitution)

Each byte of the 4x4 state matrix is replaced by a corresponding byte from the S-box, a fixed 256-byte lookup table. For a byte value 0xAB, the S-box output is found at row 0xA, column 0xB.

The S-box is constructed mathematically: first compute the multiplicative inverse in GF(2^8), then apply an affine transformation. This ensures non-linearity, meaning no byte maps to itself and no byte maps to its bitwise complement.

### ShiftRows

Each row of the 4x4 state matrix is shifted (rotated) left by a different offset. Row 0 is unchanged, row 1 shifts by 1, row 2 by 2, row 3 by 3. This ensures that each column of the output depends on bytes from all four input columns, providing diffusion across columns.

### MixColumns

Each column of the state is transformed by multiplying it with a fixed matrix using Galois Field GF(2^8) arithmetic. The matrix uses coefficients 1, 2, and 3. Addition in GF(2^8) is XOR. Multiplication by 2 is a left shift with conditional XOR of 0x1B (the irreducible polynomial). Multiplication by 3 is multiply-by-2 then XOR with the original.

MixColumns provides diffusion within each column. Combined with ShiftRows, it ensures that after a few rounds, every output bit depends on every input bit.

### AddRoundKey

The entire state is XOR-ed with the round key (a 128-bit subkey derived from the cipher key). This is the step where the secret key is mixed into the data. Without it, the cipher would be a fixed public permutation.

---

## Galois Field Arithmetic GF(2^8)

GF(2^8) is the finite field with 256 elements, used extensively in AES. Elements are bytes treated as polynomials of degree less than 8. Addition is XOR (no carries). Multiplication is polynomial multiplication modulo the irreducible polynomial x^8 + x^4 + x^3 + x + 1 (0x11B in hex).

The fundamental operation is "xtime" (multiply by 2): shift the byte left by 1; if the high bit was set before the shift, XOR the result with 0x1B to reduce modulo the polynomial. All other multiplications can be built from xtime and XOR.

---

## Number of Rounds

The number of rounds depends on the key size:
- AES-128: 10 rounds, 128-bit key, 11 round keys needed
- AES-192: 12 rounds, 192-bit key, 13 round keys needed
- AES-256: 14 rounds, 256-bit key, 15 round keys needed

The round structure is: an initial AddRoundKey, then N-1 main rounds (SubBytes, ShiftRows, MixColumns, AddRoundKey), then a final round that omits MixColumns (SubBytes, ShiftRows, AddRoundKey). The last round omits MixColumns so that encryption and decryption have the same structure with inverse operations.

---

## Key Expansion

AES expands the cipher key into a series of round keys. For AES-128, the 16-byte key (4 words of 32 bits) is expanded into 44 words (11 round keys).

The expansion uses RotWord (rotate 4 bytes left by 1), SubWord (apply S-box to each byte), and round constants (Rcon). Each new word W[i] is computed as W[i-4] XOR with a transformed version of W[i-1]. Every fourth word undergoes the special RotWord/SubWord/Rcon transformation.

---

## Modes of Operation

AES encrypts exactly one 128-bit block. To encrypt longer messages, a mode of operation is needed.

### ECB - Electronic Codebook

Each block is encrypted independently. Identical plaintext blocks produce identical ciphertext blocks, leaking patterns. The famous "ECB penguin" demonstrates this: encrypting a bitmap preserves the image outline. Never use ECB for anything other than single-block encryption.

### CBC - Cipher Block Chaining

Each plaintext block is XOR-ed with the previous ciphertext block before encryption. The first block uses an initialization vector (IV). Identical plaintext blocks produce different ciphertext. Encryption is sequential but decryption can be parallelized. A bit error in one ciphertext block corrupts two plaintext blocks.

### CTR - Counter Mode

Turns AES into a stream cipher. A counter combined with a nonce is encrypted to generate a keystream, which is XOR-ed with the plaintext. Both encryption and decryption are fully parallelizable. No padding is needed. The nonce must never be reused with the same key.

---

## Why AES Is the Standard Today

AES provides strong confusion through the S-box and strong diffusion through ShiftRows and MixColumns. After just 2 rounds, changing a single input bit changes approximately half of all output bits (avalanche effect).

No practical attack breaks full AES faster than brute force. AES-128 requires 2^128 operations to brute force, far beyond current or foreseeable computational capability. AES is used everywhere: TLS/HTTPS, Wi-Fi (WPA2/WPA3), disk encryption, VPNs, and countless other systems.

---

**Previous:** [04-des.md](04-des.md) - Data Encryption Standard
