#include <stdio.h>
#include <string.h>

int main(void)
{
  unsigned char a[10]={0,1,2,3,4,5,6,7,8,9};
  unsigned char *p1=&a[1];
  unsigned char *p2=&a[2];
  unsigned char *temp[10]={0,0,0,0,0,0,0,0,0,0};  //if not use temp array,just use *temp pointer,will occur segment fault
  int i;
  
  memcpy(temp,p1,8);
  memcpy(p2,temp,8);
  
  for(i=0;i<10;i++)
    {
      printf("%d\n",a[i]);


    }
  return 0;
}
