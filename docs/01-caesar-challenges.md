# Caesar Cipher - Challenges

Implement the Caesar cipher in C. Build it step by step.

---

## Challenge 1: Letter to Position

Write a function that converts a letter to its position (0-25).

```c
int letter_to_pos(char c);
```

**Test cases:**
```
'A' → 0
'Z' → 25
'a' → 0
'z' → 25
```

**Hints:**
- Use ASCII values: 'A' = 65, 'a' = 97
- Subtract to get position: 'A' - 'A' = 0
- Handle both uppercase and lowercase

---

## Challenge 2: Position to Letter

Write a function that converts a position (0-25) back to a letter.

```c
char pos_to_letter(int pos, int uppercase);
```

**Test cases:**
```
(0, 1) → 'A'
(25, 1) → 'Z'
(0, 0) → 'a'
(25, 0) → 'z'
```

**Hints:**
- Add position to 'A' or 'a'
- Use the `uppercase` parameter to decide which

---

## Challenge 3: Encrypt Single Character

Write a function that encrypts a single character.

```c
char caesar_encrypt_char(char c, int shift);
```

**Test cases:**
```
('A', 3) → 'D'
('Z', 3) → 'C'
('a', 3) → 'd'
('5', 3) → '5' (non-letter unchanged)
```

**Steps:**
1. Check if character is a letter (use `isalpha()` or manual check)
2. Determine if uppercase/lowercase
3. Convert to position (0-25)
4. Apply shift with modulo
5. Convert back to letter

---

## Challenge 4: Encrypt String

Write a function that encrypts an entire string.

```c
void caesar_encrypt(char *plaintext, char *ciphertext, int shift);
```

**Test case:**
```
plaintext = "Hello, World!"
shift = 3
ciphertext = "Khoor, Zruog!"
```

**Requirements:**
- Preserve case (H→K, h→k)
- Keep non-letters unchanged (space, comma, exclamation)
- Use your `caesar_encrypt_char()` function

---

## Challenge 5: Decrypt String

Write a decrypt function.

```c
void caesar_decrypt(char *ciphertext, char *plaintext, int shift);
```

**Hint:** Decrypt is just encrypt with `-shift`!

```c
caesar_decrypt(cipher, plain, shift) {
    caesar_encrypt(cipher, plain, -shift);
}
```

Or reuse your `mod()` function to handle negatives.

---

## Challenge 6: Brute Force

Write a program that tries all 26 possible shifts.

**Goal:** Given ciphertext, print all possible plaintexts.

**Example:**
```
Ciphertext: "Khoor"

Trying shift 0: Khoor
Trying shift 1: Jgnnq
Trying shift 2: Ifmmp
Trying shift 3: Hello  ← This looks like English!
...
```

**Why this works:** Only 25 keys to try. Human can spot the correct one.

---

## Challenge 7: ROT13

Implement ROT13 (shift of 13).

**Special property:** Encrypting twice gives original.

```c
void rot13(char *input, char *output);
```

**Test:**
```
rot13("Hello") → "Uryyb"
rot13("Uryyb") → "Hello"
```

---

## Challenge 8: Full Caesar Program

Combine everything into a complete program:

1. Ask user for plaintext
2. Ask for shift value
3. Encrypt and display
4. Decrypt and verify
5. Show all brute force attempts

**Menu:**
```
1. Encrypt
2. Decrypt
3. Brute force
4. ROT13
5. Exit
```

---

## Validation

When all challenges work:
- You understand substitution ciphers
- You can handle string manipulation in C
- You're ready for Vigenère cipher (polyalphabetic)

**Next:** [02-vigenere.md](02-vigenere.md)
