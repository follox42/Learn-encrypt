# DES - Data Encryption Standard

The first widely adopted symmetric block cipher, standardized by NIST in 1977.

---

## Overview

DES encrypts data in 64-bit blocks using a 56-bit key. The key is provided as 64 bits, but 8 bits are used for parity checking and discarded, leaving 56 effective key bits. DES uses 16 rounds of processing through a structure called a Feistel network.

---

## Feistel Network Structure

DES uses a Feistel network, a general method for building block ciphers. The Feistel structure has an elegant property: encryption and decryption use the same algorithm, just with subkeys applied in reverse order.

### How One Round Works

The 64-bit block is split into a left half L (32 bits) and a right half R (32 bits). In each round:

- The new left half becomes the old right half: L(i+1) = R(i)
- The new right half is computed: R(i+1) = L(i) XOR F(R(i), K(i))

The function F is the round function, which takes the 32-bit right half and a 48-bit subkey and produces a 32-bit output. The round function does not need to be reversible because the Feistel structure guarantees that the overall cipher is invertible regardless.

### The Full 16-Round Process

The plaintext goes through the Initial Permutation (IP), is split into L0 and R0, processed through 16 Feistel rounds, then the halves are swapped (R16 | L16), and the Final Permutation (IP-inverse) is applied to produce the ciphertext.

For decryption, the same structure is used with subkeys K16, K15, down to K1 instead of K1 through K16.

---

## Initial and Final Permutation

Before any rounds begin, the 64-bit plaintext is rearranged according to a fixed table called the Initial Permutation (IP). Bit 58 of the input goes to bit 1 of the output, bit 50 goes to bit 2, and so on.

After all 16 rounds and the final swap, the inverse of the Initial Permutation (IP-inverse) is applied. This undoes the rearrangement.

These permutations have no cryptographic significance. They were designed for hardware implementation convenience on 1970s chips.

---

## S-Boxes and P-Boxes

### S-Box Substitution

The S-boxes are the heart of DES security. There are 8 S-boxes, each taking a 6-bit input and producing a 4-bit output. The 48 bits (from the expanded and key-mixed right half) are split into eight 6-bit groups, and each group is fed into a different S-box.

For a 6-bit input b1 b2 b3 b4 b5 b6: the row is determined by b1 and b6 (giving values 0-3), and the column is determined by b2 b3 b4 b5 (giving values 0-15). The output is looked up in the S-box table.

S-boxes provide the only non-linear component of DES. Without them, DES would be a system of linear equations that could be solved directly. The S-boxes were designed by IBM with input from the NSA and are specifically resistant to differential cryptanalysis.

### P-Box Permutation

After the S-boxes, the 32 output bits are rearranged according to the P permutation table. This spreads S-box outputs across different S-box inputs in the next round, providing diffusion.

---

## Key Schedule (Subkey Generation)

DES generates 16 subkeys (one per round), each 48 bits long, from the original 56-bit key.

Step 1: Apply Permuted Choice 1 (PC-1) to the 64-bit key. This drops the 8 parity bits and permutes the remaining 56 bits.

Step 2: Split the 56 bits into two 28-bit halves, C0 and D0.

Step 3: For each round i (1 to 16), left-rotate C and D by 1 or 2 positions (rounds 1, 2, 9, 16 rotate by 1; all others by 2), then apply Permuted Choice 2 (PC-2) to select 48 bits from the 56-bit combined C|D. This produces the 48-bit subkey K(i).

---

## Why DES Is Broken

### Small Key Space

The 56-bit key means there are 2^56 (about 72 quadrillion) possible keys. In 1998, the EFF built a machine called "Deep Crack" that broke DES in 56 hours for $250,000. In 1999, combined with distributed computing, DES was broken in 22 hours. Today, a modern FPGA cluster can brute-force DES in hours or less.

Security experts recommend at least 128 bits of key strength. DES with 56 bits falls far short.

### Other Weaknesses

The 64-bit block size is also small. After encrypting about 2^32 blocks in certain modes, patterns can emerge (birthday bound). DES also has 4 weak keys and 12 semi-weak keys. Academic attacks (linear and differential cryptanalysis) can break DES with fewer operations than brute force, though they require enormous amounts of data.

---

## Triple DES as Improvement

To extend the lifetime of DES, Triple DES (3DES) applies DES three times using the Encrypt-Decrypt-Encrypt (EDE) scheme with two or three different keys.

With three independent keys (K1, K2, K3), the effective security is about 112 bits due to meet-in-the-middle attacks. When K1 equals K3 (two-key variant), effective security is about 80 bits. When all three keys are equal, 3DES reduces to single DES for backward compatibility.

3DES is considered deprecated. It is slow (three DES operations per block) and NIST disallowed it after 2023. AES has completely replaced it for new applications.

---

## Summary

DES taught the world how to build block ciphers. Its Feistel structure, S-box design, and key schedule influenced every cipher that followed. Understanding DES is essential background for understanding AES and modern cryptography.

---

**Next:** [05-aes.md](05-aes.md) - The Advanced Encryption Standard
