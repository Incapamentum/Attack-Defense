import matplotlib.pyplot as plt
import sys

from matplotlib import cm
from random import randint

"""
    Reads the trace file pointed by TRACE_PATH, and plots cache
    probe latency against the sample from which it was obtained.
"""

TRACE_PATH = "../spy/trace.txt"
LAT_THRESHOLD = 125
NUM_SAMPLES = 10000
NUM_SETS = 64

if (len(sys.argv) != 2):
    print("Insufficient parameters!\n")
    print(f'Usage: python3 {sys.argv[0]} [type]')
    print("     type - valid options are either 'full' or 'partial'")
    sys.exit(-1)

if ((sys.argv[1] != "full") and (sys.argv[1] != "partial")):
    print("Invalid option!\n")
    print("Valid options are either 'full' or 'partial'")
    sys.exit(-1)

op = sys.argv[1]

with open(TRACE_PATH, "r") as trace_file:
    lines = trace_file.readlines()

samples = []
cache_trace = []

SAMPLE = True

# (x-axis)
for i in range(NUM_SAMPLES):
    samples.append(i + 1)

# 64 probe latencies across the samples (y-axis)
for i in range(NUM_SAMPLES):
    cache_trace.append([])

# Bookkeeping
j = 0

for l in lines:

    probe_sample = l.split()

    if (op == "full"):

        for i in range(len(probe_sample)):
            probe_sample[i] = int(probe_sample[i])

        cache_trace[j] = probe_sample

    else:

        partial = []

        for i in range(len(probe_sample)):

            if (int(probe_sample[i]) > LAT_THRESHOLD):
                partial.append(int(probe_sample[i]))

        cache_trace[j] = partial

    j += 1

cache_trace.pop(0)

fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(20, 6))

if (op == "full"):

    for x, y in zip(samples, cache_trace):
        plt.scatter([x] * len(y), y, c=cm.hot(y), marker=".")

    plt.ylim([0, 200])

else:

    for x, y in zip(samples, cache_trace):
        plt.scatter([x] * len(y), y, c="blue", marker=".")

    plt.ylim([LAT_THRESHOLD, 200])

plt.xlabel("Sample Number")
plt.ylabel("Probe Latency (cycles)")
plt.title("Cache Activity")

plt.show()