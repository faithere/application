#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/********************global variable********************/
int run_now=1;
/********************global variable********************/


void * thread_function(void * arg)
{
  int print_count=1;
  while(print_count++<20)
    {
      if (run_now==2)
	{
	  printf("%d",run_now);
	  run_now=1;
	}
      else
	sleep(1);
    }
  pthread_exit(NULL);
}


int main(void)
{
  int res;
  pthread_t new_thread;
  void *thread_result;
  int print_count=1;

  res=pthread_create(&new_thread,NULL,thread_function,NULL);
  if (res)
    {
      perror("Thread create failed!\n");
      exit(EXIT_FAILURE);
    }
  
  while(print_count++<20)
    {
      if(run_now==1)
	{
	  printf("%d",run_now);
	  run_now=2;
	}
      else
	sleep(1);
    }
  printf("wait for thread end\n");
  
  res=pthread_join(new_thread,&thread_result);
  if (res)
    {
      perror("pthread_join failed\n");
      exit(-1);
    }
  printf("thread joined!\n Well Done");

  exit(0);
}
   
