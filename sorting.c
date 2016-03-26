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
#include "sorting.h"

void sorting(int m){
  int i, *v;
  time_t t;

  /* Aloca o vetor de tamanho m */
  v = malloc(m * sizeof(int));
  srand((unsigned) time(&t));

  /* Gera e imprime os m numeros de 0 a 99 */
  printf("SORTING: |");
  for(i = 0; i < m; i++){
    v[i] = rand() % 100;
    printf(" %02d |", v[i]);
  }
  printf("\n");

  /* Chamada da funcao de ordenacao */
  heapsort(v, m);

  /* Impressao do vetor ordenado */
  printf("SORTED: |");
  for(i = 0; i < m; i++)
    printf(" %02d |", v[i]);
  printf("\n");

  free(v);
}

void heapsort(int arr[], unsigned int N){

    int t; /* the temporary value */
    unsigned int n = N, parent = N/2, index, child; /* heap indexes */

    if(N==0) /* check if heap is empty */
      return;

    /* loop until array is sorted */
    while (1) {
        if (parent > 0) {
            /* first stage - Sorting the heap */
            t = arr[--parent];  /* save old value to t */
        } else {
            /* second stage - Extracting elements in-place */
            n--;                /* make the heap smaller */
            if (n == 0) {
                return; /* When the heap is empty, we are done */
            }
            t = arr[n];         /* save lost heap entry to temporary */
            arr[n] = arr[0];    /* save root entry beyond heap */
        }
        /* insert operation - pushing t down the heap to replace the parent */
        index = parent; /* start at the parent index */
        child = index * 2 + 1; /* get its left child index */
        while (child < n) {
            /* choose the largest child */
            if (child + 1 < n  &&  arr[child + 1] > arr[child]) {
                child++; /* right child exists and is bigger */
            }
            /* is the largest child larger than the entry? */
            if (arr[child] > t) {
                arr[index] = arr[child]; /* overwrite entry with child */
                index = child; /* move index to the child */
                child = index * 2 + 1; /* get the left child and go around again */
            } else {
                break; /* t's place is found */
            }
        }
        /* store the temporary value at its new location */
        arr[index] = t;
    }
}
