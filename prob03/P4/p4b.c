#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  if(fork() > 0) {
    write(STDOUT_FILENO,"Hello",5);
  } else {
    write(STDOUT_FILENO," World!\n",8);
  }
  return 0;
}
