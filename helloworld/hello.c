#include <stdio.h>
#include <string.h>

int main(void)
{
  char p[6];
  char *test="hello";
  strcpy(p,test);
  puts(p);
 // putchar('\n');
  printf("%s\n",p);
  printf("strlen of p=%d  sizeof of p=%d sizof of test=%d strlen of test=%d\n",strlen(p),sizeof(p),sizeof(test),strlen(test));
  return 0;
}
