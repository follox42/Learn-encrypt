/*
 * Challenge 3: Encrypt Single Character
 *
 * Goal: Encrypt one character with Caesar cipher
 *
 * Tests:
 * ('A', 3) → 'D'
 * ('Z', 3) → 'C'
 * ('a', 3) → 'd'
 * ('5', 3) → '5' (non-letter unchanged)
 */

#include <stdio.h>

// Copy your mod() function from challenge 6
int mod(int a, int n)
{
    int result = a % n;
    if(result < 0){
        return result + n;
    }
    return result;
}

char caesar_encrypt_char(char c, int shift)
{
    // Your code here
    return c;
}

int main(void)
{
    printf("('A', 3) → '%c'\n", caesar_encrypt_char('A', 3));
    printf("('Z', 3) → '%c'\n", caesar_encrypt_char('Z', 3));
    printf("('a', 3) → '%c'\n", caesar_encrypt_char('a', 3));
    printf("('5', 3) → '%c'\n", caesar_encrypt_char('5', 3));
    return 0;
}
