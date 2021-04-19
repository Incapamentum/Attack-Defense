# Attack & Defense
Completed as part of a Spring 2021 term project for the special topics course **EEL 5937** - *Attacks & Defenses in Secure Architectures*. Class instructor is Dr. Fan Yao.



## Table of Contents

I. Disclaimer  
II. System & Environment  
III. Software Tools  
IV. Attack  
V. Defense  
VI. Build Process  
VII. References



## I. Disclaimer

Source code and this repository is licensed under the GNU General Public License v3 (GPL-3). Any person may copy, distribute and modify the software as long as changes and dates are tracked in source files. Any modifications to or software including (via compiler) GPL-licensed code must also be made available under the GPL-3 along with build & install instructions.

Source code is provided as-is. It was developed and completed in partial fulfillment of a term project for the special topics course of **EEL 5937** - *Attacks & Defenses in Secure Architectures* at the University of Central Florida.

Software is provided without warranty under GPL-3. Software author (Incapamentum) and GPL-3 can not be held liable for any damages inflicted by the software. Usage of software for malicious purposes is *strictly* prohibited.



## II. System & Environment

### Computer System

OS: Ubuntu 18.04 LTS  
CPU: AMD Ryzen 7 3700X  
Memory: 32GB DDR4 at 3200 MHz

### Development Environment


Written primarily in C unless otherwise noted  
GCC 7.5.0  
Visual Studio Code 1.54.3



## III. Software Tools

The following pieces of software were used in the development of this project. Unless otherwise noted, all software is open-sourced and used as-is.

### [Mastik: A Micro-Architectural Side-Channel Toolkit](https://cs.adelaide.edu.au/~yval/Mastik/)

Provides robust implementations of side-channel attack techniques. It implements six side-channel attacks:

+ Prime+Probe on L1 data cache
+ Prime+Probe on L1 instruction cache
+ Pribe+Probe on last-level cache
+ Flush+Reload
+ Flush+Flush
+ Performance degredation attack

### [quickhpc](https://github.com/chpmrc/quickhpc) [2]

Custom utility that was developed to probe hardware performance counters (HPCs) using [PAPI](http://icl.cs.utk.edu/papi/) (Performance Application Programming Interface) at a high resolution. 

The `perf` command-line tool provides an interactive interface to HPCs that allows to collect, visualize, filter and aggregate data gathered through HPCs on a system-wide, process, or thread granularity. A subcommand to `perf` is `perf-stats`, which allows a user to specify which events to monitor, the output format and the interval of time between consecutive reports. However, this time resolution is limited to a minimum of 100 ms between two consecutive reports.

After a thorough optimization, `quickhpc` reaches a maximum resolution of 3 microseconds, which is more than 30000 times faster than the `perf-stat`

The current tool as is has actually been broken due to incompatibility with latest PAPI releases. However, a [fork](https://github.com/zechenghe/quickhpc) of the repo was found that fixes these issues. This is the version of `quickhpc` that is being used.

## IV. Attack <sup>[1]</sup>

A cache-timing side-channel attack was implemented, making use of the Prime+Probe technique. This is a general technique for an attacker *A* to learn which cache set is accessed by a victim process *V*.

The general approach is as follows:

- **Prime**: *A* fills one or more cache sets with its own code or data
- **Idle**: *A* waits for a pre-configured time interval while *V* executes and utilizes the cache
- **Probe**: *A* continues execution and measures the time to load each set of their data or code that was primed. If *V* has accessed some of the cache sets, it will have evicted some of *A*'s lines, which is observed as an increased memory access latency for those lines.

The above technique can be used to observe secret-dependent execution paths, shown via an implementation of the square-and-multiply exponentiation algorithm, and secret-dependent data access patterns, shown via an implementation of the sliding-window exponentiation algorithm.

Taking into consideration the system hardware, the spy and victim processes execute on the same core. Scripts were written that ensure both spy and victim processes execute on the same core.

The Mastik toolkit was used to develop the single-core Prime+Probe attack.



## V. Defense <sup>[2]</sup>



## VI. Build Process



## VII. References

This section contains links to papers that were used to gain insights on the development of this single-core attack.

[1] F. Liu, Y. Yarom, Q. Ge, G. Heiser and R. B. Lee, "[Last-Level Cache Side-Channel Attacks are Practical,](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7163050)" 2015 IEEE Symposium on Security and Privacy, San Jose, CA, USA, 2015, pp. 605-622, doi: 10.1109/SP.2015.43.

[2] Marco Chiappetta, Erkay Savas, and Cemal Yilmaz. 2016. Real time detection of cache-based side-channel attacks using hardware performance counters. <i>Appl. Soft Comput.</i> 49, C (December 2016), 1162–1174. DOI:https://doi.org/10.1016/j.asoc.2016.09.014

