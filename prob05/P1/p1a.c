#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
  pid_t pid;
  int fd[2];

  pipe(fd);

  pid=fork();

  if(pid > 0){
    int values[2];
    printf("Introduce x: ");
    scanf("%d",&values[0]);
    printf("Introduce y: ");
    scanf("%d",&values[1]);
    close(fd[0]);
    write(fd[1],values,2*sizeof(int));
    close(fd[1]);
  }
  else{
    int valores[2];
    close(fd[1]);
    read(fd[0],valores,2*sizeof(int));
    close(fd[0]);
    printf("\nSoma: %d\n", valores[0] + valores[1]);
    printf("Diferença: %d\n", valores[0] - valores[1]);
    printf("Produto: %d\n", valores[0] * valores[1]);
    printf("Divisão: %f\n", (double)valores[0] / valores[1]);
  }

}
