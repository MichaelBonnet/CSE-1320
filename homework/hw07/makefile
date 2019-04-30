# Name of Last Editor : Michael Bonnet
# Date of Last Edit   : 03/29/2019
# Time of Last Edit   : 11:49 CDT (GMT-6)

CFLAGS = -Wall -g -O0 -std=c99
CC=gcc

all: hw5

hw5: main.o cards.o dealer.o player.o bjack.o
	${CC} ${CFLAGS} -o hw5 main.o cards.o dealer.o player.o bjack.o

main.o: main.c cards.h bjack.h player.h

cards.o:cards.c cards.h

dealer.o:dealer.c dealer.h cards.h

player.o:player.c cards.h

bjack.o:bjack.c player.h dealer.h cards.h

clean: 
	rm -rf hw5 main.o cards.o dealer.o player.o main.o bjack.o
