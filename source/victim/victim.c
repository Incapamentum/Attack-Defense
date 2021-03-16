#include <stdio.h>

#include "square_multiply.h"

int main(void)
{
    printf("Result of square-multiply: %d\n", square_multiply(2, 5, 3, number_of_bits(5)));
}