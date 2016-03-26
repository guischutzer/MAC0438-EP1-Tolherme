#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "area.h"

double area(int s){
  int i = 0, t = 0;
  double xs, ys;
  time_t T;

  srand((unsigned) time(&T));

  printf("Faremos %d iteracoes.\n", s);
  for(i = 0; i < s; i++){
    xs = (double)rand() / (double)RAND_MAX;
    ys = (double)rand() / (double)RAND_MAX;
    ys = ys/cos(1);
    printf("x = %8f, y = %8f, 1/cos(x) = %8f\n", xs, ys, 1/cos(xs));
    if(1/cos(xs) >= ys)
      t++;
  }

  printf("t = %d\n", t);
  printf("s = %d\n", s);

  return (double) t/(double) s/cos(1);
}

int main(int argc, char *argv[]){
  double a = area(atoi(argv[1]));
  printf("Area estimada: %f.\n", a);
}
