/*
 * Challenge 4: XOR Two Bytes
 *
 * Goal: XOR two numbers and display result in decimal, binary, hex
 *
 * Test: 170 XOR 85
 * Decimal: 255
 * Binary: 11111111
 * Hex: FF
 */

#include <stdio.h>

int main(void)
{
    int nb1, nb2;
    int xor;
    printf("Enter two bytes (0-255): ");
    scanf("%d %d", &nb1, &nb2);

    xor = nb1 ^ nb2;

    char bits[9];
    for(int i = 0; i < 8; i++){
        bits[7 - i] = '0' + ((xor >> i) & 1);
    }
    bits[8] = '\0';

    printf("Test: %d XOR %d\n", nb1, nb2);
    printf("Decimal: %d\n", xor);
    printf("Binary: %s\n", bits);
    printf("Hex: %x\n", xor);
    // Your code here
    return 0;
}
