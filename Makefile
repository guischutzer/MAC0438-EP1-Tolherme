

fibo: fibo.c
	gcc -o fibo fibo.c
sorting: sorting.c
	gcc -o sorting sorting.c
buffon: buffon.c
	gcc -o buffon buffon.c -lorem
clean:
	rm *.o
