#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"

int main(int argc, char *argv[]){
  fibo(atoi(argv[1]));
}

int fibo(unsigned int k){
  printf("Calculando num. de Fibonacci para k = %d\n", k);
  printf("fibo de %d: %d\n", k, fiborec(k));
}

int fiborec(unsigned int k){
  if(k == 1 || k == 2)
    return 1;
  else
    return (fiborec(k-1) + fiborec(k-2));
}
