# Fundamentals

Before implementing any encryption algorithm, you need to understand these core concepts.

---

## 1. Binary Representation

Everything in a computer is stored as binary (0s and 1s). A single binary digit is called a **bit**.

- 8 bits = 1 **byte**
- A byte can represent values from 0 to 255

**Key concept**: Every character, number, and piece of data you encrypt is ultimately a sequence of bits.

---

## 2. Hexadecimal Notation

Hexadecimal (base 16) uses digits 0-9 and letters A-F.

- Why it matters: 1 hex digit = 4 bits, so 2 hex digits = 1 byte
- Example: `0x41` = 65 in decimal = letter 'A' in ASCII

Cryptographic data is often displayed in hexadecimal because it's more compact than binary.

---

## 3. ASCII Encoding

ASCII maps characters to numbers (0-127).

- 'A' = 65
- 'a' = 97
- '0' = 48

0-127 means it's encoded in 8 bits with the first bit to 0. 

**Key insight**: When you encrypt text, you're actually manipulating these numeric values.

---

## 4. Bitwise Operations

These operations work directly on individual bits:

### AND (&)
Both bits must be 1 to produce 1.
```
1010 & 1100 = 1000
```

### OR (|)
Either bit being 1 produces 1.
```
1010 | 1100 = 1110
```

### XOR (^)
Bits must be different to produce 1.
```
1010 ^ 1100 = 0110
```

### NOT (~)
Flips all bits.

### Shift (<<, >>)
Moves bits left or right.

---

## 5. The XOR Property

XOR is fundamental to encryption because of this property:

```
A ^ B = C
C ^ B = A
```

If you XOR data with a key, you get encrypted data.
If you XOR the encrypted data with the same key, you get the original back.

This is the foundation of most symmetric encryption.

---

## 6. Modular Arithmetic

"Clock arithmetic" - numbers wrap around after reaching a limit.

- 25 mod 26 = 25
- 27 mod 26 = 1
- 52 mod 26 = 0

**Why it matters**: Caesar cipher shifts letters using modular arithmetic to wrap 'Z' back to 'A'.

---

## What You Should Be Able To Do

Before moving to Caesar cipher, make sure you can:

1. Convert a character to its ASCII value
2. Convert a decimal number to binary and hexadecimal
3. Perform XOR on two bytes manually
4. Understand why `(x ^ y) ^ y == x`
5. Calculate modular arithmetic by hand

---

## Next

[01-caesar.md](01-caesar.md) - Your first cipher implementation
