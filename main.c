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
#include <sys/types.h>
#include "sorting.h"
#include "fibo.h"
#include "buffon.h"
#include "area.h"

int main(int argc, char *argv[]){
  int m, n, r, s, i, f;
  double b, a;
  pid_t p[4], pidpai;

  if(argc < 5){
    printf("ERRO :: Uso: ./ep1 <tamanho vetor> <numero p/ Fibonnaci> <jogadas de Buffon> <pontos de area>");
    return 1;
  }

  /* Usado para reconhecer o processo pai */
  pidpai = getpid();

  /* Inicialização dos parametros */
  m = atoi(argv[1]);
  n = atoi(argv[2]);
  r = atoi(argv[3]);
  s = atoi(argv[4]);

  /* Inicializacao do vetor de PIDs */
  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;

  /* Laco de criacao dos processos */
  for(i = 0; i < 4; i++){
    /* Cada posicao do vetor recebe o PID do
       processo correspondente (na ordem de argumentos)*/
    switch(i){
      case 0:
        printf("SORTING-->Inicio.\n");
        break;
      case 1:
        printf("FIBONACCI-->Inicio.\n");
        break;
      case 2:
        printf("BUFFON-->Inicio.\n");
        break;
      case 3:
        printf("AREA-->Inicio.\n");
        break;
      default:
        break;
    }
    fork();
    /* Caso seja um processo-filho, coloca o PID próprio no
       vetor e sai do laco, evitando criar "processos-netos" */
    if(getpid() != pidpai){
      p[i] = getpid();
      break;
    }
  }

  /* Codigo subsequente de cada processo */
  if(getpid() == pidpai){
    /* Pai espera os quatro processos. Cada wait() trava a execucao
    ate que algum processo-filho tenha acabado. Se quatro wait()s sao executados,
    significa que esperamos qualquer processo-filho sair quatro vezes,
    ou seja, esperamos os quatro processos acabarem */
    printf("PAI-->Comeco da espera\n");
    for(i = 0; i < 4; i++)
      wait();
    printf("PAI-->Fim da espera.\n");
  }
  /* Nos casos seguintes, cada processo executa a tarefa determinada */
  else if(getpid() == p[0]){
    sorting(m);
    printf("SORTING-->Fim.\n");
  }
  else if(getpid() == p[1]){
    f = fibo(n);
    printf("FIBONACCI-->Num. de Fibonacci de %d: %d\n", n, f);
  }
  else if(getpid() == p[2]){
    b = buffon(r);
    printf("BUFFON-->Probabilidade estimada: %f\n", b);
  }
  else if(getpid() == p[3]){
    a = area(s);
    printf("AREA-->Area estimada: %f\n", a);
  }

  return 0;
}
