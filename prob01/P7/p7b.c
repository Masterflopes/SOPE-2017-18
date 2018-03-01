#include <stdio.h>
#include <stdlib.h>

void exit_handler_1(){
  printf("Executing exit handler 1\n");
}

void exit_handler_2(){
  printf("Executing exit handler 2\n");
}

int main(void)
{
  if(atexit(exit_handler_1) != 0)
    printf("Error handler 1\n");
  if(atexit(exit_handler_2) != 0)
    printf("Error handler 2\n");

  printf("Main done!\n");
  exit(0);
}
