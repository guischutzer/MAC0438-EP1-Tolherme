/*******************************************************************/
/**   MAC 438  - Programação Concorrente                          **/
/**   IME-USP  - Primeiro Semestre de 2016                        **/
/**   Prof. Marcel Parolin Jackowski                              **/
/**                                                               **/
/**   Primeiro Exercício-Programa                                 **/
/**   Arquivo: EP1.c                                              **/
/**                                                               **/
/**   Guilherme Souto Schützer                      8658544       **/
/**   Tomás Bezerra Marcondes Paim                  7157602       **/
/**                                                               **/
/**   04/02/2016                                                  **/
/*******************************************************************/

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
    /* Geramos d aleatorio, variando entre 0 e 1, e
       theta aleatorio, entre 0 e 2*pi */
    d = (double)rand() / (double)RAND_MAX;
    theta = (double)rand()*2*PI / (double)RAND_MAX;
    /* Como L = G = 1, a condicao que
       checa se a agulha cruza e a seguinte: */
    if(d + sin(theta) < 0 || d + sin(theta) > 1)
      t++;
  }

  return t/(double)r;
}
