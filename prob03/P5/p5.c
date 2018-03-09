#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  if(fork() > 0) {
    write(STDOUT_FILENO,"Hello",5);
  } else {
    if(fork() > 0) {
      write(STDOUT_FILENO," my ",4);
    } else {
      write(STDOUT_FILENO,"friends!\n",9);
    }
  }
  return 0;
}
