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
#include "area.h"

double area(int s){
  int i = 0, t = 0;
  double xs, ys;
  time_t T;

  srand((unsigned) time(&T));

  printf("AREA: Faremos %d iteracoes.\n", s);
  for(i = 0; i < s; i++){
    /* xs aleatorio, valor de 0 a 1 */
    xs = (double)rand() / (double)RAND_MAX;
    /* ys aleatorio, valor de 0 a sec(1) */
    ys = (double)rand() / (double)RAND_MAX;
    ys = ys/cos(1);
    /* Se sec(xs) e maior que ys, significa que ys esta abaixo
    de sec(xs) e, portanto, o ponto esta na area.
    Incrementamos a contagem */
    if(1/cos(xs) >= ys)
      t++;
  }

  return (double) t/(double) s/cos(1);
}
