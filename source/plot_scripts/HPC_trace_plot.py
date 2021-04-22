import matplotlib.pyplot as plt
import sys

SPY_TRACE_PATH = "../hpc_data/spy_hpc.txt"
VICTIM_TRACE_PATH = "../hpc_data/victim_hpc.txt"

with open(SPY_TRACE_PATH, "r") as trace_file:
    spy_lines = trace_file.readlines()

with open(VICTIM_TRACE_PATH, "r") as trace_file:
    victim_lines = trace_file.readlines()

samples = [] # x-axis
spy_access_latency = [] # y-axis
victim_access_latency = [] # y-axis

# Extracting timings for spy
for l in spy_lines:

    l = int(l.strip())    
    spy_access_latency.append(l)

# Extracting timings for victim
for l in victim_lines:

    l = int(l.strip())
    victim_access_latency.append(l)

# Constructing samples
for i in range(len(spy_access_latency)):
    samples.append(i + 1)

# Eliminating head value (garbage)
victim_access_latency.pop(0)
spy_access_latency.pop(0)

# Inserting an average value at the beginning
victim_access_latency.insert(0, int(sum(victim_access_latency) / len(victim_access_latency)))
spy_access_latency.insert(0, int(sum(spy_access_latency) / len(spy_access_latency)))


# Graphing
fig, axes = plt.subplots(nrows=1, ncols=1, figsize=(10, 6))

plt.plot(samples, spy_access_latency, label="Spy L1 DCache Accesses")
plt.plot(samples, victim_access_latency, label="Victim L1 DCache Accesses")
plt.xlabel("Sample Number")
plt.ylabel("L1 Data Total Accesses")
plt.title("Spy and Victim Process Cache Access")
plt.legend()
plt.show()