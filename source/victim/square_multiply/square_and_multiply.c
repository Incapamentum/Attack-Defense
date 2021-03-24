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

        bit_mask = bit_mask >> 1;
    }

    return r;
}