#include <stdio.h>

typedef struct temp{
  int a;
  char b;
  char c[8];
}temp_t;

temp_t arr[2]={
  {1,2},
  {3,4,{8,9,0xa,0xb,0xc,0xd,0xe,0xf}}
};


void changeFlow(char *temp_array,char *p)
{
  
  int num=4;
  int i;
  char temp;
  for(i=0;i<4;i++)
    {
      *(p+i)=4-i;
    }
  printf("Start to Print temp_array:\n");
  for (i=0;i<8;i++)
    printf("0x%x\n",temp_array[i]);
  printf("End Print\n");
}
int main(void)
{
  temp_t test;
  int i;
  char d[4]={1,2,3,4};

  changeFlow(arr[1].c,d);
  
  for (i=0;i<4;i++)
    printf("%d=%d\n",i,d[i]);


  test.a=1;
  test.b=2;
  test.c[0]=0;
  test.c[1]=0;  
  test.c[2]=0;
  test.c[3]=0;
  test.c[4]=0;
  test.c[5]=0;
  test.c[6]=0;
  test.c[7]=0;
  test.c[8]=0;
  
  if (arr[0].c!=0)
    {
      printf("first\n");
    }

  for (i=0;i<8;i++)
    printf("c[%d]=%d\n",i,arr[0].c[i]);


  printf("c[0]=%d\n",test.c[0]);

  if (arr[1].c[0]!=0)
    {
      printf("second\n");
      printf("c[7]=%d\n",arr[1].c[7]);
    }
  return 0;
}
