import matplotlib.pyplot as plt
import matplotlib.transforms as transforms
import sys

from statistics import median

TRACE_PATH = "../calibration/trace.txt"
NUM_SAMPLES = 10000

if (len(sys.argv) != 2):
    print("Insufficient parameters!\n")
    print(f'Usage: python3 {sys.argv[0]} [set]')
    print("     set - the monitored set in question")
    sys.exit(-1)

set_num = int(sys.argv[1])

with open(TRACE_PATH, "r") as trace_file:
    lines = trace_file.readlines()

samples = [] # x-axis
cache_trace = [] # y-axis

# Bookkeeping
i = 0
count = 0

# Extracting timings from each line
for l in lines:

    # Every sample contains only 1 timing non-zero timing
    probe_sample = l.split()
    count += 1

    cache_trace.append(int(probe_sample[set_num]))

# Elimiting head value (garbage), adding in median value to the end
cache_trace.pop(0)
cache_trace.append(int(median(cache_trace)))

for i in range(len(cache_trace)):
    samples.append(i + 1)

# Setting up for horizontal line
avg = int(sum(cache_trace) / len(cache_trace))
avg_list = []

for i in range(len(cache_trace)):
    avg_list.append(avg)

fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(10, 6))

axes.axhline(y=avg, color="red")
trans = transforms.blended_transform_factory(axes.get_yticklabels()[0].get_transform(), axes.transData)
axes.text(0, avg, "{: .0f}".format(avg), color="red", transform=trans, ha="right", va="center")

plt.scatter(samples, cache_trace)
plt.plot(samples, cache_trace)
plt.xlabel("Sample Number")
plt.ylabel("Probe Time (Cycles)")
plt.title(f'Prime+Probe Latency of Set {set_num}')
plt.show()
