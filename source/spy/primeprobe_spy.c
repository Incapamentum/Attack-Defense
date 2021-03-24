#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <util.h>
#include <l1.h>

#define MAX_SAMPLES 100000

void usage(const char *prog)
{
    fprintf(stderr, "Usage: %s <samples>\n", prog);
    exit(1);
}

int main(int argc, char **argv)
{
    int n_sets, *map, rmap[L1_SETS], samples;
    uint16_t *res;
    l1pp_t l1_pp;

    // Bookkeeping
    int i, j;

    if (argv[1] == NULL)
        usage(argv[0]);

    samples = atoi(argv[1]);

    if (samples < 0)
        usage(argv[0]);

    if (samples > MAX_SAMPLES)
        samples = MAX_SAMPLES;

    l1_pp = l1_prepare();

    n_sets = l1_getmonitoredset(l1_pp, NULL, 0);
    map = calloc(n_sets, sizeof(int));
    l1_getmonitoredset(l1_pp, map, n_sets);

    for (i = 0; i < L1_SETS; i++)
        rmap[i] = -1;
    
    for (i = 0; i < n_sets; i++)
        rmap[map[i]] = i;

    res = calloc(samples * n_sets, sizeof(uint16_t));

    for (i = 0; i < samples * n_sets; i += 4096/sizeof(uint16_t))
        res[i] = i;

    // printf("sizeof(uint16_t): %lu\n", sizeof(uint16_t));

    delayloop(3000000000U);
    l1_repeatedprobe(l1_pp, samples, res, 0);

    for (int i = 0; i < samples; i++)
    {
        for (j = 0; j < L1_SETS; j++)
        {
            if (rmap[j] == -1)
                printf(" 0 \t");
            else
                printf("%3d \t", res[i * n_sets + rmap[j]]);
        }

        putchar('\n');
    }

    free(map);
    free(res);
    l1_release(l1_pp);

    return 0;
}