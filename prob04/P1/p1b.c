#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void sigint_handler(int signo)
{
  printf("In SIGINT handler ...\n");
}
int main(void)
{
  if (signal(SIGINT,sigint_handler) < 0)
  {
    fprintf(stderr,"Unable to install SIGINT handler\n");
    exit(1);
  }
  int seconds;
  printf("Sleeping for 30 seconds ...\n");
  seconds = sleep(30);
  while(seconds >0){
    seconds = sleep(seconds);
  }
  printf("Waking up ...\n");
  exit(0);
}
