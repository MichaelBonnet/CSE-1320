CC=gcc 
CFLAGS=-Wall

all: 
program: hw04_bonnet_michael.o
program.o: program.c program.h headers.h

clean:
    rm -f program program.o
run: program
    ./program