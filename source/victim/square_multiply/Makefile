C = gcc
OPT = -O2
WARN = -Wall
CFLAGS = $(OPT) $(WARN)
# CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

SRC = square_multiply_victim.c square_and_multiply.c

# OBJ = square_multiply_victim.o square_and_multiply.o
 
#################################

# default rule
all: victim_process
	@echo "----------- DONE -----------"


# rule for making victim
# victim_process: $(OBJ)
# $(C) -o square_multiply_victim $(CFLAGS) $(OBJ)
victim_process:
	$(C) $(CFLAGS) $(SRC) -o victim_sqr_mult


# generic rule for converting any .c file to any .o file
# .c.o:
# 	$(C) $(CFLAGS)  -c $*.c


# type "make clean" to remove all .o files plus the binary
clean:
	rm -f *.o victim_sqr_mult


# type "make clobber" to remove all .o files (leaves binary)
# clobber:
# 	rm -f *.o