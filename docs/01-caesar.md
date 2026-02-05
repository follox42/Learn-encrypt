# Caesar Cipher

One of the oldest and simplest encryption techniques, named after Julius Caesar who used it in his private correspondence.

---

## How It Works

**Principle**: Shift each letter by a fixed number of positions in the alphabet.

```
Plaintext:  HELLO
Shift: 3
Ciphertext: KHOOR
```

### Encryption

```
For each letter:
  new_position = (old_position + shift) mod 26
```

**Example with shift 3:**
- H (position 7) → K (position 10)
- E (position 4) → H (position 7)
- L (position 11) → O (position 14)

### Decryption

```
For each letter:
  new_position = (old_position - shift) mod 26
```

**Same as encrypting with shift -3** (or shift 23)

---

## Mathematical Representation

Let:
- `P` = plaintext letter position (0-25)
- `K` = key (shift value)
- `C` = ciphertext letter position

**Encryption**: `C = (P + K) mod 26`
**Decryption**: `P = (C - K) mod 26`

---

## Why Modulo 26?

The alphabet has 26 letters. Modulo wraps around:

```
Z (25) + 3 = 28 mod 26 = 2 = C
A (0) - 1 = -1 mod 26 = 25 = Z
```

This is why you needed the `mod()` function from challenge 6!

---

## Key Properties

1. **Symmetric**: Same algorithm for encryption/decryption (different key)
2. **Substitution cipher**: Each letter always maps to the same letter
3. **Mono-alphabetic**: Only one alphabet used
4. **Vulnerable**: Only 25 possible keys (trivial to brute force)

---

## Historical Usage

- **Julius Caesar**: Used shift of 3
- **ROT13**: Popular variant with shift of 13 (encrypting twice gives original)
- **Military**: Used until WWI (easily broken)

---

## Weaknesses

1. **Small keyspace**: Only 25 keys → brute force in seconds
2. **Frequency analysis**: Letter patterns preserved
3. **No confusion**: Same input always gives same output

---

## Variations

### ROT13

```
Shift = 13
Encrypt = Decrypt (self-inverse)
```

Used in forums to hide spoilers.

### Shift Cipher

Generic term for any shift value (Caesar is shift 3).

---

## Implementation Challenges

You'll need to handle:

1. **Uppercase and lowercase** (preserve case)
2. **Non-alphabetic characters** (spaces, punctuation - keep as-is)
3. **Negative shifts** (use your `mod()` function!)
4. **Wrapping** (Z → A, a → z)

---

## What You'll Learn

- Converting characters to positions (0-25)
- Using modular arithmetic in practice
- Handling edge cases (case, punctuation)
- Classical cryptanalysis basics

---

## Next Steps

[01-caesar-challenges.md](01-caesar-challenges.md) - Implement the cipher
