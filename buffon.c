#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "buffon.h"

#define PI 3.14159265359

double buffon(int r){
  int i, t = 0;
  double d, theta;
  time_t T;

  srand((unsigned) time(&T));

  printf("BUFFON: Faremos %d iteracoes.\n", r);
  for(i = 0; i < r; i++){
    d = (double)rand() / (double)RAND_MAX;
    theta = (double)rand()*2*PI / (double)RAND_MAX;
    if(d + sin(theta) < 0 || d + sin(theta) > 1)
      t++;
  }

  return t/(double)r;
}
