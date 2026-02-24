/*
 * Challenge 2: Position to Letter
 *
 * Goal: Convert a position (0-25) back to a letter
 *
 * Tests:
 * (0, 1)  → 'A'
 * (25, 1) → 'Z'
 * (0, 0)  → 'a'
 * (25, 0) → 'z'
 */

#include <stdio.h>

char pos_to_letter(int pos, int uppercase)
{
    // Your code here
    return 0;
}

int main(void)
{
    printf("(0, 1)  → '%c'\n", pos_to_letter(0, 1));
    printf("(25, 1) → '%c'\n", pos_to_letter(25, 1));
    printf("(0, 0)  → '%c'\n", pos_to_letter(0, 0));
    printf("(25, 0) → '%c'\n", pos_to_letter(25, 0));
    return 0;
}
