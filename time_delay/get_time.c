#include <stdio.h>
#include <sys/time.h>

void delay(long data)
{
  int i,j;
  for(i=0;i<data;i++)
    for(j=0;j<5000;j++);
}

int main(void)
{
  struct timeval timestart;
  struct timeval timeend;
  
  long diff;
  
  gettimeofday(&timestart,NULL);
  delay(1);
  gettimeofday(&timeend,NULL);
  diff=1000000*(timeend.tv_sec-timestart.tv_sec)+(timeend.tv_usec-timestart.tv_usec);
  printf("diff=%ld\n",diff);
  return 0;
}
