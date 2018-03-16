#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
  pid_t pid;
  int fd1[2], fd2[2];

  pipe(fd1);
  pipe(fd2);

  pid=fork();

  if(pid > 0){
    int values[2];
    int results[4];
    close(fd1[0]); close(fd2[1]);
    printf("Introduce x: ");
    scanf("%d",&values[0]);
    printf("Introduce y: ");
    scanf("%d",&values[1]);
    write(fd1[1],values,2*sizeof(int));
    read(fd2[0],results,4*sizeof(int));
    printf("\nSoma: %d\n", results[0]);
    printf("Diferença: %d\n", results[1]);
    printf("Produto: %d\n", results[2]);
    if(results[3] == -1){
      printf("Divisão: Impossível\n");
    }
    else{
      printf("Divisão: %d\n", results[3]);
    }
  }
  else{
    int valores[2];
    int resultados[4];
    close(fd1[1]); close(fd2[0]);
    read(fd1[0],valores,2*sizeof(int));
    resultados[0] = valores[0] + valores[1];
    resultados[1] = valores[0] - valores[1];
    resultados[2] = valores[0] * valores[1];
    if(valores[1] == 0){
      resultados[3] = -1;
    }
    else{
      resultados[3] = valores[0] / valores[1];
    }
    write(fd2[1],resultados,4*sizeof(int));
  }

}
