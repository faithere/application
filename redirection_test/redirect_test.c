#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
  int ch; /*getchar use ASCII code to operate*/

  while((ch=getchar())!=EOF) /*powerful the understanding of getchar*/
    {
      putchar(toupper(ch));
    }
  
  exit(0);
}
