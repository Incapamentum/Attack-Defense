#include <stdio.h>

#include "square_multiply.h"

int main(void)
{
    unsigned int base, exponent;
    unsigned long long modulus;

    base = 4;
    // exponent = 65537;
    // exponent = 269488144; // 0x10101010
    exponent = 2863311530; // 0xAAAAAAAA

    // p = 44893
    // q = 33301
    // modulus = (p - 1)(q - 1)
    modulus = 1494903600;

    square_multiply(base, exponent, modulus, number_of_bits(exponent));

    // printf("Result of square-multiply: %llu\n", square_multiply(base, exponent, modulus, number_of_bits(exponent)));
    // printf("Result of square-multiply: %d\n", square_multiply(4, 11, 701111, number_of_bits(11)));
}