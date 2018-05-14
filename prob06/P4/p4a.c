#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

int global_counter = 0;

void *PrintHello(void *threadnum)
{
 printf("Thread no. %d!\n", (int) threadnum);
 pthread_exit(NULL);
}
int main()
{
 pthread_t threads[NUM_THREADS];
 int t;
 for(t=0; t< NUM_THREADS; t++){
 pthread_create(&threads[t], NULL, PrintHello, (void *) t);
 }
 pthread_exit(0);
}
