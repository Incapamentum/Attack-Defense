C = gcc
OPT = -O3
WARN = -Wall
CFLAGS = $(OPT) $(WARN) $(INC) $(LIB)

SRC = victim.c square_and_multiply.c

OBJ = victim.o square_and_multiply.o
 
#################################

# default rule
all: victim_process
	@echo "my work is done here..."


# rule for making victim
victim_process: $(OBJ)
	$(C) -o victim $(CFLAGS) $(OBJ)
	@echo "----------- DONE -----------"


# generic rule for converting any .c file to any .o file
.c.o:
	$(C) $(CFLAGS)  -c $*.c


# type "make clean" to remove all .o files plus the binary
clean:
	rm -f *.o sim


# type "make clobber" to remove all .o files (leaves binary)
clobber:
	rm -f *.o