#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

/********************GLOABL MACRO***********************/
#define MAX_SIZE 1024
/********************E    N     D***********************/


/********************global variable********************/
sem_t bin_sem;

char work_area[MAX_SIZE];
/********************end end end end********************/

void * thread_function(void * arg)
{
  sem_wait(&bin_sem);
  while(strncmp("End",work_area,3)!=0)
    {
      printf("You have enter %d characters\n",strlen(work_area)-1);
      sem_wait(&bin_sem);
    }
  pthread_exit(NULL);
}

int main(void)
{
  int res;
  pthread_t new_thread;
  void *thread_result;
  
  res=sem_init(&bin_sem,0,0);
  if (res)
    {
      perror("sem init error\n");
      exit(-1);
    }
  
  res=pthread_create(&new_thread,NULL,thread_function,NULL);
  if (res)
    {
      perror("Thread create failed!\n");
      exit(EXIT_FAILURE);
    }
  
  printf("Enter some text, use \"End\" to end the input:\n");
  
  while(strncmp("End",work_area,3)!=0)
    {
      fgets(work_area,MAX_SIZE,stdin);
      sem_post(&bin_sem);
    }

  printf("\nWait for thread to join\n");
  res=pthread_join(new_thread,&thread_result);
  if (res)
    {
      perror("pthread_join failed\n");
      exit(-1);

    }
  sem_destroy(&bin_sem);
  printf("thread joined\n");
  exit(0);
}
   
