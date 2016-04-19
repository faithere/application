#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_deal(int sig)
{
  printf("you hit me one time!!!,sig_num=%d\n",sig);
  
  (void)signal(SIGINT,SIG_DFL);
}

int main(void)
{
  (void)signal(SIGINT,signal_deal);
  
  for(;;)
    {
      printf("I'm never die!!!\n");
      sleep(2);
    }
}
