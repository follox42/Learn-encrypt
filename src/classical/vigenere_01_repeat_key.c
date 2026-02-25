/*
 * Challenge 1: Repeat Key
 *
 * Goal: Write a function that repeats a key to match a given length.
 *       For example, "KEY" repeated to length 10 becomes "KEYKEYKEYK".
 *
 * Tests:
 * ("KEY", 10)    → "KEYKEYKEYK"
 * ("AB", 5)      → "ABABA"
 * ("SECRET", 3)  → "SEC"
 * ("A", 6)       → "AAAAAA"
 */

#include <stdio.h>
#include <string.h>

void repeat_key(const char *key, int length, char *output)
{
    // Your code here
    // Hint: use modulo to cycle through the key: key[i % key_length]
    // Don't forget to null-terminate the output
}

int main(void)
{
    char result[64];

    repeat_key("KEY", 10, result);
    printf("(\"KEY\", 10) → \"%s\"\n", result);

    repeat_key("AB", 5, result);
    printf("(\"AB\", 5)   → \"%s\"\n", result);

    repeat_key("SECRET", 3, result);
    printf("(\"SECRET\", 3) → \"%s\"\n", result);

    repeat_key("A", 6, result);
    printf("(\"A\", 6)    → \"%s\"\n", result);

    return 0;
}
