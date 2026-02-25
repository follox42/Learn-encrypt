# MD5 - Challenges

Implement the MD5 hash function step by step in C. Each challenge builds toward the full algorithm.

---

## Challenge 1: Message Padding

Implement MD5 message padding: extend the input to a multiple of 512 bits (64 bytes).

```c
int md5_pad(const unsigned char *message, size_t len, unsigned char *output);
```

**Test cases:**
```
Input: "abc" (3 bytes)
Output: 64 bytes:
  61 62 63 80 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  18 00 00 00 00 00 00 00

Input: "" (0 bytes)
Output: 64 bytes (0x80 at position 0, length = 0 at end)

Input: 55 bytes of 'a'
Output: 64 bytes (just fits in one block)

Input: 56 bytes of 'a'
Output: 128 bytes (needs two blocks)
```

**Hints:**
- Append 0x80 byte after the message
- Pad with 0x00 until 8 bytes remain in the block
- Append original message length in bits as a 64-bit little-endian integer
- If message length mod 64 >= 56, you need an extra block

---

## Challenge 2: Auxiliary Functions

Implement the four MD5 auxiliary functions (F, G, H, I) and the left rotate operation.

```c
uint32_t F(uint32_t B, uint32_t C, uint32_t D);
uint32_t G(uint32_t B, uint32_t C, uint32_t D);
uint32_t H(uint32_t B, uint32_t C, uint32_t D);
uint32_t I(uint32_t B, uint32_t C, uint32_t D);
uint32_t left_rotate(uint32_t x, uint32_t n);
```

**Test cases:**
```
F(0xFF, 0x00, 0xAA) = 0x00
  Explanation: F selects C where B=1, D where B=0
  B=0xFF=11111111, so pick C bits for those positions -> bottom 8 bits = 0x00

G(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = expected value
H(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = expected value
I(0xFF00FF00, 0x0F0F0F0F, 0xAAAAAAAA) = expected value

left_rotate(0x00000001, 1)  = 0x00000002
left_rotate(0x80000000, 1)  = 0x00000001
left_rotate(0xABCD1234, 4)  = 0xBCD1234A
left_rotate(0x12345678, 0)  = 0x12345678
```

**Hints:**
- F(B,C,D) = (B & C) | (~B & D)
- G(B,C,D) = (B & D) | (C & ~D)
- H(B,C,D) = B ^ C ^ D
- I(B,C,D) = C ^ (B | ~D)
- left_rotate(x, n) = (x << n) | (x >> (32 - n))
- Use `#include <stdint.h>` for uint32_t

---

## Challenge 3: One MD5 Round

Implement one MD5 round (16 operations) that updates the state variables.

```c
void md5_round(uint32_t *a, uint32_t *b, uint32_t *c, uint32_t *d,
               uint32_t *M, int round_num);
```

**Test case:**
```
Initial state: a=0x67452301, b=0xEFCDAB89, c=0x98BADCFE, d=0x10325476
Message block: the padded version of "abc" (16 words, little-endian)
After round 1: check intermediate values match known MD5 computation
```

**Hints:**
- Each round uses a different auxiliary function (F, G, H, I)
- Each round uses a different message word order
- Use the K constants table (64 values derived from sin function)
- Use the shift amounts table (s values)
- Per-operation: A = D, D = C, C = B, B = B + left_rotate(A + func + K[i] + M[g], s[i])

---

## Challenge 4: Full MD5 Hash

Implement the complete MD5 hash function.

```c
void md5(const unsigned char *message, size_t len, unsigned char *digest);
void md5_to_hex(const unsigned char *digest, char *hex_string);
```

**Test cases (from RFC 1321):**
```
md5("")                = "d41d8cd98f00b204e9800998ecf8427e"
md5("a")               = "0cc175b9c0f1b6a831c399e269772661"
md5("abc")             = "900150983cd24fb0d6963f7d28e17f72"
md5("message digest")  = "f96b697d7cb7938d525a2f31aaf161d0"
md5("abcdefghijklmnopqrstuvwxyz")
                       = "c3fcd3d76192e4007dfb496cca67e13b"
```

**Hints:**
- Combine padding, state initialization, and all 4 rounds
- Process blocks sequentially, updating the state each time
- After each block: add the round results to the running state
- Final hash is the state in little-endian byte order
- Compare your output with the `md5sum` command-line tool

---

## Challenge 5: Collision Demonstration

Demonstrate that MD5 is broken by verifying known collision pairs: two different inputs that produce the same hash.

```c
void demonstrate_collision(void);
```

**Known collision pair (from Wang et al.):**
```
Use two known binary strings that produce the same MD5 hash.
Show that:
  1. The two inputs are different (compare bytes)
  2. Their MD5 hashes are identical
  3. Print both inputs in hex and the matching hash
```

**Hints:**
- Do NOT try to find collisions yourself (it requires specialized algorithms)
- Use a published collision pair (hardcode the two known colliding byte sequences)
- The point is to demonstrate that two different inputs can have the same MD5 hash
- This is why MD5 should never be used for security

---

## Challenge 6: Full MD5 Program

Build a complete MD5 tool that can hash strings, hash files, and verify checksums.

```c
int main(int argc, char *argv[]);
```

**Features:**
```
Usage:
  ./md5tool -s "string"        Hash a string
  ./md5tool -f filename        Hash a file
  ./md5tool -c filename.md5    Verify checksums from a file

Example output:
  $ ./md5tool -s "abc"
  900150983cd24fb0d6963f7d28e17f72  "abc"

  $ ./md5tool -f test.txt
  900150983cd24fb0d6963f7d28e17f72  test.txt

  $ ./md5tool -c checksums.md5
  test.txt: OK
  data.bin: FAILED
```

**Hints:**
- Parse command-line arguments with argc/argv
- For file hashing, read the file in chunks
- For checksum verification, parse lines in the format: hash  filename
- Compare your output with the system `md5sum` command
- Handle errors gracefully (file not found, invalid arguments)
