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

  printf("AREA: Faremos %d iteracoes.\n", s);
  for(i = 0; i < s; i++){
    xs = (double)rand() / (double)RAND_MAX;
    ys = (double)rand() / (double)RAND_MAX;
    ys = ys/cos(1);
    if(1/cos(xs) >= ys)
      t++;
  }

  return (double) t/(double) s/cos(1);
}
