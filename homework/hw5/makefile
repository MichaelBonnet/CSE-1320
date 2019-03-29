# Name of Last Editor : Michael Bonnet
# Date of Last Edit   : 03/29/2019
# Time of Last Edit   : 11:49 CDT (GMT-6)

CFLAGS = -Wall -g -O0 
CC=gcc

all:hw5

hw5: main.o cards.o dealer.o player.o bjack.o
	${CC} ${CFLAGS} -o hw5 main.o cards.o dealer.o player.o bjack.o

main.o: main.c cards.h bjack.h
	${CC} ${CFLAGS}

cards.o:cards.c cards.h
	${CC} ${CFLAGS} -c cards.o

dealer.o:dealer.c dealer.h cards.h
	${CC} ${CFLAGS} -c dealer.o

player.o:player.c cards.h
	${CC} ${CFLAGS} -c player.o

bjack.o:bjack.c player.h dealer.h cards.h
	${CC} ${CFLAGS} -c bjack.o

clean: 
	rm -rf hw5 main.o cards.o dealer.o player.o main.o bjack.o
