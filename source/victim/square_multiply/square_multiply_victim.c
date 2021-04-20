#include <stdio.h>
#include <stdlib.h>

#include "square_multiply.h"

int main(int argc, char **argv)
{
    unsigned int base, exponent;
    unsigned long long modulus;

    base = 4;
    exponent = 2863311530; // 0xAAAAAAAA

    // p = 44893
    // q = 33301
    // modulus = (p - 1)(q - 1)
    modulus = 1494903600;

    if (argc > 1)
        exponent = atoi(argv[1]);

    square_multiply(base, exponent, modulus, number_of_bits(exponent));
}