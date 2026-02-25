/*
 * Challenge 3: Primality Test
 *
 * Goal: Implement a function to test if a number is prime.
 *       Use trial division (check divisibility up to sqrt(n)).
 *       Bonus: implement Miller-Rabin for larger numbers.
 *
 * Trial division algorithm:
 *   1. Handle edge cases: n <= 1 is not prime, 2 is prime
 *   2. If n is even, it is not prime
 *   3. Check odd divisors from 3 up to sqrt(n)
 *   4. If no divisor found, n is prime
 *
 * Tests:
 *   is_prime(2)    = 1
 *   is_prime(17)   = 1
 *   is_prime(97)   = 1
 *   is_prime(15)   = 0
 *   is_prime(1)    = 0
 *   is_prime(7919) = 1
 */

#include <stdio.h>

int is_prime(long long n)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    printf("=== Primality Test ===\n\n");
    printf("is_prime(2)    = %d (expected 1)\n", is_prime(2));
    printf("is_prime(17)   = %d (expected 1)\n", is_prime(17));
    printf("is_prime(97)   = %d (expected 1)\n", is_prime(97));
    printf("is_prime(15)   = %d (expected 0)\n", is_prime(15));
    printf("is_prime(1)    = %d (expected 0)\n", is_prime(1));
    printf("is_prime(7919) = %d (expected 1)\n", is_prime(7919));
    return 0;
}
