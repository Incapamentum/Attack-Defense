C = gcc
OPT = -O3
WARN = -Wall
LIBLINK = -I ../Mastik/src
L1 = ../Mastik/src/l1.c
UTIL = ../Mastik/src/util.c

CFLAGS = $(OPT) $(WARN) $(LIBLINK)

# Default rule
all: prime_probe
	@echo "----------- DONE -----------"

# Compile primeprobe attack
prime_probe:
	$(C) $(CFLAGS) primeprobe_calibrate.c $(L1) $(UTIL) -o primeprobe_calibrate

# Clean directory of objects and binary
clean:
	rm -f *.o primeprobe_calibrate