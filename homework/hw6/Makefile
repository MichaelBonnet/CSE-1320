CC     =  gcc
CFLAGS = -Wall -g -O0 -std=c99
OBJS   = main.o utils.o
BINS   = hw6

all: hw6         # default target

remake: clean hw6 # cleans then makes hw6 again

hw6: main.o utils.o
    $(CC) $(CFLAGS) -o hw6 main.o utils.o

main.o: main.c utils.c utils.h

utils.o: utils.c utils.h

clean:
    rm -f *.o
    rm -f ${BINS}
#   rm -Rf prog.dSYM/ # only sometimes necessary

.PHONY : clean