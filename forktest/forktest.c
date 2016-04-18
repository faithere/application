#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>  /*defination for pid_t*/
#include <sys/wait.h>  /*defination for wait function*/
int main(void)
{
  pid_t new_pro;
  char * message;
  int n;

  printf("fork process start!\n");

  new_pro=fork();

  puts("after fork!\n");

  switch (new_pro)
    {
    case -1:
      perror("fork failed");
      return -1;
      /*fork failed*/
    case 0:
      message="I'm child process\n";
      n=5;
      break;
    default:
      message="I'm parent process\n";
      n=2;
      break;
    }
  
  for (;n>0;n--)
    {			
      printf(message);
      sleep(1);
    }	
  return 0;
}
