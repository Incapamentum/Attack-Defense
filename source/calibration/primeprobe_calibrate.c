#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <util.h>
#include <l1.h>

#define MAX_SAMPLES 100000

// =============================
//     Ryzen 7 3700X DETAILS
// =============================
//      L1 data cache size: 32KB
//      L1 line size: 64B
//      L1 data cache associativity: 8
//
//      # lines: 32KB / 64B = 512 lines
//      # sets: 512 lines / 8 = 64 sets
//

void usage(const char *prog)
{
    fprintf(stderr, "Usage: %s <samples> <set>\n", prog);
    fprintf(stderr, "       samples - number of samples to run for");
    fprintf(stderr, "       set     - the specified set to monitor");
    exit(1);
}

int main(int argc, char **argv)
{
    int n_sets, *map, rmap[L1_SETS], samples, set;
    uint16_t *res;
    l1pp_t l1_pp;

    // Bookkeeping
    int i, j;

    if (argc != 3)
        usage(argv[0]);

    samples = atoi(argv[1]);
    set = atoi(argv[2]);

    if (samples < 0)
        usage(argv[0]);

    if (set < 0 || set > L1_SETS)
        usage(argv[0]);

    if (samples > MAX_SAMPLES)
        samples = MAX_SAMPLES;

    // Allocates memory to the L1 Prime+Probe struct. Important to this
    // is an array containing containing L1 cache sets to monitor.
    // By default, it monitors all 64 cache sets
    l1_pp = l1_prepare();

    // Removing all cache sets from being monitored
    l1_unmonitorall(l1_pp);

    // Adds specific cache set for monitoring
    l1_monitor(l1_pp, set);

    // Obtains number of sets to allocate memory for a mapping
    // for the monitored sets to be passed to it
    // By default, all L1 cache sets are be monitored
    n_sets = l1_getmonitoredset(l1_pp, NULL, 0);
    map = calloc(n_sets, sizeof(int));
    l1_getmonitoredset(l1_pp, map, n_sets);

    // Obtains a small number of sets to monitor
    for (i = 0; i < L1_SETS; i++)
        rmap[i] = -1;    
    for (i = 0; i < n_sets; i++)
        rmap[map[i]] = i;

    // Allocating memory for an array to hold cache timings
    res = calloc(samples * n_sets, sizeof(uint16_t));

    // Initializing cache timings array with default values
    for (i = 0; i < samples * n_sets; i += 4096/sizeof(uint16_t))
        res[i] = i;

    // Creating a delay before L1 data cache is probed depending on the
    // number of samples
    delayloop(3000000000U);
    l1_repeatedprobe(l1_pp, samples, res, 0);

    // Printing out the results of the Prime+Probe
    for (int i = 0; i < samples; i++)
    {
        for (j = 0; j < L1_SETS; j++)
        {
            if (rmap[j] == -1)
                printf(" 0 \t");
            else
                printf(" %3d \t", res[i * n_sets + rmap[j]]);
        }

        putchar('\n');
    }

    // Freeing memory
    free(map);
    free(res);
    l1_release(l1_pp);

    return 0;
}