#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

int main(void)
{
  pid_t child_pid;
  int i;
  char *start_message;
  char *run_message;

  int exit_code;

  start_message="fork process start!";
  puts(start_message);/*puts add \n auto,don't need write \n manually*/

  child_pid=fork();
  
  switch (child_pid)
    {
    case -1:
      perror("fork faild!\n");
      exit(1);
    case 0:
      i=10;
      exit_code=37;
      run_message="child process in\n";
      break;
    default:
      i=2;
      exit_code=0;
      run_message="father process in\n";
      break;
    }
  for(;i>0;i--)
    {
      printf(run_message);
      sleep(1);
    }

  if (child_pid!=0)
    {
      while(!waitpid(child_pid,NULL,WNOHANG))
	;//printf("child process not end!\n");
      printf("child process end now\n");
    }
 
  //  if (child_pid!=0)/*in the parent process*/
  //  {
  ///     int stat_val;
  //    pid_t pid;
      
  //    pid=wait(&stat_val);

  //    printf("child process end!PID=%d\n",pid);
  //    if (WIFEXITED(stat_val))
  //	printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
  //  else
  //printf("Child process exit abnormally!\n");
  //  
  //}

  exit(exit_code);//exit(exit_code);
}
