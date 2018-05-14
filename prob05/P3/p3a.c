#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#define LENGTH 265

int main(int argc, char* argv[]){

	if(argc == 0){
		printf("Missing file\n");
		return 1;
	}
  int[2] fd;
  pid_t pid;
  pipe(fd);

  pid=fork();

  if(pid > 0){
    close(fd[0]);
    write(fd[1],values,2*sizeof(int));
    execlp("sort", "sort",argv[1],NULL);

  }
  else{
    close(fd[1]);
    read(fd[0],valores,2*sizeof(int));
    execlp("sort", "sort",argv[1],NULL);
    write(fd[1],resultados,4*sizeof(int));
  }

	return 0;
}
