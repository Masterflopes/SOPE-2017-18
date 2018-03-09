#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  int status;
  if(fork() > 0) {
    wait(&status);
    write(STDOUT_FILENO," World!\n",8);
  } else {
    write(STDOUT_FILENO,"Hello",5);
  }
  return 0;
}
