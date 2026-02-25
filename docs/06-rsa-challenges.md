# RSA - Challenges

Implement RSA step by step in C. Each challenge builds on the previous ones.

---

## Challenge 1: Modular Exponentiation

Implement the square-and-multiply algorithm for modular exponentiation.

```c
long long mod_exp(long long base, long long exp, long long mod);
```

**Test cases:**
```
mod_exp(2, 10, 1000)  = 24
mod_exp(3, 13, 50)    = 7
mod_exp(5, 3, 13)     = 8
mod_exp(7, 256, 13)   = 9
mod_exp(2, 0, 100)    = 1
```

**Hints:**
- Process the exponent bit by bit
- At each step: square the result, then multiply by base if the current bit is 1
- Take mod at every step to prevent overflow
- Consider using `unsigned long long` for large numbers

---

## Challenge 2: GCD and Extended Euclidean Algorithm

Implement the Euclidean algorithm for GCD and the Extended Euclidean algorithm to find modular inverses.

```c
long long gcd(long long a, long long b);
long long extended_gcd(long long a, long long b, long long *x, long long *y);
long long mod_inverse(long long a, long long mod);
```

**Test cases:**
```
gcd(35, 15)           = 5
gcd(12, 8)            = 4
gcd(17, 3120)         = 1
gcd(0, 5)             = 5

mod_inverse(7, 26)    = 15    (because 7 * 15 mod 26 = 1)
mod_inverse(17, 3120) = 2753  (because 17 * 2753 mod 3120 = 1)
mod_inverse(3, 26)    = 9     (because 3 * 9 mod 26 = 1)
```

**Hints:**
- GCD: gcd(a, b) = gcd(b, a % b), base case: gcd(a, 0) = a
- Extended GCD returns x, y such that: a*x + b*y = gcd(a, b)
- mod_inverse uses extended GCD: if gcd(a, mod) = 1, then x from a*x + mod*y = 1 gives the inverse
- Handle negative results: if x < 0, add mod

---

## Challenge 3: Primality Test

Implement a function to test if a number is prime.

```c
int is_prime(long long n);
```

**Test cases:**
```
is_prime(2)     = 1
is_prime(17)    = 1
is_prime(97)    = 1
is_prime(15)    = 0
is_prime(1)     = 0
is_prime(7919)  = 1
```

**Hints:**
- Simple approach: trial division up to sqrt(n)
- Check divisibility by 2 first, then only odd numbers
- Bonus: implement Miller-Rabin probabilistic test for larger numbers

---

## Challenge 4: RSA Key Generation

Generate an RSA key pair using small primes (for learning purposes).

```c
typedef struct {
    long long n;   // modulus
    long long e;   // public exponent
    long long d;   // private exponent
} rsa_key_t;

rsa_key_t rsa_keygen(long long p, long long q);
```

**Test cases:**
```
p = 61, q = 53:
  n = 3233
  phi = 3120
  e = 17
  d = 2753
  Check: (17 * 2753) % 3120 == 1

p = 11, q = 13:
  n = 143
  phi = 120
  e = 7
  d = 103
  Check: (7 * 103) % 120 == 1
```

**Hints:**
- Compute n = p * q
- Compute phi = (p-1) * (q-1)
- Choose e: start with 65537, fall back to 17, or find the smallest e coprime to phi
- Compute d = mod_inverse(e, phi)
- Use your functions from challenges 2 and 3

---

## Challenge 5: RSA Encryption

Encrypt a number using the RSA public key.

```c
long long rsa_encrypt(long long message, long long e, long long n);
```

**Test cases (using p=61, q=53, e=17, n=3233):**
```
rsa_encrypt(65, 17, 3233) = 2790
rsa_encrypt(72, 17, 3233) = 2818
rsa_encrypt(0, 17, 3233)  = 0
rsa_encrypt(1, 17, 3233)  = 1
```

**Hints:**
- This is just mod_exp(message, e, n)
- Message must be less than n
- Each number is encrypted independently

---

## Challenge 6: RSA Decryption

Decrypt a ciphertext using the RSA private key.

```c
long long rsa_decrypt(long long ciphertext, long long d, long long n);
```

**Test cases (using d=2753, n=3233):**
```
rsa_decrypt(2790, 2753, 3233) = 65
rsa_decrypt(2818, 2753, 3233) = 72
rsa_decrypt(0, 2753, 3233)    = 0
```

**Hints:**
- This is just mod_exp(ciphertext, d, n)
- Verify: decrypt(encrypt(M)) == M for all M < n
- Try encrypting and decrypting each character of a string

---

## Challenge 7: Digital Signatures

Implement signing and verification using RSA.

```c
long long rsa_sign(long long message_hash, long long d, long long n);
int rsa_verify(long long message_hash, long long signature, long long e, long long n);
```

**Test cases (using e=17, d=2753, n=3233):**
```
sig = rsa_sign(42, 2753, 3233)
rsa_verify(42, sig, 17, 3233)          = 1  (valid)
rsa_verify(43, sig, 17, 3233)          = 0  (invalid - wrong hash)
rsa_verify(42, sig + 1, 17, 3233)      = 0  (invalid - tampered signature)
```

**Hints:**
- Signing: signature = mod_exp(hash, d, n) (use private key)
- Verifying: recovered = mod_exp(signature, e, n), compare with hash
- In real RSA, you sign a hash of the message, not the message itself
- For this exercise, use a simple hash (like sum of ASCII values mod n)

---

## Challenge 8: Complete RSA Program

Build a complete RSA program that combines all previous challenges.

**Features:**
1. Generate a key pair from two primes
2. Encrypt a string character by character
3. Decrypt back to the original string
4. Sign a message and verify the signature
5. Print all intermediate values

**Test scenario:**
```
Input primes: p = 61, q = 53
Generated keys: public (17, 3233), private (2753, 3233)

Encrypt "HELLO":
  H (72) -> 2818
  E (69) -> ...
  L (76) -> ...
  L (76) -> ...
  O (79) -> ...

Decrypt back: HELLO

Sign message hash: ...
Verify signature: VALID
```

**Hints:**
- Combine all functions from challenges 1-7
- Handle each character as a separate number
- Print step-by-step output for learning
- Try with different prime pairs to verify correctness

---

## Validation

When all challenges work:
- You understand the mathematical foundations of RSA
- You can implement modular arithmetic from scratch
- You understand public/private key pairs
- You know how digital signatures work
- You are ready for hashing algorithms (MD5, SHA-256)

**Next:** [07-md5.md](07-md5.md)
