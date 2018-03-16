#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void){
  pid_t pid;
  int fd[2];

  struct values {
    int x;
    int y;
  };

  pipe(fd);

  pid=fork();

  if(pid > 0){
    //int values[2];
    struct values valores;
    printf("Introduce x: ");
    scanf("%d",&valores.x);
    printf("Introduce y: ");
    scanf("%d",&valores.y);
    close(fd[0]);
    write(fd[1],&valores,sizeof(struct values));
    close(fd[1]);
  }
  else{
    struct values valoresb;
    close(fd[1]);
    read(fd[0],&valoresb,sizeof(struct values));
    close(fd[0]);
    printf("\nSoma: %d\n", valoresb.x + valoresb.y);
    printf("Diferença: %d\n", valoresb.x - valoresb.y);
    printf("Produto: %d\n", valoresb.x * valoresb.y);
    printf("Divisão: %f\n", (double)valoresb.x / valoresb.y);
  }

}
