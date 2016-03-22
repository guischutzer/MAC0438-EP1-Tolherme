#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double area(int r){
  int i = 0;
  double xs, ys;
  time_t T;

  srand((unsigned) time(&T));

  printf("Faremos %d iteracoes.\n", r);
  for(i = 0; i < r; i++){
    xs = (double)rand() / (double)RAND_MAX;
    ys = (double)rand() / (double)RAND_MAX;
    ys = ys/cos(1);
    printf("%8f, %8f\n", xs, ys);
  }

  return 0;
}

int main(int argc, char *argv[]){
  double a = area(atoi(argv[1]));
  printf("Área estimada: %f.\n", a);
}
