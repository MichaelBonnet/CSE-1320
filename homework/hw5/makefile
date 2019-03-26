CFLAGS = -Wall -g -O0 
CC=gcc

all:hw5

hw5: main.o cards.o dealer.o player.o bjack.o
	${CC} ${CFLAGS} -o hw5 main.o cards.o dealer.o player.o bjack.o

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
