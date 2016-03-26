#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "buffon.h"

double buffon(int r){
  int i, t = 0;
  double d, theta;
  time_t T;

  srand((unsigned) time(&T));

  printf("Faremos %d iteracoes.\n", r);
  for(i = 0; i < r; i++){
    d = (double)rand() / (double)RAND_MAX;
    theta = (double)rand()*2*M_PI / (double)RAND_MAX;
    //printf("%8f, %8f\n", d, theta);
    if(d + sin(theta) < 0 || d + sin(theta) > 1)
      t++;
  }

  return t/(double)r;
}

int main(int argc, char *argv[]){
  double p = buffon(atoi(argv[1]));
  printf("Probabilidade estimada: %f.\n", p);
}
