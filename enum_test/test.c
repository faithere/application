#include <stdio.h>

struct type{
  int a;
  int b;
  int c;
};

enum enum_type{
  FIRST,
  SECOND,
  THIRD=(8U),
};

int main(void)
{
  struct type test[2]={
    {1,2,FIRST},
    {3,4,THIRD}
  };
  
  printf("test[0].a=%d,test[0].b=%d,test[0].c=%d\n",test[0].a,test[0].b,test[0].c);
  printf("test[1].a=%d,test[1].b=%d,test[1].c=%d\n",test[1].a,test[1].b,test[1].c);
  return 0;
}
