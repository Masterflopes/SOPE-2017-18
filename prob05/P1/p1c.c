#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(void){
  pid_t pid;
  int fd[2];

  pipe(fd);

  pid=fork();

  if(pid > 0){
    char values[2][MAX_SIZE];
    printf("Introduce x: ");
    scanf("%s",values[0]);
    printf("Introduce y: ");
    scanf("%s",values[1]);
    close(fd[0]);
    write(fd[1],values,sizeof(values));
    close(fd[1]);
  }
  else{
    char valores[2][MAX_SIZE];
    close(fd[1]);
    read(fd[0],&valores,sizeof(valores));
    close(fd[0]);
    printf("\nSoma: %d\n", atoi(valores[0]) + atoi(valores[1]));
    printf("Diferença: %d\n", atoi(valores[0]) - atoi(valores[1]));
    printf("Produto: %d\n", atoi(valores[0]) * atoi(valores[1]));
    printf("Divisão: %f\n", (double)atoi(valores[0]) / atoi(valores[1]));
  }

}
