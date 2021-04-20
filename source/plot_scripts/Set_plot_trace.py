import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

from matplotlib import cm
from random import randint

TRACE_PATH = "../spy/trace.txt"
LAT_THRESHOLD = 125
NUM_SAMPLES = 10000
NUM_SETS = 64

with open(TRACE_PATH, "r") as trace_file:
    lines = trace_file.readlines()

count = 0

samples = []
cache_trace = []

# x-axis (max 10k samples)
for i in range(NUM_SAMPLES):
    samples.append(i + 1)

# 64 probe latencies
for i in range(NUM_SAMPLES):
    cache_trace.append([])

# Bookkeeping
i = 0
count = 0

for l in lines:

    # Every sample contains 64 timings
    probe_sample = l.split()
    count += len(probe_sample)
    cache_sets = []

    for j in range(len(probe_sample)):

        if (int(probe_sample[j]) > LAT_THRESHOLD):
            cache_sets.append(j)

    cache_trace[i] = cache_sets

    i += 1

cache_trace.pop(0)

fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(20, 6))

for x, y in zip(samples, cache_trace):
    plt.scatter([x] * len(y), y, c=cm.hot(y))

##plt.ylim([0, 200])
plt.xlabel("Sample Number")
plt.ylabel("Cache Set")
plt.title("Cache Set Activity, 125 Cycle Threshold")

plt.show()
