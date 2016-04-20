#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ocha(int sig)
{
  printf("I got you sig %d!!\n",sig);
}
int main(void)
{
  struct sigaction act;
  
  act.sa_handler=ocha;
  sigemptyset(&act.sa_mask);
  act.sa_flags=0;

  sigaction(SIGINT,&act,0);

  while(1)
    {
      printf("I'm never die!!\n");
      sleep(2);
    }
//  exit(0);
}
