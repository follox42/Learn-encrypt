# XOR Advanced - Challenges

Build real XOR ciphers and learn to break them.

---

## Challenge 1: Single-Byte XOR Encrypt/Decrypt

XOR encrypt and decrypt a message with a single byte key.

**Function signature:**
- Take a byte array and a single key byte
- XOR every byte of the input with the key byte
- Same function works for encrypt and decrypt (XOR is self-inverse)

**Test cases:**
- "Hello" XOR 0x4B produces hex: 03 2E 27 27 24
- XOR the result with 0x4B again to get back "Hello"
- Empty string produces empty output

---

## Challenge 2: Multi-Byte Repeating Key XOR

Encrypt and decrypt using a multi-byte key that repeats cyclically.

**Function signature:**
- Take input bytes, input length, key bytes, key length
- For each byte at position i, XOR with key[i % key_length]
- Same function works for encrypt and decrypt

**Test cases:**
- "Hello, World!" XOR "KEY" produces hex output (verify round-trip)
- "Burning 'em, if you ain't quick and nimble" XOR "ICE" produces: 0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272a282b2f20
- Encrypt then decrypt with same key returns original plaintext

---

## Challenge 3: Break Single-Byte XOR

Break a single-byte XOR cipher by frequency analysis.

**Approach:**
1. Try all 256 possible key bytes (0x00 to 0xFF)
2. Decrypt the ciphertext with each candidate key
3. Score each decrypted result by English character frequency
4. The key producing the highest score is the answer

**Scoring hint:** The most common byte in English text is space (0x20). Count how many bytes in the decrypted text are common English characters (letters, spaces, punctuation). Higher count means more likely to be English.

**Test case:**
- Ciphertext hex: "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736"
- Find the key byte that produces readable English plaintext

---

## Challenge 4: Break Repeating-Key XOR

Break a repeating-key XOR cipher without knowing the key. This combines key length detection with single-byte breaking.

**Approach:**
1. Write a Hamming distance function (count differing bits between two byte sequences)
2. For each candidate key length (2 to 40), take the first few blocks of that size and compute normalized Hamming distance. The correct key length has the lowest value.
3. Split the ciphertext into key-length groups (every N-th byte together)
4. Break each group as single-byte XOR using Challenge 3 logic
5. Reconstruct the full key

**Test cases:**
- hamming_distance("this is a test", "wokka wokka!!!") = 37
- Encrypt a known long message with a known key, then break it and verify the key is recovered

This is the hardest challenge in this section. Take it step by step.

---

## Challenge 5: Detect ECB Mode

Detect if data was encrypted using ECB mode by looking for repeated blocks.

**Concept:** In ECB mode, identical plaintext blocks produce identical ciphertext blocks. If the same 16-byte (or 8-byte) block appears more than once in the ciphertext, it was likely encrypted with ECB.

**Approach:**
1. Split the ciphertext into fixed-size blocks (e.g., 16 bytes for AES)
2. Compare all blocks pairwise
3. If any two blocks are identical, flag it as ECB

**Test cases:**
- Generate a plaintext with repeated 16-byte blocks, XOR-encrypt with a repeating key, and detect the repetition
- Random ciphertext should have no repeated blocks

---

## Challenge 6: Full XOR Cipher Tool

Build a complete XOR cipher command-line tool that combines all previous functions.

**Menu:**
- 1. Single-byte XOR encrypt/decrypt
- 2. Repeating-key XOR encrypt/decrypt
- 3. Break single-byte XOR
- 4. Break repeating-key XOR
- 5. Detect ECB mode
- 6. Exit

**Requirements:**
- Input and output in hex encoding
- Handle binary data (not just text)
- Combine all previous challenge functions into one program

---

## Validation

When all challenges work:
- You understand stream cipher fundamentals
- You can perform frequency analysis attacks
- You know why key reuse breaks XOR ciphers
- You can detect ECB mode weaknesses

**Next:** [04-des-challenges.md](04-des-challenges.md)
