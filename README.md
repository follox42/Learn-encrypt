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
├── fundamentals/            # Core concepts: binary, hex, XOR, modulo
└── classical/               # Classical ciphers: Caesar, Vigenère
Makefile                     # Build system
```

## Build & Run

```bash
# Build everything
make

# Build specific module
make fundamentals
make classical

# Run a specific challenge
./build/fundamentals/challenge_01_ascii

# Clean build artifacts
make clean
```

## Learning Path

### Phase 1: Fundamentals ✅

Core concepts required for any encryption algorithm.

| Challenge | Topic | Key Concept |
|-----------|-------|-------------|
| 01 | ASCII Explorer | Characters are numbers |
| 02 | Binary Printer | Bit extraction with `>>` and `&` |
| 03 | Hex Converter | Nibble extraction, lookup table conversion |
| 04 | XOR Two Bytes | XOR operation in decimal, binary, hex |
| 05 | XOR Proof | `(A ^ K) ^ K == A` - foundation of symmetric encryption |
| 06 | Modular Arithmetic | Euclidean modulo for negative numbers |
| 07 | String XOR | First encryption program - XOR cipher |

### Phase 2: Classical Ciphers (in progress)

Historical ciphers - learning to encrypt AND break them.

| Challenge | Topic | Key Concept |
|-----------|-------|-------------|
| 01 | Letter to Position | Character ↔ alphabet mapping |
| 02 | Position to Letter | Reverse mapping with case handling |
| 03 | Encrypt Character | Modular shift on single char |
| 04 | Encrypt String | Full string encryption with case preservation |
| 05 | Decrypt String | Decryption = encryption with negative shift |
| 06 | Brute Force | Breaking Caesar - only 25 possible keys |
| 07 | ROT13 | Self-inverse cipher (encrypt = decrypt) |
| 08 | Full Program | Complete Caesar cipher tool with menu |

### Phase 3: Symmetric Encryption (planned)

- [ ] XOR Stream Cipher
- [ ] DES (Data Encryption Standard)
- [ ] AES (Advanced Encryption Standard)

### Phase 4: Asymmetric Encryption (planned)

- [ ] RSA

### Phase 5: Hash Functions (planned)

- [ ] MD5
- [ ] SHA-256

## Technical Highlights

- **Hex conversion using lookup table** - same approach used in the Linux kernel
- **Euclidean modulo** - handles negative numbers correctly for cipher wrapping
- **Bitwise operations** over arithmetic - `>> 4` instead of `/ 16`, `& 0xF` instead of `% 16`
- **Zero external dependencies** - everything built from scratch using only `<stdio.h>`

## What I Learned

- How XOR is the foundation of symmetric encryption
- Why modular arithmetic matters for classical ciphers
- The difference between `char`, `char*`, and `char[]` in C
- How GCC fortification works (`__fortify_function`, `__attribute__((artificial))`)
- Professional C patterns: lookup tables, proper bit manipulation, safe string handling
