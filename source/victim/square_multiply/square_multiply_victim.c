#include <stdio.h>

#include "square_multiply.h"

int main(void)
{
    printf("Result of square-multiply: %d\n", square_multiply(4, 11, 701111, number_of_bits(11)));
}