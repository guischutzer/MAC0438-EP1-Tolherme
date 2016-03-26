#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"

int fibo(unsigned int k){
  printf("FIBO: Calculando num. de Fibonacci para k = %d\n", k);
  return(fiborec(k));
}

int fiborec(unsigned int k){
  if(k == 1 || k == 2)
    return 1;
  else
    return (fiborec(k-1) + fiborec(k-2));
}
