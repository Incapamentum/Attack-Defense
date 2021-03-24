C = gcc
OPT = -O3
WARN = -Wall
LIBLINK = -I ../Mastik/src
L1 = ../Mastik/src/l1.c
UTIL = ../Mastik/src/util.c

CFLAGS = $(OPT) $(WARN) $(LIBLINK)

# SRC = primeprobe_spy.c
# OBJ = primeprobe_spy.o

# Default rule
all: prime_probe
	@echo "Completed."

# Compile primeprobe attack
prime_probe:
	$(C) $(CFLAGS) primeprobe_spy.c $(L1) $(UTIL) -o primeprobe_spy

# Clean directory of objects and binary
clean:
	rm -f *.o primeprobe_spy

# Clean directory of objects
# clobber:
# 	rm -f *.o