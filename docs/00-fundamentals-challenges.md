# Fundamentals - Challenges

Implement these in C. No solutions provided - that's the point.

---

## Challenge 1: ASCII Explorer

Write a program that:
- Takes a string as input
- Prints each character with its ASCII decimal value

**Test case:**
```
Input: "Hello"
Expected output:
H -> 72
e -> 101
l -> 108
l -> 108
o -> 111
```

---

## Challenge 2: Binary Printer

Write a program that:
- Takes an integer (0-255) as input
- Prints its 8-bit binary representation

**Test cases:**
```
Input: 65    Output: 01000001
Input: 255   Output: 11111111
Input: 0     Output: 00000000
```

**Hint**: Think about how you can isolate each bit using bitwise operations.

---

## Challenge 3: Hex Converter

Write a program that:
- Takes a string as input
- Prints each character as a 2-digit hexadecimal value

**Test case:**
```
Input: "ABC"
Output: 41 42 43
```

---

## Challenge 4: XOR Two Bytes

Write a program that:
- Takes two integers (0-255) as input
- Prints the XOR result in decimal, binary, and hex

**Test case:**
```
Input: 170, 85
Output:
Decimal: 255
Binary: 11111111
Hex: FF
```

---

## Challenge 5: XOR Encryption Proof

Write a program that demonstrates the XOR property:
- Take a byte and a key byte
- XOR them to get "encrypted"
- XOR the result with the key again
- Verify you get the original byte back

**Goal**: Prove to yourself that `(A ^ K) ^ K == A`

---

## Challenge 6: Modular Arithmetic

Write a function:
```
int mod(int a, int n)
```
That handles negative numbers correctly.

**Test cases:**
```
mod(27, 26) = 1
mod(-1, 26) = 25
mod(-27, 26) = 25
```

**Why this matters**: Caesar cipher needs this for wrapping letters.

---

## Challenge 7: String XOR

Write a program that:
- Takes a string and a single-character key
- XORs each character with the key
- Prints the result as hex bytes
- Then decrypts it back to the original string

This is your first "encryption" program.

---

## Validation

When all challenges work, you're ready for [01-caesar.md](01-caesar.md)
