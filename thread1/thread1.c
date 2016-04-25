#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

/********************global variable********************/
char *message="hello thread";
/********************global variable********************/


void * thread_function(void * arg)
{
  printf("welcome to new thread!message=%s\n",arg);
  message="edit by thread\n";
  sleep(3);
  pthread_exit("goodbye new thread!\n");
}

int main(void)
{
  int res;
  pthread_t new_thread;
  void *thread_result;
  
  res=pthread_create(&new_thread,NULL,thread_function,(void *)message);
  if (res)
    {
      perror("Thread create failed!\n");
      exit(EXIT_FAILURE);
    }
  printf("wait for the thread ended!\n");
  res=pthread_join(new_thread,&thread_result);
  if (res)
    {
      perror("pthread_join failed!\n");
      exit(EXIT_FAILURE);
    }
  printf("thread ended! it returned %s\n",(char *)thread_result);
  
  printf("welcome to main,message = %s now\n",message);
  exit(EXIT_SUCCESS);
}
   
