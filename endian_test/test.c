 
#include <stdio.h>

int main(void)
{
  int temp32;
  temp32=0x12345678;
  unsigned char *temp8;
  unsigned short *temp16;

  temp8=(unsigned char *)(&temp32);
  
  temp16=(unsigned short *)(&temp32);
  
  printf("temp32=0x%x,address=0x%x\n",temp32,&temp32);
  printf("temp16=0x%x,address=0x%x\n",*(temp16),temp16);
  printf("temp8=0x%x,address=0x%x\n",*(temp8),temp8);
  
  printf("temp8+1=0x%x,address=0x%x\n",*(temp8+1),temp8+1);
  printf("temp8-1=0x%x,address=0x%x\n",*(temp8-1),temp8-1);

  
}
