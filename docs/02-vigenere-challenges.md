# Vigenere Cipher - Challenges

Implement the Vigenere cipher in C. Build on your Caesar cipher skills.

---

## Challenge 1: Repeat Key

Write a function that repeats a key to match a given length.

```c
void repeat_key(const char *key, int length, char *output);
```

**Test cases:**
```
("KEY", 10) → "KEYKEYKEYK"
("AB", 5)   → "ABABA"
("SECRET", 3) → "SEC"
("A", 6)    → "AAAAAA"
```

**Hints:**
- Use modulo to cycle through the key: `key[i % key_length]`
- Remember to null-terminate the output string

---

## Challenge 2: Encrypt Single Character

Write a function that encrypts one character using a key character.

```c
char vigenere_encrypt_char(char plain, char key);
```

**Test cases:**
```
('H', 'K') → 'R'     (7 + 10 = 17)
('e', 'K') → 'o'     (4 + 10 = 14, lowercase preserved)
('Z', 'B') → 'A'     (25 + 1 = 26 mod 26 = 0, wraps around)
('5', 'K') → '5'     (non-letter unchanged)
(' ', 'A') → ' '     (space unchanged)
```

**Hints:**
- Convert the key character to a shift value (0-25)
- The key character is always treated as uppercase (A=0, B=1, ..., Z=25)
- Reuse your logic from Caesar's `encrypt_char` - this is the same, but the shift comes from the key letter

---

## Challenge 3: Encrypt String

Write a function that encrypts a full string with the Vigenere cipher.

```c
void vigenere_encrypt(const char *plaintext, const char *key, char *ciphertext);
```

**Test cases:**
```
("Hello, World!", "KEY") → "Rijvs, Ambpb!"
("ATTACKATDAWN", "LEMON") → "LXFOPVEFRNHR"
("abc", "A")             → "abc"          (key 'A' = shift 0)
```

**Important:**
- The key index only advances for alphabetic characters
- Non-letters are copied as-is but do NOT consume a key character
- Preserve case of the plaintext

**Steps:**
1. Keep a separate key index counter
2. For each plaintext character:
   - If alphabetic: encrypt with current key letter, advance key index
   - If not alphabetic: copy unchanged, do NOT advance key index

---

## Challenge 4: Decrypt String

Write a function that decrypts a Vigenere-encrypted string.

```c
void vigenere_decrypt(const char *ciphertext, const char *key, char *plaintext);
```

**Test cases:**
```
("Rijvs, Ambpb!", "KEY") → "Hello, World!"
("LXFOPVEFRNHR", "LEMON") → "ATTACKATDAWN"
```

**Hint:** Decryption subtracts the key instead of adding it:
`P = (C - K[i]) mod 26`

You can write a separate decrypt_char function, or modify encrypt_char to handle both directions.

---

## Challenge 5: Kasiski Examination

Write a program that finds repeated sequences in ciphertext to guess the key length.

```c
void find_repeated_sequences(const char *ciphertext, int min_length);
```

**Concept:**
1. Scan through the ciphertext for repeated sequences of 3+ characters
2. Record the distance between each pair of repeated sequences
3. Find the GCD of all distances
4. The GCD suggests the likely key length

**Example:**
```
Ciphertext: "ABCXYZABCMNOPQRABCXYZ"

Repeated: "ABC" at positions 0, 6, 15
  Distance 6-0 = 6
  Distance 15-0 = 15
  Distance 15-6 = 9
  GCD(6, 15, 9) = 3
  → Key length is likely 3
```

**This is an open-ended challenge.** Focus on:
- Finding repeated substrings
- Computing distances
- Finding GCD of multiple numbers

---

## Challenge 6: Full Vigenere Program

Combine everything into a complete interactive program.

**Menu:**
```
=== Vigenere Cipher Tool ===
1. Encrypt a message
2. Decrypt a message
3. Kasiski analysis
4. Exit
```

**Features:**
- Prompt user for message and key
- Encrypt and display result
- Decrypt and verify round-trip
- Run Kasiski examination on ciphertext
- Loop until user chooses exit

---

## Validation

When all challenges work:
- You understand polyalphabetic ciphers
- You can manipulate multiple strings in C
- You understand why repeating keys create patterns
- You are ready for more advanced ciphers

**Next:** Transposition ciphers (coming soon)
