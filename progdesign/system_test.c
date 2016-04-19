#include <stdlib.h>   /*for system function*/
#include <stdio.h>

int main(void)
{
  char *p=NULL;
  char *q="deep in linux software";

  /*system function is the interface between shell and application*/
  /*if system execute failed,ERRNO=127 is returned*/

  p=q;
  p++;
  printf(p);
  printf(q);
  printf("\n");
  
  system("ps aux &");

  printf("done\n");
  return 0;
}
