CFLAGS = -O2 -ansi -pedantic -Wno-unused-result -lm
CC = gcc
RM = rm
#---------------------------------------------------

all: ep1 clean

ep1: main.o fibo.o sorting.o buffon.o area.o
	$(CC) main.o fibo.o sorting.o buffon.o area.o -o ep1 $(CFLAGS)
main.o: main.c sorting.h fibo.h buffon.h area.h
	$(CC) -c main.c $(CFLAGS)
fibo.o: fibo.h fibo.c
	$(CC) -c fibo.c $(CFLAGS)
sorting.o: sorting.h sorting.c
	$(CC) -c sorting.c $(CFLAGS)
buffon.o: buffon.h buffon.c
	$(CC) -c buffon.c $(CFLAGS)
area.o: area.h area.c
	$(CC) -c area.c $(CFLAGS)
clean:
	rm *.o
