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
#include "fibo.h"

int fibo(unsigned int k){
  printf("FIBO: Calculando num. de Fibonacci para k = %d\n", k);
  return(fiborec(k));
}

int fiborec(unsigned int k){
  /* Condicao de parada */
  if(k == 1 || k == 2)
    return 1;
  /* Chamada recursiva */
  else
    return (fiborec(k-1) + fiborec(k-2));
}
