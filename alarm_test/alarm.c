#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/**********global definition**********/
int ding_flag=0;


/**********end end   end end**********/

void ding(int sig)
{
  ding_flag=1;
}


int main(void)
{
  pid_t new_pid;

  printf("Start to run ding\n");
  new_pid=fork();

  switch (new_pid)
    {
    case -1:
      perror("fork child process faid!\n");
      exit(1);
    case 0:
      sleep(10);
      kill(getppid(),SIGALRM);
      exit(0);
    }
  (void)signal(SIGALRM,ding);
  printf("wait for alarm signal\n");
  pause();
  if (ding_flag==1)
    printf("Ding!!Alarm\n");
  printf("Done\n");
}
