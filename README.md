# Learn Encryption From Scratch

> **Warning**: Educational project only. Do not use these implementations in production.

Hands-on journey through cryptography by implementing every algorithm from scratch in C. No libraries, no shortcuts - pure understanding from bits to RSA.

## Why This Project?

- Build **deep understanding** of how encryption works at the byte level
- Practice **low-level C programming**: bitwise operations, memory management, modular arithmetic
- Implement algorithms the **professional way**: lookup tables, proper modular arithmetic, bit manipulation
- Understand **why** modern encryption exists by first breaking classical ciphers

## Project Structure

```
docs/                        # Theory documentation (English)
src/
├── fundamentals/            # Core: binary, hex, XOR, modulo
├── classical/               # Caesar, Vigenère
├── symmetric/               # XOR stream, DES, AES
├── asymmetric/              # RSA
└── hashing/                 # MD5, SHA-256
Makefile                     # Build system
```

## Build & Run

```bash
# Build everything
make

# Build specific module
make fundamentals
make classical
make symmetric
make asymmetric
make hashing

# Run a challenge
./build/fundamentals/challenge_01_ascii
./build/classical/caesar_01_letter_to_pos

# Clean
make clean
```

## Learning Path

### Phase 1: Fundamentals ✅

Core concepts required for any encryption algorithm.

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | ASCII Explorer | Characters are numbers |
| 02 | Binary Printer | Bit extraction with `>>` and `&` |
| 03 | Hex Converter | Nibble extraction, lookup table |
| 04 | XOR Two Bytes | XOR in decimal, binary, hex |
| 05 | XOR Proof | `(A ^ K) ^ K == A` |
| 06 | Modular Arithmetic | Euclidean mod for negatives |
| 07 | String XOR | First encryption program |

### Phase 2: Classical Ciphers

Historical ciphers - learn to encrypt AND break them.

**Caesar Cipher** - Shift substitution

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Letter to Position | Character ↔ alphabet mapping |
| 02 | Position to Letter | Reverse mapping with case |
| 03 | Encrypt Character | Modular shift |
| 04 | Encrypt String | Full string with case preservation |
| 05 | Decrypt String | Decrypt = encrypt with -shift |
| 06 | Brute Force | Only 25 keys to try |
| 07 | ROT13 | Self-inverse cipher |
| 08 | Full Program | Complete tool with menu |

**Vigenère Cipher** - Polyalphabetic substitution

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Repeat Key | Extend key to match plaintext length |
| 02 | Encrypt Char | Shift with key character |
| 03 | Encrypt String | Multi-key encryption |
| 04 | Decrypt String | Reverse the process |
| 05 | Kasiski Exam | Break Vigenère by finding key length |
| 06 | Full Program | Complete tool |

### Phase 3: Symmetric Encryption

Modern shared-key encryption.

**XOR Stream Cipher** - Foundation of stream ciphers

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Single Byte XOR | Basic XOR encryption |
| 02 | Multi Byte XOR | Repeating key cipher |
| 03 | Break Single | Frequency analysis attack |
| 04 | Break Repeating | Hamming distance + frequency |
| 05 | Detect ECB | Find repeated blocks |
| 06 | Full Program | Complete tool |

**DES** - Data Encryption Standard

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Permutation | Initial/Final permutation tables |
| 02 | S-Box | Substitution boxes (6→4 bits) |
| 03 | Feistel Round | One round of Feistel network |
| 04 | Key Schedule | Generate 16 subkeys |
| 05 | Encrypt Block | Full DES on 64-bit block |
| 06 | Full Program | ECB mode, Triple DES |

**AES** - Advanced Encryption Standard

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | S-Box | SubBytes transformation |
| 02 | ShiftRows | Row shifting in state matrix |
| 03 | MixColumns | Galois Field GF(2^8) math |
| 04 | Key Expansion | 128-bit → 11 round keys |
| 05 | Encrypt Block | Full AES-128 |
| 06 | Full Program | CBC mode, PKCS#7 padding |

### Phase 4: Asymmetric Encryption

**RSA** - Public key cryptography

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Modular Exp | Square-and-multiply algorithm |
| 02 | Extended GCD | Modular inverse |
| 03 | Prime Check | Primality testing |
| 04 | Key Generation | Generate public/private key pair |
| 05 | Encrypt | C = M^e mod n |
| 06 | Decrypt | M = C^d mod n |
| 07 | Sign & Verify | Digital signatures |
| 08 | Full Program | Complete RSA tool |

### Phase 5: Hash Functions

**MD5** - Message Digest (broken but educational)

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Padding | Message padding to 512-bit blocks |
| 02 | Auxiliary | F, G, H, I functions |
| 03 | Round | 16 operations per round |
| 04 | Full Hash | Complete MD5 implementation |
| 05 | Collision | Demonstrate MD5 weakness |
| 06 | Full Program | Hash strings and files |

**SHA-256** - Secure Hash Algorithm

| # | Challenge | Key Concept |
|---|-----------|-------------|
| 01 | Padding | Big-endian message padding |
| 02 | Functions | Ch, Maj, Sigma, sigma |
| 03 | Schedule | Expand 16 words → 64 |
| 04 | Compression | 64-round compression function |
| 05 | Full Hash | Complete SHA-256 |
| 06 | Full Program | Hash strings, files, verify |

## Technical Highlights

- **Hex conversion using lookup table** - same approach as the Linux kernel
- **Euclidean modulo** - correct handling of negative numbers
- **Bitwise over arithmetic** - `>> 4` instead of `/ 16`, `& 0xF` instead of `% 16`
- **Zero external dependencies** - everything from scratch using only `<stdio.h>`

## Stats

- **58 challenges** across 9 algorithms
- **18 documentation files** covering theory and challenges
- **5 phases** from fundamentals to SHA-256

## What I Learned

- How XOR is the foundation of symmetric encryption
- Why modular arithmetic matters for classical ciphers
- The difference between `char`, `char*`, and `char[]` in C
- How GCC fortification works (`__fortify_function`, `__attribute__((artificial))`)
- Professional C patterns: lookup tables, bit manipulation, safe string handling
