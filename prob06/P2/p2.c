#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 10000

int global = 50000;

void * thrfunc(void * arg)
{
  fprintf(stderr, "Starting thread %s\n", (char *) arg);
  while(global > 0){
    write(STDERR,arg,1);
    global--;
  }
 return NULL;
}

int main()
{
 pthread_t ta, tb;
 pthread_create(&ta, NULL, thrfunc, "1");
 pthread_create(&tb, NULL, thrfunc, "2");
 pthread_join(ta, NULL);
 pthread_join(tb, NULL);
 return 0;
}
