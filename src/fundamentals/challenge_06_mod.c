/*
 * Challenge 6: Modular Arithmetic
 *
 * Goal: Implement mod() that handles negative numbers correctly
 *
 * Tests:
 * mod(27, 26)  = 1
 * mod(-1, 26)  = 25
 * mod(-27, 26) = 25
 *
 * Note: C's % operator doesn't handle negatives the way crypto needs
 */

#include <stdio.h>

int mod(int a, int n)
{
    // Probleme % doesn't handle bite sign
    // It takes the sign of a
    int result = a % n;
    if(result < 0){
        return result += n;
    }
    return result;
}

int main(void)
{
    printf("mod(27, 26) = %d\n", mod(27, 26));
    printf("mod(-1, 26) = %d\n", mod(-1, 26));
    printf("mod(-27, 26) = %d\n", mod(-27, 26));
    // Test your function
    return 0;
}
