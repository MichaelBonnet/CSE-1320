CC=gcc
CFLAGS=-Wall -g -std=c99 -O0
OBJS=main.o sort.o
BINS=hw04

all: hw04

remake: clean hw04

hw04: main.o sort.o
	$(CC) $(CFLAGS) -o $@ $?

main.o: main.c sort.h constants.h
	$(CC) $(CFLAGS) -c main.c

sort.o: sort.c sort.h constants.h
	$(CC) $(CFLAGS) -c sort.c

bundle: clean
	mkdir -p hw04_Michael_Bonnet/
	cp *.c hw04_Michael_Bonnet/
	cp Makefile hw04_Michael_Bonnet/
	tar cf hw04_Michael_Bonnet.tar hw04_Michael_Bonnet/
	rm -Rf hw04_Michael_Bonnet/

clean:
	rm -f *.o
	rm -f *.tar
	rm -f ${BINS}

.PHONY : clean bundle