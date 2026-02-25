# Vigenere Cipher

A polyalphabetic substitution cipher that uses a keyword to shift letters by varying amounts, making it significantly stronger than the Caesar cipher.

---

## How It Works

**Principle**: Instead of shifting every letter by the same amount, use a repeating keyword where each letter of the key determines a different shift.

```
Plaintext:  H E L L O W O R L D
Key:        K E Y K E Y K E Y K
Ciphertext: R I J V S U Y V J N
```

### Step-by-Step

1. **Choose a keyword** (e.g., "KEY")
2. **Repeat the key** to match the plaintext length
3. **For each letter**: shift by the corresponding key letter's position

```
H (pos 7)  + K (pos 10) = R (pos 17)
E (pos 4)  + E (pos 4)  = I (pos 8)
L (pos 11) + Y (pos 24) = J (pos 9)   ← wraps around!
L (pos 11) + K (pos 10) = V (pos 21)
O (pos 14) + E (pos 4)  = S (pos 18)
```

### Non-Alphabetic Characters

Spaces, punctuation, and digits are kept unchanged. The key only advances for alphabetic characters.

```
Plaintext:  H e l l o ,   W o r l d !
Key:        K E Y K E      Y K E Y K
Ciphertext: R i j v s ,   U y v j n !
```

Note: the key does NOT advance for the comma or space.

---

## Mathematical Representation

Let:
- `P` = plaintext letter position (0-25)
- `K[i]` = key letter at position `i` (0-25)
- `C` = ciphertext letter position

**Encryption**: `C = (P + K[i]) mod 26`
**Decryption**: `P = (C - K[i]) mod 26`

Where `i` cycles through the key: `i = letter_index mod key_length`

This is essentially multiple Caesar ciphers applied in rotation.

---

## Why It Is Stronger Than Caesar

### Caesar (Monoalphabetic)

- One shift for all letters
- The letter 'E' always maps to the same ciphertext letter
- Only 25 possible keys
- Trivial to brute force

### Vigenere (Polyalphabetic)

- Different shift for each position in the key cycle
- The same plaintext letter can encrypt to different ciphertext letters
- Key space is `26^n` where `n` is the key length
- A 5-letter key gives `26^5 = 11,881,376` possible keys
- Frequency analysis on individual letters does not work directly

```
Plaintext:  A T T A C K A T D A W N
Key:        L E M O N L E M O N L E
Ciphertext: L X F O P V E F R N H R
```

Notice: both A's at positions 1 and 4 encrypt to different letters (L and O).

---

## Kasiski Examination (How to Break It)

Discovered by Friedrich Kasiski in 1863, this method finds the key length.

### The Idea

If the same plaintext sequence aligns with the same key position, it produces identical ciphertext. The distance between these repeated sequences is a multiple of the key length.

### Steps

1. **Find repeated sequences** in the ciphertext (3+ characters)
2. **Measure distances** between their starting positions
3. **Compute GCD** of all distances
4. The GCD is likely the key length (or a multiple of it)

### Example

```
Ciphertext: ... VPTN ... VPTN ...
                ^           ^
            position 5   position 20

Distance = 20 - 5 = 15
Factors of 15: 1, 3, 5, 15
Key length is likely 3 or 5
```

### After Finding Key Length

Once you know the key length `n`:
1. Group ciphertext letters by position modulo `n`
2. Each group is a simple Caesar cipher
3. Apply frequency analysis to each group separately
4. Reconstruct the key

---

## Historical Usage

- **1553**: Invented by Giovan Battista Bellaso, later attributed to Blaise de Vigenere
- **"Le chiffre indechiffrable"**: Known for centuries as "the indecipherable cipher"
- **American Civil War**: Used by the Confederacy
- **World War I**: Still in use, though breakable by then
- **300 years unbroken**: From 1553 to 1863 it was considered secure

---

## Weaknesses

1. **Repeating key**: The key cycles, creating patterns
2. **Kasiski examination**: Repeated plaintext aligned with the same key position produces repeated ciphertext
3. **Index of Coincidence**: Statistical method to determine key length
4. **Known plaintext**: If you know part of the message, you can recover part of the key
5. **Short keys**: Short keys cycle frequently, making patterns easier to detect
6. **Frequency analysis per group**: Once key length is known, each group is just a Caesar cipher

---

## Key Concepts for Implementation

You will need to handle:

1. **Key repetition**: Extend the key to match plaintext length
2. **Case preservation**: Uppercase stays uppercase, lowercase stays lowercase
3. **Non-letter passthrough**: Spaces, digits, punctuation remain unchanged
4. **Key advancement**: The key index only advances for alphabetic characters
5. **Modular arithmetic**: Same `mod 26` as Caesar, but with varying shifts

---

## What You Will Learn

- Working with multiple strings simultaneously (plaintext + key)
- Cycling through an index with modulo
- Building on Caesar cipher functions
- Understanding polyalphabetic substitution
- Introduction to classical cryptanalysis

---

## Next Steps

[02-vigenere-challenges.md](02-vigenere-challenges.md) - Implement the cipher step by step
