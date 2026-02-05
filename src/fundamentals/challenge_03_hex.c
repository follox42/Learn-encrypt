/*
 * Challenge 3: Hex Converter
 *
 * Goal: Print each character of a string as 2-digit hexadecimal
 *
 * Test: "ABC" -> 41 42 43
 */

#include <stdio.h>

int main(void)
{
    char str[] = "ABC";
    int hex[6];
    int i = 0;
    printf("%s -> ", str);
    while(str[i] != '\0') {
        hex[i] = (str[i] >> 4) & 0xF;
        hex[1+(i*2)] = str[i] & 0xF;
        printf("%x%x ", hex[i], hex[1+(i*2)]);
        i++;
    }
    // Your code here
    return 0;
}
