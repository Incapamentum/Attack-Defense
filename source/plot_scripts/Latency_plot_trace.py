import matplotlib.pyplot as plt

from matplotlib import cm
from random import randint

"""
    Reads the trace file pointed by TRACE_PATH, and plots cache
    probe latency against the sample from which it was obtained.
"""

TRACE_PATH = "../spy/trace.txt"
NUM_SAMPLES = 10000
NUM_SETS = 64

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
i = 0
count = 0

for l in lines:

    probe_sample = l.split()
    count += len(probe_sample)

    for j in range(len(probe_sample)):
        probe_sample[j] = int(probe_sample[j])

    cache_trace[i] = probe_sample

    i += 1

cache_trace.pop(0)

fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(20, 6))

if (SAMPLE):
    for x, y in zip(samples, cache_trace):
        plt.scatter([x] * len(y), y, c=cm.hot(y))

else:
    for x, s in zip(cache_trace, cache_sets):

        y = []

        for i in range(NUM_SETS):
            y.append(s)

        plt.scatter(x, y, c=cm.hot(y))


if (SAMPLE):
    plt.ylim([0, 200])
    plt.xlabel("Sample Number")
    plt.ylabel("Probe Latency (cycles)")
else:
    plt.xlabel("Probe Time")
    plt.ylabel("Cache Set")


plt.show()