#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int v;
int add;

void sigusr_handler(int signo)
{
  switch(signo){
    case 10:
      add = 1;
      break;
    case 12:
      add = -1;
      break;
    default:
      break;
  }
}

int main(void)
{
  v = 0;
  add = 1;

 struct sigaction action;
 action.sa_handler = sigusr_handler;
 sigemptyset(&action.sa_mask);
 action.sa_flags = 0;
 if (sigaction(SIGUSR1,&action,NULL) < 0)
 {
       fprintf(stderr,"Unable to install SIGINT handler\n");
       exit(1);
 }
 if (sigaction(SIGUSR2,&action,NULL) < 0)
 {
       fprintf(stderr,"Unable to install SIGINT handler\n");
       exit(1);
 }

 while(1){
   v = v + add;
    printf("v: %d\n",v);
    sleep(1);
 }
 exit(0);
}
