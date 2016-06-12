#include <stdio.h>
#include <stddef.h>

#pragma pack(1)
typedef struct TEST_STRUCT{
  int first;
  short two;
  char three;
  unsigned int fort;
  int array[6];
  char last;
}test_struct_t;
#pragma pack()

int main(void)
{
  int i;
  //  test_struct_t test;
  //  test={1,2,3,4,{1,2,3,4,5,6},5};
  i=offsetof(test_struct_t,last);
  printf("i=%d\n",i);
  return 0;
  
}
