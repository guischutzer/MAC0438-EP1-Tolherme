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

  pidpai = getpid();

  m = atoi(argv[1]);
  n = atoi(argv[2]);
  r = atoi(argv[3]);
  s = atoi(argv[4]);

  p[0] = 0;
  p[1] = 0;
  p[2] = 0;
  p[3] = 0;

  for(i = 0; i < 4; i++){
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
    if(getpid() != pidpai){
      p[i] = getpid();
      break;
    }
  }

  if(getpid() == pidpai){
    printf("PAI-->Comeco da espera\n");
    for(i = 0; i < 4; i++)
      wait();
    printf("PAI-->Fim da espera.\n");
  }
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
