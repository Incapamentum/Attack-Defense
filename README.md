# Single-Core Cache Timing Side Channel Attack
A single-core implementation of a cache timing side channel attack making use of the Prime+Probe exploit. 

Completed as part of a Spring 2021 term project for the special topics course EEL 5937 - Attacks & Defenses in Secure Architectures. Class instructor is Dr. Fan Yao.

The paper by Liu et. al [1] served as the main motivation in pursuing this term project.



## Table of Contents

I. Disclaimer  
II. System & Environment  
III. Software Tools  
IV. References



## I. Disclaimer

Source code and this repository is licensed under the GNU General Public License v3 (GPL-3). Any person may copy, distribute and modify the software as long as changes and dates are tracked in source files. Any modifications to or software including (via compiler) GPL-licensed code must also be made available under the GPL-3 along with build & install instructions.

Source code is provided as-is. It was developed and completed in partial fulfillment of a term project for the special topics course of **EEL 5937** - Attacks & Defenses in Secure Architectures at the University of Central Florida.

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

### [Cache Template Attacks](https://github.com/IAIK/cache_template_attacks)

GitHub repository containing tools that can be used to perform [Cache Template Attacks](https://www.usenix.org/conference/usenixsecurity15/technical-sessions/presentation/gruss).

### [Mastik: A Micro-Architectural Side-Channel Toolkit](https://cs.adelaide.edu.au/~yval/Mastik/)

Provides robust implementations of side-channel attack techniques. It implements six side-channel attacks:

+ Prime+Probe on L1 data cache
+ Prime+Probe on L1 instruction cache
+ Pribe+Probe on last-level cache
+ Flush+Reload
+ Flush+Flush
+ Performance degredation attack





## IV. References

This section contains links to papers that were used to gain insights on the development of this single-core attack.

[1] F. Liu, Y. Yarom, Q. Ge, G. Heiser and R. B. Lee, "[Last-Level Cache Side-Channel Attacks are Practical,](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7163050)" 2015 IEEE Symposium on Security and Privacy, San Jose, CA, USA, 2015, pp. 605-622, doi: 10.1109/SP.2015.43.

[2] P. Vila, B. Köpf and J. F. Morales, "[Theory and Practice of Finding Eviction Sets](https://ieeexplore.ieee.org/document/8835261)," 2019 IEEE Symposium on Security and Privacy (SP), San Francisco, CA, USA, 2019, pp. 39-54, doi: 10.1109/SP.2019.00042.

