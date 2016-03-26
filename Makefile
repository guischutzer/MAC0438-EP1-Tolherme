
all: main fibo sorting buffon area

ep1: main.o fibo.o sorting.o buffon.o area.o
	gcc main.o fibo.o sorting.o buffon.o area.o -o ep1

main.o: main.c sorting.h fibo.h buffon.h area.h
	gcc -c main.c
fibo.o: fibo.h fibo.c
	gcc -c fibo.c
sorting.o: sorting.h sorting.c
	gcc -c sorting.c
buffon.o: buffon.h buffon.c
	gcc -c buffon.c -lm
area.o: area.h area.c
	gcc -c area.c -lm
