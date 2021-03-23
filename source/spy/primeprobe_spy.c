#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <util.h>
#include <l1.h>

#define MAX_SAMPLES 100000

int main(int argc, char **argv)
{
    l1pp_t l1;

    l1 = l1_prepare();
    // printf("Hello World!\n");

    l1_release(l1);

    return 0;
}