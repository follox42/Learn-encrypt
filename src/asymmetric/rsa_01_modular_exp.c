/*
 * Challenge 1: Modular Exponentiation
 *
 * Goal: Implement modular exponentiation (a^b mod n) using the
 *       square-and-multiply algorithm. This is the fundamental
 *       operation behind RSA encryption and decryption.
 *
 * Algorithm (square-and-multiply):
 *   1. Convert exponent to binary
 *   2. Start with result = 1
 *   3. For each bit of the exponent (left to right):
 *      - Square the result: result = result^2 mod n
 *      - If bit is 1: multiply by base: result = result * base mod n
 *   4. Return result
 *
 * Tests:
 *   mod_exp(2, 10, 1000)  = 24
 *   mod_exp(3, 13, 50)    = 7
 *   mod_exp(5, 3, 13)     = 8
 *   mod_exp(7, 256, 13)   = 9
 *   mod_exp(2, 0, 100)    = 1
 */

#include <stdio.h>

long long mod_exp(long long base, long long exp, long long mod)
{
    /* Your code here */
    return 0;
}

int main(void)
{
    printf("=== Modular Exponentiation ===\n\n");
    printf("mod_exp(2, 10, 1000)  = %lld (expected 24)\n", mod_exp(2, 10, 1000));
    printf("mod_exp(3, 13, 50)    = %lld (expected 7)\n", mod_exp(3, 13, 50));
    printf("mod_exp(5, 3, 13)     = %lld (expected 8)\n", mod_exp(5, 3, 13));
    printf("mod_exp(7, 256, 13)   = %lld (expected 9)\n", mod_exp(7, 256, 13));
    printf("mod_exp(2, 0, 100)    = %lld (expected 1)\n", mod_exp(2, 0, 100));
    return 0;
}
