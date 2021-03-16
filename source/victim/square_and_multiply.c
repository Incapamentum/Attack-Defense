#include <stdio.h>
#include <stdlib.h>

#include "square_multiply.h"

// Returns the minimum number of bits needed to represent 'n'
int number_of_bits(unsigned int n)
{
    int count = 0;

    if (n == 0)
        return 1;

    while (n > 0)
    {
        n = n / 2;
        count++;
    }

    return count;
}

// Square-and-Multiply Exponentiation
// Exponentiation algorithm that makes use of the modulo operation: b^e mod m
unsigned int square_multiply(unsigned int b, unsigned int e, unsigned int m, int num_bits)
{
    unsigned int r = 1;

    // Bookkeeping
    int bit_mask = 1 << (num_bits - 1), i;

    for (i = num_bits - 1; i >= 0; i--)
    {
        r = (r * r) % m;

        if ((bit_mask & e) != 0)
            r = (r * b) % m;
    }

    return r;
}

// LEGACY
// Used for testing purposes
// int main(void)
// {
//     // Testing Variable
//         printf("Result of square-multiply: %d\n", square_multiply(2, 5, 3, number_of_bits(5)));
//         // int i;

//         // for (i = 0; i < 20; i++)
//         //     printf("Value: %d   Highest bit: %d\n", i, highest_bit(i));
//     // End test
    

//     return 0;
// }