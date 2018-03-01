#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){
  if(argc < 3){
    printf("Error on function call\n");
    exit(1);
  }
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int i = 1;
  int random_number;

  srand(time(NULL));

  while(random_number != n2){
    printf("Iteration %d: ", i);
    random_number = rand() % n1;
    printf("\t%d\n",random_number);
    i++;
  }
  exit(0);
}
