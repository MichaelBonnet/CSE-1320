CC=gcc
CFLAGS=-Wall -g -std=c99 -O0
OBJS=hw04_Michael_Bonnet.c
BINS=hw04

all: hw04

hw04: hw04_Michael_Bonnet.c
	${CC} ${CFLAGS}  hw04_Michael_Bonnet.c -o hw04

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