# Name of Last Editor : Michael Bonnet
# Date of Last Edit   : 04/30/2019
# Time of Last Edit   : 17:14 Central Daylight Time (GMT-6)

CFLAGS = -Wall -g -O0 -std=c99
CC=gcc

all: hw7

hw7: hw7_Bonnet_Michael.c
	${CC} ${CFLAGS} -o hw7.exe

test.c:
	./hw7.exe *.c

test.h:
	./hw7.exe *.h

test.cpp: 
	./hw7.exe *.cpp

test.txt:
	./hw7.exe *.txt

test.ch:
	./hw7.exe *.c *.h

test.cpptxt:
	./hw7.exe *.cpp *.txt

test.all:
	./hw7.exe *.c *.h *.cpp *.txt

clean: 
	rm -rf hw8.exe
