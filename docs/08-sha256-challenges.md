# SHA-256 - Challenges

Implement SHA-256 step by step in C. Each challenge builds toward the full algorithm.

---

## Challenge 1: Message Padding

Implement SHA-256 message padding: extend the input to a multiple of 512 bits with big-endian length.

```c
int sha256_pad(const unsigned char *message, size_t len, unsigned char *output);
```

**Test cases:**
```
Input: "abc" (3 bytes)
Output: 64 bytes:
  61 62 63 80 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 18

Input: "" (0 bytes)
Output: 64 bytes (0x80 at position 0, length = 0 at end, big-endian)

Input: 56 bytes of 'a'
Output: 128 bytes (needs two blocks, same boundary rule as MD5)
```

**Hints:**
- Almost identical to MD5 padding, but the length field is big-endian
- Append 0x80, then zeros, then 64-bit big-endian length in bits
- The message words themselves are also read as big-endian (unlike MD5)

---

## Challenge 2: Logical Functions

Implement the six core SHA-256 logical operations plus the rotate/shift primitives.

```c
uint32_t rotr(uint32_t x, uint32_t n);
uint32_t shr(uint32_t x, uint32_t n);
uint32_t Ch(uint32_t x, uint32_t y, uint32_t z);
uint32_t Maj(uint32_t x, uint32_t y, uint32_t z);
uint32_t Sigma0(uint32_t x);
uint32_t Sigma1(uint32_t x);
uint32_t sigma0(uint32_t x);
uint32_t sigma1(uint32_t x);
```

**Test cases:**
```
rotr(0x00000001, 1)    = 0x80000000
rotr(0xABCD1234, 4)    = 0x4ABCD123
shr(0xABCD1234, 4)     = 0x0ABCD123

Ch(0xFFFFFFFF, 0x12345678, 0xABCDEF01)  = 0x12345678
Ch(0x00000000, 0x12345678, 0xABCDEF01)  = 0xABCDEF01
Maj(0xFF00FF00, 0xFF0000FF, 0x00FF00FF) = 0xFF0000FF

Sigma0(0x6a09e667) = verify against known value
Sigma1(0x510e527f) = verify against known value
sigma0(0x61626380) = verify against known value
sigma1(0x00000018) = verify against known value
```

**Hints:**
- rotr(x, n) = (x >> n) | (x << (32 - n))
- shr(x, n)  = x >> n
- Ch(x,y,z)  = (x & y) ^ (~x & z)
- Maj(x,y,z) = (x & y) ^ (x & z) ^ (y & z)
- Sigma0(x) = rotr(x,2) ^ rotr(x,13) ^ rotr(x,22)
- Sigma1(x) = rotr(x,6) ^ rotr(x,11) ^ rotr(x,25)
- sigma0(x) = rotr(x,7) ^ rotr(x,18) ^ shr(x,3)
- sigma1(x) = rotr(x,17) ^ rotr(x,19) ^ shr(x,10)

---

## Challenge 3: Message Schedule

Expand 16 message words into 64 words for the compression function.

```c
void sha256_message_schedule(const uint32_t *block, uint32_t *W);
```

**Test case:**
```
Input block from "abc" (first 16 words, big-endian):
  W[0]  = 0x61626380
  W[1]  = 0x00000000
  ...
  W[15] = 0x00000018

After expansion:
  W[16] = sigma1(W[14]) + W[9] + sigma0(W[1]) + W[0]
  ...
  W[63] = computed value

Verify W[16] through W[63] match known SHA-256 intermediate values for "abc".
```

**Hints:**
- W[0] to W[15]: copy directly from the message block (already big-endian)
- W[t] = sigma1(W[t-2]) + W[t-7] + sigma0(W[t-15]) + W[t-16]  for t = 16..63
- All additions are modulo 2^32 (uint32_t overflow handles this naturally)

---

## Challenge 4: Compression Function

Implement the SHA-256 compression function (64 rounds).

```c
void sha256_compress(uint32_t *state, const uint32_t *W);
```

**Test case:**
```
Initial state: {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
                0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19}

After processing the "abc" block:
  state[0] = 0xba7816bf
  state[1] = 0x8f01cfea
  ...etc (the SHA-256 of "abc")

Round-by-round trace (first few rounds):
  Round 0: a=0x5d6aebcd, e=0xfa2a4622, ...
  (Compare with known SHA-256 trace for "abc")
```

**Hints:**
- Initialize a,b,c,d,e,f,g,h from the state
- For each round t (0 to 63):
    T1 = h + Sigma1(e) + Ch(e,f,g) + K[t] + W[t]
    T2 = Sigma0(a) + Maj(a,b,c)
    Shift variables: h=g, g=f, f=e, e=d+T1, d=c, c=b, b=a, a=T1+T2
- After 64 rounds, add a..h back to state[0..7]

---

## Challenge 5: Full SHA-256

Implement the complete SHA-256 hash function.

```c
void sha256(const unsigned char *message, size_t len, unsigned char *digest);
void sha256_to_hex(const unsigned char *digest, char *hex_string);
```

**Test cases (from NIST examples):**
```
sha256("")
  = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"

sha256("abc")
  = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"

sha256("abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq")
  = "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"
```

**Hints:**
- Combine padding, message schedule, and compression
- Process each 512-bit block sequentially
- Remember: big-endian byte order for words and output
- Compare your output with the `sha256sum` command-line tool
- Make sure multi-block messages work (test with the long string above)

---

## Challenge 6: Full SHA-256 Program

Build a complete SHA-256 tool that can hash strings, hash files, and compare hashes.

```c
int main(int argc, char *argv[]);
```

**Features:**
```
Usage:
  ./sha256tool -s "string"        Hash a string
  ./sha256tool -f filename        Hash a file
  ./sha256tool -c filename.sha256 Verify checksums from a file
  ./sha256tool --compare hash     Hash stdin and compare to given hash

Example output:
  $ ./sha256tool -s "abc"
  ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad  "abc"

  $ ./sha256tool -f test.txt
  ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad  test.txt

  $ ./sha256tool -c checksums.sha256
  test.txt: OK
  data.bin: FAILED
```

**Hints:**
- Parse command-line arguments with argc/argv
- For file hashing, read the file in chunks
- For checksum verification, parse lines in the format: hash  filename
- Compare your output with the system `sha256sum` command
- Handle errors gracefully (file not found, invalid arguments)
