/*
 * Challenge 1: ASCII Explorer
 *
 * Goal: Print each character of a string with its ASCII value
 *
 * Test: "Hello" should output:
 * H -> 72
 * e -> 101
 * l -> 108
 * l -> 108
 * o -> 111
 */

#include <stdio.h>

int main(void)
{
    char *a = "Hello";
    int i = 0;
    
    while (a[i] != '\0'){
        printf("\n%c -> %d ", a[i], a[i]);
        i++;
    }
    return 0;
}
