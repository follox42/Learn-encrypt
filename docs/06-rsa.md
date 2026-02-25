# RSA (Rivest-Shamir-Adleman)

The most widely used asymmetric encryption algorithm, invented in 1977. Unlike symmetric ciphers (Caesar, AES), RSA uses **two different keys**: one to encrypt, another to decrypt.

---

## Public Key vs Private Key

**The problem**: With symmetric encryption, both parties need the same secret key. How do you share that key securely in the first place?

**The solution**: Asymmetric encryption uses a **key pair**:
- **Public key**: Share with everyone. Used to encrypt messages.
- **Private key**: Keep secret. Used to decrypt messages.

```
Alice wants to send a message to Bob:

1. Bob generates a key pair (public + private)
2. Bob shares his public key with everyone
3. Alice encrypts her message with Bob's public key
4. Only Bob can decrypt it with his private key
```

Anyone can encrypt a message for Bob, but only Bob can read it.

---

## Mathematical Foundation

### Prime Numbers

A prime number has exactly two factors: 1 and itself.

```
Primes:     2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ...
Not prime:  15 = 3 x 5 (has more than two factors)
```

**Key insight**: Multiplying two primes is easy. Factoring their product is hard.

```
Easy:  61 x 53 = 3233       (instant)
Hard:  3233 = ? x ?          (need to try many factors)
```

For small numbers this is trivial, but for numbers with 300+ digits, factoring is computationally infeasible with current technology.

### Euler's Totient Function

For a number n, Euler's totient phi(n) counts how many integers from 1 to n are coprime with n (share no common factors other than 1).

```
phi(7) = 6    (1, 2, 3, 4, 5, 6 are all coprime with 7)
phi(10) = 4   (1, 3, 7, 9 are coprime with 10)
```

**For a prime p**: phi(p) = p - 1 (all numbers less than a prime are coprime with it).

**For two primes p and q**: phi(p * q) = (p - 1) * (q - 1).

This is the formula RSA uses.

### Modular Arithmetic

RSA relies heavily on modular exponentiation:

```
a^b mod n

Example: 2^10 mod 1000 = 1024 mod 1000 = 24
```

Euler's theorem states: if gcd(a, n) = 1, then a^phi(n) = 1 (mod n).

This is why RSA decryption works -- it is a direct consequence of this theorem.

---

## Key Generation

This is the setup phase. It only happens once.

### Step 1: Choose Two Large Primes

```
p = 61
q = 53
```

In practice, p and q are each 1024+ bits (300+ digits).

### Step 2: Compute n (the modulus)

```
n = p * q = 61 * 53 = 3233
```

n is part of both the public and private key.

### Step 3: Compute Euler's Totient

```
phi(n) = (p - 1) * (q - 1) = 60 * 52 = 3120
```

phi(n) must be kept secret. If an attacker knows phi(n), they can compute the private key.

### Step 4: Choose Public Exponent e

Choose e such that:
- 1 < e < phi(n)
- gcd(e, phi(n)) = 1 (e and phi(n) are coprime)

```
e = 17    (common choices: 3, 17, 65537)
```

65537 is the most common choice in practice because it is prime and has only two 1-bits in binary (10000000000000001), making modular exponentiation fast.

### Step 5: Compute Private Exponent d

Find d such that:

```
e * d = 1 (mod phi(n))
d = e^(-1) mod phi(n)
```

This means: (e * d) mod phi(n) = 1.

```
17 * d = 1 (mod 3120)
d = 2753
Check: 17 * 2753 = 46801 = 15 * 3120 + 1
```

d is computed using the **Extended Euclidean Algorithm**.

### The Key Pair

```
Public key:  (e, n) = (17, 3233)   -- share freely
Private key: (d, n) = (2753, 3233) -- keep secret
```

Discard p, q, and phi(n). They are no longer needed and would compromise security.

---

## Encryption

To encrypt a message M (represented as a number less than n):

```
C = M^e mod n
```

**Example**: Encrypt M = 65 (the letter 'A'):

```
C = 65^17 mod 3233 = 2790
```

The ciphertext C = 2790 can only be decrypted by the holder of the private key.

---

## Decryption

To decrypt ciphertext C:

```
M = C^d mod n
```

**Example**: Decrypt C = 2790:

```
M = 2790^2753 mod 3233 = 65
```

We recover M = 65 (the letter 'A').

---

## Why It Works: Euler's Theorem

RSA correctness depends on Euler's theorem.

The core idea: for any message M coprime to n:

```
M^(phi(n)) = 1 (mod n)
```

Since e * d = 1 (mod phi(n)), we can write e * d = 1 + k * phi(n) for some integer k.

```
C^d mod n = (M^e)^d mod n = M^(e*d) mod n = M^(1 + k*phi(n)) mod n
          = M * (M^phi(n))^k mod n = M * 1^k mod n = M mod n = M
```

Decryption recovers the original message because the math guarantees it.

---

## Modular Exponentiation: Square-and-Multiply

Computing M^e mod n directly is impossible for large numbers (the intermediate result would have millions of digits). The **square-and-multiply** algorithm makes it efficient:

```
To compute a^b mod n:

1. Convert b to binary
2. Start with result = 1
3. For each bit (left to right):
   - Square: result = result^2 mod n
   - If the bit is 1: Multiply: result = result * a mod n
```

**Example**: 2^10 mod 1000

```
10 in binary = 1010

result = 1
Bit 1: square -> 1, multiply -> 2
Bit 0: square -> 4
Bit 1: square -> 16, multiply -> 32
Bit 0: square -> 1024 mod 1000 = 24

2^10 mod 1000 = 24
```

---

## Key Sizes

RSA key size refers to the length of n in bits.

```
512 bits   - Broken (factored in 1999)
1024 bits  - Insecure (theoretically breakable with nation-state resources)
2048 bits  - Minimum recommended today
3072 bits  - Recommended for security beyond 2030
4096 bits  - High security, slower operations
```

Larger keys are more secure but slower. RSA is much slower than symmetric encryption (AES), which is why RSA is typically used only to encrypt small amounts of data (like a symmetric key).

---

## Padding: Why Raw RSA Is Insecure

**Textbook RSA** (raw, no padding) has serious vulnerabilities:

1. **Deterministic**: Same plaintext always produces same ciphertext. An attacker can build a dictionary of message-to-ciphertext mappings.

2. **Small message attack**: If M is small (like a single character), an attacker can try all possible values.

3. **Multiplicative property**: encrypt(A) * encrypt(B) = encrypt(A * B). This allows manipulation of ciphertexts.

**Solution**: Always use padding schemes:

- **PKCS#1 v1.5**: Older padding scheme, adds random bytes before encryption.
- **OAEP (Optimal Asymmetric Encryption Padding)**: Modern standard. Adds randomness and a hash, making RSA probabilistic and secure against chosen-ciphertext attacks.

```
Without padding: C = M^e mod n                    (insecure)
With OAEP:       C = pad(M, random)^e mod n       (secure)
```

Never use textbook RSA in production. Always use a library that implements proper padding.

---

## Digital Signatures

RSA can also be used in reverse to create **digital signatures**:

```
Signing (with private key):
  signature = hash(message)^d mod n

Verification (with public key):
  recovered_hash = signature^e mod n
  Compare recovered_hash with hash(message)
```

**What this provides**:
- **Authentication**: Only the private key holder could have created the signature.
- **Integrity**: If the message is modified, the hash will not match.
- **Non-repudiation**: The signer cannot deny having signed the message.

In practice, you sign the **hash** of the message (not the message itself), because RSA can only operate on numbers smaller than n.

---

## Performance: Why RSA Is Slow

RSA involves modular exponentiation with very large numbers (2048+ bits). This is computationally expensive compared to symmetric ciphers like AES.

```
RSA encryption:   ~1000x slower than AES
RSA key generation: even slower (finding large primes)
```

**Consequence**: RSA is not used for bulk data encryption. Instead, it is used for:
- **Key exchange**: Encrypt a small symmetric key (e.g., AES key) with RSA
- **Digital signatures**: Sign a hash (small fixed size) with RSA

### The Hybrid Approach

In practice, RSA and symmetric encryption are used together:

```
1. Alice generates a random AES key (called session key)
2. Alice encrypts the session key with Bob's RSA public key
3. Alice encrypts the actual message with AES using the session key
4. Alice sends both the encrypted key and the encrypted message
5. Bob decrypts the session key with his RSA private key
6. Bob decrypts the message with AES using the session key
```

This is how TLS/HTTPS works. You get the best of both worlds: RSA for secure key exchange, AES for fast bulk encryption.

---

## RSA vs Symmetric Encryption

| Property | RSA (Asymmetric) | AES (Symmetric) |
|---|---|---|
| Keys | Two (public + private) | One shared key |
| Speed | Slow (1000x slower) | Fast |
| Key distribution | Easy (public key is public) | Hard (must share secretly) |
| Max data size | Limited by key size | Unlimited |
| Use case | Key exchange, signatures | Bulk data encryption |

---

## Summary

```
Key Generation:
  Choose primes p, q
  n = p * q
  phi = (p-1)(q-1)
  Choose e coprime to phi
  d = e^(-1) mod phi

Public key:  (e, n)
Private key: (d, n)

Encryption: C = M^e mod n
Decryption: M = C^d mod n
Signing:    S = hash(M)^d mod n
Verifying:  hash(M) == S^e mod n
```

---

## Next Steps

[06-rsa-challenges.md](06-rsa-challenges.md) - Implement RSA step by step
