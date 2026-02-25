/*
 * Challenge 2: AES ShiftRows
 *
 * Goal: Implement the ShiftRows transformation on the 4x4 state matrix.
 *
 * Rules:
 * Row 0: no shift
 * Row 1: circular left shift by 1
 * Row 2: circular left shift by 2
 * Row 3: circular left shift by 3
 *
 * Test case:
 * Input:           After ShiftRows:
 * d4 e0 b8 1e     d4 e0 b8 1e   (row 0: unchanged)
 * 27 bf b4 41     bf b4 41 27   (row 1: shift left 1)
 * 11 98 5d 52     5d 52 11 98   (row 2: shift left 2)
 * ae f1 e5 30     30 ae f1 e5   (row 3: shift left 3)
 */

#include <stdio.h>

/* Apply ShiftRows to the 4x4 state */
void shift_rows(unsigned char state[4][4])
{
    /* Your code here */
}

/* Print state matrix */
void print_state(const unsigned char state[4][4])
{
    /* Your code here */
}

int main(void)
{
    unsigned char state[4][4] = {
        {0xD4, 0xE0, 0xB8, 0x1E},
        {0x27, 0xBF, 0xB4, 0x41},
        {0x11, 0x98, 0x5D, 0x52},
        {0xAE, 0xF1, 0xE5, 0x30}
    };

    printf("Before ShiftRows:\n");
    print_state(state);

    shift_rows(state);

    printf("After ShiftRows:\n");
    print_state(state);

    printf("Expected:\n");
    printf("  d4 e0 b8 1e\n");
    printf("  bf b4 41 27\n");
    printf("  5d 52 11 98\n");
    printf("  30 ae f1 e5\n");

    return 0;
}
