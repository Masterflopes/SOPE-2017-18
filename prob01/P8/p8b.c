#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char* argv[]){

  clock_t start, end;
  struct tms t;
  long ticks;

  if(argc < 3){
    printf("Error on function call\n");
    exit(1);
  }

  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  int i = 1;
  int random_number;

  srand(time(NULL));

  start = times(&t);
  ticks = sysconf(_SC_CLK_TCK);

  while(random_number != n2){
    printf("Iteration %d: ", i);
    random_number = rand() % n1;
    printf("\t%d\n",random_number);
    i++;
  }
  end = times(&t);

  printf("Clock: %f\n", (double) (end-start)/ticks);
  printf("User time: %f\n", (double) t.tms_utime/ticks);
  printf("System time: %f\n", (double) t.tms_stime/ticks);
  printf("Children user time: %f s\n", (double) t.tms_cutime/ticks);
  printf("Children system time: %f s\n", (double) t.tms_cstime/ticks);

  exit(0);
}
